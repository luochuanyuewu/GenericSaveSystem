// Copyright 2015-2020 Piperift. All Rights Reserved.

#pragma once
#include "SELevelFilter.h"


/////////////////////////////////////////////////////
// FSlotDataActorsTask
// Async task to serialize actors from a level.
class FSEAsyncTask : public FNonAbandonableTask {
protected:

	/** Used only if Sync */
	const UWorld* const World;
	USESlotData* SlotData;

	FSEAsyncTask(const bool bIsloading, const UWorld* InWorld, USESlotData* InSlotData)
		: World(InWorld)
		, SlotData(InSlotData)
	{}
};
