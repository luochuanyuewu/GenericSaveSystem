// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#pragma once

#include "GSS_Delegates.h"
#include "IGenericSaveSystem.h"
#include "GSS_AsyncTask_SerializeActors.h"
#include "Multithreading/GSS_Task_SaveFile.h"
#include "GSS_SavePreset.h"
#include "GSS_SlotData.h"
#include "GSS_SlotDataTask.h"

#include "Engine/Level.h"
#include "Engine/LevelStreaming.h"
#include "GameFramework/Actor.h"
#include "Async/AsyncWork.h"

#include "GSS_SlotDataTask_Saver.generated.h"


/**
* Manages the saving process of a SaveData file
* 管理存档数据的保存过程.
*/
UCLASS()
class UGSS_SlotDataTask_Saver : public UGSS_SlotDataTask
{
	GENERATED_BODY()

	bool bOverride;
	bool bSaveThumbnail;
	FName SlotName;
	int32 Width;
	int32 Height;

	FGSS_OnGameSavedSignature Delegate;

protected:
	UPROPERTY()
	UGSS_SlotInfo* SlotInfo;

	/** Begin AsyncTasks */
	TArray<FAsyncTask<FGSS_AsyncTask_SerializeActors>> Tasks;
	FAsyncTask<FGSS_Task_SaveFile>* SaveTask;
	/** End AsyncTasks */


public:
	UGSS_SlotDataTask_Saver()
		: UGSS_SlotDataTask()
		  , SaveTask(nullptr)
	{
	}

	auto* Setup(FName InSlotName, bool bInOverride, bool bInSaveThumbnail, const int32 InWidth, const int32 InHeight)
	{
		SlotName = InSlotName;
		bOverride = bInOverride;
		bSaveThumbnail = bInSaveThumbnail;
		Width = InWidth;
		Height = InHeight;

		return this;
	}

	auto* Bind(const FGSS_OnGameSavedSignature& OnSaved)
	{
		Delegate = OnSaved;
		return this;
	}

	// Where all magic happens
	virtual void OnStart() override;
	virtual void Tick(float DeltaTime) override;
	virtual void OnFinish(bool bSuccess) override;
	virtual void BeginDestroy() override;

protected:
	/** 序列化整个世界的Actor, TODO 金生 在这里序列化Saver */
	void SerializeWorld();

	void PrepareAllLevels(const TArray<ULevelStreaming*>& Levels);

	/**
	 * @brief 给一个关卡，根据线程数和关卡内Actor数量规划一个或多个FSETask_SerializeActors任务。
	 */
	void ScheduleTasksForLevel(const ULevel* Level, int32 AssignedThreads, const ULevelStreaming* StreamingLevel = nullptr);

	// void CreateSaveSaversTask();
	
	/**
	 * @brief 运行规划好的任务。
	 */
	void RunScheduledTasks();

private:
	void SaveFile();
};
