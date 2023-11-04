// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#include "Serialization/GSS_SlotDataTask_Saver.h"
#include "GameFramework/GameModeBase.h"
#include "Misc/GSS_SlotHelpers.h"
#include "GSS_SaveSubsystem.h"
#include "GSS_SlotInfo.h"
#include "GSS_SlotData.h"
#include "GSS_SavePreset.h"
#include "GSS_FileAdapter.h"
#include "Serialization/GSS_Task_SerializeSavers.h"


void UGSS_SlotDataTask_Saver::OnStart()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USlotDataTask_Saver::OnStart);
	UGSS_SaveSubsystem* Manager = GetManager();
	Manager->TryInstantiateInfo();

	bool bSave = true;
	const FString SlotNameString = SlotName.ToString();
	//Overriding
	{
		const bool bFileExists = FGSS_FileAdapter::DoesFileExist(SlotNameString);
		if (bOverride)
		{
			// Delete previous save
			if (bFileExists)
			{
				FGSS_FileAdapter::DeleteFile(SlotNameString);
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
		SlotInfo->Map = FName{FGSS_SlotHelpers::GetWorldName(World)};
		SlotData->Map = SlotData->Map;

		SlotData->bStoreGameInstance = Preset->bStoreGameInstance;

		SerializeWorld();
		GetManager()->SaveAllSavers();
		SaveFile();
		return;
	}
	Finish(false);
}

void UGSS_SlotDataTask_Saver::Tick(float DeltaTime)
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

void UGSS_SlotDataTask_Saver::OnFinish(bool bSuccess)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USlotDataTask_Saver::OnFinish);
	if (bSuccess)
	{
		// Clean serialization data
		SlotData->CleanRecords(true);

		GSS_Log(Preset, "Finished Saving", FColor::Green);
	}

	// Execute delegates
	UGSS_SaveSubsystem* Manager = GetManager();
	check(Manager);
	Delegate.ExecuteIfBound((Manager && bSuccess) ? Manager->GetCurrentInfo() : nullptr);
	Manager->OnSaveFinished(!bSuccess);
}

void UGSS_SlotDataTask_Saver::BeginDestroy()
{
	if (SaveTask)
	{
		SaveTask->EnsureCompletion(false);
		delete SaveTask;
	}

	Super::BeginDestroy();
}

void UGSS_SlotDataTask_Saver::SerializeWorld()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USlotDataTask_Saver::SerializeWorld);

	// Must have Authority
	if (!GetWorld()->GetAuthGameMode())
	{
		return;
	}

	const UWorld* World = GetWorld();
	GSS_Log(Preset, "World '" + World->GetName() + "'", FColor::Green, false, 1);

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

void UGSS_SlotDataTask_Saver::PrepareAllLevels(const TArray<ULevelStreaming*>& Levels)
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

void UGSS_SlotDataTask_Saver::ScheduleTasksForLevel(const ULevel* Level, int32 AssignedTasks, const ULevelStreaming* StreamingLevel)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USlotDataTask_Saver::BuildSerializeTasksForLevel);
	check(IsValid(Level));

	//如果没开启多线程，那么只需要分配1个任务.
	if (!Preset->IsMTSerializationSave())
	{
		AssignedTasks = 1;
	}

	const FName LevelName = StreamingLevel ? StreamingLevel->GetWorldAssetPackageFName() : FGSS_PersistentLevelRecord::PersistentName;
	GSS_Log(Preset, "Level '" + LevelName.ToString() + "'", FColor::Green, false, 1);

	// Find level record. By default, main level
	FGSS_LevelRecord* LevelRecord = &SlotData->MainLevel;
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
		Tasks.Emplace(FGSS_AsyncTask_SerializeActors
			{
				GetWorld(), SlotData, &Level->Actors, Index, NumToSerialize,
				bStoreGameInstance, LevelRecord
			});

		Index += NumToSerialize;
	}
}

void UGSS_SlotDataTask_Saver::RunScheduledTasks()
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
	for (FAsyncTask<FGSS_AsyncTask_SerializeActors>& AsyncTask : Tasks)
	{
		AsyncTask.EnsureCompletion();
	}
	// 所有Task完成后，同步数据。
	for (FAsyncTask<FGSS_AsyncTask_SerializeActors>& AsyncTask : Tasks)
	{
		AsyncTask.GetTask().DumpData();
	}
	Tasks.Empty();
}

void UGSS_SlotDataTask_Saver::SaveFile()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USlotDataTask_Saver::SaveFile);
	UGSS_SaveSubsystem* Manager = GetManager();

	SaveTask = new FAsyncTask<FGSS_Task_SaveFile>(
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
