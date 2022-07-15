// Copyright 2015-2020 Piperift. All Rights Reserved.

#include "SESaveManager.h"

#include "SEFileAdapter.h"
#include "LatentActions/SEAction_LoadInfos.h"
#include "Multithreading/SETask_DeleteSlots.h"
#include "Multithreading/SETask_LoadSlotInfos.h"
#include "SESaveSettings.h"
#include "Serialization/SESlotDataTask_LevelLoader.h"
#include "Serialization/SESlotDataTask_LevelSaver.h"
#include "Serialization/SESlotDataTask_Loader.h"
#include "Serialization/SESlotDataTask_Saver.h"
#include "Engine/LevelStreaming.h"
#include "EngineUtils.h"
#include "GameDelegates.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Saver/SESaverBase.h"
#include "Serialization/SEArchive.h"

USESaveManager::USESaveManager()
	: Super()
	  , MTTasks{}
{
}

void USESaveManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	bTickWithGameWorld = GetDefault<USESaveSettings>()->bTickWithGameWorld;

	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &USESaveManager::OnMapLoadStarted);
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &USESaveManager::OnMapLoadFinished);

	ActivePreset = GetDefault<USESaveSettings>()->CreatePreset(this);

	// AutoLoad
	if (GetPreset() && GetPreset()->bAutoLoad)
	{
		ReloadCurrentSlot();
	}

	TryInstantiateInfo();
	UpdateLevelStreamings();
	RegisterCmds();
}

void USESaveManager::Deinitialize()
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

