// Fill out your copyright notice in the Description page of Project Settings.


#include "GSS_SaveSubsystem.h"


void UGSS_SaveSubsystem::RegisterSaver(UGSS_SaverBase* Saver)
{
	for (int i = 0; i < Savers.Num(); i++)
	{
		if (Savers[i]->GetFullKey() != Saver->GetFullKey()) { continue; }

		if (Savers[i] != Saver)
		{
			GSS_Log(GetPreset(),TEXT("Saver won't be registered because one with the same key is already registered"));
		}
		return;
	}
	Savers.Add(Saver);
}

void UGSS_SaveSubsystem::UnregisterSaver(UGSS_SaverBase* Saver)
{
	Savers.Remove(Saver);
}


void UGSS_SaveSubsystem::SaveAllSavers()
{
	OrderSaversByPriority(true);
	for (int32 i = 0; i < Savers.Num(); i++)
	{
		Savers[i]->SaveData();
	}
}

void UGSS_SaveSubsystem::LoadAllSavers()
{
	OrderSaversByPriority(false);
	for (int32 i = 0; i < Savers.Num(); i++)
	{
		Savers[i]->LoadData();
	}
}


bool UGSS_SaveSubsystem::TryGetSaverDataV2(const FName& Key, TArray<uint8>& SerializedData)
{
	if (UGSS_SlotData* SlotData = GetCurrentData())
	{
		FGSS_ObjectRecord* Record;
		if (SlotData->FindSaverRecord(Key, Record))
		{
			SerializedData = Record->Data;
			return true;
		}
	}
	return false;
}

void UGSS_SaveSubsystem::AddToSaverDataV2(const FName& Key, const TArray<uint8>& SerializedData)
{
	if (UGSS_SlotData* SlotData = GetCurrentData())
	{
		FGSS_ObjectRecord* Record;
		if (SlotData->FindSaverRecord(Key, Record))
		{
			Record->Data = SerializedData;
		}
		else
		{
			FGSS_ObjectRecord NewRecord;
			NewRecord.Class = UGSS_SaverBase::StaticClass();
			// NewRecord.Class = Saver->GetClass();
			NewRecord.Data = SerializedData;
			NewRecord.Name = FName(Key);
			SlotData->SaverRecords.Add(NewRecord);
		}
	}
}


void UGSS_SaveSubsystem::IterateSavers(TFunction<void(UObject*)>&& Callback)
{
	for (UGSS_SaverBase* Saver : Savers)
	{
		Callback(Saver);
	}
}


void UGSS_SaveSubsystem::OrderSaversByPriority(bool SavePriority)
{
	if (SavePriority)
	{
		Savers.Sort([](const UGSS_SaverBase& A, const UGSS_SaverBase& B)
		{
			return A.GetSavePriority() > B.GetSavePriority();
		});
	}
	else
	{
		Savers.Sort([](const UGSS_SaverBase& A, const UGSS_SaverBase& B)
		{
			return A.GetLoadPriority() > B.GetLoadPriority();
		});
	}
}

TArray<UGSS_SaverBase*>& UGSS_SaveSubsystem::GetSavers()
{
	return Savers;
}
