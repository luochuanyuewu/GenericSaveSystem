// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.
#pragma once

class UGSS_SlotData;

class FGSS_AsyncTask : public FNonAbandonableTask
{
protected:
	/** Used only if Sync */
	const UWorld* const World;
	UGSS_SlotData* SlotData;

	FGSS_AsyncTask(const bool bIsloading, const UWorld* InWorld, UGSS_SlotData* InSlotData)
		: World(InWorld)
		  , SlotData(InSlotData)
	{
	}
};
