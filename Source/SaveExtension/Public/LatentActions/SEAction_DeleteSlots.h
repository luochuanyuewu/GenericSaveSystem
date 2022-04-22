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
enum class ESEDeleteSlotsResult : uint8
{
	Completed
};

/** FSEAction_DeleteSlots */
class FSEAction_DeleteSlots : public FPendingLatentAction
{
public:
	ESEDeleteSlotsResult& Result;

	bool bFinished;

	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;


	/**
	 * @param SlotId will load that Saved Game if Id > 0, otherwise it will load all infos
	 */
	FSEAction_DeleteSlots(USESaveManager* Manager, ESEDeleteSlotsResult& OutResult, const FLatentActionInfo& LatentInfo);

	virtual void UpdateOperation(FLatentResponse& Response) override;

#if WITH_EDITOR
	// Returns a human readable description of the latent operation's current state
	virtual FString GetDescription() const override
	{
		return TEXT("Deleting all slots...");
	}
#endif
};
