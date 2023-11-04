// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#pragma once

#include "GSS_Delegates.h"
#include "LatentActions/GSS_Action_DeleteSlots.h"
#include "LatentActions/GSS_Action_LoadGame.h"
#include "LatentActions/GSS_Action_SaveGame.h"
#include "GSS_LevelStreamingNotifier.h"
#include "Multithreading/GSS_ScopedTaskManager.h"
#include "Multithreading/GSS_Delegates.h"
#include "GSS_SaveInterface.h"
#include "GSS_SavePreset.h"
#include "Serialization/GSS_SlotDataTask.h"
#include "GSS_SlotInfo.h"
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Tickable.h"
#include "Saver/GSS_SaverBase.h"
#include "GSS_SaveSubsystem.generated.h"


class UGSS_SaverBase;
enum class EGSS_LoadInfoResult : uint8;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameSavedMC, UGSS_SlotInfo*, SlotInfo);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameLoadedMC, UGSS_SlotInfo*, SlotInfo);


struct FLatentActionInfo;


/**
 * 截屏大小
 */
USTRUCT(BlueprintType)
struct FSEScreenshotSize
{
	GENERATED_BODY()

public:
	FSEScreenshotSize()
		: Width(640)
		  , Height(360)
	{
	}

	FSEScreenshotSize(int32 InWidth, int32 InHeight)
		: Width(InWidth)
		  , Height(InHeight)
	{
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Screenshot)
	int32 Width;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Screenshot)
	int32 Height;
};


/**
 * Controls the complete saving and loading process
 */
UCLASS(ClassGroup = GenericSaveSystem)
class GENERICSAVESYSTEM_API UGSS_SaveSubsystem : public UGameInstanceSubsystem, public FTickableGameObject
{
	GENERATED_BODY()

	friend UGSS_SlotDataTask;


	/************************************************************************/
	/* PROPERTIES														    */
	/************************************************************************/
public:
	// Loaded from settings. Can be changed at runtime
	UPROPERTY(Transient, BlueprintReadWrite, Category=SaveManager)
	bool bTickWithGameWorld = false;

private:
	UPROPERTY(Transient)
	UGSS_SavePreset* ActivePreset;

	/** Currently loaded SaveInfo.
	 * SaveInfo stores basic information about a saved game. Played time, levels,progress, etc.
	 */
	UPROPERTY()
	UGSS_SlotInfo* CurrentInfo;

	/** Currently loaded SaveData. SaveData stores all serialized info about the world. */
	UPROPERTY()
	UGSS_SlotData* CurrentData;

	/** The game instance to which this save manager is owned. */
	TWeakObjectPtr<UGameInstance> OwningGameInstance;

	/** 多线程任务列表. */
	FGSS_ScopedTaskList MTTasks;

	UPROPERTY(Transient)
	TArray<UGSS_LevelStreamingNotifier*> LevelStreamingNotifiers;

	UPROPERTY(Transient)
	TArray<TScriptInterface<IGSS_SaveInterface>> SubscribedInterfaces;

	// 当前的槽数据任务,会在Tick中每帧处理其状态变化
	UPROPERTY(Transient)
	TArray<UGSS_SlotDataTask*> SlotDataTasks;

	UPROPERTY()
	TArray<UGSS_SaverBase*> Savers;

	/************************************************************************/
	/* METHODS											     			    */
	/************************************************************************/
public:
	UGSS_SaveSubsystem();

	/** Get the global save manager */
	static UGSS_SaveSubsystem* Get(const UObject* ContextObject);

	/** Begin USubsystem */
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;
	/** End USubsystem */

#pragma region Public Saver Api
	/** Begin Saver */
	void RegisterSaver(UGSS_SaverBase* Saver);
	void UnregisterSaver(UGSS_SaverBase* Saver);
	void SaveAllSavers();
	void LoadAllSavers();
	bool TryGetSaverDataV2(const FName& Key, TArray<uint8>& SerializedData);
	void AddToSaverDataV2(const FName& Key, const TArray<uint8>& SerializedData);
	void OrderSaversByPriority(bool SavePriority);
	TArray<UGSS_SaverBase*>& GetSavers();
	/** End Saver*/
#pragma endregion Public Saver Api

	void SetGameInstance(UGameInstance* GameInstance)
	{
		OwningGameInstance = GameInstance;
	}


#pragma region Public C++ Only Api

	/** C++ ONLY API */

