// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"


class UGSS_SaveSubsystem;
class UGSS_SlotInfo;
struct FSEScreenshotSize;

/**
 * Enum used to indicate quote execution results
 */
UENUM()
enum class EGSS_SaveGameResult : uint8
{
	Saving UMETA(Hidden),
	Continue,
	Failed
};

/** FGSS_Action_SaveGame */
class FGSS_Action_SaveGame : public FPendingLatentAction
{
public:
	EGSS_SaveGameResult& Result;

	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;


	FGSS_Action_SaveGame(UGSS_SaveSubsystem* Manager, FName SlotName, bool bOverrideIfNeeded, bool bScreenshot, const FSEScreenshotSize Size, EGSS_SaveGameResult& OutResult,
		const FLatentActionInfo& LatentInfo);

	virtual void UpdateOperation(FLatentResponse& Response) override;

	void OnSaveFinished(UGSS_SlotInfo* SavedSlot);

#if WITH_EDITOR
	// Returns a human readable description of the latent operation's current state
	virtual FString GetDescription() const override
	{
		return TEXT("Saving Game...");
	}
#endif
};
