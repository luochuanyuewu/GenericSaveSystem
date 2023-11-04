// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#include "LatentActions/GSS_Action_LoadInfos.h"
#include "GSS_SaveSubsystem.h"
#include "GSS_SlotInfo.h"


FGSS_Action_LoadInfos::FGSS_Action_LoadInfos(UGSS_SaveSubsystem* Manager, const bool bSortByRecent, TArray<UGSS_SlotInfo*>& InSlotInfos, EGSS_LoadInfoResult& OutResult, const FLatentActionInfo& LatentInfo)
	: Result(OutResult)
	, SlotInfos(InSlotInfos)
	, bFinished(false)
	, ExecutionFunction(LatentInfo.ExecutionFunction)
	, OutputLink(LatentInfo.Linkage)
	, CallbackTarget(LatentInfo.CallbackTarget)
{
	Manager->LoadAllSlotInfos(bSortByRecent, FGSS_OnSlotInfosLoadedSignature::CreateLambda([this](const TArray<UGSS_SlotInfo*>& Results) {
		SlotInfos = Results;
		bFinished = true;
	}));
}

void FGSS_Action_LoadInfos::UpdateOperation(FLatentResponse& Response)
{
	Response.FinishAndTriggerIf(bFinished, ExecutionFunction, OutputLink, CallbackTarget);

}
