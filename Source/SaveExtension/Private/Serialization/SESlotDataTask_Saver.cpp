// Copyright 2015-2020 Piperift. All Rights Reserved.

#include "Serialization/SESlotDataTask_Saver.h"
#include "GameFramework/GameModeBase.h"
#include "Misc/SESlotHelpers.h"
#include "SESaveManager.h"
#include "SESlotInfo.h"
#include "SESlotData.h"
#include "SESavePreset.h"
#include "SEFileAdapter.h"
#include "Serialization/SETask_SerializeSavers.h"


void USESlotDataTask_Saver::OnStart()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USlotDataTask_Saver::OnStart);
	USESaveManager* Manager = GetManager();
	Manager->TryInstantiateInfo();

	bool bSave = true;
	const FString SlotNameString = SlotName.ToString();
	//Overriding
	{
		const bool bFileExists = FSEFileAdapter::DoesFileExist(SlotNameString);
		if (bOverride)
		{
			// Delete previous save
			if (bFileExists)
			{
				FSEFileAdapter::DeleteFile(SlotNameString);
			}
		}
		else
		{
			//Only save if previous files don't exist
			//We don't want to serialize since it won't be saved anyway
			bSave = !bFileExists;
		}
	}

	if (bSave)
	{
		const UWorld* World = GetWorld();

		GetManager()->OnSaveBegan();

		SlotInfo = Manager->GetCurrentInfo();
		SlotData = Manager->GetCurrentData();
		SlotData->CleanRecords(true);

		check(SlotInfo && SlotData);

		const bool bSlotWasDifferent = SlotInfo->FileName != SlotName;
		SlotInfo->FileName = SlotName;

		if (bSaveThumbnail)
		{
			SlotInfo->CaptureThumbnail(Width, Height);
		}

		// 开始时间
		{
			SlotInfo->SaveDate = FDateTime::Now();

			// If this info has been loaded ever
			const bool bWasLoaded = SlotInfo->LoadDate.GetTicks() > 0;
			if (bWasLoaded)
			{
				// Now - Loaded
				const FTimespan SessionTime = SlotInfo->SaveDate - SlotInfo->LoadDate;

				SlotInfo->PlayedTime += SessionTime;

				if (!bSlotWasDifferent)
					SlotInfo->SlotPlayedTime += SessionTime;
				else
					SlotInfo->SlotPlayedTime = SessionTime;
			}
			else
			{
				// Slot is new, played time is world seconds
				SlotInfo->PlayedTime = FTimespan::FromSeconds(World->TimeSeconds);
				SlotInfo->SlotPlayedTime = SlotInfo->PlayedTime;
			}

			// Save current game seconds
			SlotData->TimeSeconds = World->TimeSeconds;
		}

		//Save Level info in both files
		SlotInfo->Map = FName{FSESlotHelpers::GetWorldName(World)};
		SlotData->Map = SlotData->Map;

		SlotData->bStoreGameInstance = Preset->bStoreGameInstance;

		SerializeWorld();
		GetManager()->SaveAllSavers();
		SaveFile();
		return;
	}
	Finish(false);
}

void USESlotDataTask_Saver::Tick(float DeltaTime)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USlotDataTask_Saver::Tick);
	Super::Tick(DeltaTime);

	if (SaveTask && SaveTask->IsDone())
	{
		if (bSaveThumbnail)
		{
			if (SlotInfo && SlotInfo->GetThumbnail())
			{
				Finish(true);
			}
		}
		else
		{
			Finish(true);
		}
	}
}

void USESlotDataTask_Saver::OnFinish(bool bSuccess)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USlotDataTask_Saver::OnFinish);
	if (bSuccess)
	{
		// Clean serialization data
		SlotData->CleanRecords(true);

		SELog(Preset, "Finished Saving", FColor::Green);
	}

	// Execute delegates
	USESaveManager* Manager = GetManager();
	check(Manager);
	Delegate.ExecuteIfBound((Manager && bSuccess) ? Manager->GetCurrentInfo() : nullptr);
	Manager->OnSaveFinished(!bSuccess);
}

void USESlotDataTask_Saver::BeginDestroy()
{
	if (SaveTask)
	{
		SaveTask->EnsureCompletion(false);
		delete SaveTask;
	}

	Super::BeginDestroy();
}

