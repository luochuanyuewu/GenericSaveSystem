// Copyright 2015-2020 Piperift. All Rights Reserved.

#include "LatentActions/SEAction_LoadInfos.h"
#include "SESaveManager.h"
#include "SESlotInfo.h"


FSEAction_LoadInfos::FSEAction_LoadInfos(USESaveManager* Manager, const bool bSortByRecent, TArray<USESlotInfo*>& InSlotInfos, ESELoadInfoResult& OutResult, const FLatentActionInfo& LatentInfo)
	: Result(OutResult)
	, SlotInfos(InSlotInfos)
	, bFinished(false)
	, ExecutionFunction(LatentInfo.ExecutionFunction)
	, OutputLink(LatentInfo.Linkage)
	, CallbackTarget(LatentInfo.CallbackTarget)
{
	Manager->LoadAllSlotInfos(bSortByRecent, FOnSESlotInfosLoaded::CreateLambda([this](const TArray<USESlotInfo*>& Results) {
		SlotInfos = Results;
		bFinished = true;
	}));
}

void FSEAction_LoadInfos::UpdateOperation(FLatentResponse& Response)
{
	Response.FinishAndTriggerIf(bFinished, ExecutionFunction, OutputLink, CallbackTarget);

}
