// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#include "Serialization/GSS_SlotDataTask_LevelLoader.h"


/////////////////////////////////////////////////////
// USaveDataTask_LevelLoader

void UGSS_SlotDataTask_LevelLoader::OnStart()
{
	if (SlotData && StreamingLevel && StreamingLevel->IsLevelLoaded())
	{
		FGSS_LevelRecord* LevelRecord = FindLevelRecord(StreamingLevel);
		if (!LevelRecord)
		{
			Finish(false);
			return;
		}

		if (Preset->IsFrameSplitLoad())
		{
			DeserializeLevelASync(StreamingLevel->GetLoadedLevel(), StreamingLevel);
		}
		else
		{
			DeserializeLevelSync(StreamingLevel->GetLoadedLevel(), StreamingLevel);
			FinishedDeserializing();
		}
		return;
	}
	Finish(false);
}

void UGSS_SlotDataTask_LevelLoader::DeserializeASyncLoop(float StartMS /*= 0.0f*/)
{
	FGSS_LevelRecord& LevelRecord = *FindLevelRecord(CurrentSLevel.Get());

	if (StartMS <= 0)
	{
		StartMS = GetTimeMilliseconds();
	}

	// Continue Iterating actors every tick
	for (; CurrentActorIndex < CurrentLevelActors.Num(); ++CurrentActorIndex)
	{
		AActor* Actor{ CurrentLevelActors[CurrentActorIndex].Get() };
		if (Actor)
		{
			DeserializeLevel_Actor(Actor, LevelRecord);

			const float CurrentMS = GetTimeMilliseconds();
			// If x milliseconds passed, continue on next frame
			if (CurrentMS - StartMS >= MaxFrameMs)
				return;
		}
	}

	// All levels deserialized
	FinishedDeserializing();
}
