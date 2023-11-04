// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#include "GSS_SavePreset.h"

#include "GSS_LevelFilter.h"
#include "GSS_SlotData.h"
#include "GSS_SlotInfo.h"


UGSS_SavePreset::UGSS_SavePreset()
	: Super()
	, SlotInfoClass(UGSS_SlotInfo::StaticClass())
	// , SlotDataClass(UGSS_SlotData::StaticClass())
{}

void UGSS_SavePreset::BPGetSlotNameFromId_Implementation(int32 Id, FName& Name) const
{
	// Call C++ inheritance chain by default
	return GetSlotNameFromId(Id, Name);
}

void UGSS_SavePreset::GetSlotNameFromId(int32 Id, FName& Name) const
{
	if (IsValidId(Id))
	{
		Name = FName{ FString::FromInt(Id) };
	}
}

