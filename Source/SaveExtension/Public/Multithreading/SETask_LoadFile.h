// Copyright 2015-2020 Piperift. All Rights Reserved.

#pragma once

#include "Async/AsyncWork.h"
#include "SEFileAdapter.h"
#include "SESlotData.h"
#include "SESlotInfo.h"


class USESaveManager;
/*
 * FSETask_LoadFile
 * Async task to load a File
 */
class FSETask_LoadFile : public FNonAbandonableTask
{
protected:

	TWeakObjectPtr<USESaveManager> Manager;
	const FString SlotName;

	TWeakObjectPtr<USESlotInfo> SlotInfo;
	TWeakObjectPtr<USESlotData> SlotData;


public:

	explicit FSETask_LoadFile(USESaveManager* Manager, FStringView SlotName)
		: Manager(Manager)
		, SlotName(SlotName)
	{}
	~FSETask_LoadFile()
	{
		if(SlotInfo.IsValid())
		{
			SlotInfo->ClearInternalFlags(EInternalObjectFlags::Async);
		}
		if(SlotData.IsValid())
		{
			SlotData->ClearInternalFlags(EInternalObjectFlags::Async);
		}
	}

	void DoWork()
	{
		FSEScopedFileReader FileReader(FSEFileAdapter::GetSlotPath(SlotName));
		if(FileReader.IsValid())
		{
			FSESaveFile File;
			File.Read(FileReader, false);
			SlotInfo = File.CreateAndDeserializeInfo(Manager.Get());
			SlotData = File.CreateAndDeserializeData(Manager.Get());
		}
	}

	USESlotInfo* GetInfo()
	{
		return SlotInfo.Get();
	}

	USESlotData* GetData()
	{
		return SlotData.Get();
	}

	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(FLoadFileTask, STATGROUP_ThreadPoolAsyncTasks);
	}
};
