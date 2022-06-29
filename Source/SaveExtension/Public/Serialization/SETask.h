// Copyright 2015-2020 Piperift. All Rights Reserved.

#pragma once
#include "SELevelFilter.h"


/////////////////////////////////////////////////////
// FSlotDataActorsTask
// Async task to serialize actors from a level.
class FSETask : public FNonAbandonableTask {
protected:

	/** Used only if Sync */
	const UWorld* const World;
	USESlotData* SlotData;

	// Locally cached settings
	const FSELevelFilter& Filter;


	FSETask(const bool bIsloading, const UWorld* InWorld, USESlotData* InSlotData, const FSELevelFilter& Filter)
		: World(InWorld)
		, SlotData(InSlotData)
		, Filter(Filter)
	{}
};
