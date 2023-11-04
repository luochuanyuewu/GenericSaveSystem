// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#pragma once

#include "GSS_FileAdapter.h"
#include "GSS_Delegates.h"
#include "GSS_SlotInfo.h"

#include "CoreMinimal.h"
#include "Async/AsyncWork.h"


class UGSS_SaveSubsystem;

/**
 * FGSS_Task_DeleteSlots
 * Async task to remove an specific or all slots
 * 移除某个存档槽或所有槽的异步任务。
 */
class FGSS_Task_DeleteSlots : public FNonAbandonableTask {
protected:

	const UGSS_SaveSubsystem* const Manager = nullptr;
	FString SpecificSlotName;

public:

	bool bSuccess = false;

	/** All infos Constructor */
	explicit FGSS_Task_DeleteSlots(const UGSS_SaveSubsystem* InManager, FName SlotName = {});

	void DoWork();

	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(FDeleteSlotsTask, STATGROUP_ThreadPoolAsyncTasks);
	}

private:

	UGSS_SlotInfo* LoadInfoFromFile(const FString Name) const;
};