USESaveManager* USESaveManager::Get(const UObject* ContextObject)
{
	UWorld* World = GEngine->GetWorldFromContextObject(ContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (World)
	{
		return UGameInstance::GetSubsystem<USESaveManager>(World->GetGameInstance());
	}
	return nullptr;
}


bool USESaveManager::SaveSlot(FName SlotName, bool bOverrideIfNeeded, bool bScreenshot, const FSEScreenshotSize Size, FOnSEGameSaved OnSaved)
{
	if (!CanLoadOrSave())
		return false;

	const USESavePreset* Preset = GetPreset();
	if (SlotName.IsNone())
	{
		SELog(Preset, "Can't use an empty slot name to save.", true);
		return false;
	}

	// Saving
	SELog(Preset, "Saving to Slot " + SlotName.ToString());

	UWorld* World = GetWorld();
	check(World);

	// Launch task, always fail if it didn't finish or wasn't scheduled
	const auto* Task = CreateSlotDataTask<USESlotDataTask_Saver>()
	                   ->Setup(SlotName, bOverrideIfNeeded, bScreenshot, Size.Width, Size.Height)
	                   ->Bind(OnSaved)
	                   ->Start();

	return Task->IsSucceeded() || Task->IsScheduled();
}

bool USESaveManager::SaveSlot(const USESlotInfo* SlotInfo, bool bOverrideIfNeeded, bool bScreenshot, const FSEScreenshotSize Size, FOnSEGameSaved OnSaved)
{
	if (!SlotInfo)
	{
		return false;
	}
	return SaveSlot(SlotInfo->FileName, bOverrideIfNeeded, bScreenshot, Size, OnSaved);
}

bool USESaveManager::SaveSlot(int32 SlotId, bool bOverrideIfNeeded, bool bScreenshot, const FSEScreenshotSize Size, FOnSEGameSaved OnSaved)
{
	if (!IsValidSlot(SlotId))
	{
		SELog(GetPreset(), "Invalid Slot. Cant go under 0 or exceed MaxSlots.", true);
		return false;
	}
	return SaveSlot(GetSlotNameFromId(SlotId), bOverrideIfNeeded, bScreenshot, Size, OnSaved);
}

bool USESaveManager::SaveCurrentSlot(bool bScreenshot, const FSEScreenshotSize Size, FOnSEGameSaved OnSaved)
{
	return SaveSlot(CurrentInfo, true, bScreenshot, Size, OnSaved);
}

bool USESaveManager::LoadSlot(FName SlotName, FOnSEGameLoaded OnLoaded)
{
	if (!CanLoadOrSave() || !IsSlotSaved(SlotName))
	{
		return false;
	}

	TryInstantiateInfo();

	auto* Task = CreateSlotDataTask<USESlotDataTask_Loader>()
	             ->Setup(SlotName)
	             ->Bind(OnLoaded)
	             ->Start();

	return Task->IsSucceeded() || Task->IsScheduled();
}

bool USESaveManager::LoadSlot(int32 SlotId, FOnSEGameLoaded OnLoaded)
{
	if (!IsValidSlot(SlotId))
	{
		SELog(GetPreset(), "Invalid Slot. Can't go under 0 or exceed MaxSlots.", true);
		return false;
	}
	return LoadSlot(GetSlotNameFromId(SlotId), OnLoaded);
}

bool USESaveManager::LoadSlot(const USESlotInfo* SlotInfo, FOnSEGameLoaded OnLoaded)
{
	if (!SlotInfo)
	{
		return false;
	}
	return LoadSlot(SlotInfo->FileName, OnLoaded);
}

bool USESaveManager::DeleteSlot(FName SlotName)
{
	if (SlotName.IsNone())
	{
		return false;
	}

	bool bSuccess = false;
	MTTasks.CreateTask<FSETask_DeleteSlots>(this, SlotName)
	       .BindOnFinished([&bSuccess](FSETaskHolder<FSETask_DeleteSlots>& Task) mutable
	       {
		       bSuccess = Task->bSuccess;
	       })
	       .StartSynchronousTask();
	MTTasks.Tick();
	return bSuccess;
}

void USESaveManager::LoadAllSlotInfos(bool bSortByRecent, FOnSESlotInfosLoaded Delegate)
{
	MTTasks.CreateTask<FSETask_LoadSlotInfos>(this, bSortByRecent, MoveTemp(Delegate))
	       .BindOnFinished([](auto& Task)
	       {
		       Task->AfterFinish();
	       })
	       .StartBackgroundTask();
}

void USESaveManager::LoadAllSlotInfosSync(bool bSortByRecent, FOnSESlotInfosLoaded Delegate)
{
	// MTTasks.CreateTask<FSETask_LoadSlotInfos>(this, bSortByRecent, MoveTemp(Delegate))
	//        .BindOnFinished([](FSETaskHolder<FSETask_LoadSlotInfos>& Task) {
	// 	       Task->AfterFinish();
	//        })
	//        .StartSynchronousTask();
	FSETaskHolder<FSETask_LoadSlotInfos>& TaskHolder = MTTasks.CreateTask<FSETask_LoadSlotInfos>(this, bSortByRecent, MoveTemp(Delegate));
	TaskHolder.BindOnFinished([](FSETaskHolder<FSETask_LoadSlotInfos>& Task)
	{
		Task->AfterFinish();
	});
	TaskHolder.StartSynchronousTask();

	MTTasks.Tick();
}

void USESaveManager::DeleteAllSlots(FOnSlotsDeleted Delegate)
{
	MTTasks.CreateTask<FSETask_DeleteSlots>(this)
	       .BindOnFinished([Delegate](auto& Task)
	       {
		       Delegate.ExecuteIfBound();
	       })
	       .StartBackgroundTask();
}

void USESaveManager::SerializeToBinary(UObject* Object, TArray<uint8>& OutData)
{
	FMemoryWriter MemoryWriter(OutData, true);
	FSEArchive Archive(MemoryWriter, false);
	Object->Serialize(Archive);
	MemoryWriter.FlushCache();
	MemoryWriter.Close();
}

FString USESaveManager::SerializeToBinaryString(UObject* Object)
{
	TArray<uint8> Bytes;
	SerializeToBinary(Object, Bytes);
	return BytesToString(Bytes.GetData(), Bytes.Num());
}

void USESaveManager::SerializeFromBinaryString(UObject* Object, const FString& InData)
{
	TArray<uint8> Bytes;
	int32 Size = InData.Len();
	Bytes.AddUninitialized(Size);
	StringToBytes(InData, Bytes.GetData(), InData.Len());
	SerializeFromBinary(Object, Bytes);
}

void USESaveManager::SerializeFromBinary(UObject* Object, const TArray<uint8>& InData)
{
	//Serialize from Record Data
	FMemoryReader MemoryReader(InData, true);
	FSEArchive Archive(MemoryReader, false);
	Object->Serialize(Archive);
	MemoryReader.FlushCache();
	MemoryReader.Close();
}

void USESaveManager::BPSaveSlot(FName SlotName, bool bScreenshot, const FSEScreenshotSize Size,
                                ESESaveGameResult& Result, struct FLatentActionInfo LatentInfo, bool bOverrideIfNeeded /*= true*/)
{
	if (UWorld* World = GetWorld())
	{
		Result = ESESaveGameResult::Saving;

		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		if (LatentActionManager.FindExistingAction<FSEAction_SaveGame>(
			LatentInfo.CallbackTarget, LatentInfo.UUID) == nullptr)
		{
			LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
			                                 new FSEAction_SaveGame(this, SlotName, bOverrideIfNeeded, bScreenshot, Size, Result, LatentInfo));
		}
		return;
	}
	Result = ESESaveGameResult::Failed;
}

