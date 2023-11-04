// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#include "GSS_SaveSubsystem.h"
#include "GSS_FileAdapter.h"
#include "LatentActions/GSS_Action_LoadInfos.h"
#include "Multithreading/GSS_Task_DeleteSlots.h"
#include "Multithreading/GSS_Task_LoadSlotInfos.h"
#include "GSS_GenericSaveSystemSettings.h"
#include "Serialization/GSS_SlotDataTask_LevelLoader.h"
#include "Serialization/GSS_SlotDataTask_LevelSaver.h"
#include "Serialization/GSS_SlotDataTask_Loader.h"
#include "Serialization/GSS_SlotDataTask_Saver.h"
#include "Engine/LevelStreaming.h"
#include "GameDelegates.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Saver/GSS_SaverBase.h"
#include "Serialization/GSS_Archive.h"

UGSS_SaveSubsystem::UGSS_SaveSubsystem()
	: Super()
	  , MTTasks{}
{
}

void UGSS_SaveSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	bTickWithGameWorld = GetDefault<UGSS_GenericSaveSystemSettings>()->bTickWithGameWorld;

	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UGSS_SaveSubsystem::OnMapLoadStarted);
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UGSS_SaveSubsystem::OnMapLoadFinished);

	ActivePreset = GetDefault<UGSS_GenericSaveSystemSettings>()->CreatePreset(this);

	// AutoLoad
	if (GetPreset() && GetPreset()->bAutoLoad)
	{
		ReloadCurrentSlot();
	}

	TryInstantiateInfo();
	UpdateLevelStreamings();
	RegisterCmds();
}

void UGSS_SaveSubsystem::Deinitialize()
{
	Super::Deinitialize();

	MTTasks.CancelAll();

	if (GetPreset()->bSaveOnExit)
		SaveCurrentSlot();

	FCoreUObjectDelegates::PreLoadMap.RemoveAll(this);
	FCoreUObjectDelegates::PostLoadMapWithWorld.RemoveAll(this);
	FGameDelegates::Get().GetEndPlayMapDelegate().RemoveAll(this);
	UnregisterCmds();
}

