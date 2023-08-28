// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SESerializationSubsystem.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
#ifdef SAVEEXTENSION_SESerializationSubsystem_generated_h
#error "SESerializationSubsystem.generated.h already included, missing '#pragma once' in SESerializationSubsystem.h"
#endif
#define SAVEEXTENSION_SESerializationSubsystem_generated_h

#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESerializationSubsystem_h_17_SPARSE_DATA
#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESerializationSubsystem_h_17_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execStringFromBytes); \
	DECLARE_FUNCTION(execBytesFromString); \
	DECLARE_FUNCTION(execSerializeFromBinary); \
	DECLARE_FUNCTION(execSerializeToBinary);


#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESerializationSubsystem_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execStringFromBytes); \
	DECLARE_FUNCTION(execBytesFromString); \
	DECLARE_FUNCTION(execSerializeFromBinary); \
	DECLARE_FUNCTION(execSerializeToBinary);


#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESerializationSubsystem_h_17_ACCESSORS
#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESerializationSubsystem_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSESerializationSubsystem(); \
	friend struct Z_Construct_UClass_USESerializationSubsystem_Statics; \
public: \
	DECLARE_CLASS(USESerializationSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SaveExtension"), NO_API) \
	DECLARE_SERIALIZER(USESerializationSubsystem)


#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESerializationSubsystem_h_17_INCLASS \
private: \
	static void StaticRegisterNativesUSESerializationSubsystem(); \
	friend struct Z_Construct_UClass_USESerializationSubsystem_Statics; \
public: \
	DECLARE_CLASS(USESerializationSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SaveExtension"), NO_API) \
	DECLARE_SERIALIZER(USESerializationSubsystem)


#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESerializationSubsystem_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USESerializationSubsystem(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USESerializationSubsystem) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USESerializationSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USESerializationSubsystem); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USESerializationSubsystem(USESerializationSubsystem&&); \
	NO_API USESerializationSubsystem(const USESerializationSubsystem&); \
public: \
	NO_API virtual ~USESerializationSubsystem();


#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESerializationSubsystem_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USESerializationSubsystem() { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USESerializationSubsystem(USESerializationSubsystem&&); \
	NO_API USESerializationSubsystem(const USESerializationSubsystem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USESerializationSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USESerializationSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(USESerializationSubsystem) \
	NO_API virtual ~USESerializationSubsystem();


#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESerializationSubsystem_h_14_PROLOG
#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESerializationSubsystem_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESerializationSubsystem_h_17_SPARSE_DATA \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESerializationSubsystem_h_17_RPC_WRAPPERS \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESerializationSubsystem_h_17_ACCESSORS \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESerializationSubsystem_h_17_INCLASS \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESerializationSubsystem_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESerializationSubsystem_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESerializationSubsystem_h_17_SPARSE_DATA \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESerializationSubsystem_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESerializationSubsystem_h_17_ACCESSORS \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESerializationSubsystem_h_17_INCLASS_NO_PURE_DECLS \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESerializationSubsystem_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SAVEEXTENSION_API UClass* StaticClass<class USESerializationSubsystem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESerializationSubsystem_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
