// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "LatentActions/SEAction_SaveGame.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SAVEEXTENSION_SEAction_SaveGame_generated_h
#error "SEAction_SaveGame.generated.h already included, missing '#pragma once' in SEAction_SaveGame.h"
#endif
#define SAVEEXTENSION_SEAction_SaveGame_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_LatentActions_SEAction_SaveGame_h


#define FOREACH_ENUM_ESESAVEGAMERESULT(op) \
	op(ESESaveGameResult::Saving) \
	op(ESESaveGameResult::Continue) \
	op(ESESaveGameResult::Failed) 

enum class ESESaveGameResult : uint8;
template<> struct TIsUEnumClass<ESESaveGameResult> { enum { Value = true }; };
template<> SAVEEXTENSION_API UEnum* StaticEnum<ESESaveGameResult>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