UGSS_SaveSubsystem* UGSS_SaveSubsystem::Get(const UObject* ContextObject)
{
	UWorld* World = GEngine->GetWorldFromContextObject(ContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (World)
	{
		return UGameInstance::GetSubsystem<UGSS_SaveSubsystem>(World->GetGameInstance());
	}
	return nullptr;
}


bool UGSS_SaveSubsystem::SaveSlot(FName SlotName, bool bOverrideIfNeeded, bool bScreenshot, const FSEScreenshotSize Size, FGSS_OnGameSavedSignature OnSaved)
{
	if (!CanLoadOrSave())
		return false;

	const UGSS_SavePreset* Preset = GetPreset();
	if (SlotName.IsNone())
	{
		GSS_Log(Preset, "Can't use an empty slot name to save.", true);
		return false;
	}

	// Saving
	GSS_Log(Preset, "Saving to Slot " + SlotName.ToString());

	UWorld* World = GetWorld();
	check(World);

	// Launch task, always fail if it didn't finish or wasn't scheduled
	const auto* Task = CreateSlotDataTask<UGSS_SlotDataTask_Saver>()
	                   ->Setup(SlotName, bOverrideIfNeeded, bScreenshot, Size.Width, Size.Height)
	                   ->Bind(OnSaved)
	                   ->Start();

	return Task->IsSucceeded() || Task->IsScheduled();
}

bool UGSS_SaveSubsystem::SaveSlot(const UGSS_SlotInfo* SlotInfo, bool bOverrideIfNeeded, bool bScreenshot, const FSEScreenshotSize Size, FGSS_OnGameSavedSignature OnSaved)
{
	if (!SlotInfo)
	{
		return false;
	}
	return SaveSlot(SlotInfo->FileName, bOverrideIfNeeded, bScreenshot, Size, OnSaved);
}

bool UGSS_SaveSubsystem::SaveSlot(int32 SlotId, bool bOverrideIfNeeded, bool bScreenshot, const FSEScreenshotSize Size, FGSS_OnGameSavedSignature OnSaved)
{
	if (!IsValidSlot(SlotId))
	{
		GSS_Log(GetPreset(), "Invalid Slot. Cant go under 0 or exceed MaxSlots.", true);
		return false;
	}
	return SaveSlot(GetSlotNameFromId(SlotId), bOverrideIfNeeded, bScreenshot, Size, OnSaved);
}

bool UGSS_SaveSubsystem::SaveCurrentSlot(bool bScreenshot, const FSEScreenshotSize Size, FGSS_OnGameSavedSignature OnSaved)
{
	return SaveSlot(CurrentInfo, true, bScreenshot, Size, OnSaved);
}

bool UGSS_SaveSubsystem::LoadSlot(FName SlotName, FGSS_OnGameLoadedSignature OnLoaded)
{
	if (!CanLoadOrSave() || !IsSlotSaved(SlotName))
	{
		return false;
	}

	TryInstantiateInfo();

	auto* Task = CreateSlotDataTask<UGSS_SlotDataTask_Loader>()
	             ->Setup(SlotName)
	             ->Bind(OnLoaded)
	             ->Start();

	return Task->IsSucceeded() || Task->IsScheduled();
}

bool UGSS_SaveSubsystem::LoadSlot(int32 SlotId, FGSS_OnGameLoadedSignature OnLoaded)
{
	if (!IsValidSlot(SlotId))
	{
		GSS_Log(GetPreset(), "Invalid Slot. Can't go under 0 or exceed MaxSlots.", true);
		return false;
	}
	return LoadSlot(GetSlotNameFromId(SlotId), OnLoaded);
}

bool UGSS_SaveSubsystem::LoadSlot(const UGSS_SlotInfo* SlotInfo, FGSS_OnGameLoadedSignature OnLoaded)
{
	if (!SlotInfo)
	{
		return false;
	}
	return LoadSlot(SlotInfo->FileName, OnLoaded);
}

bool UGSS_SaveSubsystem::DeleteSlot(FName SlotName)
{
	if (SlotName.IsNone())
	{
		return false;
	}

	bool bSuccess = false;
	MTTasks.CreateTask<FGSS_Task_DeleteSlots>(this, SlotName)
	       .BindOnFinished([&bSuccess](FGSS_TaskHolder<FGSS_Task_DeleteSlots>& Task) mutable
	       {
		       bSuccess = Task->bSuccess;
	       })
	       .StartSynchronousTask();
	MTTasks.Tick();
	return bSuccess;
}

void UGSS_SaveSubsystem::LoadAllSlotInfos(bool bSortByRecent, FGSS_OnSlotInfosLoadedSignature Delegate)
{
	MTTasks.CreateTask<FGSS_Task_LoadSlotInfos>(this, bSortByRecent, MoveTemp(Delegate))
	       .BindOnFinished([](auto& Task)
	       {
		       Task->AfterFinish();
	       })
	       .StartBackgroundTask();
}

void UGSS_SaveSubsystem::LoadAllSlotInfosSync(bool bSortByRecent, FGSS_OnSlotInfosLoadedSignature Delegate)
{
	// MTTasks.CreateTask<FGSS_Task_LoadSlotInfos>(this, bSortByRecent, MoveTemp(Delegate))
	//        .BindOnFinished([](FGSS_TaskHolder<FGSS_Task_LoadSlotInfos>& Task) {
	// 	       Task->AfterFinish();
	//        })
	//        .StartSynchronousTask();
	FGSS_TaskHolder<FGSS_Task_LoadSlotInfos>& TaskHolder = MTTasks.CreateTask<FGSS_Task_LoadSlotInfos>(this, bSortByRecent, MoveTemp(Delegate));
	TaskHolder.BindOnFinished([](FGSS_TaskHolder<FGSS_Task_LoadSlotInfos>& Task)
	{
		Task->AfterFinish();
	});
	TaskHolder.StartSynchronousTask();

	MTTasks.Tick();
}

void UGSS_SaveSubsystem::DeleteAllSlots(FGSS_OnSlotsDeletedSignature Delegate)
{
	MTTasks.CreateTask<FGSS_Task_DeleteSlots>(this)
	       .BindOnFinished([Delegate](auto& Task)
	       {
		       Delegate.ExecuteIfBound();
	       })
	       .StartBackgroundTask();
}

void UGSS_SaveSubsystem::SerializeToBinary(UObject* Object, TArray<uint8>& OutData)
{
	FMemoryWriter MemoryWriter(OutData, true);
	FGSS_Archive Archive(MemoryWriter, false);
	Object->Serialize(Archive);
	MemoryWriter.FlushCache();
	MemoryWriter.Close();
}

FString UGSS_SaveSubsystem::SerializeToBinaryString(UObject* Object)
{
	TArray<uint8> Bytes;
	SerializeToBinary(Object, Bytes);
	return BytesToString(Bytes.GetData(), Bytes.Num());
}

void UGSS_SaveSubsystem::SerializeFromBinaryString(UObject* Object, const FString& InData)
{
	TArray<uint8> Bytes;
	int32 Size = InData.Len();
	Bytes.AddUninitialized(Size);
	StringToBytes(InData, Bytes.GetData(), InData.Len());
	SerializeFromBinary(Object, Bytes);
}

void UGSS_SaveSubsystem::SerializeFromBinary(UObject* Object, const TArray<uint8>& InData)
{
	//Serialize from Record Data
	FMemoryReader MemoryReader(InData, true);
	FGSS_Archive Archive(MemoryReader, false);
	Object->Serialize(Archive);
	MemoryReader.FlushCache();
	MemoryReader.Close();
}

void UGSS_SaveSubsystem::BPSaveSlot(FName SlotName, bool bScreenshot, const FSEScreenshotSize Size,
                                EGSS_SaveGameResult& Result, struct FLatentActionInfo LatentInfo, bool bOverrideIfNeeded /*= true*/)
{
	if (UWorld* World = GetWorld())
	{
		Result = EGSS_SaveGameResult::Saving;

		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		if (LatentActionManager.FindExistingAction<FGSS_Action_SaveGame>(
			LatentInfo.CallbackTarget, LatentInfo.UUID) == nullptr)
		{
			LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
			                                 new FGSS_Action_SaveGame(this, SlotName, bOverrideIfNeeded, bScreenshot, Size, Result, LatentInfo));
		}
		return;
	}
	Result = EGSS_SaveGameResult::Failed;
}

