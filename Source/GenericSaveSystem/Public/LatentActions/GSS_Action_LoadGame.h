// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"


class UGSS_SaveSubsystem;
class UGSS_SlotInfo;

/**
 * Enum used to indicate quote execution results
 */
UENUM()
enum class EGSS_LoadGameResult : uint8
{
	Loading UMETA(Hidden),
	Continue,
	Failed
};

/** FGSS_Action_LoadGame */
class FGSS_Action_LoadGame : public FPendingLatentAction
{
public:
	EGSS_LoadGameResult& Result;

	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;


	FGSS_Action_LoadGame(UGSS_SaveSubsystem* Manager, FName SlotName, EGSS_LoadGameResult& Result, const FLatentActionInfo& LatentInfo);

	virtual void UpdateOperation(FLatentResponse& Response) override;

	void OnLoadFinished(UGSS_SlotInfo* SavedSlot);

#if WITH_EDITOR
	// Returns a human readable description of the latent operation's current state
	virtual FString GetDescription() const override
	{
		return TEXT("Loading Game...");
	}
#endif
};
