// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SESavePreset.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SAVEEXTENSION_SESavePreset_generated_h
#error "SESavePreset.generated.h already included, missing '#pragma once' in SESavePreset.h"
#endif
#define SAVEEXTENSION_SESavePreset_generated_h

#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h_32_SPARSE_DATA
#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h_32_RPC_WRAPPERS \
	virtual void BPGetSlotNameFromId_Implementation(int32 Id, FName& Name) const; \
 \
	DECLARE_FUNCTION(execBPGetSlotNameFromId);


#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h_32_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void BPGetSlotNameFromId_Implementation(int32 Id, FName& Name) const; \
 \
	DECLARE_FUNCTION(execBPGetSlotNameFromId);


#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h_32_ACCESSORS
#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h_32_CALLBACK_WRAPPERS
#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h_32_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSESavePreset(); \
	friend struct Z_Construct_UClass_USESavePreset_Statics; \
public: \
	DECLARE_CLASS(USESavePreset, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SaveExtension"), NO_API) \
	DECLARE_SERIALIZER(USESavePreset)


#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h_32_INCLASS \
private: \
	static void StaticRegisterNativesUSESavePreset(); \
	friend struct Z_Construct_UClass_USESavePreset_Statics; \
public: \
	DECLARE_CLASS(USESavePreset, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SaveExtension"), NO_API) \
	DECLARE_SERIALIZER(USESavePreset)


#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h_32_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USESavePreset(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USESavePreset) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USESavePreset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USESavePreset); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USESavePreset(USESavePreset&&); \
	NO_API USESavePreset(const USESavePreset&); \
public: \
	NO_API virtual ~USESavePreset();


#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h_32_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USESavePreset(USESavePreset&&); \
	NO_API USESavePreset(const USESavePreset&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USESavePreset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USESavePreset); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(USESavePreset) \
	NO_API virtual ~USESavePreset();


#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h_29_PROLOG
#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h_32_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h_32_SPARSE_DATA \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h_32_RPC_WRAPPERS \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h_32_ACCESSORS \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h_32_CALLBACK_WRAPPERS \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h_32_INCLASS \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h_32_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h_32_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h_32_SPARSE_DATA \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h_32_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h_32_ACCESSORS \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h_32_CALLBACK_WRAPPERS \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h_32_INCLASS_NO_PURE_DECLS \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h_32_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SAVEEXTENSION_API UClass* StaticClass<class USESavePreset>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h


#define FOREACH_ENUM_ESAVEASYNCMODE(op) \
	op(ESaveASyncMode::OnlySync) \
	op(ESaveASyncMode::LoadAsync) \
	op(ESaveASyncMode::SaveAsync) \
	op(ESaveASyncMode::SaveAndLoadAsync) 

enum class ESaveASyncMode : uint8;
template<> struct TIsUEnumClass<ESaveASyncMode> { enum { Value = true }; };
template<> SAVEEXTENSION_API UEnum* StaticEnum<ESaveASyncMode>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
