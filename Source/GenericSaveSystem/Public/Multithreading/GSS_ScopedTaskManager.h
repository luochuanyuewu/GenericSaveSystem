// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#pragma once

#include "Async/AsyncWork.h"

class IGSS_TaskHolder
{
public:
	virtual bool Tick() = 0;
	virtual void Cancel(bool bFinishSynchronously) = 0;
	virtual ~IGSS_TaskHolder() { }
};

//一个任务Holder持有一个TaskType类型的任务
template <class TaskType>
class FGSS_TaskHolder : public FAsyncTask<TaskType>, public IGSS_TaskHolder
{
	using Super = FAsyncTask<TaskType>;

public:
	DECLARE_EVENT_OneParam(FGSS_TaskHolder<TaskType>, FFinishedEvent, FGSS_TaskHolder<TaskType>&);

	bool bNotified = false;
	FFinishedEvent _OnFinished;

	FGSS_TaskHolder()
		: IGSS_TaskHolder()
		, Super() { }

	virtual ~FGSS_TaskHolder() { }

	template <typename... ArgTypes>
	FGSS_TaskHolder(ArgTypes&&... CtrArgs)
		: Super(Forward<ArgTypes>(CtrArgs)...)
		, IGSS_TaskHolder() { }

	//传入一个签名为 void(FGSS_TaskHolder<TaskType>&)的函数.
	auto& BindOnFinished(TFunction<void(FGSS_TaskHolder<TaskType>&)> Delegate)
	{
		_OnFinished.AddLambda(Delegate);
		return *this;
	}

	/**
	 * @brief 判断任务是否完成，完成则触发通知并返回真，否则返回假。
	 */
	virtual bool Tick() override
	{
		if (Super::IsDone())
		{
			TryNotifyFinish();
			return true;
		}
		return false;
	}

	virtual void Cancel(bool bFinishSynchronously) override
	{
		if (!Super::IsIdle())
		{
			Super::EnsureCompletion(bFinishSynchronously);
			TryNotifyFinish();
		}
		else if (Super::IsDone())
		{
			TryNotifyFinish();
		}
	}

	TaskType* operator->()
	{
		return &Super::GetTask();
	}

private:
	void TryNotifyFinish()
	{
		if (!bNotified)
		{
			_OnFinished.Broadcast(*this);
			bNotified = true;
		}
	}
};

/** Manages the lifetime of many multi-threaded tasks 几种管理多个多线程任务的生命周期。 */
class FGSS_ScopedTaskList
{
	/** 当前执行中的任务 */
	TArray<TUniquePtr<IGSS_TaskHolder>> Tasks;

public:
	FGSS_ScopedTaskList() { }

	template <class TaskType, typename... ArgTypes>
	inline FGSS_TaskHolder<TaskType>& CreateTask(ArgTypes&&... CtrArgs)
	{
		auto NewTask = MakeUnique<FGSS_TaskHolder<TaskType>>(Forward<ArgTypes>(CtrArgs)...);
		auto* TaskPtr = NewTask.Get();
		Tasks.Add(MoveTemp(NewTask));
		return *TaskPtr;
	}

	/** 对所有任务Tick一次，并移除其中已经完成的任务。*/
	void Tick()
	{
		Tasks.RemoveAllSwap([](auto& Task) { return Task->Tick(); });
	}

	/** 取消所有任务的执行. */
	void CancelAll()
	{
		for (auto& Task : Tasks)
		{
			Task->Cancel(true);
		}
		Tasks.Empty();
	}
};
