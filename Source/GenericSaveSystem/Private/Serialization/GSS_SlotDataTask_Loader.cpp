// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#include "Serialization/GSS_SlotDataTask_Loader.h"
#include "GameFramework/Character.h"
#include "Serialization/MemoryReader.h"
#include "Kismet/GameplayStatics.h"
#include "Components/PrimitiveComponent.h"
#include "Misc/GSS_SlotHelpers.h"
#include "GSS_SavePreset.h"
#include "GSS_SaveSubsystem.h"
#include "Serialization/GSS_Archive.h"


/////////////////////////////////////////////////////
// Helpers

namespace Loader
{
	static int32 RemoveSingleRecordPtrSwap(TArray<FGSS_ActorRecord*>& Records, AActor* Actor, bool bAllowShrinking = true)
	{
		if (!Actor)
		{
			return 0;
		}

		const int32 I = Records.IndexOfByPredicate([Records, Actor](auto* Record)
		{
			return *Record == Actor;
		});
		if (I != INDEX_NONE)
		{
			Records.RemoveAtSwap(I, 1, bAllowShrinking);
			return 1;
		}
		return 0;
	}
}


/////////////////////////////////////////////////////
// USaveDataTask_Loader

void UGSS_SlotDataTask_Loader::OnStart()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USlotDataTask_Loader::OnStart);
	UGSS_SaveSubsystem* Manager = GetManager();

	GSS_Log(Preset, "Loading from Slot " + SlotName.ToString());

	NewSlotInfo = Manager->LoadInfo(SlotName);
	if (!NewSlotInfo)
	{
		GSS_Log(Preset, "Slot Info not found! Can't load.", FColor::White, true, 1);
		Finish(false);
		return;
	}

	// We load data while the map opens or GC runs
	StartLoadingData();

	const UWorld* World = GetWorld();

	// Cross-Level loading
	// TODO: Handle empty Map as empty world
	FName CurrentMapName{FGSS_SlotHelpers::GetWorldName(World)};
	if (CurrentMapName != NewSlotInfo->Map)
	{
		LoadState = EGSS_LoadDataTaskState::LoadingMap;
		FString MapToOpen = NewSlotInfo->Map.ToString();
		if (!GEngine->MakeSureMapNameIsValid(MapToOpen))
		{
			UE_LOG(LogGenericSaveSystem, Warning, TEXT("Slot '%s' was saved in map '%s' but it did not exist while loading. Corrupted save file?"), *NewSlotInfo->FileName.ToString(), *MapToOpen);
			Finish(false);
			return;
		}

		UGameplayStatics::OpenLevel(this, FName{MapToOpen});
		// 这个关卡如果加载完毕，会让SaveManager知道，SaveManager会让这个Task知道（OnMapLoaded），从而推进到下一个阶段。

		GSS_Log(Preset, "Slot '" + SlotName.ToString() + "' is recorded on another Map. Loading before charging slot.", FColor::White, false, 1);

		return;
	}
	else if (IsDataLoaded()) //LoadDataTask 为同步加载时，这里才会马上为真.
	{
		StartDeserialization();
	}
	else
	{
		LoadState = EGSS_LoadDataTaskState::WaitingForData;
	}
}

void UGSS_SlotDataTask_Loader::Tick(float DeltaTime)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USlotDataTask_Loader::Tick);
	switch (LoadState)
	{
	case EGSS_LoadDataTaskState::Deserializing:
		if (CurrentLevel.IsValid())
		{
			DeserializeASyncLoop();
		}
		break;

	case EGSS_LoadDataTaskState::WaitingForData:
		if (IsDataLoaded())
		{
			StartDeserialization();
		}
	}
}

void UGSS_SlotDataTask_Loader::OnFinish(bool bSuccess)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USlotDataTask_Loader::OnFinish);
	if (bSuccess)
	{
		GSS_Log(Preset, "Finished Loading", FColor::Green);
	}

	// Execute delegates
	Delegate.ExecuteIfBound((bSuccess) ? NewSlotInfo : nullptr);

	GetManager()->OnLoadFinished(!bSuccess);
}

