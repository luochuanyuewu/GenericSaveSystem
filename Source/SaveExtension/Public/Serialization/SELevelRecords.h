// Copyright 2015-2020 Piperift. All Rights Reserved.


#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelStreaming.h"
#include "SERecords.h"
#include "SELevelFilter.h"
#include "SELevelRecords.generated.h"


/** Represents a level in the world (streaming or persistent) */
USTRUCT()
struct FSELevelRecord : public FSEBaseRecord
{
	GENERATED_BODY()

	// bool bOverrideGeneralFilter = false;
	// Filter is used if bOverrideGeneralFilter is true
	// FSELevelFilter Filter;

	/** Record of the Level Script Actor */
	FSEActorRecord LevelScript;

	/** Records of the World Actors */
	TArray<FSEActorRecord> Actors;


	FSELevelRecord() : Super() {}

	virtual bool Serialize(FArchive& Ar) override;

	bool IsValid() const { return !Name.IsNone(); }

	void CleanRecords();
};


/** Represents a persistent level in the world */
USTRUCT()
struct FSEPersistentLevelRecord : public FSELevelRecord
{
	GENERATED_BODY()

	static const FName PersistentName;

	FSEPersistentLevelRecord() : Super()
	{
		Name = PersistentName;
	}
};


/** Represents a serialized streaming level in the world */
USTRUCT()
struct FSEStreamingLevelRecord : public FSELevelRecord
{
	GENERATED_BODY()

	FSEStreamingLevelRecord() : Super() {}
	FSEStreamingLevelRecord(const ULevelStreaming& Level) : Super()
	{
		Name = Level.GetWorldAssetPackageFName();
	}

	FORCEINLINE bool operator==(const ULevelStreaming* Level) const
	{
		return Level && Name == Level->GetWorldAssetPackageFName();
	}
};
