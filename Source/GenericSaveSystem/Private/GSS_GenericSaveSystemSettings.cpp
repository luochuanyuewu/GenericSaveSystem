// "// Copyright 2021 luochuanyuewu. All Rights Reserved."


#include "GSS_GenericSaveSystemSettings.h"


const UGSS_GenericSaveSystemSettings* UGSS_GenericSaveSystemSettings::Get()
{
	return GetDefault<UGSS_GenericSaveSystemSettings>();
}



UGSS_SavePreset* UGSS_GenericSaveSystemSettings::CreatePreset(UObject* Outer) const
{
	if(UClass* PresetClass = Preset.Get())
	{
		return NewObject<UGSS_SavePreset>(Outer, PresetClass);
	}
	return NewObject<UGSS_SavePreset>(Outer);
}