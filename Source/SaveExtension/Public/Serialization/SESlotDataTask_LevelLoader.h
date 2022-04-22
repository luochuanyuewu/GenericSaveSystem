// Copyright 2015-2020 Piperift. All Rights Reserved.

#pragma once

#include "ISaveExtension.h"

#include "SESavePreset.h"

#include "SESlotDataTask_Loader.h"
#include "SESlotDataTask_LevelLoader.generated.h"


/**
* Manages the serializing process of a single level
*/
UCLASS()
class USESlotDataTask_LevelLoader : public USESlotDataTask_Loader
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

	virtual void DeserializeASyncLoop(float StartMS = 0.0f) override;
};
