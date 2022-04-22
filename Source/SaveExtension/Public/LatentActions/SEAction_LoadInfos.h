// Copyright 2015-2020 Piperift. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

#include "Multithreading/SETask_LoadSlotInfos.h"


class USESaveManager;
class USESlotInfo;

/**
 * Enum used to indicate quote execution results
 */
UENUM()
enum class ESELoadInfoResult : uint8
{
	Completed
};

/** FSEAction_LoadInfos */
class FSEAction_LoadInfos : public FPendingLatentAction
{

public:
	ESELoadInfoResult& Result;

	TArray<USESlotInfo*>& SlotInfos;
	bool bFinished;

	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;


	/**
	 * @param SlotId will load that Saved Game if Id > 0, otherwise it will load all infos
	 */
	FSEAction_LoadInfos(USESaveManager* Manager, const bool bSortByRecent, TArray<USESlotInfo*>& SaveInfos, ESELoadInfoResult& OutResult, const FLatentActionInfo& LatentInfo);

	virtual void UpdateOperation(FLatentResponse& Response) override;

#if WITH_EDITOR
	virtual FString GetDescription() const override
	{
		return TEXT("Loading all infos...");
	}
#endif
};
