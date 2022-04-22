// Copyright 2015-2020 Piperift. All Rights Reserved.

#include "SESavePreset.h"

#include "SELevelFilter.h"
#include "SESlotData.h"
#include "SESlotInfo.h"


USESavePreset::USESavePreset()
	: Super()
	, SlotInfoClass(USESlotInfo::StaticClass())
	, SlotDataClass(USESlotData::StaticClass())
{}

void USESavePreset::BPGetSlotNameFromId_Implementation(int32 Id, FName& Name) const
{
	// Call C++ inheritance chain by default
	return GetSlotNameFromId(Id, Name);
}

void USESavePreset::GetSlotNameFromId(int32 Id, FName& Name) const
{
	if (IsValidId(Id))
	{
		Name = FName{ FString::FromInt(Id) };
	}
}

FSELevelFilter USESavePreset::ToFilter() const
{
	FSELevelFilter Filter{};
	Filter.FromPreset(*this);
	return Filter;
}
