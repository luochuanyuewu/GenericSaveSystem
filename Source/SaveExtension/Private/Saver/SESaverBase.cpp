// Fill out your copyright notice in the Description page of Project Settings.


#include "Saver/SESaverBase.h"

#include "SESaveManager.h"
#include "Saver/SESaverSlotData.h"


// Sets default values for this component's properties
USESaverBase::USESaverBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


void USESaverBase::SaveData()
{
	if (USESaverSlotData* SlotData = Cast<USESaverSlotData>(GetManager()->GetCurrentData()))
	{
		SlotData->DataRecords[GetFullKey()] = SerializeSaveData();
	}
}

void USESaverBase::LoadData()
{
	if (USESaverSlotData* SlotData = Cast<USESaverSlotData>(GetManager()->GetCurrentData()))
	{
		if (SlotData->DataRecords.Contains(GetFullKey()))
		{
			DeserializeAndLoadSaveData(SlotData->DataRecords[GetFullKey()]);
		}
	}
}


FString USESaverBase::SerializeSaveData()
{
	return TEXT("");
}

void USESaverBase::DeserializeAndLoadSaveData(const FString& SerializedSaveData) { }

FString USESaverBase::GetFullKey() const
{
	return FString::Format(TEXT("{0}_{1}_{2}"), {GetName(), GetClass()->GetName(), SaveKey});
}

void USESaverBase::BeginPlay()
{
	GetManager()->RegisterSaver(this);
	Super::BeginPlay();
	if (bLoadOnBeginPlay)
	{
		LoadData();
	}
}

void USESaverBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	if (USESaveManager* Manager = GetManager())
	{
		if (bSaveOnEndPlay)
			SaveData();
		Manager->UnregisterSaver(this);
	}
}

USESaveManager* USESaverBase::GetManager()
{
	return GetWorld()->GetGameInstance()->GetSubsystem<USESaveManager>();
}
