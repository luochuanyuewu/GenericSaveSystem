// Copyright 2015-2020 Piperift. All Rights Reserved.

#pragma once

#include "Async/AsyncWork.h"

class ISETaskHolder
{
public:
	virtual bool Tick() = 0;
	virtual void Cancel(bool bFinishSynchronously) = 0;
	virtual ~ISETaskHolder() { }
};

//一个任务Holder持有一个TaskType类型的任务
template <class TaskType>
class FSETaskHolder : public FAsyncTask<TaskType>, public ISETaskHolder
{
	using Super = FAsyncTask<TaskType>;

public:
	DECLARE_EVENT_OneParam(FSETaskHolder<TaskType>, FFinishedEvent, FSETaskHolder<TaskType>&);

	bool bNotified = false;
	FFinishedEvent _OnFinished;

	FSETaskHolder()
		: ISETaskHolder()
		, Super() { }

	virtual ~FSETaskHolder() { }

	template <typename... ArgTypes>
	FSETaskHolder(ArgTypes&&... CtrArgs)
		: Super(Forward<ArgTypes>(CtrArgs)...)
		, ISETaskHolder() { }

	//传入一个签名为 void(FSETaskHolder<TaskType>&)的函数.
	auto& BindOnFinished(TFunction<void(FSETaskHolder<TaskType>&)> Delegate)
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
class FSEScopedTaskList
{
	/** 当前执行中的任务 */
	TArray<TUniquePtr<ISETaskHolder>> Tasks;

public:
	FSEScopedTaskList() { }

	template <class TaskType, typename... ArgTypes>
	inline FSETaskHolder<TaskType>& CreateTask(ArgTypes&&... CtrArgs)
	{
		auto NewTask = MakeUnique<FSETaskHolder<TaskType>>(Forward<ArgTypes>(CtrArgs)...);
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
