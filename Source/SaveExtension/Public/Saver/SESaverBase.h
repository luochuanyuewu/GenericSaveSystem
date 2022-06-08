// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Serialization/SERecords.h"
#include "SESaverBase.generated.h"


class USESaveManager;
UCLASS(Abstract,ClassGroup=(SaveExtension), meta=(BlueprintSpawnableComponent))
class SAVEEXTENSION_API USESaverBase : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USESaverBase();


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 SavePriority = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 LoadPriority = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString SaveKey;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bSaveOnQuit = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bLoadOnBeginPlay = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bSaveOnEndPlay = true;

	virtual void SaveData();
	virtual void LoadData();

	virtual FString GetFullKey() const;

protected:

	virtual FString SerializeSaveData();

	virtual void DeserializeAndLoadSaveData(const FString& SerializedSaveData);

	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	USESaveManager* GetManager();
};
