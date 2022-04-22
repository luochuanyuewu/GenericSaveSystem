// Copyright 2015-2020 Piperift. All Rights Reserved.

#pragma once

#include "Delegates.h"
#include "LatentActions/SEAction_DeleteSlots.h"
#include "LatentActions/SEAction_LoadGame.h"
#include "LatentActions/SEAction_SaveGame.h"
#include "SELevelStreamingNotifier.h"
#include "Multithreading/SEScopedTaskManager.h"
#include "Multithreading/Delegates.h"
#include "SESaveInterface.h"
#include "SESavePreset.h"
#include "Serialization/SESlotDataTask.h"
#include "SESlotData.h"
#include "SESlotInfo.h"

#include "Async/AsyncWork.h"
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GenericPlatform/GenericPlatformFile.h"
#include "HAL/PlatformFilemanager.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Tickable.h"

#include "SESaveManager.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameSavedMC, USESlotInfo*, SlotInfo);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameLoadedMC, USESlotInfo*, SlotInfo);


struct FLatentActionInfo;

USTRUCT(BlueprintType)
struct FScreenshotSize
{
	GENERATED_BODY()

public:
	FScreenshotSize() : Width(640), Height(360) {}
	FScreenshotSize(int32 InWidth, int32 InHeight) : Width(InWidth), Height(InHeight) {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Screenshot)
	int32 Width;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Screenshot)
	int32 Height;
};


/**
 * Controls the complete saving and loading process
 */
UCLASS(ClassGroup = SaveExtension, meta = (DisplayName = "SaveManager"))
class SAVEEXTENSION_API USESaveManager : public UGameInstanceSubsystem, public FTickableGameObject
{
	GENERATED_BODY()

	friend USESlotDataTask;


	/************************************************************************/
	/* PROPERTIES														    */
	/************************************************************************/
public:

	// Loaded from settings. Can be changed at runtime
	UPROPERTY(Transient, BlueprintReadWrite, Category=SaveManager)
	bool bTickWithGameWorld = false;

private:
	UPROPERTY(Transient)
	USESavePreset* ActivePreset;

	/** Currently loaded SaveInfo. SaveInfo stores basic information about a saved game. Played time, levels,
	 * progress, etc. */
	UPROPERTY()
	USESlotInfo* CurrentInfo;

	/** Currently loaded SaveData. SaveData stores all serialized info about the world. */
	UPROPERTY()
	USESlotData* CurrentData;

	/** The game instance to which this save manager is owned. */
	TWeakObjectPtr<UGameInstance> OwningGameInstance;

	FSEScopedTaskList MTTasks;

	UPROPERTY(Transient)
	TArray<USELevelStreamingNotifier*> LevelStreamingNotifiers;

	UPROPERTY(Transient)
	TArray<TScriptInterface<ISESaveInterface>> SubscribedInterfaces;

	UPROPERTY(Transient)
	TArray<USESlotDataTask*> Tasks;


	/************************************************************************/
	/* METHODS											     			    */
	/************************************************************************/
public:
	USESaveManager();


	/** Begin USubsystem */
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;
	/** End USubsystem */

	void SetGameInstance(UGameInstance* GameInstance)
	{
		OwningGameInstance = GameInstance;
	}

	/** C++ ONLY API */

	/** Save the Game into an specified slot name */
	bool SaveSlot(FName SlotName, bool bOverrideIfNeeded = true, bool bScreenshot = false,
		const FScreenshotSize Size = {}, FOnSEGameSaved OnSaved = {});

	/** Save the Game info an SlotInfo */
	bool SaveSlot(const USESlotInfo* SlotInfo, bool bOverrideIfNeeded = true, bool bScreenshot = false,
		const FScreenshotSize Size = {}, FOnSEGameSaved OnSaved = {});

	/** Save the Game into an specified slot id */
	bool SaveSlot(int32 SlotId, bool bOverrideIfNeeded = true, bool bScreenshot = false,
		const FScreenshotSize Size = {}, FOnSEGameSaved OnSaved = {});