void UGSS_SlotDataTask_Loader::BeginDestroy()
{
	if (LoadDataTask)
	{
		LoadDataTask->EnsureCompletion(false);
		delete LoadDataTask;
	}

	Super::BeginDestroy();
}

void UGSS_SlotDataTask_Loader::OnMapLoaded()
{
	if (LoadState != EGSS_LoadDataTaskState::LoadingMap)
	{
		return;
	}

	const UWorld* World = GetWorld();
	if (!World)
	{
		UE_LOG(LogGenericSaveSystem, Warning, TEXT("Failed loading map from saved slot."));
		Finish(false);
	}
	const FName NewMapName{FGSS_SlotHelpers::GetWorldName(World)};
	if (NewMapName == NewSlotInfo->Map)
	{
		if (IsDataLoaded())
		{
			StartDeserialization();
		}
		else
		{
			LoadState = EGSS_LoadDataTaskState::WaitingForData;
		}
	}
}

void UGSS_SlotDataTask_Loader::StartDeserialization()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USlotDataTask_Loader::StartDeserialization);
	check(NewSlotInfo);

	LoadState = EGSS_LoadDataTaskState::Deserializing;

	SlotData = GetLoadedData();
	if (!SlotData)
	{
		// Failed to load data
		Finish(false);
		return;
	}

	NewSlotInfo->LoadDate = FDateTime::Now();

	GetManager()->OnLoadBegan();
	//Apply current Info if succeeded
	GetManager()->__SetCurrentInfo(NewSlotInfo);

	BeforeDeserialize();

	if (Preset->IsFrameSplitLoad())
		DeserializeASync();
	else
		DeserializeSync();
}

void UGSS_SlotDataTask_Loader::StartLoadingData()
{
	LoadDataTask = new FAsyncTask<FGSS_Task_LoadFile>(GetManager(), SlotName.ToString());

	if (Preset->IsMTFilesLoad())
		LoadDataTask->StartBackgroundTask();
	else
		LoadDataTask->StartSynchronousTask();
}

UGSS_SlotData* UGSS_SlotDataTask_Loader::GetLoadedData() const
{
	if (IsDataLoaded())
	{
		return LoadDataTask->GetTask().GetData();
	}
	return nullptr;
}

void UGSS_SlotDataTask_Loader::BeforeDeserialize()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USlotDataTask_Loader::BeforeDeserialize);
	UWorld* World = GetWorld();

	// Set current game time to the saved value
	World->TimeSeconds = SlotData->TimeSeconds;

	if (SlotData->bStoreGameInstance)
	{
		DeserializeGameInstance();
	}
}

void UGSS_SlotDataTask_Loader::DeserializeSync()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USlotDataTask_Loader::DeserializeSync);

	const UWorld* World = GetWorld();
	check(World);

	GSS_Log(Preset, "World '" + World->GetName() + "'", FColor::Green, false, 1);

	PrepareAllLevels();

	// Deserialize world
	{
		DeserializeLevelSync(World->GetCurrentLevel());

		const TArray<ULevelStreaming*>& Levels = World->GetStreamingLevels();
		for (const ULevelStreaming* Level : Levels)
		{
			if (Level->IsLevelLoaded())
			{
				DeserializeLevelSync(Level->GetLoadedLevel(), Level);
			}
		}
	}

	// Deserialize Savers
	{
	}

	FinishedDeserializing();
}

