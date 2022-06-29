// Copyright 2015-2020 Piperift. All Rights Reserved.

#pragma once

#include "SETask_SerializeActors.h"
#include "GameFramework/Actor.h"
#include "SESavePreset.h"
#include "SETask.h"
#include "Serialization/SERecords.h"
#include "Serialization/SELevelRecords.h"


class USESlotData;

// /** Called when game has been saved
//  * @param SlotInfo the saved slot. Null if save failed
//  */
// DECLARE_DELEGATE_OneParam(FOnSEGameSaved, USESlotInfo*);


/////////////////////////////////////////////////////
// FSETask_SerializeActors
// 序列化一个关卡中所有Actor的异步任务。
class FSETask_SerializeActors : public FSETask
{
	const TArray<AActor*>* const LevelActors;
	const int32 StartIndex;
	const int32 Num;
	const bool bStoreGameInstance = false;

	/** USE ONLY FOR DUMPING DATA */
	FSELevelRecord* LevelRecord = nullptr;

	FSEActorRecord LevelScriptRecord;
	TArray<FSEActorRecord> ActorRecords;


public:
	FSETask_SerializeActors(const UWorld* World, USESlotData* SlotData,
	                        const TArray<AActor*>* const InLevelActors, const int32 InStartIndex, const int32 InNum, bool bStoreGameInstance,
	                        FSELevelRecord* InLevelRecord, const FSELevelFilter& Filter)
		: FSETask(false, World, SlotData, Filter)
		  , LevelActors(InLevelActors)
		  , StartIndex(InStartIndex)
		  , Num(InNum)
		  , bStoreGameInstance(bStoreGameInstance)
		  , LevelRecord(InLevelRecord)
		  , LevelScriptRecord{}
		  , ActorRecords{}
	{
		// No apparent performance benefit
		// ActorRecords.Reserve(Num);
	}

	void DoWork();

	/** Called after task has completed to recover resulting information */
	void DumpData()
	{
		if (LevelScriptRecord.IsValid())
			LevelRecord->LevelScript = LevelScriptRecord;

		// Shrink not needed. Move wont keep reserved space
		LevelRecord->Actors.Append(MoveTemp(ActorRecords));
	}

	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(FSETask_SerializeActors, STATGROUP_ThreadPoolAsyncTasks);
	}

private:
	void SerializeGameInstance();

	/** Serializes an actor into this Actor Record */
	bool SerializeActor(const AActor* Actor, FSEActorRecord& Record) const;

	/** Serializes the components of an actor into a provided Actor Record */
	inline void SerializeActorComponents(const AActor* Actor, FSEActorRecord& ActorRecord, int8 indent = 0) const;
};
