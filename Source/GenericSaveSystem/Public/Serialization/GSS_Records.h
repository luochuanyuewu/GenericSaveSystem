// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.


#pragma once

#include "CoreMinimal.h"
#include "GSS_Records.generated.h"

class UGSS_SaverBase;
class UGSS_SlotData;


USTRUCT()
struct GENERICSAVESYSTEM_API FGSS_BaseRecord
{
	GENERATED_BODY()

	FName Name;


	FGSS_BaseRecord()
		: Name()
	{
	}

	virtual bool Serialize(FArchive& Ar);

	friend FArchive& operator<<(FArchive& Ar, FGSS_BaseRecord& Record)
	{
		Record.Serialize(Ar);
		return Ar;
	}

	virtual ~FGSS_BaseRecord()
	{
	}
};

template <>
struct TStructOpsTypeTraits<FGSS_BaseRecord> : public TStructOpsTypeTraitsBase2<FGSS_BaseRecord>
{
	enum { WithSerializer = true };
};

FORCEINLINE bool operator==(const FGSS_BaseRecord& A, const FGSS_BaseRecord& B) { return A.Name == B.Name; }


/** Represents a serialized Object */
USTRUCT()
struct GENERICSAVESYSTEM_API FGSS_ObjectRecord : public FGSS_BaseRecord
{
	GENERATED_BODY()

	UPROPERTY()
	UClass* Class;

	TArray<uint8> Data;
	TArray<FName> Tags;


	FGSS_ObjectRecord()
		: Super()
		  , Class(nullptr)
	{
	}

	FGSS_ObjectRecord(const UObject* Object);

	virtual bool Serialize(FArchive& Ar) override;

	bool IsValid() const
	{
		return !Name.IsNone() && Class && Data.Num() > 0;
	}

	FORCEINLINE bool operator==(const UObject* Other) const
	{
		return Other && Name == Other->GetFName() && Class == Other->GetClass();
	}

	bool operator==(const UGSS_SaverBase* Other) const;
};


/** Represents a serialized Component */
USTRUCT()
struct GENERICSAVESYSTEM_API FGSS_ComponentRecord : public FGSS_ObjectRecord
{
	GENERATED_BODY()

	FTransform Transform;


	virtual bool Serialize(FArchive& Ar) override;
};


/** Represents a serialized Actor */
USTRUCT()
struct GENERICSAVESYSTEM_API FGSS_ActorRecord : public FGSS_ObjectRecord
{
	GENERATED_BODY()

	bool bHiddenInGame;
	/** Whether or not this actor was spawned in runtime */
	bool bIsProcedural;
	FTransform Transform;
	FVector LinearVelocity = FVector::ZeroVector;
	FVector AngularVelocity = FVector::ZeroVector;
	TArray<FGSS_ComponentRecord> ComponentRecords;


	FGSS_ActorRecord()
		: Super()
	{
	}

	FGSS_ActorRecord(const AActor* Actor)
		: Super(Actor)
	{
	}

	virtual bool Serialize(FArchive& Ar) override;

};
