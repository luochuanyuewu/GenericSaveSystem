// Copyright 2015-2020 Piperift. All Rights Reserved.

#pragma once

#include "Async/AsyncWork.h"
#include "SEFileAdapter.h"

/*
 * FSETask_SaveFile 保存文件的异步任务.
 */
class FSETask_SaveFile : public FNonAbandonableTask
{
protected:
	USESlotInfo* Info;
	USESlotData* Data;
	const FString SlotName;
	const bool bUseCompression;

public:
	FSETask_SaveFile(USESlotInfo* Info, USESlotData* Data, const FString& InSlotName, const bool bInUseCompression)
		: Info(Info)
		, Data(Data)
		, SlotName(InSlotName)
		, bUseCompression(bInUseCompression) {}

	void DoWork()
	{
		FSEFileAdapter::SaveFile(SlotName, Info, Data, bUseCompression);
	}

	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(FSaveFileTask, STATGROUP_ThreadPoolAsyncTasks);
	}
};