	/** Save the Game into an specified slot name */
	bool SaveSlot(FName SlotName, bool bOverrideIfNeeded = true, bool bScreenshot = false, const FSEScreenshotSize Size = {}, FGSS_OnGameSavedSignature OnSaved = {});

	/** Save the Game info an SlotInfo */
	bool SaveSlot(const UGSS_SlotInfo* SlotInfo, bool bOverrideIfNeeded = true, bool bScreenshot = false, const FSEScreenshotSize Size = {}, FGSS_OnGameSavedSignature OnSaved = {});

	/** Save the Game into an specified slot id */
	bool SaveSlot(int32 SlotId, bool bOverrideIfNeeded = true, bool bScreenshot = false, const FSEScreenshotSize Size = {}, FGSS_OnGameSavedSignature OnSaved = {});

	/** Save the currently loaded Slot */
	bool SaveCurrentSlot(bool bScreenshot = false, const FSEScreenshotSize Size = {}, FGSS_OnGameSavedSignature OnSaved = {});

	/** Load game from a file name */
	bool LoadSlot(FName SlotName, FGSS_OnGameLoadedSignature OnLoaded = {});

	/** Load game from a slot Id */
	bool LoadSlot(int32 SlotId, FGSS_OnGameLoadedSignature OnLoaded = {});

	/** Load game from a SlotInfo */
	bool LoadSlot(const UGSS_SlotInfo* SlotInfo, FGSS_OnGameLoadedSignature OnLoaded = {});

	/** Reload the currently loaded slot if any */
	bool ReloadCurrentSlot(FGSS_OnGameLoadedSignature OnLoaded = {})
	{
		return LoadSlot(CurrentInfo, MoveTemp(OnLoaded));
	}

	/**
	 * Find all saved games and return their SlotInfos
	 * @param bSortByRecent Should slots be ordered by save date?
	 * @param Delegate Callback
	 */
	void LoadAllSlotInfos(bool bSortByRecent, FGSS_OnSlotInfosLoadedSignature Delegate);
	void LoadAllSlotInfosSync(bool bSortByRecent, FGSS_OnSlotInfosLoadedSignature Delegate);

	/** Delete a saved game on an specified slot name
	 * Performance: Interacts with disk, can be slow
	 */
	bool DeleteSlot(FName SlotName);

	/** Delete all saved slots from disk, loaded or not */
	void DeleteAllSlots(FGSS_OnSlotsDeletedSignature Delegate);


	void SerializeToBinary(UObject* Object, TArray<uint8>& OutData);
	FString SerializeToBinaryString(UObject* Object);
	void SerializeFromBinary(UObject* Object, const TArray<uint8>& InData);
	void SerializeFromBinaryString(UObject* Object, const FString& InData);

	bool IsLoading() const;

#pragma endregion Public C++ Only Api


#pragma region Public Blueprint Only Api
	/** BLUEPRINT ONLY API */

	// NOTE: This functions are mostly made to accommodate better Blueprint nodes that directly communicate
	// with the normal C++ API

