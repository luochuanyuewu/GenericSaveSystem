// Copyright 2015-2020 Piperift. All Rights Reserved.

#pragma once

#include "Async/AsyncWork.h"
#include "SEFileAdapter.h"
#include "Multithreading/Delegates.h"

#include "SESlotInfo.h"

class USESaveManager;


/**
 * FSETask_LoadSlotInfos
 * Async task to load one or many slot infos
 */
class FSETask_LoadSlotInfos : public FNonAbandonableTask
{
protected:

	const USESaveManager* Manager;

	const bool bSortByRecent = false;
	// If not empty, only this specific slot will be loaded
	const FName SlotName;

	TArray<USESlotInfo*> LoadedSlots;

	FOnSESlotInfosLoaded Delegate;


public:

	/** All infos Constructor */
	explicit FSETask_LoadSlotInfos(const USESaveManager* Manager, bool bInSortByRecent, const FOnSESlotInfosLoaded& Delegate)
		: Manager(Manager)
		, bSortByRecent(bInSortByRecent)
		, Delegate(Delegate)
	{}

	/** One info Constructor */
	explicit FSETask_LoadSlotInfos(USESaveManager* Manager, FName SlotName)
		: Manager(Manager)
		, SlotName(SlotName)
	{}

	void DoWork();

	/** Called after the task has finished */
	void AfterFinish();

	const TArray<USESlotInfo*>& GetLoadedSlots() const
	{
		return LoadedSlots;
	}

	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(FLoadAllSlotInfosTask, STATGROUP_ThreadPoolAsyncTasks);
	}
};
