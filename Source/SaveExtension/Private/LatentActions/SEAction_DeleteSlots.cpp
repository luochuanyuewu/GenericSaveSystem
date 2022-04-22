// Copyright 2015-2020 Piperift. All Rights Reserved.

#include "LatentActions/SEAction_DeleteSlots.h"

#include "SESaveManager.h"
#include "SESlotInfo.h"


FSEAction_DeleteSlots::FSEAction_DeleteSlots(USESaveManager* Manager, ESEDeleteSlotsResult& OutResult, const FLatentActionInfo& LatentInfo)
	: Result(OutResult)
	, bFinished(false)
	, ExecutionFunction(LatentInfo.ExecutionFunction)
	, OutputLink(LatentInfo.Linkage)
	, CallbackTarget(LatentInfo.CallbackTarget)
{
	Manager->DeleteAllSlots(FOnSlotsDeleted::CreateLambda([this]() {
		bFinished = true;
	}));
}

void FSEAction_DeleteSlots::UpdateOperation(FLatentResponse& Response)
{
	Response.FinishAndTriggerIf(bFinished, ExecutionFunction, OutputLink, CallbackTarget);
}
