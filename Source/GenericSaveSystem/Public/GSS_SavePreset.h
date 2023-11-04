// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GSS_SavePreset.generated.h"


class UGSS_SlotData;
/**
* Specifies the behavior while saving or loading
*/
UENUM()
enum class ESaveASyncMode : uint8
{
	OnlySync,
	LoadAsync,
	SaveAsync,
	SaveAndLoadAsync
};

class UGSS_SlotInfo;



/**
 * What to save, how to save it, when, every x minutes, what info file, what data file, save by level streaming?
 */
UCLASS(ClassGroup = GenericSaveSystem, Blueprintable)
class GENERICSAVESYSTEM_API UGSS_SavePreset : public UObject
{
	GENERATED_BODY()

public:
	/**
	* Specify the SaveInfo object to be used with this preset
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	TSubclassOf<UGSS_SlotInfo> SlotInfoClass;

	/**
	* Specify the SaveData object to be used with this preset
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	TSubclassOf<UGSS_SlotData> SlotDataClass;

	/** Maximum amount of saved slots at the same time */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (ClampMin = "0"))
	int32 MaxSlots = 0;

	/** If checked, will attempt to Save Game to first Slot found, timed event. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	bool bAutoSave = true;

	/** Interval in seconds for auto saving */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (EditCondition = "bAutoSave", UIMin = "15", UIMax = "3600"))
	int32 AutoSaveInterval = 120.f;

	/** If checked, will attempt to Save Game to first Slot found, timed event. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, meta = (EditCondition = "bAutoSave"))
	bool bSaveOnExit = false;

	/** If checked, will attempt to Load Game from last Slot found, when game starts
	 * 会在存档子系统Initialize时调用.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	bool bAutoLoad = true;

	/**
	 * If checked, will print messages to Log, and Viewport if DebugInScreen is enabled.
	 * Ignored in package or Shipping mode.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, AdvancedDisplay)
	bool bDebug = false;

	/**
	 * If checked and Debug is enabled, will print messages to Viewport.
	 * Ignored in package or Shipping mode.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay, AdvancedDisplay, meta = (EditCondition = "bDebug"))
	bool bDebugInScreen = true;


	/** If true save files will be compressed
	 * Performance: Can add from 10ms to 20ms to loading and saving (estimate) but reduce file sizes making them up to 30x smaller
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Serialization)
	bool bUseCompression = true;

	/** If true will store the game instance */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Serialization)
	bool bStoreGameInstance = true;

public:
	/** Serialization will be multi-threaded between all available cores. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Asynchronous")
	ESaveASyncMode MultithreadedSerialization = ESaveASyncMode::SaveAsync;

	/** Split serialization between multiple frames. Ignored if MultithreadedSerialization is used
	 * Currently only implemented on Loading
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Asynchronous")
	ESaveASyncMode FrameSplittedSerialization = ESaveASyncMode::OnlySync;


	/** Max milliseconds to use every frame in an asynchronous operation.
	 * If running at 60Fps (16.6ms), loading or saving asynchronously will add MaxFrameMS:
	 * 16.6ms + 5MS = 21.6ms -> 46Fps
	 * This means gameplay will not be stopped nor have frame drops while saving or loading. Works best for non multi-threaded platforms
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Asynchronous", meta = (UIMin="3", UIMax="10"))
	float MaxFrameMs = 5.f;

	/** Files will be loaded or saved on a secondary thread while game continues */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Asynchronous")
	ESaveASyncMode MultithreadedFiles = ESaveASyncMode::SaveAndLoadAsync;


protected:
	/** If true, will Save and Load levels when they are shown or hidden.
	 * This includes level streaming and world composition.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Level Streaming")
	bool bSaveAndLoadSublevels = true;


public:
	UGSS_SavePreset();

	UFUNCTION(BlueprintNativeEvent, Category = "Slots", meta = (DisplayName="Get Slot Name from Id"))
	void BPGetSlotNameFromId(int32 Id, FName& Name) const;

protected:
	virtual void GetSlotNameFromId(int32 Id, FName& Name) const;


	/** HELPERS */
public:
	int32 GetMaxIds() const;

	bool IsValidId(int32 Id) const;

	bool IsMTSerializationLoad() const
	{
		return MultithreadedSerialization == ESaveASyncMode::LoadAsync || MultithreadedSerialization == ESaveASyncMode::SaveAndLoadAsync;
	}

	bool IsMTSerializationSave() const
	{
		return MultithreadedSerialization == ESaveASyncMode::SaveAsync || MultithreadedSerialization == ESaveASyncMode::SaveAndLoadAsync;
	}

	ESaveASyncMode GetFrameSplitSerialization() const { return FrameSplittedSerialization; }
	float GetMaxFrameMs() const { return MaxFrameMs; }

	bool IsFrameSplitLoad() const
	{
		return !IsMTSerializationLoad() && (FrameSplittedSerialization == ESaveASyncMode::LoadAsync || FrameSplittedSerialization == ESaveASyncMode::SaveAndLoadAsync);
	}

	bool IsFrameSplitSave() const
	{
		return !IsMTSerializationSave() && (FrameSplittedSerialization == ESaveASyncMode::SaveAsync || FrameSplittedSerialization == ESaveASyncMode::SaveAndLoadAsync);
	}

	bool IsMTFilesLoad() const
	{
		return MultithreadedFiles == ESaveASyncMode::LoadAsync || MultithreadedFiles == ESaveASyncMode::SaveAndLoadAsync;
	}

	bool IsMTFilesSave() const
	{
		return MultithreadedFiles == ESaveASyncMode::SaveAsync || MultithreadedFiles == ESaveASyncMode::SaveAndLoadAsync;
	}
};


inline int32 UGSS_SavePreset::GetMaxIds() const
{
	return MaxSlots <= 0 ? 16384 : MaxSlots;
}

inline bool UGSS_SavePreset::IsValidId(int32 Id) const
{
	const int32 MaxIds = GetMaxIds();
	return Id >= 0 && (MaxIds <= 0 || Id < MaxIds);
}