void UGSS_SaveSubsystem::BPSaveSlotById(int32 SlotId, bool bScreenshot, const FSEScreenshotSize Size, EGSS_SaveGameResult& Result, FLatentActionInfo LatentInfo, bool bOverrideIfNeeded)
{
	if (!IsValidSlot(SlotId))
	{
		GSS_Log(GetPreset(), "Invalid Slot. Cant go under 0 or exceed MaxSlots.", true);
		Result = EGSS_SaveGameResult::Failed;
		return;
	}
	BPSaveSlot(GetSlotNameFromId(SlotId), bScreenshot, Size, Result, MoveTemp(LatentInfo), bOverrideIfNeeded);
}

void UGSS_SaveSubsystem::BPSaveSlotByInfo(const UGSS_SlotInfo* SlotInfo, bool bScreenshot, const FSEScreenshotSize Size, EGSS_SaveGameResult& Result, FLatentActionInfo LatentInfo, bool bOverrideIfNeeded)
{
	if (!SlotInfo)
	{
		Result = EGSS_SaveGameResult::Failed;
		return;
	}
	BPSaveSlot(SlotInfo->FileName, bScreenshot, Size, Result, MoveTemp(LatentInfo), bOverrideIfNeeded);
}

void UGSS_SaveSubsystem::BPSaveCurrentSlot(bool bScreenshot, const FSEScreenshotSize Size, EGSS_SaveGameResult& Result, FLatentActionInfo LatentInfo)
{
	BPSaveSlotByInfo(CurrentInfo, bScreenshot, Size, Result, MoveTemp(LatentInfo), true);
}