	/** Save the currently loaded Slot */
	bool SaveCurrentSlot(bool bScreenshot = false, const FScreenshotSize Size = {}, FOnSEGameSaved OnSaved = {});


	/** Load game from a file name */
	bool LoadSlot(FName SlotName, FOnSEGameLoaded OnLoaded = {});

	/** Load game from a slot Id */
	bool LoadSlot(int32 SlotId, FOnSEGameLoaded OnLoaded = {});

	/** Load game from a SlotInfo */
	bool LoadSlot(const USESlotInfo* SlotInfo, FOnSEGameLoaded OnLoaded = {});

	/** Reload the currently loaded slot if any */
	bool ReloadCurrentSlot(FOnSEGameLoaded OnLoaded = {})
	{
		return LoadSlot(CurrentInfo, MoveTemp(OnLoaded));
	}

	/**
	 * Find all saved games and return their SlotInfos
	 * @param bSortByRecent Should slots be ordered by save date?
	 * @param SaveInfos All saved games found on disk
	 */
	void LoadAllSlotInfos(bool bSortByRecent, FOnSESlotInfosLoaded Delegate);
	void LoadAllSlotInfosSync(bool bSortByRecent, FOnSESlotInfosLoaded Delegate);

	/** Delete a saved game on an specified slot name
	 * Performance: Interacts with disk, can be slow
	 */
	bool DeleteSlot(FName SlotName);

	/** Delete all saved slots from disk, loaded or not */
	void DeleteAllSlots(FOnSlotsDeleted Delegate);


	/** BLUEPRINT ONLY API */
public:
	// NOTE: This functions are mostly made to accommodate better Blueprint nodes that directly communicate
	// with the normal C++ API

