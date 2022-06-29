// Fill out your copyright notice in the Description page of Project Settings.


#include "SESaveManager.h"
#include "Saver/SESaverSlotData.h"


void USESaveManager::RegisterSaver(USESaverBase* Saver)
{
	for (int i = 0; i < Savers.Num(); i++)
	{
		if (Savers[i]->GetFullKey() != Saver->GetFullKey()) { continue; }

		if (Savers[i] != Saver)
		{
			SELog(GetPreset(),TEXT("Saver won't be registered because one with the same key is already registered"));
		}
		return;
	}
	Savers.Add(Saver);
}

void USESaveManager::UnregisterSaver(USESaverBase* Saver)
{
	Savers.Remove(Saver);
}


void USESaveManager::SaveAllSavers()
{
	OrderSaversByPriority(true);
	for (int32 i = 0; i < Savers.Num(); i++)
	{
		Savers[i]->SaveData();
	}
}

void USESaveManager::LoadAllSavers()
{
	OrderSaversByPriority(false);
	for (int32 i = 0; i < Savers.Num(); i++)
	{
		Savers[i]->LoadData();
	}
}


bool USESaveManager::TryGetSaverDataV2(const FName& Key, TArray<uint8>& SerializedData)
{
	if (USESlotData* SlotData = GetCurrentData())
	{
		FSEObjectRecord* Record;
		if (SlotData->FindSaverRecord(Key, Record))
		{
			SerializedData = Record->Data;
			return true;
		}
	}
	return false;
}

void USESaveManager::AddToSaverDataV2(const FName& Key, const TArray<uint8>& SerializedData)
{
	if (USESlotData* SlotData = GetCurrentData())
	{
		FSEObjectRecord* Record;
		if (SlotData->FindSaverRecord(Key, Record))
		{
			Record->Data = SerializedData;
		}
		else
		{
			FSEObjectRecord NewRecord;
			NewRecord.Class = USESaverBase::StaticClass();
			// NewRecord.Class = Saver->GetClass();
			NewRecord.Data = SerializedData;
			NewRecord.Name = FName(Key);
			SlotData->SaverRecords.Add(NewRecord);
		}
	}
}


void USESaveManager::IterateSavers(TFunction<void(UObject*)>&& Callback)
{
	for (USESaverBase* Saver : Savers)
	{
		Callback(Saver);
	}
}

USESaveManager* USESaveManager::Get(const UObject* ContextObject)
{
	UWorld* World = GEngine->GetWorldFromContextObject(ContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (World)
	{
		return UGameInstance::GetSubsystem<USESaveManager>(World->GetGameInstance());
	}
	return nullptr;
}


void USESaveManager::OrderSaversByPriority(bool SavePriority)
{
	if (SavePriority)
	{
		Savers.Sort([](const USESaverBase& A, const USESaverBase& B)
		{
			return A.SavePriority > B.SavePriority;
		});
	}
	else
	{
		Savers.Sort([](const USESaverBase& A, const USESaverBase& B)
		{
			return A.LoadPriority > B.LoadPriority;
		});
	}
}

TArray<USESaverBase*>& USESaveManager::GetSavers()
{
	return Savers;
}
