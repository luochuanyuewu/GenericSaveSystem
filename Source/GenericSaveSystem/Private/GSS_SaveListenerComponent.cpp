// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#include "GSS_SaveListenerComponent.h"

#include "GSS_SaveSubsystem.h"
#include "Serialization/GSS_AsyncTask.h"


UGSS_SaveListenerComponent::UGSS_SaveListenerComponent()
	: Super()
{}

void UGSS_SaveListenerComponent::BeginPlay()
{
	Super::BeginPlay();
	if (UGSS_SaveSubsystem* Manager = GetManager())
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
		UE_LOG(LogGenericSaveSystem, Error, TEXT("LifetimeComponent couldnt find a SaveManager. It will do nothing."))
	}
}

void UGSS_SaveListenerComponent::EndPlay(EEndPlayReason::Type Reason)
{
	if (UGSS_SaveSubsystem* Manager = GetManager())
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

void UGSS_SaveListenerComponent::OnSaveBegan()
{
	if (UGSS_SaveFilter::ShouldSave(GetOwner()))
	{
		Saved.Broadcast();
	}
}

void UGSS_SaveListenerComponent::OnLoadFinished(bool bError)
{
	if (UGSS_SaveFilter::ShouldSave(GetOwner()))
	{
		Resume.Broadcast();
	}
}

UGSS_SaveSubsystem* UGSS_SaveListenerComponent::GetManager() const
{
	return UGSS_SaveSubsystem::Get(GetWorld());
}
