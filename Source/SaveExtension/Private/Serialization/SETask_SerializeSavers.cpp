// Copyright 2015-2020 Piperift. All Rights Reserved.

#include "Serialization/SETask_SerializeSavers.h"
#include "Serialization/MemoryWriter.h"
#include "SESavePreset.h"
#include "SESlotData.h"
#include "Saver/SESaverBase.h"
#include "Serialization/SEArchive.h"


/////////////////////////////////////////////////////
// FMTTask_SerializeActors
void FSETask_SerializeSavers::DoWork()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(FSETask_SerializeSavers::DoWork);
	
	
	for (int32 i=0;i<Savers->Num();i++)
	{
		const USESaverBase* const Saver = (*Savers)[i];
		if (Saver)
		{
			FSEObjectRecord& Record = FindSaverRecord(Saver);
			SerializeSaver(Saver, Record);
		}
	}
	//
	// for (int32 I = 0; I < Num; ++I)
	// {
	// 	const USESaverBase* const Saver = (*Savers)[StartIndex + I];
	// 	if (Saver)
	// 	{
	// 		FSEObjectRecord& Record = SaverRecords.AddDefaulted_GetRef();
	// 		SerializeSaver(Saver, Record);
	// 	}
	// }
}

FSEObjectRecord& FSETask_SerializeSavers::FindSaverRecord(const USESaverBase* Saver)
{
	FSEObjectRecord* Found = SaverRecords.FindByPredicate([&](const FSEObjectRecord& Record)
	{
		return Record.Name == FName(Saver->GetFullKey());
	});
	if (Found)
	{
		return *Found;
	}
	return SaverRecords.AddDefaulted_GetRef();
}

void FSETask_SerializeSavers::DumpData()
{
	SlotData->SaverRecords = MoveTemp(SaverRecords);
}

bool FSETask_SerializeSavers::SerializeSaver(const USESaverBase* Saver, FSEObjectRecord& Record) const
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
	FSEArchive Archive(MemoryWriter, false);
	const_cast<USESaverBase*>(Saver)->Serialize(Archive);
	return true;
}
