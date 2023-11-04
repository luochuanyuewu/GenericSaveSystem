// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GSS_SaveInterface.h"
#include "GSS_SaveListenerComponent.generated.h"



DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSELifetimeStartSignature);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSELifetimeSavedSignature);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSELifetimeResumeSignature);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSELifetimeFinishSignature);


/**
 * Controls the complete saving and loading process
 */
UCLASS(BlueprintType, ClassGroup = GenericSaveSystem, meta = (BlueprintSpawnableComponent))
class GENERICSAVESYSTEM_API UGSS_SaveListenerComponent : public UActorComponent, public IGSS_SaveInterface
{
	GENERATED_BODY()

	/************************************************************************/
	/* METHODS											     			    */
	/************************************************************************/
public:

	UGSS_SaveListenerComponent();

	virtual void BeginPlay() override;
	virtual void EndPlay(EEndPlayReason::Type Reason) override;


	// Event called when Save process starts
	virtual void OnSaveBegan() override;

	// Event called when Load process ends
	virtual void OnLoadFinished(bool bError);


	UGSS_SaveSubsystem* GetManager() const;



	/***********************************************************************/
	/* EVENTS															   */
	/***********************************************************************/
protected:

	// Called once when this actor gets created for the first time. Similar to BeginPlay
	UPROPERTY(BlueprintAssignable, Category = "GenericSaveSystem")
	FSELifetimeStartSignature Start;

	// Called when game is saved
	UPROPERTY(BlueprintAssignable, Category = "GenericSaveSystem")
	FSELifetimeSavedSignature Saved;

	// Called when game loaded
	UPROPERTY(BlueprintAssignable, Category = "GenericSaveSystem")
	FSELifetimeResumeSignature Resume;

	// Called when this actor gets destroyed for ever
	UPROPERTY(BlueprintAssignable, Category = "GenericSaveSystem")
	FSELifetimeFinishSignature Finish;


public:

	FSELifetimeStartSignature& OnStart() { return Start; }
	FSELifetimeSavedSignature& OnSaved() { return Saved; }
	FSELifetimeResumeSignature& OnResume() { return Resume; }
	FSELifetimeFinishSignature& OnFinish() { return Finish; }
};
