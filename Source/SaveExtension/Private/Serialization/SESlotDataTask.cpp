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
	if (!bRunning && Manager->SlotDataTasks.Num() > 0 && Manager->SlotDataTasks[0] == this)
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
		GetManager()->FinishSlotDataTask(this);
		bFinished = true;
		bSucceeded = bSuccess;
	}
}

bool USESlotDataTask::IsScheduled() const
{
	return GetManager()->SlotDataTasks.Contains(this);
}

USESaveManager* USESlotDataTask::GetManager() const
{
	return Cast<USESaveManager>(GetOuter());
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
