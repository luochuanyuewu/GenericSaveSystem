// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

#include "Multithreading/GSS_Task_LoadSlotInfos.h"


class UGSS_SaveSubsystem;
class UGSS_SlotInfo;

/**
 * Enum used to indicate quote execution results
 */
UENUM()
enum class EGSS_LoadInfoResult : uint8
{
	Completed
};

/** FGSS_Action_LoadInfos */
class FGSS_Action_LoadInfos : public FPendingLatentAction
{

public:
	EGSS_LoadInfoResult& Result;

	TArray<UGSS_SlotInfo*>& SlotInfos;
	bool bFinished;

	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;


	/**
	 * @param SlotId will load that Saved Game if Id > 0, otherwise it will load all infos
	 */
	FGSS_Action_LoadInfos(UGSS_SaveSubsystem* Manager, const bool bSortByRecent, TArray<UGSS_SlotInfo*>& SaveInfos, EGSS_LoadInfoResult& OutResult, const FLatentActionInfo& LatentInfo);

	virtual void UpdateOperation(FLatentResponse& Response) override;

#if WITH_EDITOR
	virtual FString GetDescription() const override
	{
		return TEXT("Loading all infos...");
	}
#endif
};
