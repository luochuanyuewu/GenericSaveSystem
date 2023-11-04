// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#include "Serialization/GSS_Records.h"
#include "GSS_SlotData.h"
#include "Saver/GSS_SaverBase.h"


// Records

bool FGSS_BaseRecord::Serialize(FArchive& Ar)
{
	Ar << Name;
	return true;
}

FGSS_ObjectRecord::FGSS_ObjectRecord(const UObject* Object) : Super()
{
	Class = nullptr;
	if (Object)
	{
		Name = Object->GetFName();
		Class = Object->GetClass();
	}
}

bool FGSS_ObjectRecord::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);

	if (!Name.IsNone())
		Ar << Class;
	else if (Ar.IsLoading())
		Class = nullptr;

	if (Class)
	{
		Ar << Data;
		Ar << Tags;
	}
	return true;
}

bool FGSS_ObjectRecord::operator==(const UGSS_SaverBase* Other) const
{
	return Other && Name == FName(Other->GetFullKey()) && Class == Other->GetClass();
}

bool FGSS_ComponentRecord::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);
	if (Class)
	{
		Ar << Transform;
	}
	return true;
}

bool FGSS_ActorRecord::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);
	if (!Class)
	{
		return true;
	}

	Ar.SerializeBits(&bHiddenInGame, 1);
	Ar.SerializeBits(&bIsProcedural, 1);

	Ar << Transform;

	// Reduce memory footprint to 1 bool if not moving
	bool bIsMoving = Ar.IsSaving() && (!LinearVelocity.IsNearlyZero() || !AngularVelocity.IsNearlyZero());
	Ar << bIsMoving;
	if(bIsMoving)
	{
		Ar << LinearVelocity;
		Ar << AngularVelocity;
	}
	Ar << ComponentRecords;
	return true;
}
