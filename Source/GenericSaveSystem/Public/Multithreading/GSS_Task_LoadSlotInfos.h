// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#pragma once

#include "Async/AsyncWork.h"
#include "GSS_FileAdapter.h"
#include "GSS_Delegates.h"

#include "GSS_SlotInfo.h"

class UGSS_SaveSubsystem;


/**
 * FGSS_Task_LoadSlotInfos
 * Async task to load one or many slot infos
 */
class FGSS_Task_LoadSlotInfos : public FNonAbandonableTask
{
protected:

	const UGSS_SaveSubsystem* Manager;

	const bool bSortByRecent = false;
	// If not empty, only this specific slot will be loaded
	const FName SlotName;

	TArray<UGSS_SlotInfo*> LoadedSlots;

	FGSS_OnSlotInfosLoadedSignature Delegate;


public:

	/** All infos Constructor */
	explicit FGSS_Task_LoadSlotInfos(const UGSS_SaveSubsystem* Manager, bool bInSortByRecent, const FGSS_OnSlotInfosLoadedSignature& Delegate)
		: Manager(Manager)
		, bSortByRecent(bInSortByRecent)
		, Delegate(Delegate)
	{}

	/** One info Constructor */
	explicit FGSS_Task_LoadSlotInfos(UGSS_SaveSubsystem* Manager, FName SlotName)
		: Manager(Manager)
		, SlotName(SlotName)
	{}

	void DoWork();

	/** Called after the task has finished */
	void AfterFinish();

	const TArray<UGSS_SlotInfo*>& GetLoadedSlots() const
	{
		return LoadedSlots;
	}

	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(FLoadAllSlotInfosTask, STATGROUP_ThreadPoolAsyncTasks);
	}
};
