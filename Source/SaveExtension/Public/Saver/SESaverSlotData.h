// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SESlotData.h"
#include "UObject/Object.h"
#include "SESaverSlotData.generated.h"

/**
 * 
 */
UCLASS()
class SAVEEXTENSION_API USESaverSlotData : public USESlotData
{
	GENERATED_BODY()
public:
	TMap<FString, FString> DataRecords;

	virtual void Serialize(FArchive& Ar) override;
};
