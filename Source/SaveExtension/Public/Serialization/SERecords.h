// Copyright 2015-2020 Piperift. All Rights Reserved.


#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelStreaming.h"
#include "Engine/LevelScriptActor.h"
#include "SERecords.generated.h"

class USESaverBase;
class USESlotData;


USTRUCT()
struct FSEBaseRecord
{
	GENERATED_BODY()

	FName Name;


	FSEBaseRecord()
		: Name()
	{
	}

	virtual bool Serialize(FArchive& Ar);

	friend FArchive& operator<<(FArchive& Ar, FSEBaseRecord& Record)
	{
		Record.Serialize(Ar);
		return Ar;
	}

	virtual ~FSEBaseRecord()
	{
	}
};

template <>
struct TStructOpsTypeTraits<FSEBaseRecord> : public TStructOpsTypeTraitsBase2<FSEBaseRecord>
{
	enum { WithSerializer = true };
};

FORCEINLINE bool operator==(const FSEBaseRecord& A, const FSEBaseRecord& B) { return A.Name == B.Name; }


/** Represents a serialized Object */
USTRUCT()
struct SAVEEXTENSION_API FSEObjectRecord : public FSEBaseRecord
{
	GENERATED_BODY()

	UPROPERTY()
	UClass* Class;

	TArray<uint8> Data;
	TArray<FName> Tags;


	FSEObjectRecord()
		: Super()
		  , Class(nullptr)
	{
	}

	FSEObjectRecord(const UObject* Object);

	virtual bool Serialize(FArchive& Ar) override;

	bool IsValid() const
	{
		return !Name.IsNone() && Class && Data.Num() > 0;
	}

	FORCEINLINE bool operator==(const UObject* Other) const
	{
		return Other && Name == Other->GetFName() && Class == Other->GetClass();
	}

	bool operator==(const USESaverBase* Other) const;
};


/** Represents a serialized Component */
USTRUCT()
struct SAVEEXTENSION_API FSEComponentRecord : public FSEObjectRecord
{
	GENERATED_BODY()

	FTransform Transform;


	virtual bool Serialize(FArchive& Ar) override;
};


/** Represents a serialized Actor */
USTRUCT()
struct SAVEEXTENSION_API FSEActorRecord : public FSEObjectRecord
{
	GENERATED_BODY()

	bool bHiddenInGame;
	/** Whether or not this actor was spawned in runtime */
	bool bIsProcedural;
	FTransform Transform;
	FVector LinearVelocity = FVector::ZeroVector;
	FVector AngularVelocity = FVector::ZeroVector;
	TArray<FSEComponentRecord> ComponentRecords;


	FSEActorRecord()
		: Super()
	{
	}

	FSEActorRecord(const AActor* Actor)
		: Super(Actor)
	{
	}

	virtual bool Serialize(FArchive& Ar) override;

};
