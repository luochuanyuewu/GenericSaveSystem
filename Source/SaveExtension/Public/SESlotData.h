// Copyright 2015-2020 Piperift. All Rights Reserved.


#pragma once

#include "ISaveExtension.h"

 #include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"

#include "Serialization/SERecords.h"
#include "Serialization/SELevelRecords.h"

#include "SESlotData.generated.h"


/**
 * USaveData stores all information that can be accessible only while the game is loaded.
 * Works like a common SaveGame object
 * E.g: Items, Quests, Enemies, World Actors, AI, Physics
 */
UCLASS(ClassGroup = SaveExtension, hideCategories = ("Activation", "Actor Tick", "Actor", "Input", "Rendering", "Replication", "Socket", "Thumbnail"))
class SAVEEXTENSION_API USESlotData : public USaveGame
{
	GENERATED_BODY()

public:

	USESlotData() : Super() {}


	/** Full Name of the Map where this SlotData was saved */
	UPROPERTY(Category = SaveData, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FName Map;

	/** Game world time since game started in seconds */
	UPROPERTY(Category = SaveData, BlueprintReadOnly)
	float TimeSeconds;

	/** Records
	 * All serialized information to be saved or loaded
	 * Serialized manually for performance
	 */
	bool bStoreGameInstance = false;
	FSEObjectRecord GameInstance;

	FSELevelFilter GeneralLevelFilter;
	FSEPersistentLevelRecord MainLevel;
	TArray<FSEStreamingLevelRecord> SubLevels;


	void CleanRecords(bool bKeepSublevels);

	/** Using manual serialization. It's way faster than reflection serialization */
	virtual void Serialize(FArchive& Ar) override;
};
