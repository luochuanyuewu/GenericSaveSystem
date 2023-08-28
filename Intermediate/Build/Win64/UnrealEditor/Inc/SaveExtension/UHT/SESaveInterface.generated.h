// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SESaveInterface.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SAVEEXTENSION_SESaveInterface_generated_h
#error "SESaveInterface.generated.h already included, missing '#pragma once' in SESaveInterface.h"
#endif
#define SAVEEXTENSION_SESaveInterface_generated_h

#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_14_SPARSE_DATA
#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_14_RPC_WRAPPERS
#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_14_ACCESSORS
#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_14_CALLBACK_WRAPPERS
#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USESaveInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USESaveInterface) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USESaveInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USESaveInterface); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USESaveInterface(USESaveInterface&&); \
	NO_API USESaveInterface(const USESaveInterface&); \
public: \
	NO_API virtual ~USESaveInterface();


#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USESaveInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USESaveInterface(USESaveInterface&&); \
	NO_API USESaveInterface(const USESaveInterface&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USESaveInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USESaveInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USESaveInterface) \
	NO_API virtual ~USESaveInterface();


#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_14_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUSESaveInterface(); \
	friend struct Z_Construct_UClass_USESaveInterface_Statics; \
public: \
	DECLARE_CLASS(USESaveInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/SaveExtension"), NO_API) \
	DECLARE_SERIALIZER(USESaveInterface)


#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_14_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_14_GENERATED_UINTERFACE_BODY() \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_14_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_14_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_14_GENERATED_UINTERFACE_BODY() \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_14_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_14_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~ISESaveInterface() {} \
public: \
	typedef USESaveInterface UClassType; \
	typedef ISESaveInterface ThisClass; \
	static void Execute_ReceiveOnLoadBegan(UObject* O); \
	static void Execute_ReceiveOnLoadFinished(UObject* O, bool bError); \
	static void Execute_ReceiveOnSaveBegan(UObject* O); \
	static void Execute_ReceiveOnSaveFinished(UObject* O, bool bError); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_14_INCLASS_IINTERFACE \
protected: \
	virtual ~ISESaveInterface() {} \
public: \
	typedef USESaveInterface UClassType; \
	typedef ISESaveInterface ThisClass; \
	static void Execute_ReceiveOnLoadBegan(UObject* O); \
	static void Execute_ReceiveOnLoadFinished(UObject* O, bool bError); \
	static void Execute_ReceiveOnSaveBegan(UObject* O); \
	static void Execute_ReceiveOnSaveFinished(UObject* O, bool bError); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_11_PROLOG
#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_14_SPARSE_DATA \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_14_RPC_WRAPPERS \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_14_ACCESSORS \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_14_CALLBACK_WRAPPERS \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_14_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_14_SPARSE_DATA \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_14_ACCESSORS \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_14_CALLBACK_WRAPPERS \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_14_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SAVEEXTENSION_API UClass* StaticClass<class USESaveInterface>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
