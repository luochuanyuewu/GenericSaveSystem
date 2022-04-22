// Copyright 2015-2020 Piperift. All Rights Reserved.

#include "Serialization/SESlotDataTask_LevelLoader.h"


/////////////////////////////////////////////////////
// USaveDataTask_LevelLoader

void USESlotDataTask_LevelLoader::OnStart()
{
	if (SlotData && StreamingLevel && StreamingLevel->IsLevelLoaded())
	{
		FSELevelRecord* LevelRecord = FindLevelRecord(StreamingLevel);
		if (!LevelRecord)
		{
			Finish(false);
			return;
		}

		GetLevelFilter(*LevelRecord).BakeAllowedClasses();

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

void USESlotDataTask_LevelLoader::DeserializeASyncLoop(float StartMS /*= 0.0f*/)
{
	FSELevelRecord& LevelRecord = *FindLevelRecord(CurrentSLevel.Get());

	if (StartMS <= 0)
	{
		StartMS = GetTimeMilliseconds();
	}

	const auto& Filter = GetLevelFilter(LevelRecord);

	// Continue Iterating actors every tick
	for (; CurrentActorIndex < CurrentLevelActors.Num(); ++CurrentActorIndex)
	{
		AActor* Actor{ CurrentLevelActors[CurrentActorIndex].Get() };
		if (Actor)
		{
			DeserializeLevel_Actor(Actor, LevelRecord, Filter);

			const float CurrentMS = GetTimeMilliseconds();
			// If x milliseconds passed, continue on next frame
			if (CurrentMS - StartMS >= MaxFrameMs)
				return;
		}
	}

	// All levels deserialized
	FinishedDeserializing();
}
