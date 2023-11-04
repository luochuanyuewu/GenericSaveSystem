// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.


#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"

#include "Serialization/GSS_Records.h"
#include "Serialization/GSS_LevelRecords.h"

#include "GSS_SlotData.generated.h"


/**
 * USaveData stores all information that can be accessible only while the game is loaded.
 * Works like a common SaveGame object
 * E.g: Items, Quests, Enemies, World Actors, AI, Physics
 */
UCLASS(ClassGroup = GenericSaveSystem, hideCategories = ("Activation", "Actor Tick", "Actor", "Input", "Rendering", "Replication", "Socket", "Thumbnail"))
class GENERICSAVESYSTEM_API UGSS_SlotData : public USaveGame
{
	GENERATED_BODY()

public:
	UGSS_SlotData() : Super()
	{
	}


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
	FGSS_ObjectRecord GameInstance;

	FGSS_PersistentLevelRecord MainLevel;
	TArray<FGSS_StreamingLevelRecord> SubLevels;

	bool FindSaverRecord(const FName& Name, FGSS_ObjectRecord*& Record);

	TArray<FGSS_ObjectRecord> SaverRecords; //DOTO 跨关卡也存在.

	void CleanRecords(bool bKeepSublevels);

	/** Using manual serialization. It's way faster than reflection serialization */
	virtual void Serialize(FArchive& Ar) override;
};
