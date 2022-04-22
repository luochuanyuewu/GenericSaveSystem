// Copyright 2015-2020 Piperift. All Rights Reserved.

#include "LatentActions/SEAction_LoadGame.h"
#include "SESaveManager.h"
#include "Serialization/SESlotDataTask_Loader.h"
#include "SESlotInfo.h"


FSEAction_LoadGame::FSEAction_LoadGame(USESaveManager* Manager, FName SlotName, ESELoadGameResult& OutResult, const FLatentActionInfo& LatentInfo)
	: Result(OutResult)
	, ExecutionFunction(LatentInfo.ExecutionFunction)
	, OutputLink(LatentInfo.Linkage)
	, CallbackTarget(LatentInfo.CallbackTarget)
{
	const bool bStarted = Manager->LoadSlot(SlotName, FOnSEGameLoaded::CreateRaw(this, &FSEAction_LoadGame::OnLoadFinished));
	if (!bStarted)
	{
		Result = ESELoadGameResult::Failed;
	}
}

void FSEAction_LoadGame::UpdateOperation(FLatentResponse& Response)
{
	Response.FinishAndTriggerIf(Result != ESELoadGameResult::Loading, ExecutionFunction, OutputLink, CallbackTarget);
}

void FSEAction_LoadGame::OnLoadFinished(USESlotInfo* SavedSlot)
{
	Result = SavedSlot ? ESELoadGameResult::Continue : ESELoadGameResult::Failed;
}
