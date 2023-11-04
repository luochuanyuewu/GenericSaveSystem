// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#include "Serialization/GSS_LevelRecords.h"
#include "GSS_SlotData.h"


/////////////////////////////////////////////////////
// LevelRecords

const FName FGSS_PersistentLevelRecord::PersistentName{ "Persistent" };


bool FGSS_LevelRecord::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);

	// Ar << bOverrideGeneralFilter;
	// if (bOverrideGeneralFilter)
	// {
	// 	static UScriptStruct* const LevelFilterType{ UGSS_SaveFilter::StaticStruct() };
	// 	LevelFilterType->SerializeItem(Ar, &Filter, nullptr);
	// }

	Ar << LevelScript;
	Ar << Actors;

	return true;
}

void FGSS_LevelRecord::CleanRecords()
{
	LevelScript = {};
	Actors.Empty();
}