void UGSS_SlotDataTask_Loader::DeserializeLevelSync(const ULevel* Level, const ULevelStreaming* StreamingLevel)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USlotDataTask_Loader::DeserializeLevelSync);

	if (!IsValid(Level))
		return;

	const FName LevelName = StreamingLevel ? StreamingLevel->GetWorldAssetPackageFName() : FGSS_PersistentLevelRecord::PersistentName;
	GSS_Log(Preset, "Level '" + LevelName.ToString() + "'", FColor::Green, false, 1);

	if (FGSS_LevelRecord* LevelRecord = FindLevelRecord(StreamingLevel))
	{
		for (auto ActorItr = Level->Actors.CreateConstIterator(); ActorItr; ++ActorItr)
		{
			TObjectPtr<AActor> Actor = *ActorItr;
			if (IsValid(Actor) && UGSS_SaveFilter::ShouldSave(Actor))
			{
				DeserializeLevel_Actor(Actor, *LevelRecord);
			}
		}
	}
}

void UGSS_SlotDataTask_Loader::DeserializeASync()
{
	// Deserialize world
	{
		GSS_Log(Preset, "World '" + GetWorld()->GetName() + "'", FColor::Green, false, 1);

		PrepareAllLevels();
		DeserializeLevelASync(GetWorld()->GetCurrentLevel());
	}
}

void UGSS_SlotDataTask_Loader::DeserializeLevelASync(ULevel* Level, ULevelStreaming* StreamingLevel)
{
	check(IsValid(Level));

	const FName LevelName = StreamingLevel ? StreamingLevel->GetWorldAssetPackageFName() : FGSS_PersistentLevelRecord::PersistentName;
	GSS_Log(Preset, "Level '" + LevelName.ToString() + "'", FColor::Green, false, 1);

	FGSS_LevelRecord* LevelRecord = FindLevelRecord(StreamingLevel);
	if (!LevelRecord)
	{
		Finish(false);
		return;
	}

	const float StartMS = GetTimeMilliseconds();

	CurrentLevel = Level;
	CurrentSLevel = StreamingLevel;
	CurrentActorIndex = 0;

	// Copy actors array. New actors won't be considered for deserialization
	CurrentLevelActors.Empty(Level->Actors.Num());
	for (TObjectPtr<AActor> Actor : Level->Actors)
	{
		if (IsValid(Actor))
		{
			CurrentLevelActors.Add(Actor);
		}
	}

	DeserializeASyncLoop(StartMS);
}

void UGSS_SlotDataTask_Loader::DeserializeASyncLoop(float StartMS)
{
	FGSS_LevelRecord* LevelRecord = FindLevelRecord(CurrentSLevel.Get());
	if (!LevelRecord)
	{
		return;
	}

	if (StartMS <= 0)
	{
		StartMS = GetTimeMilliseconds();
	}

	// Continue Iterating actors every tick
	for (; CurrentActorIndex < CurrentLevelActors.Num(); ++CurrentActorIndex)
	{
		AActor* const Actor{CurrentLevelActors[CurrentActorIndex].Get()};
		if (IsValid(Actor) && UGSS_SaveFilter::ShouldSave(Actor))
		{
			DeserializeLevel_Actor(Actor, *LevelRecord);

			const float CurrentMS = GetTimeMilliseconds();
			// If x milliseconds passed, stop and continue on next frame
			if (CurrentMS - StartMS >= MaxFrameMs)
			{
				return;
			}
		}
	}

	ULevelStreaming* CurrentLevelStreaming = CurrentSLevel.Get();
	FindNextAsyncLevel(CurrentLevelStreaming);
	if (CurrentLevelStreaming)
	{
		// Iteration has ended. Deserialize next level
		CurrentLevel = CurrentLevelStreaming->GetLoadedLevel();
		if (CurrentLevel.IsValid())
		{
			DeserializeLevelASync(CurrentLevel.Get(), CurrentLevelStreaming);
			return;
		}
	}

	// All levels deserialized
	FinishedDeserializing();
}