void UGSS_SaveSubsystem::BPLoadSlot(
	FName SlotName, EGSS_LoadGameResult& Result, struct FLatentActionInfo LatentInfo)
{
	if (UWorld* World = GetWorld())
	{
		Result = EGSS_LoadGameResult::Loading;

		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		if (LatentActionManager.FindExistingAction<FGSS_Action_LoadGame>(
			LatentInfo.CallbackTarget, LatentInfo.UUID) == nullptr)
		{
			LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
			                                 new FGSS_Action_LoadGame(this, SlotName, Result, LatentInfo));
		}
		return;
	}
	Result = EGSS_LoadGameResult::Failed;
}

void UGSS_SaveSubsystem::BPLoadSlotById(int32 SlotId, EGSS_LoadGameResult& Result, FLatentActionInfo LatentInfo)
{
	BPLoadSlot(GetSlotNameFromId(SlotId), Result, MoveTemp(LatentInfo));
}

void UGSS_SaveSubsystem::BPLoadSlotByInfo(const UGSS_SlotInfo* SlotInfo, EGSS_LoadGameResult& Result, FLatentActionInfo LatentInfo)
{
	if (!SlotInfo)
	{
		Result = EGSS_LoadGameResult::Failed;
		return;
	}
	BPLoadSlot(SlotInfo->FileName, Result, MoveTemp(LatentInfo));
}

void UGSS_SaveSubsystem::BPReloadCurrentSlot(EGSS_LoadGameResult& Result, FLatentActionInfo LatentInfo)
{
	BPLoadSlotByInfo(CurrentInfo, Result, MoveTemp(LatentInfo));
}

void UGSS_SaveSubsystem::BPLoadAllSlotInfos(const bool bSortByRecent, TArray<UGSS_SlotInfo*>& SaveInfos, EGSS_LoadInfoResult& Result, struct FLatentActionInfo LatentInfo)
{
	if (UWorld* World = GetWorld())
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		if (LatentActionManager.FindExistingAction<FGSS_Action_LoadInfos>(
			LatentInfo.CallbackTarget, LatentInfo.UUID) == nullptr)
		{
			LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
			                                 new FGSS_Action_LoadInfos(this, bSortByRecent, SaveInfos, Result, LatentInfo));
		}
	}
}

bool UGSS_SaveSubsystem::DeleteSlotById(int32 SlotId)
{
	if (!IsValidSlot(SlotId))
	{
		return false;
	}
	return DeleteSlot(GetSlotNameFromId(SlotId));
}

void UGSS_SaveSubsystem::BPDeleteAllSlots(EGSS_DeleteSlotsResult& Result, struct FLatentActionInfo LatentInfo)
{
	if (UWorld* World = GetWorld())
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		if (LatentActionManager.FindExistingAction<FGSS_Action_DeleteSlots>(
			LatentInfo.CallbackTarget, LatentInfo.UUID) == nullptr)
		{
			LatentActionManager.AddNewAction(
				LatentInfo.CallbackTarget, LatentInfo.UUID, new FGSS_Action_DeleteSlots(this, Result, LatentInfo));
		}
	}
}

UGSS_SavePreset* UGSS_SaveSubsystem::BPGetPreset() const
{
	return ActivePreset;
}

bool UGSS_SaveSubsystem::IsSavingOrLoading() const
{
	return HasSlotDataTasks();
}

bool UGSS_SaveSubsystem::DeleteSlot(UGSS_SlotInfo* Slot)
{
	return Slot ? DeleteSlot(Slot->FileName) : false;
}

