// Copyright 2015-2020 Piperift. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"


class USESaveManager;
class USESlotInfo;

/**
 * Enum used to indicate quote execution results
 */
UENUM()
enum class ESELoadGameResult : uint8
{
	Loading UMETA(Hidden),
	Continue,
	Failed
};

/** FSEAction_LoadGame */
class FSEAction_LoadGame : public FPendingLatentAction
{
public:
	ESELoadGameResult& Result;

	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;


	FSEAction_LoadGame(USESaveManager* Manager, FName SlotName, ESELoadGameResult& Result, const FLatentActionInfo& LatentInfo);

	virtual void UpdateOperation(FLatentResponse& Response) override;

	void OnLoadFinished(USESlotInfo* SavedSlot);

#if WITH_EDITOR
	// Returns a human readable description of the latent operation's current state
	virtual FString GetDescription() const override
	{
		return TEXT("Loading Game...");
	}
#endif
};
