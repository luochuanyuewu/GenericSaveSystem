// Copyright 2015-2020 Piperift. All Rights Reserved.

#include "Serialization/SERecords.h"
#include "SESlotData.h"
#include "Saver/SESaverBase.h"


// Records

bool FSEBaseRecord::Serialize(FArchive& Ar)
{
	Ar << Name;
	return true;
}

FSEObjectRecord::FSEObjectRecord(const UObject* Object) : Super()
{
	Class = nullptr;
	if (Object)
	{
		Name = Object->GetFName();
		Class = Object->GetClass();
	}
}

bool FSEObjectRecord::Serialize(FArchive& Ar)
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

bool FSEObjectRecord::operator==(const USESaverBase* Other) const
{
	return Other && Name == FName(Other->GetFullKey()) && Class == Other->GetClass();
}

bool FSEComponentRecord::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);
	if (Class)
	{
		Ar << Transform;
	}
	return true;
}

bool FSEActorRecord::Serialize(FArchive& Ar)
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
