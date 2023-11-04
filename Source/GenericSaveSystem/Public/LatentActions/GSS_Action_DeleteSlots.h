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
enum class EGSS_DeleteSlotsResult : uint8
{
	Completed
};

/** FGSS_Action_DeleteSlots */
class FGSS_Action_DeleteSlots : public FPendingLatentAction
{
public:
	EGSS_DeleteSlotsResult& Result;

	bool bFinished;

	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;


	/**
	 * @param SlotId will load that Saved Game if Id > 0, otherwise it will load all infos
	 */
	FGSS_Action_DeleteSlots(UGSS_SaveSubsystem* Manager, EGSS_DeleteSlotsResult& OutResult, const FLatentActionInfo& LatentInfo);

	virtual void UpdateOperation(FLatentResponse& Response) override;

#if WITH_EDITOR
	// Returns a human readable description of the latent operation's current state
	virtual FString GetDescription() const override
	{
		return TEXT("Deleting all slots...");
	}
#endif
};
