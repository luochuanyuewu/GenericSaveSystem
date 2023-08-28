// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Serialization/SERecords.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SAVEEXTENSION_SERecords_generated_h
#error "SERecords.generated.h already included, missing '#pragma once' in SERecords.h"
#endif
#define SAVEEXTENSION_SERecords_generated_h

#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SERecords_h_18_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSEBaseRecord_Statics; \
	static class UScriptStruct* StaticStruct();


template<> SAVEEXTENSION_API UScriptStruct* StaticStruct<struct FSEBaseRecord>();

#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SERecords_h_54_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSEObjectRecord_Statics; \
	static class UScriptStruct* StaticStruct(); \
	typedef FSEBaseRecord Super;


template<> SAVEEXTENSION_API UScriptStruct* StaticStruct<struct FSEObjectRecord>();

#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SERecords_h_91_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSEComponentRecord_Statics; \
	static class UScriptStruct* StaticStruct(); \
	typedef FSEObjectRecord Super;


template<> SAVEEXTENSION_API UScriptStruct* StaticStruct<struct FSEComponentRecord>();

#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SERecords_h_104_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSEActorRecord_Statics; \
	static class UScriptStruct* StaticStruct(); \
	typedef FSEObjectRecord Super;


template<> SAVEEXTENSION_API UScriptStruct* StaticStruct<struct FSEActorRecord>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SERecords_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
