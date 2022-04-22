// Copyright 2015-2020 Piperift. All Rights Reserved.

#pragma once

#include "Async/AsyncWork.h"

class ISETaskHolder
{
public:
	virtual bool Tick() = 0;
	virtual void Cancel(bool bFinishSynchronously) = 0;
	virtual ~ISETaskHolder()
	{
	}
};

template <class TaskType>
class FSETaskHolder : public FAsyncTask<TaskType>, public ISETaskHolder
{
	using Super = FAsyncTask<TaskType>;

public:
	DECLARE_EVENT_OneParam(FSETaskHolder<TaskType>, FFinishedEvent, FSETaskHolder<TaskType>&);

	bool bNotified = false;
	FFinishedEvent _OnFinished;

	FSETaskHolder() : ISETaskHolder(), Super()
	{
	}
	virtual ~FSETaskHolder()
	{
	}

	template <typename... ArgTypes>
	FSETaskHolder(ArgTypes&&... CtrArgs) : Super(Forward<ArgTypes>(CtrArgs)...), ISETaskHolder()
	{
	}

	auto& OnFinished(TFunction<void(FSETaskHolder<TaskType>&)> Delegate)
	{
		_OnFinished.AddLambda(Delegate);
		return *this;
	}

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

/** Manages the lifetime of many multi-threaded tasks */
class FSEScopedTaskList
{
	TArray<TUniquePtr<ISETaskHolder>> Tasks;

public:
	FSEScopedTaskList()
	{
	}

	template <class TaskType, typename... ArgTypes>
	inline FSETaskHolder<TaskType>& CreateTask(ArgTypes&&... CtrArgs)
	{
		auto NewTask = MakeUnique<FSETaskHolder<TaskType>>(Forward<ArgTypes>(CtrArgs)...);
		auto* TaskPtr = NewTask.Get();
		Tasks.Add(MoveTemp(NewTask));
		return *TaskPtr;
	}

	void Tick()
	{
		// Tick all running tasks and remove the ones that finished
		Tasks.RemoveAllSwap([](auto& Task) { return Task->Tick(); });
	}

	void CancelAll()
	{
		for (auto& Task : Tasks)
		{
			Task->Cancel(true);
		}
		Tasks.Empty();
	}
};
