// Copyright 2015-2020 Piperift. All Rights Reserved.

#include "Serialization/SELevelRecords.h"
#include "SESlotData.h"


/////////////////////////////////////////////////////
// LevelRecords

const FName FSEPersistentLevelRecord::PersistentName{ "Persistent" };


bool FSELevelRecord::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);

	// Ar << bOverrideGeneralFilter;
	// if (bOverrideGeneralFilter)
	// {
	// 	static UScriptStruct* const LevelFilterType{ FSELevelFilter::StaticStruct() };
	// 	LevelFilterType->SerializeItem(Ar, &Filter, nullptr);
	// }

	Ar << LevelScript;
	Ar << Actors;

	return true;
}

void FSELevelRecord::CleanRecords()
{
	LevelScript = {};
	Actors.Empty();
}