void UGSS_SlotDataTask_Loader::PrepareLevel(const ULevel* Level, FGSS_LevelRecord& LevelRecord)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USlotDataTask_Loader::PrepareLevel);

	// 场景里没有，但是Records里有的Actor					=> 重新生成
	// 场景里有，但是Records没有的Actor						=> 重新销毁
	// 剩下的									     => 直接还原数据。

	TArray<FGSS_ActorRecord*> ActorsToSpawn;
	ActorsToSpawn.Reserve(LevelRecord.Actors.Num());
	for (FGSS_ActorRecord& Record : LevelRecord.Actors)
	{
		ActorsToSpawn.Add(&Record);
	}

	TArray<AActor*> ActorsToDestroy{};
	{
		// O(M*Log(N))
		for (AActor* const Actor : Level->Actors)
		{
			// Remove records which actors do exist
			const bool bFoundActorRecord = Loader::RemoveSingleRecordPtrSwap(ActorsToSpawn, Actor, false) > 0;

			if (Actor && UGSS_SaveFilter::ShouldSave(Actor))
			{
				if (!bFoundActorRecord) // Don't destroy level actors
				{
					// If the actor wasn't found, mark it for destruction
					Actor->Destroy();
				}
			}
		}
		ActorsToSpawn.Shrink();
	}

	// 重新创建存档里有但是当前却不存在的Actor.
	RespawnActors(ActorsToSpawn, Level);
}

void UGSS_SlotDataTask_Loader::FinishedDeserializing()
{
	// Clean serialization data
	SlotData->CleanRecords(true);
	GetManager()->__SetCurrentData(SlotData);
	UGSS_SaveSubsystem* Manager = GetManager();
	Manager->LoadAllSavers();
	Finish(true);
}

void UGSS_SlotDataTask_Loader::PrepareAllLevels()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USlotDataTask_Loader::PrepareAllLevels);

	const UWorld* World = GetWorld();
	check(World);

	// Prepare Main level
	PrepareLevel(World->GetCurrentLevel(), SlotData->MainLevel);

	// Prepare other loaded sub-levels
	const TArray<ULevelStreaming*>& Levels = World->GetStreamingLevels();
	for (const ULevelStreaming* Level : Levels)
	{
		if (Level->IsLevelLoaded())
		{
			FGSS_LevelRecord* LevelRecord = FindLevelRecord(Level);
			if (LevelRecord)
			{
				PrepareLevel(Level->GetLoadedLevel(), *LevelRecord);
			}
		}
	}
}

void UGSS_SlotDataTask_Loader::RespawnActors(const TArray<FGSS_ActorRecord*>& Records, const ULevel* Level)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USlotDataTask_Loader::RespawnActors);

	FActorSpawnParameters SpawnInfo{};
	SpawnInfo.OverrideLevel = const_cast<ULevel*>(Level);
	SpawnInfo.NameMode = FActorSpawnParameters::ESpawnActorNameMode::Requested;

	UWorld* const World = GetWorld();

	// Respawn all procedural actors
	for (auto* Record : Records)
	{
		SpawnInfo.Name = Record->Name;
		auto* NewActor = World->SpawnActor(Record->Class, &Record->Transform, SpawnInfo);

		// We update the name on the record in case it changed
		Record->Name = NewActor->GetFName();
	}
}

void UGSS_SlotDataTask_Loader::DeserializeLevel_Actor(AActor* const Actor, const FGSS_LevelRecord& LevelRecord)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USlotDataTask_Loader::DeserializeLevel_Actor);

	// Find the record
	const FGSS_ActorRecord* const Record = LevelRecord.Actors.FindByKey(Actor);
	if (Record && Record->IsValid() && Record->Class == Actor->GetClass())
	{
		DeserializeActor(Actor, *Record);
	}
}

void UGSS_SlotDataTask_Loader::DeserializeGameInstance()
{
	bool bSuccess = true;
	auto* GameInstance = GetWorld()->GetGameInstance();
	const FGSS_ObjectRecord& Record = SlotData->GameInstance;

	if (!IsValid(GameInstance) || GameInstance->GetClass() != Record.Class)
		bSuccess = false;

	if (bSuccess)
	{
		//Serialize from Record Data
		FMemoryReader MemoryReader(Record.Data, true);
		FGSS_Archive Archive(MemoryReader, false);
		GameInstance->Serialize(Archive);
	}

	GSS_Log(Preset, "Game Instance '" + Record.Name.ToString() + "'", FColor::Green, !bSuccess, 1);
}

