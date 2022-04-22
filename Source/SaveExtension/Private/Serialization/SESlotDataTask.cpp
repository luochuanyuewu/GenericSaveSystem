// Copyright 2015-2020 Piperift. All Rights Reserved.

#include "Serialization/SESlotDataTask.h"

#include "SESaveManager.h"
#include "SESavePreset.h"


/////////////////////////////////////////////////////
// USaveDataTask

USESlotDataTask* USESlotDataTask::Start()
{
	const USESaveManager* Manager = GetManager();

	// If not running and first task is this
	if (!bRunning && Manager->Tasks.Num() > 0 && Manager->Tasks[0] == this)
	{
		bRunning = true;
		OnStart();
	}
	return this;
}

void USESlotDataTask::Finish(bool bSuccess)
{
	if (bRunning)
	{
		OnFinish(bSuccess);
		MarkAsGarbage();
		GetManager()->FinishTask(this);
		bFinished = true;
		bSucceeded = bSuccess;
	}
}

bool USESlotDataTask::IsScheduled() const
{
	return GetManager()->Tasks.Contains(this);
}

USESaveManager* USESlotDataTask::GetManager() const
{
	return Cast<USESaveManager>(GetOuter());
}

void USESlotDataTask::BakeAllFilters()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USlotDataTask::BakeAllFilters);
	SlotData->GeneralLevelFilter.BakeAllowedClasses();

	if(SlotData->MainLevel.bOverrideGeneralFilter)
	{
		SlotData->MainLevel.Filter.BakeAllowedClasses();
	}

	for(const auto& Level : SlotData->SubLevels)
	{
		if(Level.bOverrideGeneralFilter)
		{
			Level.Filter.BakeAllowedClasses();
		}
	}
}

const FSELevelFilter& USESlotDataTask::GetGeneralFilter() const
{
	check(SlotData);
	return SlotData->GeneralLevelFilter;
}

const FSELevelFilter& USESlotDataTask::GetLevelFilter(const FSELevelRecord& Level) const
{
	if(Level.bOverrideGeneralFilter)
	{
		return Level.Filter;
	}
	return GetGeneralFilter();
}

FSELevelRecord* USESlotDataTask::FindLevelRecord(const ULevelStreaming* Level) const
{
	if (!Level)
		return &SlotData->MainLevel;
	else // Find the Sub-Level
		return SlotData->SubLevels.FindByKey(Level);
}

UWorld* USESlotDataTask::GetWorld() const
{
	return GetOuter()->GetWorld();
}
