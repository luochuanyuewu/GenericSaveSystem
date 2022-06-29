// Copyright 2015-2020 Piperift. All Rights Reserved.

#pragma once

#include "Delegates.h"
#include "Multithreading/SETask_LoadFile.h"
#include "SESavePreset.h"
#include "SESlotInfo.h"
#include "SESlotData.h"
#include "SESlotDataTask.h"
#include "Engine/Level.h"
#include "Engine/LevelStreaming.h"
#include "GameFramework/Actor.h"

#include "SESlotDataTask_Loader.generated.h"


enum class ELoadDataTaskState : uint8
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
class USESlotDataTask_Loader : public USESlotDataTask
{
	GENERATED_BODY()

	FName SlotName;

	UPROPERTY()
	USESlotInfo* NewSlotInfo;

	FOnSEGameLoaded Delegate;

protected:
	// Async variables
	TWeakObjectPtr<ULevel> CurrentLevel;
	TWeakObjectPtr<ULevelStreaming> CurrentSLevel;

	int32 CurrentActorIndex = 0;
	TArray<TWeakObjectPtr<AActor>> CurrentLevelActors;

	/** Start AsyncTasks */
	FAsyncTask<FSETask_LoadFile>* LoadDataTask;
	/** End AsyncTasks */

	ELoadDataTaskState LoadState = ELoadDataTaskState::NotStarted;


public:
	USESlotDataTask_Loader()
		: Super() {}

	auto Setup(FName InSlotName)
	{
		SlotName = InSlotName;
		return this;
	}

	auto Bind(const FOnSEGameLoaded& OnLoaded)
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
	void RespawnActors(const TArray<FSEActorRecord*>& Records, const ULevel* Level);

protected:
	//~ Begin Files
	void StartLoadingData();

	USESlotData* GetLoadedData() const;
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
	void PrepareLevel(const ULevel* Level, FSELevelRecord& LevelRecord);

	/** Deserializes all Level actors. */
	inline void DeserializeLevel_Actor(AActor* const Actor, const FSELevelRecord& LevelRecord, const FSELevelFilter& Filter);

	void FindNextAsyncLevel(ULevelStreaming*& OutLevelStreaming) const;

private:
	/** Deserializes Game Instance Object and its Properties.
	Requires 'SaveGameMode' flag to be used. */
	void DeserializeGameInstance();

	/** Serializes an actor into this Actor Record */
	bool DeserializeActor(AActor* Actor, const FSEActorRecord& Record, const FSELevelFilter& Filter);

	/** Deserializes the components of an actor from a provided Record */
	void DeserializeActorComponents(AActor* Actor, const FSEActorRecord& ActorRecord, const FSELevelFilter& Filter, int8 indent = 0);
	/** END Deserialization */
};
