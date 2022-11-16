// Copyright 2015-2020 Piperift. All Rights Reserved.

#include "Serialization/SESlotDataTask_LevelSaver.h"


/////////////////////////////////////////////////////
// FSaveDataTask_LevelSaver

void USESlotDataTask_LevelSaver::OnStart()
{
	if (SlotData && StreamingLevel && StreamingLevel->IsLevelLoaded())
	{
		FSELevelRecord* LevelRecord = FindLevelRecord(StreamingLevel);
		if (!LevelRecord)
		{
			Finish(false);
			return;
		}

		const int32 NumberOfThreads = FMath::Max(1, FPlatformMisc::NumberOfWorkerThreadsToSpawn());
		ScheduleTasksForLevel(StreamingLevel->GetLoadedLevel(), NumberOfThreads, StreamingLevel);

		RunScheduledTasks();

		Finish(true);
		return;
	}
	Finish(false);
}
