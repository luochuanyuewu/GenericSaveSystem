// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SESaveManager.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class ISESaveInterface;
class ULevelStreaming;
class USESavePreset;
class USESlotData;
class USESlotInfo;
enum class ESEDeleteSlotsResult : uint8;
enum class ESELoadGameResult : uint8;
enum class ESELoadInfoResult : uint8;
enum class ESESaveGameResult : uint8;
struct FLatentActionInfo;
struct FSEScreenshotSize;
#ifdef SAVEEXTENSION_SESaveManager_generated_h
#error "SESaveManager.generated.h already included, missing '#pragma once' in SESaveManager.h"
#endif
#define SAVEEXTENSION_SESaveManager_generated_h

#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h_27_DELEGATE \
struct _Script_SaveExtension_eventOnGameSavedMC_Parms \
{ \
	USESlotInfo* SlotInfo; \
}; \
static inline void FOnGameSavedMC_DelegateWrapper(const FMulticastScriptDelegate& OnGameSavedMC, USESlotInfo* SlotInfo) \
{ \
	_Script_SaveExtension_eventOnGameSavedMC_Parms Parms; \
	Parms.SlotInfo=SlotInfo; \
	OnGameSavedMC.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h_29_DELEGATE \
struct _Script_SaveExtension_eventOnGameLoadedMC_Parms \
{ \
	USESlotInfo* SlotInfo; \
}; \
static inline void FOnGameLoadedMC_DelegateWrapper(const FMulticastScriptDelegate& OnGameLoadedMC, USESlotInfo* SlotInfo) \
{ \
	_Script_SaveExtension_eventOnGameLoadedMC_Parms Parms; \
	Parms.SlotInfo=SlotInfo; \
	OnGameLoadedMC.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h_41_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSEScreenshotSize_Statics; \
	SAVEEXTENSION_API static class UScriptStruct* StaticStruct();


template<> SAVEEXTENSION_API UScriptStruct* StaticStruct<struct FSEScreenshotSize>();

#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h_69_SPARSE_DATA
#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h_69_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execUnsubscribeFromEvents); \
	DECLARE_FUNCTION(execSubscribeForEvents); \
	DECLARE_FUNCTION(execDeserializeStreamingLevel); \
	DECLARE_FUNCTION(execSerializeStreamingLevel); \
	DECLARE_FUNCTION(execGetSlotNameFromId); \
	DECLARE_FUNCTION(execSetActivePreset); \
	DECLARE_FUNCTION(execIsInSlot); \
	DECLARE_FUNCTION(execIsSlotSavedById); \
	DECLARE_FUNCTION(execIsSlotSaved); \
	DECLARE_FUNCTION(execGetSlotInfo); \
	DECLARE_FUNCTION(execGetCurrentData); \
	DECLARE_FUNCTION(execGetCurrentInfo); \
	DECLARE_FUNCTION(execDeleteSlot); \
	DECLARE_FUNCTION(execIsSavingOrLoading); \
	DECLARE_FUNCTION(execBPGetPreset); \
	DECLARE_FUNCTION(execBPDeleteAllSlots); \
	DECLARE_FUNCTION(execDeleteSlotById); \
	DECLARE_FUNCTION(execBPLoadAllSlotInfos); \
	DECLARE_FUNCTION(execBPReloadCurrentSlot); \
	DECLARE_FUNCTION(execBPLoadSlotByInfo); \
	DECLARE_FUNCTION(execBPLoadSlotById); \
	DECLARE_FUNCTION(execBPLoadSlot); \
	DECLARE_FUNCTION(execBPSaveCurrentSlot); \
	DECLARE_FUNCTION(execBPSaveSlotByInfo); \
	DECLARE_FUNCTION(execBPSaveSlotById); \
	DECLARE_FUNCTION(execBPSaveSlot);


#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h_69_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execUnsubscribeFromEvents); \
	DECLARE_FUNCTION(execSubscribeForEvents); \
	DECLARE_FUNCTION(execDeserializeStreamingLevel); \
	DECLARE_FUNCTION(execSerializeStreamingLevel); \
	DECLARE_FUNCTION(execGetSlotNameFromId); \
	DECLARE_FUNCTION(execSetActivePreset); \
	DECLARE_FUNCTION(execIsInSlot); \
	DECLARE_FUNCTION(execIsSlotSavedById); \
	DECLARE_FUNCTION(execIsSlotSaved); \
	DECLARE_FUNCTION(execGetSlotInfo); \
	DECLARE_FUNCTION(execGetCurrentData); \
	DECLARE_FUNCTION(execGetCurrentInfo); \
	DECLARE_FUNCTION(execDeleteSlot); \
	DECLARE_FUNCTION(execIsSavingOrLoading); \
	DECLARE_FUNCTION(execBPGetPreset); \
	DECLARE_FUNCTION(execBPDeleteAllSlots); \
	DECLARE_FUNCTION(execDeleteSlotById); \
	DECLARE_FUNCTION(execBPLoadAllSlotInfos); \
	DECLARE_FUNCTION(execBPReloadCurrentSlot); \
	DECLARE_FUNCTION(execBPLoadSlotByInfo); \
	DECLARE_FUNCTION(execBPLoadSlotById); \
	DECLARE_FUNCTION(execBPLoadSlot); \
	DECLARE_FUNCTION(execBPSaveCurrentSlot); \
	DECLARE_FUNCTION(execBPSaveSlotByInfo); \
	DECLARE_FUNCTION(execBPSaveSlotById); \
	DECLARE_FUNCTION(execBPSaveSlot);


#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h_69_ACCESSORS
#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h_69_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSESaveManager(); \
	friend struct Z_Construct_UClass_USESaveManager_Statics; \
public: \
	DECLARE_CLASS(USESaveManager, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SaveExtension"), NO_API) \
	DECLARE_SERIALIZER(USESaveManager)


#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h_69_INCLASS \
private: \
	static void StaticRegisterNativesUSESaveManager(); \
	friend struct Z_Construct_UClass_USESaveManager_Statics; \
public: \
	DECLARE_CLASS(USESaveManager, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SaveExtension"), NO_API) \
	DECLARE_SERIALIZER(USESaveManager)


#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h_69_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USESaveManager(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USESaveManager) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USESaveManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USESaveManager); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USESaveManager(USESaveManager&&); \
	NO_API USESaveManager(const USESaveManager&); \
public: \
	NO_API virtual ~USESaveManager();


#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h_69_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USESaveManager(USESaveManager&&); \
	NO_API USESaveManager(const USESaveManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USESaveManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USESaveManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(USESaveManager) \
	NO_API virtual ~USESaveManager();


#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h_66_PROLOG
#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h_69_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h_69_SPARSE_DATA \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h_69_RPC_WRAPPERS \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h_69_ACCESSORS \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h_69_INCLASS \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h_69_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h_69_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h_69_SPARSE_DATA \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h_69_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h_69_ACCESSORS \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h_69_INCLASS_NO_PURE_DECLS \
	FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h_69_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SAVEEXTENSION_API UClass* StaticClass<class USESaveManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
