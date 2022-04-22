// Copyright 2015-2020 Piperift. All Rights Reserved.

#pragma once

#include "SEFileAdapter.h"
#include "Multithreading/Delegates.h"
#include "SESlotInfo.h"

#include "CoreMinimal.h"
#include "Async/AsyncWork.h"


class USESaveManager;

/**
 * FSETask_DeleteSlots
 * Async task to remove an specific or all slots
 * 移除某个存档槽或所有槽的异步任务。
 */
class FSETask_DeleteSlots : public FNonAbandonableTask {
protected:

	const USESaveManager* const Manager = nullptr;
	FString SpecificSlotName;

public:

	bool bSuccess = false;

	/** All infos Constructor */
	explicit FSETask_DeleteSlots(const USESaveManager* InManager, FName SlotName = {});

	void DoWork();

	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(FDeleteSlotsTask, STATGROUP_ThreadPoolAsyncTasks);
	}

private:

	USESlotInfo* LoadInfoFromFile(const FString Name) const;
};
