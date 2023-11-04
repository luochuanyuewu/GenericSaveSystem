// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#pragma once

#include "IGenericSaveSystem.h"

#include "GSS_SavePreset.h"

#include "GSS_SlotDataTask_Saver.h"
#include "GSS_SlotDataTask_LevelSaver.generated.h"


/**
* Manages the serializing process of a single level
* 管理一个流送关卡的序列化过程。
*/
UCLASS()
class UGSS_SlotDataTask_LevelSaver : public UGSS_SlotDataTask_Saver
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

	virtual void OnFinish(bool bSuccess) override
	{
		GSS_Log(Preset, "Finished Serializing level", FColor::Green);
	}
};
