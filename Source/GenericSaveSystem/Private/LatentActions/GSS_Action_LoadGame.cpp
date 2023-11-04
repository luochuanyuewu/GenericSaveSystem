// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#include "LatentActions/GSS_Action_LoadGame.h"
#include "GSS_SaveSubsystem.h"
#include "Serialization/GSS_SlotDataTask_Loader.h"
#include "GSS_SlotInfo.h"


FGSS_Action_LoadGame::FGSS_Action_LoadGame(UGSS_SaveSubsystem* Manager, FName SlotName, EGSS_LoadGameResult& OutResult, const FLatentActionInfo& LatentInfo)
	: Result(OutResult)
	, ExecutionFunction(LatentInfo.ExecutionFunction)
	, OutputLink(LatentInfo.Linkage)
	, CallbackTarget(LatentInfo.CallbackTarget)
{
	const bool bStarted = Manager->LoadSlot(SlotName, FGSS_OnGameLoadedSignature::CreateRaw(this, &FGSS_Action_LoadGame::OnLoadFinished));
	if (!bStarted)
	{
		Result = EGSS_LoadGameResult::Failed;
	}
}

void FGSS_Action_LoadGame::UpdateOperation(FLatentResponse& Response)
{
	Response.FinishAndTriggerIf(Result != EGSS_LoadGameResult::Loading, ExecutionFunction, OutputLink, CallbackTarget);
}

void FGSS_Action_LoadGame::OnLoadFinished(UGSS_SlotInfo* SavedSlot)
{
	Result = SavedSlot ? EGSS_LoadGameResult::Continue : EGSS_LoadGameResult::Failed;
}