UGSS_SlotInfo* UGSS_SaveSubsystem::GetCurrentInfo()
{
	TryInstantiateInfo();
	return CurrentInfo;
}

UGSS_SlotData* UGSS_SaveSubsystem::GetCurrentData()
{
	TryInstantiateInfo();
	return CurrentData;
}

UGSS_SlotInfo* UGSS_SaveSubsystem::GetSlotInfo(int32 SlotId)
{
	return LoadInfo(SlotId);
}

bool UGSS_SaveSubsystem::IsSlotSaved(FName SlotName) const
{
	return FGSS_FileAdapter::DoesFileExist(SlotName.ToString());
}

bool UGSS_SaveSubsystem::IsSlotSavedById(int32 SlotId) const
{
	return IsValidSlot(SlotId) ? IsSlotSaved(GetSlotNameFromId(SlotId)) : false;
}

bool UGSS_SaveSubsystem::IsInSlot() const
{
	return CurrentInfo && CurrentData;
}

UGSS_SavePreset* UGSS_SaveSubsystem::SetActivePreset(TSubclassOf<UGSS_SavePreset> PresetClass)
{
	// We can only change a preset if we have no tasks running
	if (HasSlotDataTasks() || !PresetClass.Get())
	{
		return nullptr;
	}

	// If We have a preset and its already of the same class, dont do anything
	if (ActivePreset && ActivePreset->GetClass() == PresetClass)
	{
		return nullptr;
	}

	ActivePreset = NewObject<UGSS_SavePreset>(this, PresetClass);
	return ActivePreset;
}

const UGSS_SavePreset* UGSS_SaveSubsystem::GetPreset() const
{
	if (IsValid(ActivePreset))
	{
		return ActivePreset;
	}
	return GetDefault<UGSS_SavePreset>();
}

bool UGSS_SaveSubsystem::CanLoadOrSave()
{
	const AGameModeBase* GameMode = UGameplayStatics::GetGameMode(this);

	if (GameMode && !GameMode->HasAuthority())
	{
		return false;
	}

	return IsValid(GetWorld());
}

void UGSS_SaveSubsystem::TryInstantiateInfo(bool bForced)
{
	if (IsInSlot() && !bForced)
		return;

	const UGSS_SavePreset* Preset = GetPreset();

	UClass* InfoClass = Preset->SlotInfoClass.Get();
	if (!InfoClass)
		InfoClass = UGSS_SlotInfo::StaticClass();

	UClass* DataClass = Preset->SlotDataClass.Get();
	if (!DataClass)
		DataClass = UGSS_SlotData::StaticClass();

	CurrentInfo = NewObject<UGSS_SlotInfo>(GetTransientPackage(), InfoClass);
	CurrentData = NewObject<UGSS_SlotData>(GetTransientPackage(), DataClass);
}

void UGSS_SaveSubsystem::UpdateLevelStreamings()
{
	UWorld* World = GetWorld();
	if (!World || World->IsPartitionedWorld())
	{
		return;
	}

	const TArray<ULevelStreaming*>& Levels = World->GetStreamingLevels();

	LevelStreamingNotifiers.Empty(Levels.Num()); // Avoid memory deallocation
	LevelStreamingNotifiers.Reserve(Levels.Num()); // Reserve extra memory
	for (auto* Level : Levels)
	{
		UGSS_LevelStreamingNotifier* Notifier = NewObject<UGSS_LevelStreamingNotifier>(this);
		Notifier->SetLevelStreaming(Level);
		Notifier->OnLevelShown().BindUFunction(
			this, GET_FUNCTION_NAME_CHECKED(UGSS_SaveSubsystem, DeserializeStreamingLevel));
		Notifier->OnLevelHidden().BindUFunction(
			this, GET_FUNCTION_NAME_CHECKED(UGSS_SaveSubsystem, SerializeStreamingLevel));
		LevelStreamingNotifiers.Add(Notifier);
	}
}