	/** Save the Game into an specified Slot */
	UFUNCTION(Category = "GenericSaveSystem|Saving", BlueprintCallable, meta = (AdvancedDisplay = "bScreenshot, Size",
		DisplayName = "Save Slot", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Result", UnsafeDuringActorConstruction))
	void BPSaveSlot(FName SlotName, bool bScreenshot, const FSEScreenshotSize Size, EGSS_SaveGameResult& Result, FLatentActionInfo LatentInfo, bool bOverrideIfNeeded = true);

	/** Save the Game into an specified Slot */
	UFUNCTION(Category = "GenericSaveSystem|Saving", BlueprintCallable, meta = (AdvancedDisplay = "bScreenshot, Size",
		DisplayName = "Save Slot by Id", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Result", UnsafeDuringActorConstruction))
	void BPSaveSlotById(int32 SlotId, bool bScreenshot, const FSEScreenshotSize Size, EGSS_SaveGameResult& Result, FLatentActionInfo LatentInfo, bool bOverrideIfNeeded = true);

	/** Save the Game to a Slot */
	UFUNCTION(Category = "GenericSaveSystem|Saving", BlueprintCallable, meta = (AdvancedDisplay = "bScreenshot, Size",
		DisplayName = "Save Slot by Info", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Result", UnsafeDuringActorConstruction))
	void BPSaveSlotByInfo(const UGSS_SlotInfo* SlotInfo, bool bScreenshot, const FSEScreenshotSize Size, EGSS_SaveGameResult& Result, FLatentActionInfo LatentInfo, bool bOverrideIfNeeded = true);

	/** Save the currently loaded Slot */
	UFUNCTION(BlueprintCallable, Category = "GenericSaveSystem|Saving",
		meta = (AdvancedDisplay = "bScreenshot, Size", DisplayName = "Save Current Slot", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Result", UnsafeDuringActorConstruction))
	void BPSaveCurrentSlot(bool bScreenshot, const FSEScreenshotSize Size, EGSS_SaveGameResult& Result, FLatentActionInfo LatentInfo);
	/** Load game from a slot name */
	UFUNCTION(BlueprintCallable, Category = "GenericSaveSystem|Loading",
		meta = (DisplayName = "Load Slot", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Result", UnsafeDuringActorConstruction))
	void BPLoadSlot(FName SlotName, EGSS_LoadGameResult& Result, FLatentActionInfo LatentInfo);

	/** Load game from a slot Id */
	UFUNCTION(BlueprintCallable, Category = "GenericSaveSystem|Loading",
		meta = (DisplayName = "Load Slot by Id", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Result", UnsafeDuringActorConstruction))
	void BPLoadSlotById(int32 SlotId, EGSS_LoadGameResult& Result, FLatentActionInfo LatentInfo);

	/** Load game from a SlotInfo */
	UFUNCTION(BlueprintCallable, Category = "GenericSaveSystem|Loading",
		meta = (DisplayName = "Load Slot by Info", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Result", UnsafeDuringActorConstruction))
	void BPLoadSlotByInfo(const UGSS_SlotInfo* SlotInfo, EGSS_LoadGameResult& Result, FLatentActionInfo LatentInfo);

	/** Reload the currently loaded slot if any */
	UFUNCTION(BlueprintCallable, Category = "GenericSaveSystem|Loading",
		meta = (DisplayName = "Reload Current Slot", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Result", UnsafeDuringActorConstruction))
	void BPReloadCurrentSlot(EGSS_LoadGameResult& Result, FLatentActionInfo LatentInfo);

	/**
	 * Find all saved games and return their SlotInfos
	 * @param bSortByRecent Should slots be ordered by save date?
	 * @param SaveInfos All saved games found on disk
	 */
	UFUNCTION(BlueprintCallable, Category = "GenericSaveSystem", meta = (Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Result", DisplayName = "Load All Slot Infos"))
	void BPLoadAllSlotInfos(const bool bSortByRecent, TArray<UGSS_SlotInfo*>& SaveInfos, EGSS_LoadInfoResult& Result, struct FLatentActionInfo LatentInfo);

	/** Delete a saved game on an specified slot Id
	 * Performance: Interacts with disk, can be slow
	 */
	UFUNCTION(BlueprintCallable, Category = "GenericSaveSystem")
	bool DeleteSlotById(int32 SlotId);
	/** Delete all saved slots from disk, loaded or not */
	UFUNCTION(BlueprintCallable, Category = "GenericSaveSystem", meta = (Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Result", DisplayName = "Delete All Slots"))
	void BPDeleteAllSlots(EGSS_DeleteSlotsResult& Result, FLatentActionInfo LatentInfo);

	UFUNCTION(BlueprintPure, Category = "GenericSaveSystem")
	UGSS_SavePreset* BPGetPreset() const;

	/** @return true when saving or loading anything, including levels */
	UFUNCTION(BlueprintPure, Category = "GenericSaveSystem")
	bool IsSavingOrLoading() const;

#pragma endregion  Public Blueprint Only Api

#pragma region Public Bp & C++ Api
	/** BLUEPRINTS & C++ API */
public:
	/** Delete a saved game on an specified slot
	 * Performance: Interacts with disk, can be slow
	 */
	UFUNCTION(BlueprintCallable, Category = "GenericSaveSystem")
	bool DeleteSlot(UGSS_SlotInfo* Slot);

	/** Get the currently loaded SlotInfo. If game was never loaded returns a new SlotInfo */
	UFUNCTION(BlueprintPure, Category = "GenericSaveSystem")
	UGSS_SlotInfo* GetCurrentInfo();

	/** Get the currently loaded SlotData. If game was never loaded returns an empty SlotData  */
	UFUNCTION(BlueprintPure, Category = "GenericSaveSystem")
	UGSS_SlotData* GetCurrentData();

	/**
	 * Load and return an SlotInfo by Id if it exists
	 * Performance: Interacts with disk, could be slow if called frequently
	 * @param SlotId Id of the SlotInfo to be loaded
	 * @return the SlotInfo associated with an Id
	 */
	UFUNCTION(BlueprintCallable, Category = "GenericSaveSystem|Slots")
	UGSS_SlotInfo* GetSlotInfo(int32 SlotId);

	/** Check if an slot exists on disk
	 * @return true if the slot exists
	 */
	UFUNCTION(BlueprintPure, Category = "GenericSaveSystem|Slots")
	bool IsSlotSaved(FName SlotName) const;

	/** Check if an slot exists on disk
	 * @return true if the slot exists
	 */
	UFUNCTION(BlueprintPure, Category = "GenericSaveSystem|Slots")
	bool IsSlotSavedById(int32 SlotId) const;

	/** Check if currently playing in a saved slot
	 * @return true if currently playing in a saved slot
	 */
	UFUNCTION(BlueprintPure, Category = "GenericSaveSystem|Slots")
	bool IsInSlot() const;

	/**
	 * Set the preset to be used for saving and loading
	 * @return true if the preset was set successfully
	 */
	UFUNCTION(BlueprintCallable, Category = "GenericSaveSystem")
	UGSS_SavePreset* SetActivePreset(TSubclassOf<UGSS_SavePreset> PresetClass);

	const UGSS_SavePreset* GetPreset() const;

	void TryInstantiateInfo(bool bForced = false);

	UFUNCTION(BlueprintPure, Category = "GenericSaveSystem")
	FName GetSlotNameFromId(const int32 SlotId) const;

	bool IsValidSlot(const int32 Slot) const;

	void __SetCurrentInfo(UGSS_SlotInfo* NewInfo);

	void __SetCurrentData(UGSS_SlotData* NewData);

	UGSS_SlotInfo* LoadInfo(FName SlotName);

	UGSS_SlotInfo* LoadInfo(uint32 SlotId);

#pragma endregion Public Bp & C++ Api

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

	//创建一个槽数据任务,并加入任务列表.
	UGSS_SlotDataTask* CreateSlotDataTask(TSubclassOf<UGSS_SlotDataTask> TaskType);

	template <class TaskType>
	TaskType* CreateSlotDataTask()
	{
		return Cast<TaskType>(CreateSlotDataTask(TaskType::StaticClass()));
	}

	void FinishSlotDataTask(UGSS_SlotDataTask* Task);

public:
	bool HasSlotDataTasks() const
	{
		return SlotDataTasks.Num() > 0;
	}

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

#pragma region Events

public:
	UPROPERTY(BlueprintAssignable, Category = "GenericSaveSystem")
	FOnGameSavedMC OnGameSaved;

	UPROPERTY(BlueprintAssignable, Category = "GenericSaveSystem")
	FOnGameLoadedMC OnGameLoaded;


	/** Subscribe to receive save and load events on an Interface */
	UFUNCTION(Category = "GenericSaveSystem", BlueprintCallable)
	void SubscribeForEvents(const TScriptInterface<IGSS_SaveInterface>& Interface);

	/** Unsubscribe to no longer receive save and load events on an Interface */
	UFUNCTION(Category = GenericSaveSystem, BlueprintCallable)
	void UnsubscribeFromEvents(const TScriptInterface<IGSS_SaveInterface>& Interface);

	void OnSaveBegan();
	void OnSaveFinished(const bool bError);
	void OnLoadBegan();
	void OnLoadFinished(const bool bError);

private:
	void OnMapLoadStarted(const FString& MapName);
	void OnMapLoadFinished(UWorld* LoadedWorld);

	void IterateSubscribedInterfaces(TFunction<void(UObject*)>&& Callback);
	void IterateSavers(TFunction<void(UObject*)>&& Callback);

#pragma endregion Events

#pragma region CMD

protected:
	void RegisterCmds();
	void UnregisterCmds();
	void CmdLoadSlot(const TArray<FString>& Args);
	void CmdSaveSlot(const TArray<FString>& Args);

private:
#if !UE_BUILD_SHIPPING
	IConsoleCommand* SaveSlotCmd;
	IConsoleCommand* LoadSlotCmd;
#endif
#pragma endregion CMD
};


inline TStatId UGSS_SaveSubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(USESaveManager, STATGROUP_Tickables);
}
