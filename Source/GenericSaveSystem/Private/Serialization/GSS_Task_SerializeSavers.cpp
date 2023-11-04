// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#include "Serialization/GSS_Task_SerializeSavers.h"
#include "Serialization/MemoryWriter.h"
#include "GSS_SavePreset.h"
#include "GSS_SlotData.h"
#include "Saver/GSS_SaverBase.h"
#include "Serialization/GSS_Archive.h"


/////////////////////////////////////////////////////
// FMTTask_SerializeActors
void FGSS_Task_SerializeSavers::DoWork()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(FSETask_SerializeSavers::DoWork);
	
	
	for (int32 i=0;i<Savers->Num();i++)
	{
		const UGSS_SaverBase* const Saver = (*Savers)[i];
		if (Saver)
		{
			FGSS_ObjectRecord& Record = FindSaverRecord(Saver);
			SerializeSaver(Saver, Record);
		}
	}
	//
	// for (int32 I = 0; I < Num; ++I)
	// {
	// 	const UGSS_SaverBase* const Saver = (*Savers)[StartIndex + I];
	// 	if (Saver)
	// 	{
	// 		FGSS_ObjectRecord& Record = SaverRecords.AddDefaulted_GetRef();
	// 		SerializeSaver(Saver, Record);
	// 	}
	// }
}

FGSS_ObjectRecord& FGSS_Task_SerializeSavers::FindSaverRecord(const UGSS_SaverBase* Saver)
{
	FGSS_ObjectRecord* Found = SaverRecords.FindByPredicate([&](const FGSS_ObjectRecord& Record)
	{
		return Record.Name == FName(Saver->GetFullKey());
	});
	if (Found)
	{
		return *Found;
	}
	return SaverRecords.AddDefaulted_GetRef();
}

void FGSS_Task_SerializeSavers::DumpData()
{
	SlotData->SaverRecords = MoveTemp(SaverRecords);
}

bool FGSS_Task_SerializeSavers::SerializeSaver(const UGSS_SaverBase* Saver, FGSS_ObjectRecord& Record) const
{
	TRACE_CPUPROFILER_EVENT_SCOPE(FMTTask_SerializeActors::SerializeActor);

	//Clean the record
	// Record = {Saver};
	Record.Class = nullptr;
	if (Saver)
	{
		Record.Name = FName(Saver->GetFullKey());
		Record.Class = Saver->GetClass();
	}
	
	TRACE_CPUPROFILER_EVENT_SCOPE(Serialize);
	FMemoryWriter MemoryWriter(Record.Data, true);
	FGSS_Archive Archive(MemoryWriter, false);
	const_cast<UGSS_SaverBase*>(Saver)->Serialize(Archive);
	return true;
}
