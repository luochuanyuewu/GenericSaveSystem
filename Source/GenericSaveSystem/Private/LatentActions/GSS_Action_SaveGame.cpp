// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#include "LatentActions/GSS_Action_SaveGame.h"
#include "GSS_SaveSubsystem.h"
#include "GSS_SlotInfo.h"


FGSS_Action_SaveGame::FGSS_Action_SaveGame(UGSS_SaveSubsystem* Manager, FName SlotName, bool bOverrideIfNeeded, bool bScreenshot, const FSEScreenshotSize Size, EGSS_SaveGameResult& OutResult, const FLatentActionInfo& LatentInfo)
	: Result(OutResult)
	, ExecutionFunction(LatentInfo.ExecutionFunction)
	, OutputLink(LatentInfo.Linkage)
	, CallbackTarget(LatentInfo.CallbackTarget)
{
	const bool bStarted = Manager->SaveSlot(SlotName, bOverrideIfNeeded, bScreenshot, Size, FGSS_OnGameSavedSignature::CreateRaw(this, &FGSS_Action_SaveGame::OnSaveFinished));

	if (!bStarted)
	{
		Result = EGSS_SaveGameResult::Failed;
	}
}

void FGSS_Action_SaveGame::UpdateOperation(FLatentResponse& Response)
{
	Response.FinishAndTriggerIf(Result != EGSS_SaveGameResult::Saving, ExecutionFunction, OutputLink, CallbackTarget);
}

void FGSS_Action_SaveGame::OnSaveFinished(UGSS_SlotInfo* SavedSlot)
{
	Result = SavedSlot ? EGSS_SaveGameResult::Continue : EGSS_SaveGameResult::Failed;
}
