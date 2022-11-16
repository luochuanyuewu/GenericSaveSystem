// Fill out your copyright notice in the Description page of Project Settings.


#include "SESaveManager.h"


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


void USESaveManager::OrderSaversByPriority(bool SavePriority)
{
	if (SavePriority)
	{
		Savers.Sort([](const USESaverBase& A, const USESaverBase& B)
		{
			return A.GetSavePriority() > B.GetSavePriority();
		});
	}
	else
	{
		Savers.Sort([](const USESaverBase& A, const USESaverBase& B)
		{
			return A.GetLoadPriority() > B.GetLoadPriority();
		});
	}
}

TArray<USESaverBase*>& USESaveManager::GetSavers()
{
	return Savers;
}
