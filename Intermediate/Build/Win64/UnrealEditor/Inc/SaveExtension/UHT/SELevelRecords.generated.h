// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Serialization/SELevelRecords.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SAVEEXTENSION_SELevelRecords_generated_h
#error "SELevelRecords.generated.h already included, missing '#pragma once' in SELevelRecords.h"
#endif
#define SAVEEXTENSION_SELevelRecords_generated_h

#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SELevelRecords_h_17_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSELevelRecord_Statics; \
	SAVEEXTENSION_API static class UScriptStruct* StaticStruct(); \
	typedef FSEBaseRecord Super;


template<> SAVEEXTENSION_API UScriptStruct* StaticStruct<struct FSELevelRecord>();

#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SELevelRecords_h_44_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSEPersistentLevelRecord_Statics; \
	SAVEEXTENSION_API static class UScriptStruct* StaticStruct(); \
	typedef FSELevelRecord Super;


template<> SAVEEXTENSION_API UScriptStruct* StaticStruct<struct FSEPersistentLevelRecord>();

#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SELevelRecords_h_59_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSEStreamingLevelRecord_Statics; \
	SAVEEXTENSION_API static class UScriptStruct* StaticStruct(); \
	typedef FSELevelRecord Super;


template<> SAVEEXTENSION_API UScriptStruct* StaticStruct<struct FSEStreamingLevelRecord>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SELevelRecords_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
