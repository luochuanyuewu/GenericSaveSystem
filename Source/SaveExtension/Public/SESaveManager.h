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
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Tickable.h"
#include "Saver/SESaverBase.h"
#include "SESaveManager.generated.h"


class USESaverBase;
enum class ESELoadInfoResult : uint8;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameSavedMC, USESlotInfo*, SlotInfo);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameLoadedMC, USESlotInfo*, SlotInfo);


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

	/** Currently loaded SaveInfo.
	 * SaveInfo stores basic information about a saved game. Played time, levels,progress, etc.
	 */
	UPROPERTY()
	USESlotInfo* CurrentInfo;

	/** Currently loaded SaveData. SaveData stores all serialized info about the world. */
	UPROPERTY()
	USESlotData* CurrentData;

	/** The game instance to which this save manager is owned. */
	TWeakObjectPtr<UGameInstance> OwningGameInstance;

	/** 多线程任务列表. */
	FSEScopedTaskList MTTasks;

	UPROPERTY(Transient)
	TArray<USELevelStreamingNotifier*> LevelStreamingNotifiers;

	UPROPERTY(Transient)
	TArray<TScriptInterface<ISESaveInterface>> SubscribedInterfaces;

	// 当前的槽数据任务,会在Tick中每帧处理其状态变化
	UPROPERTY(Transient)
	TArray<USESlotDataTask*> SlotDataTasks;

	UPROPERTY()
	TArray<USESaverBase*> Savers;

	/************************************************************************/
	/* METHODS											     			    */
	/************************************************************************/
public:
	USESaveManager();

	/** Get the global save manager */
	static USESaveManager* Get(const UObject* ContextObject);

	/** Begin USubsystem */
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;
	/** End USubsystem */

#pragma region Public Saver Api
	/** Begin Saver */
	void RegisterSaver(USESaverBase* Saver);
	void UnregisterSaver(USESaverBase* Saver);
	void SaveAllSavers();
	void LoadAllSavers();
	bool TryGetSaverDataV2(const FName& Key, TArray<uint8>& SerializedData);
	void AddToSaverDataV2(const FName& Key, const TArray<uint8>& SerializedData);
	void OrderSaversByPriority(bool SavePriority);
	TArray<USESaverBase*>& GetSavers();
	/** End Saver*/
#pragma endregion Public Saver Api

	void SetGameInstance(UGameInstance* GameInstance)
	{
		OwningGameInstance = GameInstance;
	}


