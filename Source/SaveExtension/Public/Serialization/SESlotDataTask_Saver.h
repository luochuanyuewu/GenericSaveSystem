// Copyright 2015-2020 Piperift. All Rights Reserved.

#pragma once

#include "Delegates.h"
#include "ISaveExtension.h"
#include "SETask_SerializeActors.h"
#include "Multithreading/SETask_SaveFile.h"
#include "SESavePreset.h"
#include "SESlotData.h"
#include "SESlotDataTask.h"

#include "Engine/Level.h"
#include "Engine/LevelStreaming.h"
#include "GameFramework/Actor.h"
#include "Async/AsyncWork.h"

#include "SESlotDataTask_Saver.generated.h"


class FSETask_SerializeSavers;
/**
* Manages the saving process of a SaveData file
* 管理存档数据的保存过程.
*/
UCLASS()
class USESlotDataTask_Saver : public USESlotDataTask
{
	GENERATED_BODY()

	bool bOverride;
	bool bSaveThumbnail;
	FName SlotName;
	int32 Width;
	int32 Height;

	FOnSEGameSaved Delegate;

protected:
	UPROPERTY()
	USESlotInfo* SlotInfo;

	// /** Start Async variables */
	// TWeakObjectPtr<ULevel> CurrentLevel;
	// TWeakObjectPtr<ULevelStreaming> CurrentSLevel;
	// int32 CurrentActorIndex;
	// TArray<TWeakObjectPtr<AActor>> CurrentLevelActors;
	// /** End Async variables */

	/** Begin AsyncTasks */
	TArray<FAsyncTask<FSETask_SerializeActors>> Tasks;
	// FAsyncTask<FSETask_SerializeSavers>* SaverTask;
	FAsyncTask<FSETask_SaveFile>* SaveTask;
	/** End AsyncTasks */


public:
	USESlotDataTask_Saver()
		: USESlotDataTask()
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

	auto* Bind(const FOnSEGameSaved& OnSaved)
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
