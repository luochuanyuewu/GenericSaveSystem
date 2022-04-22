// Copyright 2015-2020 Piperift. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"


class USESaveManager;
class USESlotInfo;
struct FScreenshotSize;

/**
 * Enum used to indicate quote execution results
 */
UENUM()
enum class ESESaveGameResult : uint8
{
	Saving UMETA(Hidden),
	Continue,
	Failed
};

/** FSEAction_SaveGame */
class FSEAction_SaveGame : public FPendingLatentAction
{
public:
	ESESaveGameResult& Result;

	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;


	FSEAction_SaveGame(USESaveManager* Manager, FName SlotName, bool bOverrideIfNeeded, bool bScreenshot, const FScreenshotSize Size, ESESaveGameResult& OutResult,
		const FLatentActionInfo& LatentInfo);

	virtual void UpdateOperation(FLatentResponse& Response) override;

	void OnSaveFinished(USESlotInfo* SavedSlot);

#if WITH_EDITOR
	// Returns a human readable description of the latent operation's current state
	virtual FString GetDescription() const override
	{
		return TEXT("Saving Game...");
	}
#endif
};
