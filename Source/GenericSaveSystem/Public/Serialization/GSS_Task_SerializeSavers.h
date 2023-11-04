// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#pragma once

#include "GSS_AsyncTask.h"
#include "GSS_Records.h"

class UGSS_SaverBase;
class UGSS_SlotData;


// FGSS_Task_SerializeSavers
// 序列化所有当前注册的Saver
class FGSS_Task_SerializeSavers : public FGSS_AsyncTask
{

	const TArray<UGSS_SaverBase*>* const Savers;
	TArray<FGSS_ObjectRecord> SaverRecords;

public:
	FGSS_Task_SerializeSavers(const UWorld* World, UGSS_SlotData* SlotData,
	                        const TArray<UGSS_SaverBase*>* const InSavers,TArray<FGSS_ObjectRecord> InSaverRecords)
		: FGSS_AsyncTask(false, World, SlotData)
		  , Savers(InSavers)
		  , SaverRecords{InSaverRecords}
	{
	}

	void DoWork();

	FGSS_ObjectRecord& FindSaverRecord(const UGSS_SaverBase* Saver);

	/** 
	 * 在任务完成后被调用，用于取回任务相关的结果。
	 */
	void DumpData();

	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(FSETask_SerializeSavers, STATGROUP_ThreadPoolAsyncTasks);
	}
private:
	/** Serializes an saver into this Object Record */
	bool SerializeSaver(const UGSS_SaverBase* Saver, FGSS_ObjectRecord& Record) const;
};
