// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#include "LatentActions/GSS_Action_DeleteSlots.h"

#include "GSS_SaveSubsystem.h"
#include "GSS_SlotInfo.h"


FGSS_Action_DeleteSlots::FGSS_Action_DeleteSlots(UGSS_SaveSubsystem* Manager, EGSS_DeleteSlotsResult& OutResult, const FLatentActionInfo& LatentInfo)
	: Result(OutResult)
	, bFinished(false)
	, ExecutionFunction(LatentInfo.ExecutionFunction)
	, OutputLink(LatentInfo.Linkage)
	, CallbackTarget(LatentInfo.CallbackTarget)
{
	Manager->DeleteAllSlots(FGSS_OnSlotsDeletedSignature::CreateLambda([this]() {
		bFinished = true;
	}));
}

void FGSS_Action_DeleteSlots::UpdateOperation(FLatentResponse& Response)
{
	Response.FinishAndTriggerIf(bFinished, ExecutionFunction, OutputLink, CallbackTarget);
}
