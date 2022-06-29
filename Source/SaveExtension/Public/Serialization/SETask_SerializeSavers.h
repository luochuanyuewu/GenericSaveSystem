// // Copyright 2015-2020 Piperift. All Rights Reserved.
//
// #pragma once
//
// #include "SETask_SerializeActors.h"
// #include "GameFramework/Actor.h"
// #include "SESavePreset.h"
// #include "SESlotData.h"
// #include "SETask.h"
// #include "Saver/SESaverBase.h"
// #include "Serialization/SERecords.h"
// #include "Serialization/SELevelRecords.h"
//
//
// class USESlotData;
//
//
// /////////////////////////////////////////////////////
// // FSETask_SerializeSavers
// // 序列化所有当前注册的Saver
// class FSETask_SerializeSavers : public FSETask
// {
// 	const TArray<USESaverBase*>* const Savers;
// 	TArray<FSEObjectRecord> SaverRecords;
//
//
// public:
// 	FSETask_SerializeSavers(const UWorld* World, USESlotData* SlotData,
// 	                        const TArray<USESaverBase*>* const InSavers,TArray<FSEObjectRecord> InSaverRecords, const FSELevelFilter& Filter)
// 		: FSETask(false, World, SlotData, Filter)
// 		  , Savers(InSavers)
// 		  , SaverRecords{InSaverRecords}
// 	{
// 	}
//
// 	void DoWork();
//
// 	FSEObjectRecord& FindSaverRecord(const USESaverBase* Saver);
//
// 	/** 
// 	 * 在任务完成后被调用，用于取回任务相关的结果。
// 	 */
// 	void DumpData()
// 	{
// 		// Shrink not needed. Move wont keep reserved space
// 		SlotData->SaverRecords = MoveTemp(SaverRecords);
// 	}
//
// 	FORCEINLINE TStatId GetStatId() const
// 	{
// 		RETURN_QUICK_DECLARE_CYCLE_STAT(FSETask_SerializeSavers, STATGROUP_ThreadPoolAsyncTasks);
// 	}
// private:
// 	/** Serializes an saver into this Object Record */
// 	bool SerializeSaver(const USESaverBase* Saver, FSEObjectRecord& Record) const;
// };