bool UGSS_SlotDataTask_Loader::DeserializeActor(AActor* Actor, const FGSS_ActorRecord& Record)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USlotDataTask_Loader::DeserializeActor);

	// Always load saved tags
	Actor->Tags = Record.Tags;

	const bool bSavesPhysics = UGSS_SaveFilter::StoresPhysics(Actor);
	if (UGSS_SaveFilter::StoresTransform(Actor))
	{
		Actor->SetActorTransform(Record.Transform);

		if (UGSS_SaveFilter::StoresPhysics(Actor))
		{
			USceneComponent* Root = Actor->GetRootComponent();
			if (auto* Primitive = Cast<UPrimitiveComponent>(Root))
			{
				Primitive->SetPhysicsLinearVelocity(Record.LinearVelocity);
				Primitive->SetPhysicsAngularVelocityInRadians(Record.AngularVelocity);
			}
			else
			{
				Root->ComponentVelocity = Record.LinearVelocity;
			}
		}
	}

	Actor->SetActorHiddenInGame(Record.bHiddenInGame);

	DeserializeActorComponents(Actor, Record, 2);

	{
		//Serialize from Record Data
		FMemoryReader MemoryReader(Record.Data, true);
		FGSS_Archive Archive(MemoryReader, false);
		Actor->Serialize(Archive);
	}

	return true;
}

void UGSS_SlotDataTask_Loader::DeserializeActorComponents(AActor* Actor, const FGSS_ActorRecord& ActorRecord, int8 Indent)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(UUSlotDataTask_Loader::DeserializeActorComponents);

	const TSet<UActorComponent*>& Components = Actor->GetComponents();
	for (auto* Component : Components)
	{
		if (!UGSS_SaveFilter::ShouldSave(Component))
		{
			continue;
		}

		// Find the record
		const FGSS_ComponentRecord* Record = ActorRecord.ComponentRecords.FindByKey(Component);
		if (!Record)
		{
			GSS_Log(Preset, "Component '" + Component->GetFName().ToString() + "' - Record not found", FColor::Red, false, Indent + 1);
			continue;
		}

		if (UGSS_SaveFilter::StoresTransform(Component))
		{
			USceneComponent* Scene = CastChecked<USceneComponent>(Component);
			if (Scene->Mobility == EComponentMobility::Movable)
			{
				Scene->SetRelativeTransform(Record->Transform);
			}
		}

		if (UGSS_SaveFilter::StoresTags(Component))
		{
			Component->ComponentTags = Record->Tags;
		}

		if (!Component->GetClass()->IsChildOf<UPrimitiveComponent>())
		{
			FMemoryReader MemoryReader(Record->Data, true);
			FGSS_Archive Archive(MemoryReader, false);
			Component->Serialize(Archive);
		}
	}
}

void UGSS_SlotDataTask_Loader::FindNextAsyncLevel(ULevelStreaming*& OutLevelStreaming) const
{
	OutLevelStreaming = nullptr;

	const UWorld* World = GetWorld();
	const TArray<ULevelStreaming*>& Levels = World->GetStreamingLevels();
	if (CurrentLevel.IsValid() && Levels.Num() > 0)
	{
		if (!CurrentSLevel.IsValid())
		{
			//Current is persistent, get first streaming level
			OutLevelStreaming = Levels[0];
			return;
		}
		else
		{
			int32 CurrentIndex = Levels.IndexOfByKey(CurrentSLevel);
			if (CurrentIndex != INDEX_NONE && Levels.Num() > CurrentIndex + 1)
			{
				OutLevelStreaming = Levels[CurrentIndex + 1];
			}
		}
	}

	// If this level is unloaded, find next
	if (OutLevelStreaming && !OutLevelStreaming->IsLevelLoaded())
	{
		FindNextAsyncLevel(OutLevelStreaming);
	}
}
