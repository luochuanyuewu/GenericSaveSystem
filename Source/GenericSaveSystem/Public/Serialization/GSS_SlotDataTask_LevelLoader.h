// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#pragma once

#include "IGenericSaveSystem.h"

#include "GSS_SavePreset.h"

#include "GSS_SlotDataTask_Loader.h"
#include "GSS_SlotDataTask_LevelLoader.generated.h"


/**
* Manages the serializing process of a single level
*/
UCLASS()
class UGSS_SlotDataTask_LevelLoader : public UGSS_SlotDataTask_Loader
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
