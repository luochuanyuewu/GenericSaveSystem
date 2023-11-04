// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#include "Serialization/GSS_SlotDataTask.h"

#include "GSS_SaveSubsystem.h"
#include "GSS_SavePreset.h"


/////////////////////////////////////////////////////
// USaveDataTask

UGSS_SlotDataTask* UGSS_SlotDataTask::Start()
{
	const UGSS_SaveSubsystem* Manager = GetManager();

	// If not running and first task is this
	if (!bRunning && Manager->SlotDataTasks.Num() > 0 && Manager->SlotDataTasks[0] == this)
	{
		bRunning = true;
		OnStart();
	}
	return this;
}

void UGSS_SlotDataTask::Finish(bool bSuccess)
{
	if (bRunning)
	{
		OnFinish(bSuccess);
		MarkAsGarbage();
		GetManager()->FinishSlotDataTask(this);
		bFinished = true;
		bSucceeded = bSuccess;
	}
}

bool UGSS_SlotDataTask::IsScheduled() const
{
	return GetManager()->SlotDataTasks.Contains(this);
}

UGSS_SaveSubsystem* UGSS_SlotDataTask::GetManager() const
{
	return Cast<UGSS_SaveSubsystem>(GetOuter());
}


FGSS_LevelRecord* UGSS_SlotDataTask::FindLevelRecord(const ULevelStreaming* Level) const
{
	if (!Level)
		return &SlotData->MainLevel;
	else // Find the Sub-Level
		return SlotData->SubLevels.FindByKey(Level);
}

UWorld* UGSS_SlotDataTask::GetWorld() const
{
	return GetOuter()->GetWorld();
}
