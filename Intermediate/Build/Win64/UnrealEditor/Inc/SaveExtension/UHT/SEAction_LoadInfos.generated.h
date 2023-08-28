// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "LatentActions/SEAction_LoadInfos.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SAVEEXTENSION_SEAction_LoadInfos_generated_h
#error "SEAction_LoadInfos.generated.h already included, missing '#pragma once' in SEAction_LoadInfos.h"
#endif
#define SAVEEXTENSION_SEAction_LoadInfos_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_LatentActions_SEAction_LoadInfos_h


#define FOREACH_ENUM_ESELOADINFORESULT(op) \
	op(ESELoadInfoResult::Completed) 

enum class ESELoadInfoResult : uint8;
template<> struct TIsUEnumClass<ESELoadInfoResult> { enum { Value = true }; };
template<> SAVEEXTENSION_API UEnum* StaticEnum<ESELoadInfoResult>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