void USESaveManager::BPSaveSlotById(int32 SlotId, bool bScreenshot, const FSEScreenshotSize Size, ESESaveGameResult& Result, FLatentActionInfo LatentInfo, bool bOverrideIfNeeded)
{
	if (!IsValidSlot(SlotId))
	{
		SELog(GetPreset(), "Invalid Slot. Cant go under 0 or exceed MaxSlots.", true);
		Result = ESESaveGameResult::Failed;
		return;
	}
	BPSaveSlot(GetSlotNameFromId(SlotId), bScreenshot, Size, Result, MoveTemp(LatentInfo), bOverrideIfNeeded);
}

void USESaveManager::BPSaveSlotByInfo(const USESlotInfo* SlotInfo, bool bScreenshot, const FSEScreenshotSize Size, ESESaveGameResult& Result, FLatentActionInfo LatentInfo, bool bOverrideIfNeeded)
{
	if (!SlotInfo)
	{
		Result = ESESaveGameResult::Failed;
		return;
	}
	BPSaveSlot(SlotInfo->FileName, bScreenshot, Size, Result, MoveTemp(LatentInfo), bOverrideIfNeeded);
}

void USESaveManager::BPSaveCurrentSlot(bool bScreenshot, const FSEScreenshotSize Size, ESESaveGameResult& Result, FLatentActionInfo LatentInfo)
{
	BPSaveSlotByInfo(CurrentInfo, bScreenshot, Size, Result, MoveTemp(LatentInfo), true);
}

void USESaveManager::BPLoadSlot(
	FName SlotName, ESELoadGameResult& Result, struct FLatentActionInfo LatentInfo)
{
	if (UWorld* World = GetWorld())
	{
		Result = ESELoadGameResult::Loading;

		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		if (LatentActionManager.FindExistingAction<FSEAction_LoadGame>(
			LatentInfo.CallbackTarget, LatentInfo.UUID) == nullptr)
		{
			LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
			                                 new FSEAction_LoadGame(this, SlotName, Result, LatentInfo));
		}
		return;
	}
	Result = ESELoadGameResult::Failed;
}

void USESaveManager::BPLoadSlotById(int32 SlotId, ESELoadGameResult& Result, FLatentActionInfo LatentInfo)
{
	BPLoadSlot(GetSlotNameFromId(SlotId), Result, MoveTemp(LatentInfo));
}

void USESaveManager::BPLoadSlotByInfo(const USESlotInfo* SlotInfo, ESELoadGameResult& Result, FLatentActionInfo LatentInfo)
{
	if (!SlotInfo)
	{
		Result = ESELoadGameResult::Failed;
		return;
	}
	BPLoadSlot(SlotInfo->FileName, Result, MoveTemp(LatentInfo));
}

void USESaveManager::BPReloadCurrentSlot(ESELoadGameResult& Result, FLatentActionInfo LatentInfo)
{
	BPLoadSlotByInfo(CurrentInfo, Result, MoveTemp(LatentInfo));
}

void USESaveManager::BPLoadAllSlotInfos(const bool bSortByRecent, TArray<USESlotInfo*>& SaveInfos, ESELoadInfoResult& Result, struct FLatentActionInfo LatentInfo)
{
	if (UWorld* World = GetWorld())
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		if (LatentActionManager.FindExistingAction<FSEAction_LoadInfos>(
			LatentInfo.CallbackTarget, LatentInfo.UUID) == nullptr)
		{
			LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
			                                 new FSEAction_LoadInfos(this, bSortByRecent, SaveInfos, Result, LatentInfo));
		}
	}
}

