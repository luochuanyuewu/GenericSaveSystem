// Copyright 2015-2020 Piperift. All Rights Reserved.

#include "SELifetimeComponent.h"
#include "Serialization/SETask.h"


USELifetimeComponent::USELifetimeComponent()
	: Super()
{}

void USELifetimeComponent::BeginPlay()
{
	Super::BeginPlay();
	if (USESaveManager* Manager = GetManager())
	{
		Manager->SubscribeForEvents(this);

		// If manager is loading, it has probably manually created
		// this actor and its not a natural start
		if (!Manager->IsLoading())
		{
			Start.Broadcast();
		}
	}
	else
	{
		UE_LOG(LogSaveExtension, Error, TEXT("LifetimeComponent couldnt find a SaveManager. It will do nothing."))
	}
}

void USELifetimeComponent::EndPlay(EEndPlayReason::Type Reason)
{
	if (USESaveManager* Manager = GetManager())
	{
		// If manager is loading, it has probably manually destroyed
		// this actor and its not a natural destroy
		if (!Manager->IsLoading())
		{
			Finish.Broadcast();
		}

		Manager->UnsubscribeFromEvents(this);
	}

	Super::EndPlay(Reason);
}

void USELifetimeComponent::OnSaveBegan(const FSELevelFilter& Filter)
{
	if (Filter.ShouldSave(GetOwner()))
	{
		Saved.Broadcast();
	}
}

void USELifetimeComponent::OnLoadFinished(const FSELevelFilter& Filter, bool bError)
{
	if (Filter.ShouldSave(GetOwner()))
	{
		Resume.Broadcast();
	}
}
