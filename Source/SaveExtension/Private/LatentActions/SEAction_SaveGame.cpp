// Copyright 2015-2020 Piperift. All Rights Reserved.

#include "LatentActions/SEAction_SaveGame.h"
#include "SESaveManager.h"
#include "SESlotInfo.h"


FSEAction_SaveGame::FSEAction_SaveGame(USESaveManager* Manager, FName SlotName, bool bOverrideIfNeeded, bool bScreenshot, const FSEScreenshotSize Size, ESESaveGameResult& OutResult, const FLatentActionInfo& LatentInfo)
	: Result(OutResult)
	, ExecutionFunction(LatentInfo.ExecutionFunction)
	, OutputLink(LatentInfo.Linkage)
	, CallbackTarget(LatentInfo.CallbackTarget)
{
	const bool bStarted = Manager->SaveSlot(SlotName, bOverrideIfNeeded, bScreenshot, Size, FOnSEGameSaved::CreateRaw(this, &FSEAction_SaveGame::OnSaveFinished));

	if (!bStarted)
	{
		Result = ESESaveGameResult::Failed;
	}
}

void FSEAction_SaveGame::UpdateOperation(FLatentResponse& Response)
{
	Response.FinishAndTriggerIf(Result != ESESaveGameResult::Saving, ExecutionFunction, OutputLink, CallbackTarget);
}

void FSEAction_SaveGame::OnSaveFinished(USESlotInfo* SavedSlot)
{
	Result = SavedSlot ? ESESaveGameResult::Continue : ESESaveGameResult::Failed;
}