void UGSS_SaveSubsystem::SerializeStreamingLevel(ULevelStreaming* LevelStreaming)
{
	if (!LevelStreaming->GetLoadedLevel()->bIsBeingRemoved)
	{
		CreateSlotDataTask<UGSS_SlotDataTask_LevelSaver>()->Setup(LevelStreaming)->Start();
	}
}

void UGSS_SaveSubsystem::DeserializeStreamingLevel(ULevelStreaming* LevelStreaming)
{
	CreateSlotDataTask<UGSS_SlotDataTask_LevelLoader>()->Setup(LevelStreaming)->Start();
}

UGSS_SlotInfo* UGSS_SaveSubsystem::LoadInfo(FName SlotName)
{
	if (SlotName.IsNone())
	{
		GSS_Log(GetPreset(), "Invalid Slot. Cant go under 0 or exceed MaxSlots", true);
		return nullptr;
	}

	auto& Task = MTTasks.CreateTask<FGSS_Task_LoadSlotInfos>(this, SlotName)
	                    .BindOnFinished([](auto& Task)
	                    {
		                    Task->AfterFinish();
	                    });
	Task.StartSynchronousTask();

	check(Task.IsDone());

	const auto& Infos = Task->GetLoadedSlots();
	return Infos.Num() > 0 ? Infos[0] : nullptr;
}

UGSS_SlotInfo* UGSS_SaveSubsystem::LoadInfo(uint32 SlotId)
{
	return IsValidSlot(SlotId) ? LoadInfo(GetSlotNameFromId(SlotId)) : nullptr;
}

UGSS_SlotDataTask* UGSS_SaveSubsystem::CreateSlotDataTask(TSubclassOf<UGSS_SlotDataTask> TaskType)
{
	UGSS_SlotDataTask* Task = NewObject<UGSS_SlotDataTask>(this, TaskType.Get());
	Task->Prepare(CurrentData, *GetPreset());
	SlotDataTasks.Add(Task);
	return Task;
}

void UGSS_SaveSubsystem::FinishSlotDataTask(UGSS_SlotDataTask* Task)
{
	SlotDataTasks.Remove(Task);

	// Start next task
	if (SlotDataTasks.Num() > 0)
	{
		SlotDataTasks[0]->Start();
	}
}

FName UGSS_SaveSubsystem::GetSlotNameFromId(const int32 SlotId) const
{
	if (const auto* Preset = GetPreset())
	{
		FName Name;
		Preset->BPGetSlotNameFromId(SlotId, Name);
		return Name;
	}
	return FName{FString::FromInt(SlotId)};
}

bool UGSS_SaveSubsystem::IsValidSlot(const int32 Slot) const
{
	return GetPreset()->IsValidId(Slot);
}

void UGSS_SaveSubsystem::__SetCurrentInfo(UGSS_SlotInfo* NewInfo)
{
	CurrentInfo = NewInfo;
}

void UGSS_SaveSubsystem::__SetCurrentData(UGSS_SlotData* NewData)
{
	CurrentData = NewData;
}

bool UGSS_SaveSubsystem::IsLoading() const
{
	return HasSlotDataTasks() &&
		(SlotDataTasks[0]->IsA<UGSS_SlotDataTask_Loader>() || SlotDataTasks[0]->IsA<UGSS_SlotDataTask_LevelLoader>());
}

void UGSS_SaveSubsystem::Tick(float DeltaTime)
{
	if (SlotDataTasks.Num())
	{
		UGSS_SlotDataTask* Task = SlotDataTasks[0];
		check(Task);
		if (Task->IsRunning())
		{
			Task->Tick(DeltaTime);
		}
	}

	MTTasks.Tick();
}

bool UGSS_SaveSubsystem::IsTickable() const
{
	return !HasAnyFlags(RF_ClassDefaultObject) && IsValid(this);
}

UWorld* UGSS_SaveSubsystem::GetTickableGameObjectWorld() const
{
	return bTickWithGameWorld ? GetWorld() : nullptr;
}

