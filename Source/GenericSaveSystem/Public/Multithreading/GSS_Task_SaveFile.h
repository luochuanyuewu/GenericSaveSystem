// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#pragma once

#include "Async/AsyncWork.h"
#include "GSS_FileAdapter.h"

/*
 * FGSS_Task_SaveFile 保存文件的异步任务.
 */
class FGSS_Task_SaveFile : public FNonAbandonableTask
{
protected:
	UGSS_SlotInfo* Info;
	UGSS_SlotData* Data;
	const FString SlotName;
	const bool bUseCompression;

public:
	FGSS_Task_SaveFile(UGSS_SlotInfo* Info, UGSS_SlotData* Data, const FString& InSlotName, const bool bInUseCompression)
		: Info(Info)
		, Data(Data)
		, SlotName(InSlotName)
		, bUseCompression(bInUseCompression) {}

	void DoWork()
	{
		FGSS_FileAdapter::SaveFile(SlotName, Info, Data, bUseCompression);
	}

	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(FSaveFileTask, STATGROUP_ThreadPoolAsyncTasks);
	}
};