bool USESaveManager::DeleteSlotById(int32 SlotId)
{
	if (!IsValidSlot(SlotId))
	{
		return false;
	}
	return DeleteSlot(GetSlotNameFromId(SlotId));
}

void USESaveManager::BPDeleteAllSlots(ESEDeleteSlotsResult& Result, struct FLatentActionInfo LatentInfo)
{
	if (UWorld* World = GetWorld())
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
		if (LatentActionManager.FindExistingAction<FSEAction_DeleteSlots>(
			LatentInfo.CallbackTarget, LatentInfo.UUID) == nullptr)
		{
			LatentActionManager.AddNewAction(
				LatentInfo.CallbackTarget, LatentInfo.UUID, new FSEAction_DeleteSlots(this, Result, LatentInfo));
		}
	}
}

USESavePreset* USESaveManager::BPGetPreset() const
{
	return ActivePreset;
}

bool USESaveManager::IsSavingOrLoading() const
{
	return HasSlotDataTasks();
}

bool USESaveManager::DeleteSlot(USESlotInfo* Slot)
{
	return Slot ? DeleteSlot(Slot->FileName) : false;
}

USESlotInfo* USESaveManager::GetCurrentInfo()
{
	TryInstantiateInfo();
	return CurrentInfo;
}

USESlotData* USESaveManager::GetCurrentData()
{
	TryInstantiateInfo();
	return CurrentData;
}

USESlotInfo* USESaveManager::GetSlotInfo(int32 SlotId)
{
	return LoadInfo(SlotId);
}

bool USESaveManager::IsSlotSaved(FName SlotName) const
{
	return FSEFileAdapter::DoesFileExist(SlotName.ToString());
}

bool USESaveManager::IsSlotSavedById(int32 SlotId) const
{
	return IsValidSlot(SlotId) ? IsSlotSaved(GetSlotNameFromId(SlotId)) : false;
}

bool USESaveManager::IsInSlot() const
{
	return CurrentInfo && CurrentData;
}

USESavePreset* USESaveManager::SetActivePreset(TSubclassOf<USESavePreset> PresetClass)
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

	ActivePreset = NewObject<USESavePreset>(this, PresetClass);
	return ActivePreset;
}

const USESavePreset* USESaveManager::GetPreset() const
{
	if (IsValid(ActivePreset))
	{
		return ActivePreset;
	}
	return GetDefault<USESavePreset>();
}

bool USESaveManager::CanLoadOrSave()
{
	const AGameModeBase* GameMode = UGameplayStatics::GetGameMode(this);

	if (GameMode && !GameMode->HasAuthority())
	{
		return false;
	}

	return IsValid(GetWorld());
}

void USESaveManager::TryInstantiateInfo(bool bForced)
{
	if (IsInSlot() && !bForced)
		return;

	const USESavePreset* Preset = GetPreset();

	UClass* InfoClass = Preset->SlotInfoClass.Get();
	if (!InfoClass)
		InfoClass = USESlotInfo::StaticClass();

	UClass* DataClass = Preset->SlotDataClass.Get();
	if (!DataClass)
		DataClass = USESlotData::StaticClass();

	CurrentInfo = NewObject<USESlotInfo>(GetTransientPackage(), InfoClass);
	CurrentData = NewObject<USESlotData>(GetTransientPackage(), DataClass);
}

void USESaveManager::UpdateLevelStreamings()
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
		USELevelStreamingNotifier* Notifier = NewObject<USELevelStreamingNotifier>(this);
		Notifier->SetLevelStreaming(Level);
		Notifier->OnLevelShown().BindUFunction(
			this, GET_FUNCTION_NAME_CHECKED(USESaveManager, DeserializeStreamingLevel));
		Notifier->OnLevelHidden().BindUFunction(
			this, GET_FUNCTION_NAME_CHECKED(USESaveManager, SerializeStreamingLevel));
		LevelStreamingNotifiers.Add(Notifier);
	}
}

