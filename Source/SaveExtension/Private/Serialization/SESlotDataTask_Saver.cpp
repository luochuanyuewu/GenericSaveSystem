// Copyright 2015-2020 Piperift. All Rights Reserved.

#include "Serialization/SESlotDataTask_Saver.h"

#include "GameFramework/GameModeBase.h"
#include "Serialization/MemoryWriter.h"

#include "Misc/SESlotHelpers.h"
#include "SESaveManager.h"
#include "SESlotInfo.h"
#include "SESlotData.h"
#include "SESavePreset.h"
#include "SEFileAdapter.h"


/////////////////////////////////////////////////////
// USaveDataTask_Saver

void USESlotDataTask_Saver::OnStart()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USlotDataTask_Saver::OnStart);
	USESaveManager* Manager = GetManager();
	Manager->TryInstantiateInfo();

	bool bSave = true;
	const FString SlotNameStr = SlotName.ToString();
	//Overriding
	{
		const bool bFileExists = FSEFileAdapter::DoesFileExist(SlotNameStr);
		if (bOverride)
		{
			// Delete previous save
			if (bFileExists)
			{
				FSEFileAdapter::DeleteFile(SlotNameStr);
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

		GetManager()->OnSaveBegan(GetGeneralFilter());

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

		// Time stats
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
		SlotInfo->Map = FName{ FSESlotHelpers::GetWorldName(World) };
		SlotData->Map = SlotData->Map;

		SlotData->bStoreGameInstance = Preset->bStoreGameInstance;
		SlotData->GeneralLevelFilter = Preset->ToFilter();

		SerializeWorld();
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
	Delegate.ExecuteIfBound((Manager && bSuccess)? Manager->GetCurrentInfo() : nullptr);
	Manager->OnSaveFinished(
		SlotData? GetGeneralFilter() : FSELevelFilter{},
		!bSuccess
	);
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

	// Threads available + 1 (Synchronous Thread)
	const int32 NumberOfThreads = FMath::Max(1, FPlatformMisc::NumberOfWorkerThreadsToSpawn() + 1);
	const int32 TasksPerLevel = FMath::Max(1, FMath::RoundToInt(float(NumberOfThreads) / (Levels.Num() + 1)));
	Tasks.Reserve(NumberOfThreads);

	SerializeLevelSync(World->GetCurrentLevel(), TasksPerLevel);
	for (const ULevelStreaming* Level : Levels)
	{
		if (Level->IsLevelLoaded())
		{
			SerializeLevelSync(Level->GetLoadedLevel(), TasksPerLevel, Level);
		}
	}

	RunScheduledTasks();
}

void USESlotDataTask_Saver::PrepareAllLevels(const TArray<ULevelStreaming*>& Levels)
{
	BakeAllFilters();

	// Create the sub-level records if non existent
	for (const ULevelStreaming* Level : Levels)
	{
		if (Level->IsLevelLoaded())
		{
			SlotData->SubLevels.AddUnique({ *Level });
		}
	}
}

void USESlotDataTask_Saver::SerializeLevelSync(const ULevel* Level, int32 AssignedTasks, const ULevelStreaming* StreamingLevel)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USlotDataTask_Saver::SerializeLevelSync);
	check(IsValid(Level));

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

	auto& Filter = GetLevelFilter(*LevelRecord);

	const int32 MinObjectsPerTask = 40;
	const int32 ActorCount = Level->Actors.Num();
	const int32 NumBalancedPerTask = FMath::CeilToInt((float) ActorCount / AssignedTasks);
	const int32 NumPerTask = FMath::Max(NumBalancedPerTask, MinObjectsPerTask);

	// Split all actors between multi-threaded tasks
	int32 Index = 0;
	while (Index < ActorCount)
	{
		const int32 NumRemaining = ActorCount - Index;
		const int32 NumToSerialize = FMath::Min(NumRemaining, NumPerTask);

		// First task saves the GameInstance
		bool bStoreGameInstance = Index <= 0 && SlotData->bStoreGameInstance;
		// Add new Task
		Tasks.Emplace(FSETask_SerializeActors
		{
			GetWorld(), SlotData, &Level->Actors, Index, NumToSerialize,
			bStoreGameInstance, LevelRecord, Filter
		});

		Index += NumToSerialize;
	}
}

void USESlotDataTask_Saver::RunScheduledTasks()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USlotDataTask_Saver::RunScheduledTasks);
	// Start all serialization tasks
	if (Tasks.Num() > 0)
	{
		for (int32 I = 1; I < Tasks.Num(); ++I)
		{
			if (Preset->IsMTSerializationSave())
				Tasks[I].StartBackgroundTask();
			else
				Tasks[I].StartSynchronousTask();
		}
		// First task stores
		Tasks[0].StartSynchronousTask();
	}
	// Wait until all tasks have finished
	for (auto& AsyncTask : Tasks)
	{
		AsyncTask.EnsureCompletion();
	}
	// All tasks finished, sync data
	for (auto& AsyncTask : Tasks)
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
