// Copyright 2015-2020 Piperift. All Rights Reserved.

#pragma once

#include "SESavePreset.h"

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"

#include "SESaveSettings.generated.h"


UCLASS(ClassGroup = SaveExtension, defaultconfig, config = Game, meta=(DisplayName="Save Extension"))
class SAVEEXTENSION_API USESaveSettings : public UDeveloperSettings
{
    GENERATED_BODY()

protected:

    UPROPERTY(EditAnywhere, Category = "Save Extension", Config, meta = (DisplayName = "Preset"))
	TSubclassOf<USESavePreset> Preset;

	/**
	 * 定义用作唯一ID的属性的名字，会通过反射查找Actor是否有此属性来判定唯一性。
	 */
	UPROPERTY(EditAnywhere, Category = "Save Extension", Config)
	FString GuidPropertyName = "SaveGuid";


public:

    // If true SaveManager will tick with the world. If game is paused, saving process may be interrupted.
    UPROPERTY(EditAnywhere, Category = "Save Extension", Config)
    bool bTickWithGameWorld = false;


    USESavePreset* CreatePreset(UObject* Outer) const;
};


inline USESavePreset* USESaveSettings::CreatePreset(UObject* Outer) const
{
    if(UClass* PresetClass = Preset.Get())
	{
        return NewObject<USESavePreset>(Outer, PresetClass);
	}
    return NewObject<USESavePreset>(Outer);
}
