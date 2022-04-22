// Copyright 2015-2020 Piperift. All Rights Reserved.

#pragma once

#include "ISaveExtension.h"

#include "SESavePreset.h"

#include "SESlotDataTask_Saver.h"
#include "SESlotDataTask_LevelSaver.generated.h"


/**
* Manages the serializing process of a single level
*/
UCLASS()
class USESlotDataTask_LevelSaver : public USESlotDataTask_Saver
{
	GENERATED_BODY()


	UPROPERTY()
	ULevelStreaming* StreamingLevel;

public:

	auto Setup(ULevelStreaming* InStreamingLevel)
	{
		StreamingLevel = InStreamingLevel;
		return this;
	}

private:

	virtual void OnStart() override;
	virtual void OnFinish(bool bSuccess) override  {
		SELog(Preset, "Finished Serializing level", FColor::Green);
	}
};
