// Copyright 2015-2020 Piperift. All Rights Reserved.

#pragma once

#include "ISaveExtension.h"

#include "Engine/Level.h"
#include "Engine/LevelStreaming.h"
#include "GameFramework/Actor.h"

#include "SESlotData.h"
#include "SELevelFilter.h"

#include "SESlotDataTask.generated.h"

class USESaveManager;


/**
* @brief Base class for managing a SaveData file.管理一个存档数据文件的基类
* @attention SlotDataTask对象由SaveManager管理，且都在主线程操作，其内部会管理各种异步Task。
*/
UCLASS()
class USESlotDataTask : public UObject
{
	GENERATED_BODY()

private:
	uint8 bRunning : 1;
	uint8 bFinished : 1;
	uint8 bSucceeded : 1;

protected:
	UPROPERTY()
	USESlotData* SlotData;

	UPROPERTY()
	const USESavePreset* Preset;

	UPROPERTY()
	float MaxFrameMs = 0.f;

public:
	USESlotDataTask()
		: Super()
		, bRunning(false)
		, bFinished(false) {}

	void Prepare(USESlotData* InSaveData, const USESavePreset& InPreset)
	{
		SlotData = InSaveData;
		Preset = &InPreset;
		MaxFrameMs = Preset->GetMaxFrameMs();
	}

	USESlotDataTask* Start();

	virtual void Tick(float DeltaTime) {}

	void Finish(bool bSuccess);

	bool IsRunning() const { return bRunning; }
	bool IsFinished() const { return bFinished; }
	bool IsSucceeded() const { return IsFinished() && bSucceeded; }
	bool IsFailed() const { return IsFinished() && !bSucceeded; }
	bool IsScheduled() const;

	virtual void OnTick(float DeltaTime) {}

protected:
	virtual void OnStart() {}

	virtual void OnFinish(bool bSuccess) {}

	USESaveManager* GetManager() const;

	void BakeAllFilters();

	const FSELevelFilter& GetGeneralFilter() const;
	const FSELevelFilter& GetLevelFilter(const FSELevelRecord& Level) const;

	FSELevelRecord* FindLevelRecord(const ULevelStreaming* Level) const;

	//~ Begin UObject Interface
	virtual UWorld* GetWorld() const override;
	//~ End UObject Interface

	FORCEINLINE float GetTimeMilliseconds() const
	{
		return FPlatformTime::ToMilliseconds(FPlatformTime::Cycles());
	}
};


/////////////////////////////////////////////////////
// FSlotDataActorsTask
// Async task to serialize actors from a level.
class FSESlotDataActorsTask : public FNonAbandonableTask
{
protected:
	const bool bIsSync;
	/** USE ONLY IF SYNC */
	const UWorld* const World;
	/** USE ONLY IF SYNC */
	USESlotData* SlotData;

	const FSELevelFilter& Filter;


	FSESlotDataActorsTask(const bool bInIsSync, const UWorld* InWorld, USESlotData* InSlotData, const FSELevelFilter& Filter)
		: bIsSync(bInIsSync)
		, World(InWorld)
		, SlotData(InSlotData)
		, Filter(Filter) {}
};
