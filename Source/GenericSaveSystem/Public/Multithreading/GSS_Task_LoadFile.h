// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#pragma once

#include "Async/AsyncWork.h"
#include "GSS_FileAdapter.h"
#include "GSS_SlotData.h"
#include "GSS_SlotInfo.h"


class UGSS_SaveSubsystem;
/*
 * FGSS_Task_LoadFile
 * Async task to load a File
 */
class FGSS_Task_LoadFile : public FNonAbandonableTask
{
protected:

	TWeakObjectPtr<UGSS_SaveSubsystem> Manager;
	const FString SlotName;

	TWeakObjectPtr<UGSS_SlotInfo> SlotInfo;
	TWeakObjectPtr<UGSS_SlotData> SlotData;


public:

	explicit FGSS_Task_LoadFile(UGSS_SaveSubsystem* Manager, FStringView SlotName)
		: Manager(Manager)
		, SlotName(SlotName)
	{}
	~FGSS_Task_LoadFile()
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
		FSEScopedFileReader FileReader(FGSS_FileAdapter::GetSlotPath(SlotName));
		if(FileReader.IsValid())
		{
			FGSS_SaveFile File;
			File.Read(FileReader, false);
			SlotInfo = File.CreateAndDeserializeInfo(Manager.Get());
			SlotData = File.CreateAndDeserializeData(Manager.Get());
		}
	}

	UGSS_SlotInfo* GetInfo()
	{
		return SlotInfo.Get();
	}

	UGSS_SlotData* GetData()
	{
		return SlotData.Get();
	}

	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(FLoadFileTask, STATGROUP_ThreadPoolAsyncTasks);
	}
};
