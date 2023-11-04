// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"
#include "Engine/Engine.h"
#include "GSS_SavePreset.h"

DECLARE_LOG_CATEGORY_EXTERN(LogGenericSaveSystem, All, All);

class IGenericSaveSystem : public IModuleInterface
{
public:
	static inline IGenericSaveSystem& Get()
	{
		return FModuleManager::LoadModuleChecked<IGenericSaveSystem>("GenericSaveSystem");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("GenericSaveSystem");
	}

	static void Log(const UGSS_SavePreset* Preset, const FString Message, bool bError)
	{
		Log(Preset, Message, FColor::White, bError, 2.f);
	}

	static void Log(const UGSS_SavePreset* Preset, const FString Message, FColor Color = FColor::White, bool bError = false, const float Duration = 2.f)
	{
		if (Preset->bDebug)
		{
			if (bError)
			{
				Color = FColor::Red;
			}

			const FString ComposedMessage{FString::Printf(TEXT("SE: %s"), *Message)};

			if (bError)
			{
				UE_LOG(LogGenericSaveSystem, Error, TEXT("%s"), *ComposedMessage);
			}
			else
			{
				UE_LOG(LogGenericSaveSystem, Log, TEXT("%s"), *ComposedMessage);
			}

			if (Preset->bDebugInScreen && GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, Duration, Color, ComposedMessage);
			}
		}
	}
};

// Only log in Editor
#if WITH_EDITORONLY_DATA
template <typename... Args>
void GSS_Log(Args&&... args)
{
	IGenericSaveSystem::Log(Forward<Args>(args)...);
}
#else
template <typename... Args>
void GSS_Log(Args &&...args)
{
} // Optimized away by compiler
#endif