void USESaveManager::SerializeStreamingLevel(ULevelStreaming* LevelStreaming)
{
	if (!LevelStreaming->GetLoadedLevel()->bIsBeingRemoved)
	{
		CreateSlotDataTask<USESlotDataTask_LevelSaver>()->Setup(LevelStreaming)->Start();
	}
}

void USESaveManager::DeserializeStreamingLevel(ULevelStreaming* LevelStreaming)
{
	CreateSlotDataTask<USESlotDataTask_LevelLoader>()->Setup(LevelStreaming)->Start();
}

USESlotInfo* USESaveManager::LoadInfo(FName SlotName)
{
	if (SlotName.IsNone())
	{
		SELog(GetPreset(), "Invalid Slot. Cant go under 0 or exceed MaxSlots", true);
		return nullptr;
	}

	auto& Task = MTTasks.CreateTask<FSETask_LoadSlotInfos>(this, SlotName)
	                    .BindOnFinished([](auto& Task)
	                    {
		                    Task->AfterFinish();
	                    });
	Task.StartSynchronousTask();

	check(Task.IsDone());

	const auto& Infos = Task->GetLoadedSlots();
	return Infos.Num() > 0 ? Infos[0] : nullptr;
}

USESlotInfo* USESaveManager::LoadInfo(uint32 SlotId)
{
	return IsValidSlot(SlotId) ? LoadInfo(GetSlotNameFromId(SlotId)) : nullptr;
}

USESlotDataTask* USESaveManager::CreateSlotDataTask(TSubclassOf<USESlotDataTask> TaskType)
{
	USESlotDataTask* Task = NewObject<USESlotDataTask>(this, TaskType.Get());
	Task->Prepare(CurrentData, *GetPreset());
	SlotDataTasks.Add(Task);
	return Task;
}

void USESaveManager::FinishSlotDataTask(USESlotDataTask* Task)
{
	SlotDataTasks.Remove(Task);

	// Start next task
	if (SlotDataTasks.Num() > 0)
	{
		SlotDataTasks[0]->Start();
	}
}

FName USESaveManager::GetSlotNameFromId(const int32 SlotId) const
{
	if (const auto* Preset = GetPreset())
	{
		FName Name;
		Preset->BPGetSlotNameFromId(SlotId, Name);
		return Name;
	}
	return FName{FString::FromInt(SlotId)};
}

bool USESaveManager::IsValidSlot(const int32 Slot) const
{
	return GetPreset()->IsValidId(Slot);
}

void USESaveManager::__SetCurrentInfo(USESlotInfo* NewInfo)
{
	CurrentInfo = NewInfo;
}

void USESaveManager::__SetCurrentData(USESlotData* NewData)
{
	CurrentData = NewData;
}

bool USESaveManager::IsLoading() const
{
	return HasSlotDataTasks() &&
		(SlotDataTasks[0]->IsA<USESlotDataTask_Loader>() || SlotDataTasks[0]->IsA<USESlotDataTask_LevelLoader>());
}

void USESaveManager::Tick(float DeltaTime)
{
	if (SlotDataTasks.Num())
	{
		USESlotDataTask* Task = SlotDataTasks[0];
		check(Task);
		if (Task->IsRunning())
		{
			Task->Tick(DeltaTime);
		}
	}

	MTTasks.Tick();
}

bool USESaveManager::IsTickable() const
{
	bool bMet = !HasAnyFlags(RF_ClassDefaultObject);

	return bMet && IsValid(this);
}

UWorld* USESaveManager::GetTickableGameObjectWorld() const
{
	return bTickWithGameWorld ? GetWorld() : nullptr;
}

void USESaveManager::SubscribeForEvents(const TScriptInterface<ISESaveInterface>& Interface)
{
	SubscribedInterfaces.AddUnique(Interface);
}

void USESaveManager::UnsubscribeFromEvents(const TScriptInterface<ISESaveInterface>& Interface)
{
	SubscribedInterfaces.Remove(Interface);
}

