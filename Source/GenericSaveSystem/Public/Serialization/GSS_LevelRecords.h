// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.


#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelStreaming.h"
#include "GSS_Records.h"
#include "GSS_LevelRecords.generated.h"


/** Represents a level in the world (streaming or persistent) */
USTRUCT()
struct FGSS_LevelRecord : public FGSS_BaseRecord
{
	GENERATED_BODY()

	// bool bOverrideGeneralFilter = false;
	// Filter is used if bOverrideGeneralFilter is true
	// UGSS_SaveFilter Filter;

	/** Record of the Level Script Actor */
	FGSS_ActorRecord LevelScript;

	/** Records of the World Actors */
	TArray<FGSS_ActorRecord> Actors;


	FGSS_LevelRecord() : Super() {}

	virtual bool Serialize(FArchive& Ar) override;

	bool IsValid() const { return !Name.IsNone(); }

	void CleanRecords();
};


/** Represents a persistent level in the world */
USTRUCT()
struct FGSS_PersistentLevelRecord : public FGSS_LevelRecord
{
	GENERATED_BODY()

	static const FName PersistentName;

	FGSS_PersistentLevelRecord() : Super()
	{
		Name = PersistentName;
	}
};


/** Represents a serialized streaming level in the world */
USTRUCT()
struct FGSS_StreamingLevelRecord : public FGSS_LevelRecord
{
	GENERATED_BODY()

	FGSS_StreamingLevelRecord() : Super() {}
	FGSS_StreamingLevelRecord(const ULevelStreaming& Level) : Super()
	{
		Name = Level.GetWorldAssetPackageFName();
	}

	FORCEINLINE bool operator==(const ULevelStreaming* Level) const
	{
		return Level && Name == Level->GetWorldAssetPackageFName();
	}
};
