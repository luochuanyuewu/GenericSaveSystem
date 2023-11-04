// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#pragma once

#include "GSS_Delegates.h"
#include "Multithreading/GSS_Task_LoadFile.h"
#include "GSS_SavePreset.h"
#include "GSS_SlotData.h"
#include "GSS_SlotDataTask.h"
#include "Engine/Level.h"
#include "Engine/LevelStreaming.h"
#include "GameFramework/Actor.h"

#include "GSS_SlotDataTask_Loader.generated.h"


enum class EGSS_LoadDataTaskState : uint8
{
	NotStarted,

	// Once loading starts we either load the map
	LoadingMap,
	WaitingForData,

	RestoringActors,
	Deserializing
};

/**
* Manages the loading process of a SaveData file
* 管理存档数据文件的加载过程。
*/
UCLASS()
class UGSS_SlotDataTask_Loader : public UGSS_SlotDataTask
{
	GENERATED_BODY()

	FName SlotName;

	UPROPERTY()
	UGSS_SlotInfo* NewSlotInfo;

	FGSS_OnGameLoadedSignature Delegate;

protected:
	// Async variables
	TWeakObjectPtr<ULevel> CurrentLevel;
	TWeakObjectPtr<ULevelStreaming> CurrentSLevel;

	int32 CurrentActorIndex = 0;
	TArray<TWeakObjectPtr<AActor>> CurrentLevelActors;

	/** Start AsyncTasks */
	FAsyncTask<FGSS_Task_LoadFile>* LoadDataTask;
	/** End AsyncTasks */

	EGSS_LoadDataTaskState LoadState = EGSS_LoadDataTaskState::NotStarted;


public:
	UGSS_SlotDataTask_Loader()
		: Super() {}

	auto Setup(FName InSlotName)
	{
		SlotName = InSlotName;
		return this;
	}

	auto Bind(const FGSS_OnGameLoadedSignature& OnLoaded)
	{
		Delegate = OnLoaded;
		return this;
	}

	void OnMapLoaded();

private:
	virtual void OnStart() override;

	virtual void Tick(float DeltaTime) override;
	virtual void OnFinish(bool bSuccess) override;
	virtual void BeginDestroy() override;

	void StartDeserialization();

	/** Spawns Actors hat were saved but which actors are not in the world. */
	void RespawnActors(const TArray<FGSS_ActorRecord*>& Records, const ULevel* Level);

protected:
	//~ Begin Files
	void StartLoadingData();

	UGSS_SlotData* GetLoadedData() const;
	FORCEINLINE const bool IsDataLoaded() const { return LoadDataTask && LoadDataTask->IsDone(); };
	//~ End Files


	/** BEGIN Deserialization */
	void BeforeDeserialize();
	void DeserializeSync();
	void DeserializeLevelSync(const ULevel* Level, const ULevelStreaming* StreamingLevel = nullptr);

	void DeserializeASync();
	void DeserializeLevelASync(ULevel* Level, ULevelStreaming* StreamingLevel = nullptr);

	virtual void DeserializeASyncLoop(float StartMS = 0.0f);

	void FinishedDeserializing();

	void PrepareAllLevels();
	void PrepareLevel(const ULevel* Level, FGSS_LevelRecord& LevelRecord);

	/** Deserializes all Level actors. */
	inline void DeserializeLevel_Actor(AActor* const Actor, const FGSS_LevelRecord& LevelRecord);

	void FindNextAsyncLevel(ULevelStreaming*& OutLevelStreaming) const;

private:
	/** Deserializes Game Instance Object and its Properties.
	Requires 'SaveGameMode' flag to be used. */
	void DeserializeGameInstance();

	/** Serializes an actor into this Actor Record */
	bool DeserializeActor(AActor* Actor, const FGSS_ActorRecord& Record);

	/** Deserializes the components of an actor from a provided Record */
	void DeserializeActorComponents(AActor* Actor, const FGSS_ActorRecord& ActorRecord, int8 indent = 0);
	/** END Deserialization */
};