void USESaveManager::OnSaveBegan(const FSELevelFilter& Filter)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USaveManager::OnSaveBegan);

	IterateSubscribedInterfaces([&Filter](auto* Object)
	{
		check(Object->template Implements<USESaveInterface>());

		// C++ event
		if (ISESaveInterface* Interface = Cast<ISESaveInterface>(Object))
		{
			Interface->OnSaveBegan(Filter);
		}
		ISESaveInterface::Execute_ReceiveOnSaveBegan(Object, Filter);
	});
	IterateSavers([&Filter](auto* Object)
	{
		check(Object->template Implements<USESaveInterface>());

		// C++ event
		if (ISESaveInterface* Interface = Cast<ISESaveInterface>(Object))
		{
			Interface->OnSaveBegan(Filter);
		}
		ISESaveInterface::Execute_ReceiveOnSaveBegan(Object, Filter);
	});
}

void USESaveManager::OnSaveFinished(const FSELevelFilter& Filter, const bool bError)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USaveManager::OnSaveFinished);

	IterateSubscribedInterfaces([&Filter, bError](auto* Object)
	{
		check(Object->template Implements<USESaveInterface>());

		// C++ event
		if (ISESaveInterface* Interface = Cast<ISESaveInterface>(Object))
		{
			Interface->OnSaveFinished(Filter, bError);
		}
		ISESaveInterface::Execute_ReceiveOnSaveFinished(Object, Filter, bError);
	});
	IterateSavers([&Filter, bError](auto* Object)
	{
		check(Object->template Implements<USESaveInterface>());

		// C++ event
		if (ISESaveInterface* Interface = Cast<ISESaveInterface>(Object))
		{
			Interface->OnSaveFinished(Filter, bError);
		}
		ISESaveInterface::Execute_ReceiveOnSaveFinished(Object, Filter, bError);
	});

	if (!bError)
	{
		OnGameSaved.Broadcast(CurrentInfo);
	}
}

void USESaveManager::OnLoadBegan(const FSELevelFilter& Filter)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USaveManager::OnLoadBegan);

	IterateSubscribedInterfaces([&Filter](auto* Object)
	{
		check(Object->template Implements<USESaveInterface>());

		// C++ event
		if (ISESaveInterface* Interface = Cast<ISESaveInterface>(Object))
		{
			Interface->OnLoadBegan(Filter);
		}
		ISESaveInterface::Execute_ReceiveOnLoadBegan(Object, Filter);
	});

	IterateSavers([&Filter](auto* Object)
	{
		check(Object->template Implements<USESaveInterface>());

		// C++ event
		if (ISESaveInterface* Interface = Cast<ISESaveInterface>(Object))
		{
			Interface->OnLoadBegan(Filter);
		}
		ISESaveInterface::Execute_ReceiveOnLoadBegan(Object, Filter);
	});
}

void USESaveManager::OnLoadFinished(const FSELevelFilter& Filter, const bool bError)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USaveManager::OnLoadFinished);

	IterateSubscribedInterfaces([&Filter, bError](auto* Object)
	{
		check(Object->template Implements<USESaveInterface>());

		// C++ event
		if (ISESaveInterface* Interface = Cast<ISESaveInterface>(Object))
		{
			Interface->OnLoadFinished(Filter, bError);
		}
		ISESaveInterface::Execute_ReceiveOnLoadFinished(Object, Filter, bError);
	});

	if (!bError)
	{
		OnGameLoaded.Broadcast(CurrentInfo);
	}
}

void USESaveManager::OnMapLoadStarted(const FString& MapName)
{
	SELog(GetPreset(), "Loading Map '" + MapName + "'", FColor::Purple);
}

void USESaveManager::OnMapLoadFinished(UWorld* LoadedWorld)
{
	if (auto* ActiveLoader = Cast<USESlotDataTask_Loader>(SlotDataTasks.Num() ? SlotDataTasks[0] : nullptr))
	{
		ActiveLoader->OnMapLoaded();
	}

	UpdateLevelStreamings();
}

void USESaveManager::IterateSubscribedInterfaces(TFunction<void(UObject*)>&& Callback)
{
	for (const TScriptInterface<ISESaveInterface>& Interface : SubscribedInterfaces)
	{
		if (UObject* const Object = Interface.GetObject())
		{
			Callback(Object);
		}
	}
}


UWorld* USESaveManager::GetWorld() const
{
	check(GetGameInstance());

	// If we are a CDO, we must return nullptr instead to fool UObject::ImplementsGetWorld.
	if (HasAllFlags(RF_ClassDefaultObject))
		return nullptr;

	return GetGameInstance()->GetWorld();
}
