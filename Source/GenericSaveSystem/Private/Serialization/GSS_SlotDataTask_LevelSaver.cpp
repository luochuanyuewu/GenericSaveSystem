// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#include "Serialization/GSS_SlotDataTask_LevelSaver.h"


/////////////////////////////////////////////////////
// FSaveDataTask_LevelSaver

void UGSS_SlotDataTask_LevelSaver::OnStart()
{
	if (SlotData && StreamingLevel && StreamingLevel->IsLevelLoaded())
	{
		FGSS_LevelRecord* LevelRecord = FindLevelRecord(StreamingLevel);
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
