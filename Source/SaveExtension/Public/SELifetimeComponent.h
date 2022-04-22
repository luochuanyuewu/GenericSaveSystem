// Copyright 2015-2020 Piperift. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SESaveInterface.h"
#include "SESaveManager.h"

#include "SELifetimeComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSELifetimeStartSignature);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSELifetimeSavedSignature);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSELifetimeResumeSignature);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSELifetimeFinishSignature);



/**
 * Controls the complete saving and loading process
 */
UCLASS(BlueprintType, ClassGroup = SaveExtension, meta = (BlueprintSpawnableComponent))
class SAVEEXTENSION_API USELifetimeComponent : public UActorComponent, public ISESaveInterface
{
	GENERATED_BODY()

	/************************************************************************/
	/* METHODS											     			    */
	/************************************************************************/
public:

	USELifetimeComponent();

	virtual void BeginPlay() override;
	virtual void EndPlay(EEndPlayReason::Type Reason) override;


	// Event called when Save process starts
	virtual void OnSaveBegan(const FSELevelFilter& Filter) override;

	// Event called when Load process ends
	virtual void OnLoadFinished(const FSELevelFilter& Filter, bool bError);


	USESaveManager* GetManager() const
	{
		return USESaveManager::Get(GetWorld());
	}


	/***********************************************************************/
	/* EVENTS															   */
	/***********************************************************************/
protected:

	// Called once when this actor gets created for the first time. Similar to BeginPlay
	UPROPERTY(BlueprintAssignable, Category = SaveExtension)
	FSELifetimeStartSignature Start;

	// Called when game is saved
	UPROPERTY(BlueprintAssignable, Category = SaveExtension)
	FSELifetimeSavedSignature Saved;

	// Called when game loaded
	UPROPERTY(BlueprintAssignable, Category = SaveExtension)
	FSELifetimeResumeSignature Resume;

	// Called when this actor gets destroyed for ever
	UPROPERTY(BlueprintAssignable, Category = SaveExtension)
	FSELifetimeFinishSignature Finish;


public:

	FSELifetimeStartSignature& OnStart() { return Start; }
	FSELifetimeSavedSignature& OnSaved() { return Saved; }
	FSELifetimeResumeSignature& OnResume() { return Resume; }
	FSELifetimeFinishSignature& OnFinish() { return Finish; }
};
