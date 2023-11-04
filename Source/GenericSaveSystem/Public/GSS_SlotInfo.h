// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Texture2D.h"
#include "GameFramework/SaveGame.h"

#include "GSS_SlotInfo.generated.h"


/**
 * USaveInfo stores information that needs to be accessible WITHOUT loading the game.
 * Works like a common SaveGame object
 * E.g: Dates, played time, progress, level
 */
UCLASS(ClassGroup = GenericSaveSystem, hideCategories = ("Activation", "Actor Tick", "Actor", "Input", "Rendering", "Replication", "Socket", "Thumbnail"))
class GENERICSAVESYSTEM_API UGSS_SlotInfo : public USaveGame
{
	GENERATED_BODY()

public:

	UGSS_SlotInfo() : Super()
		, PlayedTime(FTimespan::Zero())
		, SlotPlayedTime(FTimespan::Zero())
		, SaveDate(FDateTime::Now())
	{}


	/** Slot where this SaveInfo and its saveData are saved */
	UPROPERTY(BlueprintReadOnly, Category = SlotInfo)
	FName FileName;

	UPROPERTY(BlueprintReadWrite, Category = SlotInfo)
	FText DisplayName;

	/** Played time since this saved game was started. Not related to slots, slots can change */
	UPROPERTY(BlueprintReadOnly, Category = SlotInfo)
	FTimespan PlayedTime;

	/** Played time since this saved game was created */
	UPROPERTY(BlueprintReadOnly, Category = SlotInfo)
	FTimespan SlotPlayedTime;

	/** Last date this slot was saved. */
	UPROPERTY(BlueprintReadOnly, Category = SlotInfo)
	FDateTime SaveDate;

	/** Date at which this slot was loaded. */
	UPROPERTY(BlueprintReadOnly, Transient, Category = SlotInfo)
	FDateTime LoadDate;

	/** Root Level where this Slot was saved */
	UPROPERTY(BlueprintReadOnly, Category = SlotInfo)
	FName Map;

private:

	UPROPERTY()
	FString ThumbnailPath;

	/** Thumbnail gets cached here the first time it is requested */
	UPROPERTY(Transient)
	UTexture2D* CachedThumbnail;


public:

	/** Returns this slot's thumbnail if any */
	UFUNCTION(BlueprintCallable, Category = SlotInfo)
	UTexture2D* GetThumbnail() const;

	/** Captures a thumbnail for the current slot */
	bool CaptureThumbnail(const int32 Width = 640, const int32 Height = 360);


	/** Internal Usage. Will be called when an screenshot is captured */
	void _SetThumbnailPath(const FString& Path);

	/** Internal Usage. Will be called to remove previous thumbnail */
	FString _GetThumbnailPath() { return ThumbnailPath; }
};
