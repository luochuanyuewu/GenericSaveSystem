// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#pragma once

#include "GSS_AsyncTask_SerializeActors.h"
#include "GameFramework/Actor.h"
#include "GSS_SavePreset.h"
#include "GSS_AsyncTask.h"
#include "Serialization/GSS_Records.h"
#include "Serialization/GSS_LevelRecords.h"


class UGSS_SlotData;

// /** Called when game has been saved
//  * @param SlotInfo the saved slot. Null if save failed
//  */
// DECLARE_DELEGATE_OneParam(FGSS_OnGameSavedSignature, UGSS_SlotInfo*);


/////////////////////////////////////////////////////
// FSETask_SerializeActors
// 序列化一个关卡中所有Actor的异步任务。
class FGSS_AsyncTask_SerializeActors : public FGSS_AsyncTask
{
	const TArray<AActor*>* const LevelActors;
	const int32 StartIndex;
	const int32 Num;
	const bool bStoreGameInstance = false;

	/** USE ONLY FOR DUMPING DATA */
	FGSS_LevelRecord* LevelRecord = nullptr;

	FGSS_ActorRecord LevelScriptRecord;
	TArray<FGSS_ActorRecord> ActorRecords;

public:
	FGSS_AsyncTask_SerializeActors(const UWorld* World, UGSS_SlotData* SlotData,
	                             const TArray<AActor*>* const InLevelActors, const int32 InStartIndex, const int32 InNum, bool bStoreGameInstance,
	                             FGSS_LevelRecord* InLevelRecord)
		: FGSS_AsyncTask(false, World, SlotData)
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
	bool SerializeActor(const AActor* Actor, FGSS_ActorRecord& Record) const;

	/** Serializes the components of an actor into a provided Actor Record */
	inline void SerializeActorComponents(const AActor* Actor, FGSS_ActorRecord& ActorRecord, int8 indent = 0) const;
};
