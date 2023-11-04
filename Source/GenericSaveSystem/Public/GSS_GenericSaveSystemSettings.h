// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#pragma once

#include "GSS_SavePreset.h"

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"

#include "GSS_GenericSaveSystemSettings.generated.h"


UCLASS(ClassGroup = GenericSaveSystem, defaultconfig, config = Game)
class GENERICSAVESYSTEM_API UGSS_GenericSaveSystemSettings : public UDeveloperSettings
{
    GENERATED_BODY()

public:
	
	static const UGSS_GenericSaveSystemSettings* Get();


    UPROPERTY(EditAnywhere, Category = "Save Extension", Config, meta = (DisplayName = "Preset"))
	TSubclassOf<UGSS_SavePreset> Preset;

	/**
	 * 定义用作唯一ID的属性的名字，会通过反射查找Actor是否有此属性来判定唯一性。
	 */
	UPROPERTY(EditAnywhere, Category = "Save Extension", Config)
	FString GuidPropertyName = "SaveGuid";

	/**
	 * @brief actor/component with this tag will be serializable.
	 */
	UPROPERTY(EditAnywhere, Category= "Save Extension")
	FName SerializableTag = "Serializable";

    // If true SaveManager will tick with the world. If game is paused, saving process may be interrupted.
    UPROPERTY(EditAnywhere, Category = "Save Extension", Config)
    bool bTickWithGameWorld = false;


    UGSS_SavePreset* CreatePreset(UObject* Outer) const;
};


