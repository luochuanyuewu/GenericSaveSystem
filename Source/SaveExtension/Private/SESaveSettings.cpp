// "// Copyright 2021 luochuanyuewu. All Rights Reserved."


#include "SESaveSettings.h"


const USESaveSettings* USESaveSettings::Get()
{
	return GetDefault<USESaveSettings>();
}



USESavePreset* USESaveSettings::CreatePreset(UObject* Outer) const
{
	if(UClass* PresetClass = Preset.Get())
	{
		return NewObject<USESavePreset>(Outer, PresetClass);
	}
	return NewObject<USESavePreset>(Outer);
}