	/** Save the Game into an specified Slot */
	UFUNCTION(Category = "SaveExtension|Saving", BlueprintCallable, meta = (AdvancedDisplay = "bScreenshot, Size",
		DisplayName = "Save Slot", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Result", UnsafeDuringActorConstruction))
	void BPSaveSlot(FName SlotName, bool bScreenshot, const FScreenshotSize Size, ESESaveGameResult& Result, FLatentActionInfo LatentInfo, bool bOverrideIfNeeded = true);

	/** Save the Game into an specified Slot */
	UFUNCTION(Category = "SaveExtension|Saving", BlueprintCallable, meta = (AdvancedDisplay = "bScreenshot, Size",
		DisplayName = "Save Slot by Id", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Result", UnsafeDuringActorConstruction))
	void BPSaveSlotById(int32 SlotId, bool bScreenshot, const FScreenshotSize Size, ESESaveGameResult& Result, FLatentActionInfo LatentInfo, bool bOverrideIfNeeded = true);

	/** Save the Game to a Slot */
	UFUNCTION(Category = "SaveExtension|Saving", BlueprintCallable, meta = (AdvancedDisplay = "bScreenshot, Size",
		DisplayName = "Save Slot by Info", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Result", UnsafeDuringActorConstruction))
	void BPSaveSlotByInfo(const USESlotInfo* SlotInfo, bool bScreenshot, const FScreenshotSize Size, ESESaveGameResult& Result, FLatentActionInfo LatentInfo, bool bOverrideIfNeeded = true);

	/** Save the currently loaded Slot */
	UFUNCTION(BlueprintCallable, Category = "SaveExtension|Saving",
		meta = (AdvancedDisplay = "bScreenshot, Size", DisplayName = "Save Current Slot", Latent,
			LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Result", UnsafeDuringActorConstruction))
	void BPSaveCurrentSlot(bool bScreenshot, const FScreenshotSize Size, ESESaveGameResult& Result, FLatentActionInfo LatentInfo)
	{
		BPSaveSlotByInfo(CurrentInfo, bScreenshot, Size, Result, MoveTemp(LatentInfo), true);
	}

	/** Load game from a slot name */
	UFUNCTION(BlueprintCallable, Category = "SaveExtension|Loading",
		meta = (DisplayName = "Load Slot", Latent, LatentInfo = "LatentInfo",
			ExpandEnumAsExecs = "Result", UnsafeDuringActorConstruction))
	void BPLoadSlot(FName SlotName, ESELoadGameResult& Result, FLatentActionInfo LatentInfo);

	/** Load game from a slot Id */
	UFUNCTION(BlueprintCallable, Category = "SaveExtension|Loading",
		meta = (DisplayName = "Load Slot by Id", Latent, LatentInfo = "LatentInfo",
			ExpandEnumAsExecs = "Result", UnsafeDuringActorConstruction))
	void BPLoadSlotById(int32 SlotId, ESELoadGameResult& Result, FLatentActionInfo LatentInfo);

	/** Load game from a SlotInfo */
	UFUNCTION(BlueprintCallable, Category = "SaveExtension|Loading",
		meta = (DisplayName = "Load Slot by Info", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Result",
			UnsafeDuringActorConstruction))
	void BPLoadSlotByInfo(const USESlotInfo* SlotInfo, ESELoadGameResult& Result, FLatentActionInfo LatentInfo);

	/** Reload the currently loaded slot if any */
	UFUNCTION(BlueprintCallable, Category = "SaveExtension|Loading",
		meta = (DisplayName = "Reload Current Slot", Latent, LatentInfo = "LatentInfo",
			ExpandEnumAsExecs = "Result", UnsafeDuringActorConstruction))
	void BPReloadCurrentSlot(ESELoadGameResult& Result, FLatentActionInfo LatentInfo)
	{
		BPLoadSlotByInfo(CurrentInfo, Result, MoveTemp(LatentInfo));
	}

	/**
	 * Find all saved games and return their SlotInfos
	 * @param bSortByRecent Should slots be ordered by save date?
	 * @param SaveInfos All saved games found on disk
	 */
	UFUNCTION(BlueprintCallable, Category = "SaveExtension",
		meta = (Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Result",
			DisplayName = "Load All Slot Infos"))
	void BPLoadAllSlotInfos(const bool bSortByRecent, TArray<USESlotInfo*>& SaveInfos, ELoadInfoResult& Result,
		struct FLatentActionInfo LatentInfo);

	/** Delete a saved game on an specified slot Id
	 * Performance: Interacts with disk, can be slow
	 */
	UFUNCTION(BlueprintCallable, Category = "SaveExtension")
	FORCEINLINE bool DeleteSlotById(int32 SlotId)
	{
		if (!IsValidSlot(SlotId))
		{
			return false;
		}
		return DeleteSlot(GetSlotNameFromId(SlotId));
	}

	/** Delete all saved slots from disk, loaded or not */
	UFUNCTION(BlueprintCallable, Category = "SaveExtension",
		meta = (Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Result",
			DisplayName = "Delete All Slots"))
	void BPDeleteAllSlots(ESEDeleteSlotsResult& Result, FLatentActionInfo LatentInfo);

	UFUNCTION(BlueprintPure, Category = "SaveExtension")
	USESavePreset* BPGetPreset() const
	{
		return ActivePreset;
	}


	/** BLUEPRINTS & C++ API */
public:

	/** Delete a saved game on an specified slot
	 * Performance: Interacts with disk, can be slow
	 */
	UFUNCTION(BlueprintCallable, Category = "SaveExtension")
	bool DeleteSlot(USESlotInfo* Slot)
	{
		return Slot? DeleteSlot(Slot->FileName) : false;
	}

	/** Get the currently loaded SlotInfo. If game was never loaded returns a new SlotInfo */
	UFUNCTION(BlueprintPure, Category = "SaveExtension")
	FORCEINLINE USESlotInfo* GetCurrentInfo()
	{
		TryInstantiateInfo();
		return CurrentInfo;
	}

	/** Get the currently loaded SlotData. If game was never loaded returns an empty SlotData  */
	UFUNCTION(BlueprintPure, Category = "SaveExtension")
	FORCEINLINE USESlotData* GetCurrentData()
	{
		TryInstantiateInfo();
		return CurrentData;
	}

	/**
	 * Load and return an SlotInfo by Id if it exists
	 * Performance: Interacts with disk, could be slow if called frequently
	 * @param SlotId Id of the SlotInfo to be loaded
	 * @return the SlotInfo associated with an Id
	 */
	UFUNCTION(BlueprintCallable, Category = "SaveExtension|Slots")
	FORCEINLINE USESlotInfo* GetSlotInfo(int32 SlotId)
	{
		return LoadInfo(SlotId);
	}

	/** Check if an slot exists on disk
	 * @return true if the slot exists
	 */
	UFUNCTION(BlueprintPure, Category = "SaveExtension|Slots")
	bool IsSlotSaved(FName SlotName) const;

	/** Check if an slot exists on disk
	 * @return true if the slot exists
	 */
	UFUNCTION(BlueprintPure, Category = "SaveExtension|Slots")
	bool IsSlotSavedById(int32 SlotId) const
	{
		return IsValidSlot(SlotId)? IsSlotSaved(GetSlotNameFromId(SlotId)) : false;
	}

	/** Check if currently playing in a saved slot
	 * @return true if currently playing in a saved slot
	 */
	UFUNCTION(BlueprintPure, Category = "SaveExtension|Slots")
	FORCEINLINE bool IsInSlot() const
	{
		return CurrentInfo && CurrentData;
	}

	/**
	 * Set the preset to be used for saving and loading
	 * @return true if the preset was set successfully
	 */
	UFUNCTION(BlueprintCallable, Category = "SaveExtension")
	USESavePreset* SetActivePreset(TSubclassOf<USESavePreset> PresetClass);

	const USESavePreset* GetPreset() const;

	void TryInstantiateInfo(bool bForced = false);

	UFUNCTION(BlueprintPure, Category = "SaveExtension")
	FName GetSlotNameFromId(const int32 SlotId) const;

	bool IsValidSlot(const int32 Slot) const;

	void __SetCurrentInfo(USESlotInfo* NewInfo)
	{
		CurrentInfo = NewInfo;
	}

	void __SetCurrentData(USESlotData* NewData)
	{
		CurrentData = NewData;
	}

	USESlotInfo* LoadInfo(FName SlotName);
	USESlotInfo* LoadInfo(uint32 SlotId)
	{
		return IsValidSlot(SlotId)? LoadInfo(GetSlotNameFromId(SlotId)) : nullptr;
	}

protected:
	bool CanLoadOrSave();

private:
	//~ Begin LevelStreaming
	void UpdateLevelStreamings();

	UFUNCTION()
	void SerializeStreamingLevel(ULevelStreaming* LevelStreaming);
	UFUNCTION()
	void DeserializeStreamingLevel(ULevelStreaming* LevelStreaming);
	//~ End LevelStreaming

	void OnLevelLoaded(ULevelStreaming* StreamingLevel) {}

	USESlotDataTask* CreateTask(TSubclassOf<USESlotDataTask> TaskType);

	template <class TaskType>
	TaskType* CreateTask()
	{
		return Cast<TaskType>(CreateTask(TaskType::StaticClass()));
	}

	void FinishTask(USESlotDataTask* Task);

public:
	bool HasTasks() const
	{
		return Tasks.Num() > 0;
	}

	/** @return true when saving or loading anything, including levels */
	UFUNCTION(BlueprintPure, Category = SaveExtension)
	bool IsSavingOrLoading() const
	{
		return HasTasks();
	}

	bool IsLoading() const;

protected:
	//~ Begin Tickable Object Interface
	virtual void Tick(float DeltaTime) override;
	virtual bool IsTickable() const override;
	virtual UWorld* GetTickableGameObjectWorld() const override;
	virtual TStatId GetStatId() const override;
	//~ End Tickable Object Interface

	//~ Begin UObject Interface
	virtual UWorld* GetWorld() const override;
	//~ End UObject Interface


	/***********************************************************************/
	/* EVENTS                                                              */
	/***********************************************************************/
public:
	UPROPERTY(BlueprintAssignable, Category = SaveExtension)
	FOnGameSavedMC OnGameSaved;

	UPROPERTY(BlueprintAssignable, Category = SaveExtension)
	FOnGameLoadedMC OnGameLoaded;


	/** Subscribe to receive save and load events on an Interface */
	UFUNCTION(Category = SaveExtension, BlueprintCallable)
	void SubscribeForEvents(const TScriptInterface<ISESaveInterface>& Interface);

	/** Unsubscribe to no longer receive save and load events on an Interface */
	UFUNCTION(Category = SaveExtension, BlueprintCallable)
	void UnsubscribeFromEvents(const TScriptInterface<ISESaveInterface>& Interface);

	void OnSaveBegan(const FSELevelFilter& Filter);
	void OnSaveFinished(const FSELevelFilter& Filter, const bool bError);
	void OnLoadBegan(const FSELevelFilter& Filter);
	void OnLoadFinished(const FSELevelFilter& Filter, const bool bError);

private:
	void OnMapLoadStarted(const FString& MapName);
	void OnMapLoadFinished(UWorld* LoadedWorld);

	void IterateSubscribedInterfaces(TFunction<void(UObject*)>&& Callback);


	/***********************************************************************/
	/* STATIC                                                              */
	/***********************************************************************/
public:
	/** Get the global save manager */
	static USESaveManager* Get(const UObject* ContextObject);


	/***********************************************************************/
	/* DEPRECATED                                                          */
	/***********************************************************************/

	UFUNCTION(Category = "SaveExtension|Saving", BlueprintCallable, meta = (DeprecatedFunction, DeprecationMessage="Use 'Save Slot by Id' instead.", 
		AdvancedDisplay = "bScreenshot, Size", DisplayName = "Save Slot to Id", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Result", UnsafeDuringActorConstruction))
	void BPSaveSlotToId(int32 SlotId, bool bScreenshot, const FScreenshotSize Size, ESESaveGameResult& Result, FLatentActionInfo LatentInfo, bool bOverrideIfNeeded = true)
	{
		BPSaveSlotById(SlotId, bScreenshot, Size, Result, LatentInfo, bOverrideIfNeeded);
	}

	UFUNCTION(BlueprintCallable, Category = "SaveExtension|Loading", meta = (DeprecatedFunction, DeprecationMessage="Use 'Load Slot by Id' instead.",
		DisplayName = "Load Slot from Id", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Result", UnsafeDuringActorConstruction))
	void BPLoadSlotFromId(int32 SlotId, ESELoadGameResult& Result, FLatentActionInfo LatentInfo)
	{
		BPLoadSlotById(SlotId, Result, LatentInfo);
	}
};


inline bool USESaveManager::SaveSlot(int32 SlotId, bool bOverrideIfNeeded, bool bScreenshot,
	const FScreenshotSize Size, FOnSEGameSaved OnSaved)
{
	if (!IsValidSlot(SlotId))
	{
		SELog(GetPreset(), "Invalid Slot. Cant go under 0 or exceed MaxSlots.", true);
		return false;
	}
	return SaveSlot(GetSlotNameFromId(SlotId), bOverrideIfNeeded, bScreenshot, Size, OnSaved);
}

inline bool USESaveManager::SaveSlot(const USESlotInfo* SlotInfo, bool bOverrideIfNeeded, bool bScreenshot,
	const FScreenshotSize Size, FOnSEGameSaved OnSaved)
{
	if (!SlotInfo)
	{
		return false;
	}
	return SaveSlot(SlotInfo->FileName, bOverrideIfNeeded, bScreenshot, Size, OnSaved);
}

inline void USESaveManager::BPSaveSlotById(int32 SlotId, bool bScreenshot, const FScreenshotSize Size, ESESaveGameResult& Result, FLatentActionInfo LatentInfo, bool bOverrideIfNeeded)
{
	if (!IsValidSlot(SlotId))
	{
		SELog(GetPreset(), "Invalid Slot. Cant go under 0 or exceed MaxSlots.", true);
		Result = ESESaveGameResult::Failed;
		return;
	}
	BPSaveSlot(GetSlotNameFromId(SlotId), bScreenshot, Size, Result, MoveTemp(LatentInfo), bOverrideIfNeeded);
}

inline void USESaveManager::BPSaveSlotByInfo(const USESlotInfo* SlotInfo, bool bScreenshot, const FScreenshotSize Size,
	ESESaveGameResult& Result, struct FLatentActionInfo LatentInfo, bool bOverrideIfNeeded)
{
	if (!SlotInfo)
	{
		Result = ESESaveGameResult::Failed;
		return;
	}
	BPSaveSlot(SlotInfo->FileName, bScreenshot, Size, Result, MoveTemp(LatentInfo), bOverrideIfNeeded);
}

/** Save the currently loaded Slot */
inline bool USESaveManager::SaveCurrentSlot(bool bScreenshot, const FScreenshotSize Size, FOnSEGameSaved OnSaved)
{
	return SaveSlot(CurrentInfo, true, bScreenshot, Size, OnSaved);
}

inline bool USESaveManager::LoadSlot(int32 SlotId, FOnSEGameLoaded OnLoaded)
{
	if (!IsValidSlot(SlotId))
	{
		SELog(GetPreset(), "Invalid Slot. Can't go under 0 or exceed MaxSlots.", true);
		return false;
	}
	return LoadSlot(GetSlotNameFromId(SlotId), OnLoaded);
}

inline bool USESaveManager::LoadSlot(const USESlotInfo* SlotInfo, FOnSEGameLoaded OnLoaded)
{
	if (!SlotInfo)
	{
		return false;
	}
	return LoadSlot(SlotInfo->FileName, OnLoaded);
}

inline void USESaveManager::BPLoadSlotById(
	int32 SlotId, ESELoadGameResult& Result, struct FLatentActionInfo LatentInfo)
{
	BPLoadSlot(GetSlotNameFromId(SlotId), Result, MoveTemp(LatentInfo));
}

inline void USESaveManager::BPLoadSlotByInfo(const USESlotInfo* SlotInfo, ESELoadGameResult& Result, FLatentActionInfo LatentInfo)
{
	if (!SlotInfo)
	{
		Result = ESELoadGameResult::Failed;
		return;
	}
	BPLoadSlot(SlotInfo->FileName, Result, MoveTemp(LatentInfo));
}

inline bool USESaveManager::IsValidSlot(const int32 Slot) const
{
	return GetPreset()->IsValidId(Slot);
}

inline void USESaveManager::IterateSubscribedInterfaces(TFunction<void(UObject*)>&& Callback)
{
	for (const TScriptInterface<ISESaveInterface>& Interface : SubscribedInterfaces)
	{
		if (UObject* const Object = Interface.GetObject())
		{
			Callback(Object);
		}
	}
}

inline USESaveManager* USESaveManager::Get(const UObject* Context)
{
	UWorld* World = GEngine->GetWorldFromContextObject(Context, EGetWorldErrorMode::LogAndReturnNull);
	if (World)
	{
		return UGameInstance::GetSubsystem<USESaveManager>(World->GetGameInstance());
	}
	return nullptr;
}

inline bool USESaveManager::IsTickable() const
{
	return !HasAnyFlags(RF_ClassDefaultObject) && !IsValid(this);
}

inline UWorld* USESaveManager::GetTickableGameObjectWorld() const
{
	return bTickWithGameWorld? GetWorld() : nullptr;
}

inline TStatId USESaveManager::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(USaveManager, STATGROUP_Tickables);
}