void USESlotDataTask_Saver::SerializeWorld()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USlotDataTask_Saver::SerializeWorld);

	// Must have Authority
	if (!GetWorld()->GetAuthGameMode())
	{
		return;
	}

	const UWorld* World = GetWorld();
	SELog(Preset, "World '" + World->GetName() + "'", FColor::Green, false, 1);

	const TArray<ULevelStreaming*>& Levels = World->GetStreamingLevels();
	PrepareAllLevels(Levels);

	// 可用线程 + 1 个(同步线程)
	const int32 NumberOfThreads = FMath::Max(1, FPlatformMisc::NumberOfWorkerThreadsToSpawn() + 1);
	const int32 TasksPerLevel = FMath::Max(1, FMath::RoundToInt(float(NumberOfThreads) / (Levels.Num() + 1)));
	Tasks.Reserve(NumberOfThreads);

	ScheduleTasksForLevel(World->GetCurrentLevel(), TasksPerLevel);
	for (const ULevelStreaming* Level : Levels)
	{
		if (Level->IsLevelLoaded())
		{
			ScheduleTasksForLevel(Level->GetLoadedLevel(), TasksPerLevel, Level);
		}
	}

	RunScheduledTasks();
}

void USESlotDataTask_Saver::PrepareAllLevels(const TArray<ULevelStreaming*>& Levels)
{
	// Create the sub-level records if non existent
	for (const ULevelStreaming* Level : Levels)
	{
		if (Level->IsLevelLoaded())
		{
			SlotData->SubLevels.AddUnique({*Level});
		}
	}
}

void USESlotDataTask_Saver::ScheduleTasksForLevel(const ULevel* Level, int32 AssignedTasks, const ULevelStreaming* StreamingLevel)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USlotDataTask_Saver::BuildSerializeTasksForLevel);
	check(IsValid(Level));

	//如果没开启多线程，那么只需要分配1个任务.
	if (!Preset->IsMTSerializationSave())
	{
		AssignedTasks = 1;
	}

	const FName LevelName = StreamingLevel ? StreamingLevel->GetWorldAssetPackageFName() : FSEPersistentLevelRecord::PersistentName;
	SELog(Preset, "Level '" + LevelName.ToString() + "'", FColor::Green, false, 1);

	// Find level record. By default, main level
	FSELevelRecord* LevelRecord = &SlotData->MainLevel;
	if (StreamingLevel)
	{
		LevelRecord = FindLevelRecord(StreamingLevel);
	}
	check(LevelRecord);

	// Empty level record before serializing it
	LevelRecord->CleanRecords();

	const int32 MinObjectsPerTask = 40;
	const int32 ActorCount = Level->Actors.Num();
	const int32 NumBalancedPerTask = FMath::CeilToInt((float)ActorCount / AssignedTasks);
	const int32 NumPerTask = FMath::Max(NumBalancedPerTask, MinObjectsPerTask);

	// Split all actors between multi-threaded tasks
	// 根据Actor数量，创建出多个Task，每个Task负责序列化一些Actor。
	int32 Index = 0;
	while (Index < ActorCount)
	{
		//
		const int32 NumRemaining = ActorCount - Index;
		//算出此任务序列化多少个Actor.
		const int32 NumToSerialize = FMath::Min(NumRemaining, NumPerTask);

		// 第一个Task是否保存GameInstance.
		bool bStoreGameInstance = Index <= 0 && SlotData->bStoreGameInstance;
		// 添加新的异步任务,只是添加了，但是还没开始。
		Tasks.Emplace(FSEAsyncTask_SerializeActors
			{
				GetWorld(), SlotData, &Level->Actors, Index, NumToSerialize,
				bStoreGameInstance, LevelRecord
			});

		Index += NumToSerialize;
	}
}

void USESlotDataTask_Saver::RunScheduledTasks()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USlotDataTask_Saver::RunScheduledTasks);
	// 开始所有的序列化任务。
	if (Tasks.Num() > 0)
	{
		for (int32 I = 1; I < Tasks.Num(); ++I)
		{
			if (Preset->IsMTSerializationSave())
				Tasks[I].StartBackgroundTask();
			else
				Tasks[I].StartSynchronousTask();
		}
		// 不管第一个任务是否保存GameInstance，
		Tasks[0].StartSynchronousTask();
	}
	// 一直等待直到所有的Task完成。
	for (FAsyncTask<FSEAsyncTask_SerializeActors>& AsyncTask : Tasks)
	{
		AsyncTask.EnsureCompletion();
	}
	// 所有Task完成后，同步数据。
	for (FAsyncTask<FSEAsyncTask_SerializeActors>& AsyncTask : Tasks)
	{
		AsyncTask.GetTask().DumpData();
	}
	Tasks.Empty();
}

void USESlotDataTask_Saver::SaveFile()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USlotDataTask_Saver::SaveFile);
	USESaveManager* Manager = GetManager();

	SaveTask = new FAsyncTask<FSETask_SaveFile>(
		Manager->GetCurrentInfo(), Manager->GetCurrentData(),
		SlotName.ToString(), Preset->bUseCompression);

	if (Preset->IsMTFilesSave())
	{
		SaveTask->StartBackgroundTask();
	}
	else
	{
		SaveTask->StartSynchronousTask();

		if (!bSaveThumbnail)
		{
			Finish(true);
		}
	}
}