#pragma region Public C++ Only Api

	/** C++ ONLY API */

	/** Save the Game into an specified slot name */
	bool SaveSlot(FName SlotName, bool bOverrideIfNeeded = true, bool bScreenshot = false, const FSEScreenshotSize Size = {}, FOnSEGameSaved OnSaved = {});

	/** Save the Game info an SlotInfo */
	bool SaveSlot(const USESlotInfo* SlotInfo, bool bOverrideIfNeeded = true, bool bScreenshot = false, const FSEScreenshotSize Size = {}, FOnSEGameSaved OnSaved = {});

	/** Save the Game into an specified slot id */
	bool SaveSlot(int32 SlotId, bool bOverrideIfNeeded = true, bool bScreenshot = false, const FSEScreenshotSize Size = {}, FOnSEGameSaved OnSaved = {});

	/** Save the currently loaded Slot */
	bool SaveCurrentSlot(bool bScreenshot = false, const FSEScreenshotSize Size = {}, FOnSEGameSaved OnSaved = {});

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
	UFUNCTION(Category = "SaveExtension|Saving", BlueprintCallable, meta = (AdvancedDisplay = "bScreenshot, Size",
		DisplayName = "Save Slot", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Result", UnsafeDuringActorConstruction))
	void BPSaveSlot(FName SlotName, bool bScreenshot, const FSEScreenshotSize Size, ESESaveGameResult& Result, FLatentActionInfo LatentInfo, bool bOverrideIfNeeded = true);

	/** Save the Game into an specified Slot */
	UFUNCTION(Category = "SaveExtension|Saving", BlueprintCallable, meta = (AdvancedDisplay = "bScreenshot, Size",
		DisplayName = "Save Slot by Id", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Result", UnsafeDuringActorConstruction))
	void BPSaveSlotById(int32 SlotId, bool bScreenshot, const FSEScreenshotSize Size, ESESaveGameResult& Result, FLatentActionInfo LatentInfo, bool bOverrideIfNeeded = true);

	/** Save the Game to a Slot */
	UFUNCTION(Category = "SaveExtension|Saving", BlueprintCallable, meta = (AdvancedDisplay = "bScreenshot, Size",
		DisplayName = "Save Slot by Info", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Result", UnsafeDuringActorConstruction))
	void BPSaveSlotByInfo(const USESlotInfo* SlotInfo, bool bScreenshot, const FSEScreenshotSize Size, ESESaveGameResult& Result, FLatentActionInfo LatentInfo, bool bOverrideIfNeeded = true);

	/** Save the currently loaded Slot */
	UFUNCTION(BlueprintCallable, Category = "SaveExtension|Saving",
		meta = (AdvancedDisplay = "bScreenshot, Size", DisplayName = "Save Current Slot", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Result", UnsafeDuringActorConstruction))
	void BPSaveCurrentSlot(bool bScreenshot, const FSEScreenshotSize Size, ESESaveGameResult& Result, FLatentActionInfo LatentInfo);
	/** Load game from a slot name */
	UFUNCTION(BlueprintCallable, Category = "SaveExtension|Loading", meta = (DisplayName = "Load Slot", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Result", UnsafeDuringActorConstruction))
	void BPLoadSlot(FName SlotName, ESELoadGameResult& Result, FLatentActionInfo LatentInfo);

	/** Load game from a slot Id */
	UFUNCTION(BlueprintCallable, Category = "SaveExtension|Loading",
		meta = (DisplayName = "Load Slot by Id", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Result", UnsafeDuringActorConstruction))
	void BPLoadSlotById(int32 SlotId, ESELoadGameResult& Result, FLatentActionInfo LatentInfo);

	/** Load game from a SlotInfo */
	UFUNCTION(BlueprintCallable, Category = "SaveExtension|Loading",
		meta = (DisplayName = "Load Slot by Info", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Result", UnsafeDuringActorConstruction))
	void BPLoadSlotByInfo(const USESlotInfo* SlotInfo, ESELoadGameResult& Result, FLatentActionInfo LatentInfo);

	/** Reload the currently loaded slot if any */
	UFUNCTION(BlueprintCallable, Category = "SaveExtension|Loading",
		meta = (DisplayName = "Reload Current Slot", Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Result", UnsafeDuringActorConstruction))
	void BPReloadCurrentSlot(ESELoadGameResult& Result, FLatentActionInfo LatentInfo);

	/**
	 * Find all saved games and return their SlotInfos
	 * @param bSortByRecent Should slots be ordered by save date?
	 * @param SaveInfos All saved games found on disk
	 */
	UFUNCTION(BlueprintCallable, Category = "SaveExtension", meta = (Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Result", DisplayName = "Load All Slot Infos"))
	void BPLoadAllSlotInfos(const bool bSortByRecent, TArray<USESlotInfo*>& SaveInfos, ESELoadInfoResult& Result, struct FLatentActionInfo LatentInfo);

	/** Delete a saved game on an specified slot Id
	 * Performance: Interacts with disk, can be slow
	 */
	UFUNCTION(BlueprintCallable, Category = "SaveExtension")
	bool DeleteSlotById(int32 SlotId);
	/** Delete all saved slots from disk, loaded or not */
	UFUNCTION(BlueprintCallable, Category = "SaveExtension", meta = (Latent, LatentInfo = "LatentInfo", ExpandEnumAsExecs = "Result", DisplayName = "Delete All Slots"))
	void BPDeleteAllSlots(ESEDeleteSlotsResult& Result, FLatentActionInfo LatentInfo);

	UFUNCTION(BlueprintPure, Category = "SaveExtension")
	USESavePreset* BPGetPreset() const;

	/** @return true when saving or loading anything, including levels */
	UFUNCTION(BlueprintPure, Category = SaveExtension)
	bool IsSavingOrLoading() const;

#pragma endregion  Public Blueprint Only Api

#pragma region Public Bp & C++ Api
	/** BLUEPRINTS & C++ API */
public:
	/** Delete a saved game on an specified slot
	 * Performance: Interacts with disk, can be slow
	 */
	UFUNCTION(BlueprintCallable, Category = "SaveExtension")
	bool DeleteSlot(USESlotInfo* Slot);

	/** Get the currently loaded SlotInfo. If game was never loaded returns a new SlotInfo */
	UFUNCTION(BlueprintPure, Category = "SaveExtension")
	USESlotInfo* GetCurrentInfo();

	/** Get the currently loaded SlotData. If game was never loaded returns an empty SlotData  */
	UFUNCTION(BlueprintPure, Category = "SaveExtension")
	USESlotData* GetCurrentData();

	/**
	 * Load and return an SlotInfo by Id if it exists
	 * Performance: Interacts with disk, could be slow if called frequently
	 * @param SlotId Id of the SlotInfo to be loaded
	 * @return the SlotInfo associated with an Id
	 */
	UFUNCTION(BlueprintCallable, Category = "SaveExtension|Slots")
	USESlotInfo* GetSlotInfo(int32 SlotId);

	/** Check if an slot exists on disk
	 * @return true if the slot exists
	 */
	UFUNCTION(BlueprintPure, Category = "SaveExtension|Slots")
	bool IsSlotSaved(FName SlotName) const;

	/** Check if an slot exists on disk
	 * @return true if the slot exists
	 */
	UFUNCTION(BlueprintPure, Category = "SaveExtension|Slots")
	bool IsSlotSavedById(int32 SlotId) const;

	/** Check if currently playing in a saved slot
	 * @return true if currently playing in a saved slot
	 */
	UFUNCTION(BlueprintPure, Category = "SaveExtension|Slots")
	bool IsInSlot() const;

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

	void __SetCurrentInfo(USESlotInfo* NewInfo);

	void __SetCurrentData(USESlotData* NewData);

	USESlotInfo* LoadInfo(FName SlotName);

	USESlotInfo* LoadInfo(uint32 SlotId);

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
	USESlotDataTask* CreateSlotDataTask(TSubclassOf<USESlotDataTask> TaskType);

	template <class TaskType>
	TaskType* CreateSlotDataTask()
	{
		return Cast<TaskType>(CreateSlotDataTask(TaskType::StaticClass()));
	}

	void FinishSlotDataTask(USESlotDataTask* Task);

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
	void IterateSavers(TFunction<void(UObject*)>&& Callback);

#pragma endregion Events
};


inline TStatId USESaveManager::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(USESaveManager, STATGROUP_Tickables);
}
