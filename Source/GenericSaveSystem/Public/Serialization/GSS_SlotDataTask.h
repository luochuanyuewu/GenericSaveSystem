// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#pragma once

#include "IGenericSaveSystem.h"

#include "Engine/Level.h"
#include "Engine/LevelStreaming.h"
#include "GameFramework/Actor.h"

#include "GSS_SlotData.h"
#include "GSS_LevelFilter.h"

#include "GSS_SlotDataTask.generated.h"

class UGSS_SaveSubsystem;


/**
* @brief Base class for managing a SaveData file.管理一个存档数据文件的基类
* @attention SlotDataTask对象由SaveManager管理，且都在主线程操作，其内部会管理各种异步Task。
*/
UCLASS()
class UGSS_SlotDataTask : public UObject
{
	GENERATED_BODY()

private:
	uint8 bRunning : 1;
	uint8 bFinished : 1;
	uint8 bSucceeded : 1;

protected:
	UPROPERTY()
	UGSS_SlotData* SlotData;

	UPROPERTY()
	const UGSS_SavePreset* Preset;

	UPROPERTY()
	float MaxFrameMs = 0.f;

public:
	UGSS_SlotDataTask()
		: Super()
		  , bRunning(false)
		  , bFinished(false)
		  , bSucceeded(false)
		  , SlotData(nullptr), Preset(nullptr)
	{
	}

	void Prepare(UGSS_SlotData* InSaveData, const UGSS_SavePreset& InPreset)
	{
		SlotData = InSaveData;
		Preset = &InPreset;
		MaxFrameMs = Preset->GetMaxFrameMs();
	}

	UGSS_SlotDataTask* Start();

	virtual void Tick(float DeltaTime)
	{
	}

	void Finish(bool bSuccess);

	bool IsRunning() const { return bRunning; }
	bool IsFinished() const { return bFinished; }
	bool IsSucceeded() const { return IsFinished() && bSucceeded; }
	bool IsFailed() const { return IsFinished() && !bSucceeded; }
	bool IsScheduled() const;

	virtual void OnTick(float DeltaTime)
	{
	}

protected:
	virtual void OnStart()
	{
	}

	virtual void OnFinish(bool bSuccess)
	{
	}

	UGSS_SaveSubsystem* GetManager() const;

	FGSS_LevelRecord* FindLevelRecord(const ULevelStreaming* Level) const;

	//~ Begin UObject Interface
	virtual UWorld* GetWorld() const override;
	//~ End UObject Interface

	FORCEINLINE float GetTimeMilliseconds() const
	{
		return FPlatformTime::ToMilliseconds(FPlatformTime::Cycles());
	}
};


/////////////////////////////////////////////////////
// FGSS_SlotDataActorsTask
// Async task to serialize actors from a level.
class FGSS_SlotDataActorsTask : public FNonAbandonableTask
{
protected:
	const bool bIsSync;
	/** USE ONLY IF SYNC */
	const UWorld* const World;
	/** USE ONLY IF SYNC */
	UGSS_SlotData* SlotData;

	FGSS_SlotDataActorsTask(const bool bInIsSync, const UWorld* InWorld, UGSS_SlotData* InSlotData)
		: bIsSync(bInIsSync)
		  , World(InWorld)
		  , SlotData(InSlotData)
	{
	}
};