void UGSS_SaveSubsystem::SubscribeForEvents(const TScriptInterface<IGSS_SaveInterface>& Interface)
{
	SubscribedInterfaces.AddUnique(Interface);
}

void UGSS_SaveSubsystem::UnsubscribeFromEvents(const TScriptInterface<IGSS_SaveInterface>& Interface)
{
	SubscribedInterfaces.Remove(Interface);
}

void UGSS_SaveSubsystem::OnSaveBegan()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USaveManager::OnSaveBegan);

	IterateSubscribedInterfaces([](auto* Object)
	{
		check(Object->template Implements<UGSS_SaveInterface>());

		// C++ event
		if (IGSS_SaveInterface* Interface = Cast<IGSS_SaveInterface>(Object))
		{
			Interface->OnSaveBegan();
		}
		IGSS_SaveInterface::Execute_ReceiveOnSaveBegan(Object);
	});
}

void UGSS_SaveSubsystem::OnSaveFinished(const bool bError)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USaveManager::OnSaveFinished);

	IterateSubscribedInterfaces([ bError](auto* Object)
	{
		check(Object->template Implements<UGSS_SaveInterface>());

		// C++ event
		if (IGSS_SaveInterface* Interface = Cast<IGSS_SaveInterface>(Object))
		{
			Interface->OnSaveFinished(bError);
		}
		IGSS_SaveInterface::Execute_ReceiveOnSaveFinished(Object, bError);
	});

	if (!bError)
	{
		OnGameSaved.Broadcast(CurrentInfo);
	}
}

void UGSS_SaveSubsystem::OnLoadBegan()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USaveManager::OnLoadBegan);

	IterateSubscribedInterfaces([](auto* Object)
	{
		check(Object->template Implements<UGSS_SaveInterface>());

		// C++ event
		if (IGSS_SaveInterface* Interface = Cast<IGSS_SaveInterface>(Object))
		{
			Interface->OnLoadBegan();
		}
		IGSS_SaveInterface::Execute_ReceiveOnLoadBegan(Object);
	});
}

void UGSS_SaveSubsystem::OnLoadFinished(const bool bError)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USaveManager::OnLoadFinished);

	IterateSubscribedInterfaces([bError](auto* Object)
	{
		check(Object->template Implements<UGSS_SaveInterface>());

		// C++ event
		if (IGSS_SaveInterface* Interface = Cast<IGSS_SaveInterface>(Object))
		{
			Interface->OnLoadFinished(bError);
		}
		IGSS_SaveInterface::Execute_ReceiveOnLoadFinished(Object, bError);
	});

	if (!bError)
	{
		OnGameLoaded.Broadcast(CurrentInfo);
	}
}

void UGSS_SaveSubsystem::OnMapLoadStarted(const FString& MapName)
{
	GSS_Log(GetPreset(), "Loading Map '" + MapName + "'", FColor::Purple);
}

void UGSS_SaveSubsystem::OnMapLoadFinished(UWorld* LoadedWorld)
{
	if (auto* ActiveLoader = Cast<UGSS_SlotDataTask_Loader>(SlotDataTasks.Num() ? SlotDataTasks[0] : nullptr))
	{
		ActiveLoader->OnMapLoaded();
	}

	UpdateLevelStreamings();
}

void UGSS_SaveSubsystem::IterateSubscribedInterfaces(TFunction<void(UObject*)>&& Callback)
{
	for (const TScriptInterface<IGSS_SaveInterface>& Interface : SubscribedInterfaces)
	{
		if (UObject* const Object = Interface.GetObject())
		{
			Callback(Object);
		}
	}
}


UWorld* UGSS_SaveSubsystem::GetWorld() const
{
	check(GetGameInstance());

	// If we are a CDO, we must return nullptr instead to fool UObject::ImplementsGetWorld.
	if (HasAllFlags(RF_ClassDefaultObject))
		return nullptr;

	return GetGameInstance()->GetWorld();
}
