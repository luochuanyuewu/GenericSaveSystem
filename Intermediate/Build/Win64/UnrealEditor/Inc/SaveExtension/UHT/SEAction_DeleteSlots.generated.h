// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "LatentActions/SEAction_DeleteSlots.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SAVEEXTENSION_SEAction_DeleteSlots_generated_h
#error "SEAction_DeleteSlots.generated.h already included, missing '#pragma once' in SEAction_DeleteSlots.h"
#endif
#define SAVEEXTENSION_SEAction_DeleteSlots_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_LatentActions_SEAction_DeleteSlots_h


#define FOREACH_ENUM_ESEDELETESLOTSRESULT(op) \
	op(ESEDeleteSlotsResult::Completed) 

enum class ESEDeleteSlotsResult : uint8;
template<> struct TIsUEnumClass<ESEDeleteSlotsResult> { enum { Value = true }; };
template<> SAVEEXTENSION_API UEnum* StaticEnum<ESEDeleteSlotsResult>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
