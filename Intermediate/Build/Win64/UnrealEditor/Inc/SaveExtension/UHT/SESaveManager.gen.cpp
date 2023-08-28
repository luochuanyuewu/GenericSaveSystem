// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveExtension/Public/SESaveManager.h"
#include "Engine/Classes/Engine/GameInstance.h"
#include "Engine/Classes/Engine/LatentActionManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSESaveManager() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
	ENGINE_API UClass* Z_Construct_UClass_ULevelStreaming_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FLatentActionInfo();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USELevelStreamingNotifier_NoRegister();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESaveInterface_NoRegister();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESaveManager();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESaveManager_NoRegister();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESavePreset_NoRegister();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESaverBase_NoRegister();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESlotData_NoRegister();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESlotDataTask_NoRegister();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESlotInfo_NoRegister();
	SAVEEXTENSION_API UEnum* Z_Construct_UEnum_SaveExtension_ESEDeleteSlotsResult();
	SAVEEXTENSION_API UEnum* Z_Construct_UEnum_SaveExtension_ESELoadGameResult();
	SAVEEXTENSION_API UEnum* Z_Construct_UEnum_SaveExtension_ESELoadInfoResult();
	SAVEEXTENSION_API UEnum* Z_Construct_UEnum_SaveExtension_ESESaveGameResult();
	SAVEEXTENSION_API UFunction* Z_Construct_UDelegateFunction_SaveExtension_OnGameLoadedMC__DelegateSignature();
	SAVEEXTENSION_API UFunction* Z_Construct_UDelegateFunction_SaveExtension_OnGameSavedMC__DelegateSignature();
	SAVEEXTENSION_API UScriptStruct* Z_Construct_UScriptStruct_FSEScreenshotSize();
	UPackage* Z_Construct_UPackage__Script_SaveExtension();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_SaveExtension_OnGameSavedMC__DelegateSignature_Statics
	{
		struct _Script_SaveExtension_eventOnGameSavedMC_Parms
		{
			USESlotInfo* SlotInfo;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SlotInfo;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_SaveExtension_OnGameSavedMC__DelegateSignature_Statics::NewProp_SlotInfo = { "SlotInfo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(_Script_SaveExtension_eventOnGameSavedMC_Parms, SlotInfo), Z_Construct_UClass_USESlotInfo_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_SaveExtension_OnGameSavedMC__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SaveExtension_OnGameSavedMC__DelegateSignature_Statics::NewProp_SlotInfo,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SaveExtension_OnGameSavedMC__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SaveExtension_OnGameSavedMC__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SaveExtension, nullptr, "OnGameSavedMC__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_SaveExtension_OnGameSavedMC__DelegateSignature_Statics::_Script_SaveExtension_eventOnGameSavedMC_Parms), Z_Construct_UDelegateFunction_SaveExtension_OnGameSavedMC__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SaveExtension_OnGameSavedMC__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SaveExtension_OnGameSavedMC__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SaveExtension_OnGameSavedMC__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SaveExtension_OnGameSavedMC__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_SaveExtension_OnGameSavedMC__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_SaveExtension_OnGameLoadedMC__DelegateSignature_Statics
	{
		struct _Script_SaveExtension_eventOnGameLoadedMC_Parms
		{
			USESlotInfo* SlotInfo;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SlotInfo;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_SaveExtension_OnGameLoadedMC__DelegateSignature_Statics::NewProp_SlotInfo = { "SlotInfo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(_Script_SaveExtension_eventOnGameLoadedMC_Parms, SlotInfo), Z_Construct_UClass_USESlotInfo_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_SaveExtension_OnGameLoadedMC__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SaveExtension_OnGameLoadedMC__DelegateSignature_Statics::NewProp_SlotInfo,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SaveExtension_OnGameLoadedMC__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SaveExtension_OnGameLoadedMC__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SaveExtension, nullptr, "OnGameLoadedMC__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_SaveExtension_OnGameLoadedMC__DelegateSignature_Statics::_Script_SaveExtension_eventOnGameLoadedMC_Parms), Z_Construct_UDelegateFunction_SaveExtension_OnGameLoadedMC__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SaveExtension_OnGameLoadedMC__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SaveExtension_OnGameLoadedMC__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SaveExtension_OnGameLoadedMC__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SaveExtension_OnGameLoadedMC__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_SaveExtension_OnGameLoadedMC__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SEScreenshotSize;
class UScriptStruct* FSEScreenshotSize::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SEScreenshotSize.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SEScreenshotSize.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSEScreenshotSize, Z_Construct_UPackage__Script_SaveExtension(), TEXT("SEScreenshotSize"));
	}
	return Z_Registration_Info_UScriptStruct_SEScreenshotSize.OuterSingleton;
}
template<> SAVEEXTENSION_API UScriptStruct* StaticStruct<FSEScreenshotSize>()
{
	return FSEScreenshotSize::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FSEScreenshotSize_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Width_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Width;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Height_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Height;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSEScreenshotSize_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * \xe6\x88\xaa\xe5\xb1\x8f\xe5\xa4\xa7\xe5\xb0\x8f\n */" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
		{ "ToolTip", "\xe6\x88\xaa\xe5\xb1\x8f\xe5\xa4\xa7\xe5\xb0\x8f" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSEScreenshotSize_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSEScreenshotSize>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSEScreenshotSize_Statics::NewProp_Width_MetaData[] = {
		{ "Category", "Screenshot" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSEScreenshotSize_Statics::NewProp_Width = { "Width", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSEScreenshotSize, Width), METADATA_PARAMS(Z_Construct_UScriptStruct_FSEScreenshotSize_Statics::NewProp_Width_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSEScreenshotSize_Statics::NewProp_Width_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSEScreenshotSize_Statics::NewProp_Height_MetaData[] = {
		{ "Category", "Screenshot" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSEScreenshotSize_Statics::NewProp_Height = { "Height", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSEScreenshotSize, Height), METADATA_PARAMS(Z_Construct_UScriptStruct_FSEScreenshotSize_Statics::NewProp_Height_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSEScreenshotSize_Statics::NewProp_Height_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSEScreenshotSize_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSEScreenshotSize_Statics::NewProp_Width,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSEScreenshotSize_Statics::NewProp_Height,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSEScreenshotSize_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SaveExtension,
		nullptr,
		&NewStructOps,
		"SEScreenshotSize",
		sizeof(FSEScreenshotSize),
		alignof(FSEScreenshotSize),
		Z_Construct_UScriptStruct_FSEScreenshotSize_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSEScreenshotSize_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSEScreenshotSize_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSEScreenshotSize_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSEScreenshotSize()
	{
		if (!Z_Registration_Info_UScriptStruct_SEScreenshotSize.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SEScreenshotSize.InnerSingleton, Z_Construct_UScriptStruct_FSEScreenshotSize_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_SEScreenshotSize.InnerSingleton;
	}
	DEFINE_FUNCTION(USESaveManager::execUnsubscribeFromEvents)
	{
		P_GET_TINTERFACE_REF(ISESaveInterface,Z_Param_Out_Interface);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UnsubscribeFromEvents(Z_Param_Out_Interface);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USESaveManager::execSubscribeForEvents)
	{
		P_GET_TINTERFACE_REF(ISESaveInterface,Z_Param_Out_Interface);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SubscribeForEvents(Z_Param_Out_Interface);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USESaveManager::execDeserializeStreamingLevel)
	{
		P_GET_OBJECT(ULevelStreaming,Z_Param_LevelStreaming);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DeserializeStreamingLevel(Z_Param_LevelStreaming);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USESaveManager::execSerializeStreamingLevel)
	{
		P_GET_OBJECT(ULevelStreaming,Z_Param_LevelStreaming);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SerializeStreamingLevel(Z_Param_LevelStreaming);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USESaveManager::execGetSlotNameFromId)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_SlotId);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FName*)Z_Param__Result=P_THIS->GetSlotNameFromId(Z_Param_SlotId);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USESaveManager::execSetActivePreset)
	{
		P_GET_OBJECT(UClass,Z_Param_PresetClass);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USESavePreset**)Z_Param__Result=P_THIS->SetActivePreset(Z_Param_PresetClass);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USESaveManager::execIsInSlot)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsInSlot();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USESaveManager::execIsSlotSavedById)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_SlotId);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsSlotSavedById(Z_Param_SlotId);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USESaveManager::execIsSlotSaved)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_SlotName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsSlotSaved(Z_Param_SlotName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USESaveManager::execGetSlotInfo)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_SlotId);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USESlotInfo**)Z_Param__Result=P_THIS->GetSlotInfo(Z_Param_SlotId);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USESaveManager::execGetCurrentData)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USESlotData**)Z_Param__Result=P_THIS->GetCurrentData();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USESaveManager::execGetCurrentInfo)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USESlotInfo**)Z_Param__Result=P_THIS->GetCurrentInfo();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USESaveManager::execDeleteSlot)
	{
		P_GET_OBJECT(USESlotInfo,Z_Param_Slot);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->DeleteSlot(Z_Param_Slot);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USESaveManager::execIsSavingOrLoading)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsSavingOrLoading();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USESaveManager::execBPGetPreset)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USESavePreset**)Z_Param__Result=P_THIS->BPGetPreset();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USESaveManager::execBPDeleteAllSlots)
	{
		P_GET_ENUM_REF(ESEDeleteSlotsResult,Z_Param_Out_Result);
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BPDeleteAllSlots((ESEDeleteSlotsResult&)(Z_Param_Out_Result),Z_Param_LatentInfo);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USESaveManager::execDeleteSlotById)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_SlotId);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->DeleteSlotById(Z_Param_SlotId);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USESaveManager::execBPLoadAllSlotInfos)
	{
		P_GET_UBOOL(Z_Param_bSortByRecent);
		P_GET_TARRAY_REF(USESlotInfo*,Z_Param_Out_SaveInfos);
		P_GET_ENUM_REF(ESELoadInfoResult,Z_Param_Out_Result);
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BPLoadAllSlotInfos(Z_Param_bSortByRecent,Z_Param_Out_SaveInfos,(ESELoadInfoResult&)(Z_Param_Out_Result),Z_Param_LatentInfo);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USESaveManager::execBPReloadCurrentSlot)
	{
		P_GET_ENUM_REF(ESELoadGameResult,Z_Param_Out_Result);
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BPReloadCurrentSlot((ESELoadGameResult&)(Z_Param_Out_Result),Z_Param_LatentInfo);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USESaveManager::execBPLoadSlotByInfo)
	{
		P_GET_OBJECT(USESlotInfo,Z_Param_SlotInfo);
		P_GET_ENUM_REF(ESELoadGameResult,Z_Param_Out_Result);
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BPLoadSlotByInfo(Z_Param_SlotInfo,(ESELoadGameResult&)(Z_Param_Out_Result),Z_Param_LatentInfo);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USESaveManager::execBPLoadSlotById)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_SlotId);
		P_GET_ENUM_REF(ESELoadGameResult,Z_Param_Out_Result);
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BPLoadSlotById(Z_Param_SlotId,(ESELoadGameResult&)(Z_Param_Out_Result),Z_Param_LatentInfo);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USESaveManager::execBPLoadSlot)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_SlotName);
		P_GET_ENUM_REF(ESELoadGameResult,Z_Param_Out_Result);
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BPLoadSlot(Z_Param_SlotName,(ESELoadGameResult&)(Z_Param_Out_Result),Z_Param_LatentInfo);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USESaveManager::execBPSaveCurrentSlot)
	{
		P_GET_UBOOL(Z_Param_bScreenshot);
		P_GET_STRUCT(FSEScreenshotSize,Z_Param_Size);
		P_GET_ENUM_REF(ESESaveGameResult,Z_Param_Out_Result);
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BPSaveCurrentSlot(Z_Param_bScreenshot,Z_Param_Size,(ESESaveGameResult&)(Z_Param_Out_Result),Z_Param_LatentInfo);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USESaveManager::execBPSaveSlotByInfo)
	{
		P_GET_OBJECT(USESlotInfo,Z_Param_SlotInfo);
		P_GET_UBOOL(Z_Param_bScreenshot);
		P_GET_STRUCT(FSEScreenshotSize,Z_Param_Size);
		P_GET_ENUM_REF(ESESaveGameResult,Z_Param_Out_Result);
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo);
		P_GET_UBOOL(Z_Param_bOverrideIfNeeded);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BPSaveSlotByInfo(Z_Param_SlotInfo,Z_Param_bScreenshot,Z_Param_Size,(ESESaveGameResult&)(Z_Param_Out_Result),Z_Param_LatentInfo,Z_Param_bOverrideIfNeeded);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USESaveManager::execBPSaveSlotById)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_SlotId);
		P_GET_UBOOL(Z_Param_bScreenshot);
		P_GET_STRUCT(FSEScreenshotSize,Z_Param_Size);
		P_GET_ENUM_REF(ESESaveGameResult,Z_Param_Out_Result);
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo);
		P_GET_UBOOL(Z_Param_bOverrideIfNeeded);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BPSaveSlotById(Z_Param_SlotId,Z_Param_bScreenshot,Z_Param_Size,(ESESaveGameResult&)(Z_Param_Out_Result),Z_Param_LatentInfo,Z_Param_bOverrideIfNeeded);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USESaveManager::execBPSaveSlot)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_SlotName);
		P_GET_UBOOL(Z_Param_bScreenshot);
		P_GET_STRUCT(FSEScreenshotSize,Z_Param_Size);
		P_GET_ENUM_REF(ESESaveGameResult,Z_Param_Out_Result);
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo);
		P_GET_UBOOL(Z_Param_bOverrideIfNeeded);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BPSaveSlot(Z_Param_SlotName,Z_Param_bScreenshot,Z_Param_Size,(ESESaveGameResult&)(Z_Param_Out_Result),Z_Param_LatentInfo,Z_Param_bOverrideIfNeeded);
		P_NATIVE_END;
	}
	void USESaveManager::StaticRegisterNativesUSESaveManager()
	{
		UClass* Class = USESaveManager::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BPDeleteAllSlots", &USESaveManager::execBPDeleteAllSlots },
			{ "BPGetPreset", &USESaveManager::execBPGetPreset },
			{ "BPLoadAllSlotInfos", &USESaveManager::execBPLoadAllSlotInfos },
			{ "BPLoadSlot", &USESaveManager::execBPLoadSlot },
			{ "BPLoadSlotById", &USESaveManager::execBPLoadSlotById },
			{ "BPLoadSlotByInfo", &USESaveManager::execBPLoadSlotByInfo },
			{ "BPReloadCurrentSlot", &USESaveManager::execBPReloadCurrentSlot },
			{ "BPSaveCurrentSlot", &USESaveManager::execBPSaveCurrentSlot },
			{ "BPSaveSlot", &USESaveManager::execBPSaveSlot },
			{ "BPSaveSlotById", &USESaveManager::execBPSaveSlotById },
			{ "BPSaveSlotByInfo", &USESaveManager::execBPSaveSlotByInfo },
			{ "DeleteSlot", &USESaveManager::execDeleteSlot },
			{ "DeleteSlotById", &USESaveManager::execDeleteSlotById },
			{ "DeserializeStreamingLevel", &USESaveManager::execDeserializeStreamingLevel },
			{ "GetCurrentData", &USESaveManager::execGetCurrentData },
			{ "GetCurrentInfo", &USESaveManager::execGetCurrentInfo },
			{ "GetSlotInfo", &USESaveManager::execGetSlotInfo },
			{ "GetSlotNameFromId", &USESaveManager::execGetSlotNameFromId },
			{ "IsInSlot", &USESaveManager::execIsInSlot },
			{ "IsSavingOrLoading", &USESaveManager::execIsSavingOrLoading },
			{ "IsSlotSaved", &USESaveManager::execIsSlotSaved },
			{ "IsSlotSavedById", &USESaveManager::execIsSlotSavedById },
			{ "SerializeStreamingLevel", &USESaveManager::execSerializeStreamingLevel },
			{ "SetActivePreset", &USESaveManager::execSetActivePreset },
			{ "SubscribeForEvents", &USESaveManager::execSubscribeForEvents },
			{ "UnsubscribeFromEvents", &USESaveManager::execUnsubscribeFromEvents },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USESaveManager_BPDeleteAllSlots_Statics
	{
		struct SESaveManager_eventBPDeleteAllSlots_Parms
		{
			ESEDeleteSlotsResult Result;
			FLatentActionInfo LatentInfo;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UECodeGen_Private::FStructPropertyParams NewProp_LatentInfo;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USESaveManager_BPDeleteAllSlots_Statics::NewProp_Result_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USESaveManager_BPDeleteAllSlots_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventBPDeleteAllSlots_Parms, Result), Z_Construct_UEnum_SaveExtension_ESEDeleteSlotsResult, METADATA_PARAMS(nullptr, 0) }; // 1661764414
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USESaveManager_BPDeleteAllSlots_Statics::NewProp_LatentInfo = { "LatentInfo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventBPDeleteAllSlots_Parms, LatentInfo), Z_Construct_UScriptStruct_FLatentActionInfo, METADATA_PARAMS(nullptr, 0) }; // 2194022737
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESaveManager_BPDeleteAllSlots_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPDeleteAllSlots_Statics::NewProp_Result_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPDeleteAllSlots_Statics::NewProp_Result,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPDeleteAllSlots_Statics::NewProp_LatentInfo,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_BPDeleteAllSlots_Statics::Function_MetaDataParams[] = {
		{ "Category", "SaveExtension" },
		{ "Comment", "/** Delete all saved slots from disk, loaded or not */" },
		{ "DisplayName", "Delete All Slots" },
		{ "ExpandEnumAsExecs", "Result" },
		{ "Latent", "" },
		{ "LatentInfo", "LatentInfo" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
		{ "ToolTip", "Delete all saved slots from disk, loaded or not" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESaveManager_BPDeleteAllSlots_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESaveManager, nullptr, "BPDeleteAllSlots", nullptr, nullptr, sizeof(Z_Construct_UFunction_USESaveManager_BPDeleteAllSlots_Statics::SESaveManager_eventBPDeleteAllSlots_Parms), Z_Construct_UFunction_USESaveManager_BPDeleteAllSlots_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_BPDeleteAllSlots_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_BPDeleteAllSlots_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_BPDeleteAllSlots_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESaveManager_BPDeleteAllSlots()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESaveManager_BPDeleteAllSlots_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USESaveManager_BPGetPreset_Statics
	{
		struct SESaveManager_eventBPGetPreset_Parms
		{
			USESavePreset* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USESaveManager_BPGetPreset_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventBPGetPreset_Parms, ReturnValue), Z_Construct_UClass_USESavePreset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESaveManager_BPGetPreset_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPGetPreset_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_BPGetPreset_Statics::Function_MetaDataParams[] = {
		{ "Category", "SaveExtension" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESaveManager_BPGetPreset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESaveManager, nullptr, "BPGetPreset", nullptr, nullptr, sizeof(Z_Construct_UFunction_USESaveManager_BPGetPreset_Statics::SESaveManager_eventBPGetPreset_Parms), Z_Construct_UFunction_USESaveManager_BPGetPreset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_BPGetPreset_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_BPGetPreset_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_BPGetPreset_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESaveManager_BPGetPreset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESaveManager_BPGetPreset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USESaveManager_BPLoadAllSlotInfos_Statics
	{
		struct SESaveManager_eventBPLoadAllSlotInfos_Parms
		{
			bool bSortByRecent;
			TArray<USESlotInfo*> SaveInfos;
			ESELoadInfoResult Result;
			FLatentActionInfo LatentInfo;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bSortByRecent_MetaData[];
#endif
		static void NewProp_bSortByRecent_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSortByRecent;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SaveInfos_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_SaveInfos;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UECodeGen_Private::FStructPropertyParams NewProp_LatentInfo;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_BPLoadAllSlotInfos_Statics::NewProp_bSortByRecent_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_USESaveManager_BPLoadAllSlotInfos_Statics::NewProp_bSortByRecent_SetBit(void* Obj)
	{
		((SESaveManager_eventBPLoadAllSlotInfos_Parms*)Obj)->bSortByRecent = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USESaveManager_BPLoadAllSlotInfos_Statics::NewProp_bSortByRecent = { "bSortByRecent", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(SESaveManager_eventBPLoadAllSlotInfos_Parms), &Z_Construct_UFunction_USESaveManager_BPLoadAllSlotInfos_Statics::NewProp_bSortByRecent_SetBit, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_BPLoadAllSlotInfos_Statics::NewProp_bSortByRecent_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_BPLoadAllSlotInfos_Statics::NewProp_bSortByRecent_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USESaveManager_BPLoadAllSlotInfos_Statics::NewProp_SaveInfos_Inner = { "SaveInfos", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UClass_USESlotInfo_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USESaveManager_BPLoadAllSlotInfos_Statics::NewProp_SaveInfos = { "SaveInfos", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventBPLoadAllSlotInfos_Parms, SaveInfos), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USESaveManager_BPLoadAllSlotInfos_Statics::NewProp_Result_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USESaveManager_BPLoadAllSlotInfos_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventBPLoadAllSlotInfos_Parms, Result), Z_Construct_UEnum_SaveExtension_ESELoadInfoResult, METADATA_PARAMS(nullptr, 0) }; // 2864278528
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USESaveManager_BPLoadAllSlotInfos_Statics::NewProp_LatentInfo = { "LatentInfo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventBPLoadAllSlotInfos_Parms, LatentInfo), Z_Construct_UScriptStruct_FLatentActionInfo, METADATA_PARAMS(nullptr, 0) }; // 2194022737
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESaveManager_BPLoadAllSlotInfos_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPLoadAllSlotInfos_Statics::NewProp_bSortByRecent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPLoadAllSlotInfos_Statics::NewProp_SaveInfos_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPLoadAllSlotInfos_Statics::NewProp_SaveInfos,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPLoadAllSlotInfos_Statics::NewProp_Result_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPLoadAllSlotInfos_Statics::NewProp_Result,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPLoadAllSlotInfos_Statics::NewProp_LatentInfo,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_BPLoadAllSlotInfos_Statics::Function_MetaDataParams[] = {
		{ "Category", "SaveExtension" },
		{ "Comment", "/**\n\x09 * Find all saved games and return their SlotInfos\n\x09 * @param bSortByRecent Should slots be ordered by save date?\n\x09 * @param SaveInfos All saved games found on disk\n\x09 */" },
		{ "DisplayName", "Load All Slot Infos" },
		{ "ExpandEnumAsExecs", "Result" },
		{ "Latent", "" },
		{ "LatentInfo", "LatentInfo" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
		{ "ToolTip", "Find all saved games and return their SlotInfos\n@param bSortByRecent Should slots be ordered by save date?\n@param SaveInfos All saved games found on disk" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESaveManager_BPLoadAllSlotInfos_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESaveManager, nullptr, "BPLoadAllSlotInfos", nullptr, nullptr, sizeof(Z_Construct_UFunction_USESaveManager_BPLoadAllSlotInfos_Statics::SESaveManager_eventBPLoadAllSlotInfos_Parms), Z_Construct_UFunction_USESaveManager_BPLoadAllSlotInfos_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_BPLoadAllSlotInfos_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_BPLoadAllSlotInfos_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_BPLoadAllSlotInfos_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESaveManager_BPLoadAllSlotInfos()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESaveManager_BPLoadAllSlotInfos_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USESaveManager_BPLoadSlot_Statics
	{
		struct SESaveManager_eventBPLoadSlot_Parms
		{
			FName SlotName;
			ESELoadGameResult Result;
			FLatentActionInfo LatentInfo;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_SlotName;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UECodeGen_Private::FStructPropertyParams NewProp_LatentInfo;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_USESaveManager_BPLoadSlot_Statics::NewProp_SlotName = { "SlotName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventBPLoadSlot_Parms, SlotName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USESaveManager_BPLoadSlot_Statics::NewProp_Result_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USESaveManager_BPLoadSlot_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventBPLoadSlot_Parms, Result), Z_Construct_UEnum_SaveExtension_ESELoadGameResult, METADATA_PARAMS(nullptr, 0) }; // 4094298572
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USESaveManager_BPLoadSlot_Statics::NewProp_LatentInfo = { "LatentInfo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventBPLoadSlot_Parms, LatentInfo), Z_Construct_UScriptStruct_FLatentActionInfo, METADATA_PARAMS(nullptr, 0) }; // 2194022737
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESaveManager_BPLoadSlot_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPLoadSlot_Statics::NewProp_SlotName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPLoadSlot_Statics::NewProp_Result_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPLoadSlot_Statics::NewProp_Result,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPLoadSlot_Statics::NewProp_LatentInfo,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_BPLoadSlot_Statics::Function_MetaDataParams[] = {
		{ "Category", "SaveExtension|Loading" },
		{ "Comment", "/** Load game from a slot name */" },
		{ "DisplayName", "Load Slot" },
		{ "ExpandEnumAsExecs", "Result" },
		{ "Latent", "" },
		{ "LatentInfo", "LatentInfo" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
		{ "ToolTip", "Load game from a slot name" },
		{ "UnsafeDuringActorConstruction", "" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESaveManager_BPLoadSlot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESaveManager, nullptr, "BPLoadSlot", nullptr, nullptr, sizeof(Z_Construct_UFunction_USESaveManager_BPLoadSlot_Statics::SESaveManager_eventBPLoadSlot_Parms), Z_Construct_UFunction_USESaveManager_BPLoadSlot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_BPLoadSlot_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_BPLoadSlot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_BPLoadSlot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESaveManager_BPLoadSlot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESaveManager_BPLoadSlot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USESaveManager_BPLoadSlotById_Statics
	{
		struct SESaveManager_eventBPLoadSlotById_Parms
		{
			int32 SlotId;
			ESELoadGameResult Result;
			FLatentActionInfo LatentInfo;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_SlotId;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UECodeGen_Private::FStructPropertyParams NewProp_LatentInfo;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USESaveManager_BPLoadSlotById_Statics::NewProp_SlotId = { "SlotId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventBPLoadSlotById_Parms, SlotId), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USESaveManager_BPLoadSlotById_Statics::NewProp_Result_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USESaveManager_BPLoadSlotById_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventBPLoadSlotById_Parms, Result), Z_Construct_UEnum_SaveExtension_ESELoadGameResult, METADATA_PARAMS(nullptr, 0) }; // 4094298572
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USESaveManager_BPLoadSlotById_Statics::NewProp_LatentInfo = { "LatentInfo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventBPLoadSlotById_Parms, LatentInfo), Z_Construct_UScriptStruct_FLatentActionInfo, METADATA_PARAMS(nullptr, 0) }; // 2194022737
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESaveManager_BPLoadSlotById_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPLoadSlotById_Statics::NewProp_SlotId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPLoadSlotById_Statics::NewProp_Result_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPLoadSlotById_Statics::NewProp_Result,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPLoadSlotById_Statics::NewProp_LatentInfo,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_BPLoadSlotById_Statics::Function_MetaDataParams[] = {
		{ "Category", "SaveExtension|Loading" },
		{ "Comment", "/** Load game from a slot Id */" },
		{ "DisplayName", "Load Slot by Id" },
		{ "ExpandEnumAsExecs", "Result" },
		{ "Latent", "" },
		{ "LatentInfo", "LatentInfo" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
		{ "ToolTip", "Load game from a slot Id" },
		{ "UnsafeDuringActorConstruction", "" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESaveManager_BPLoadSlotById_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESaveManager, nullptr, "BPLoadSlotById", nullptr, nullptr, sizeof(Z_Construct_UFunction_USESaveManager_BPLoadSlotById_Statics::SESaveManager_eventBPLoadSlotById_Parms), Z_Construct_UFunction_USESaveManager_BPLoadSlotById_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_BPLoadSlotById_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_BPLoadSlotById_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_BPLoadSlotById_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESaveManager_BPLoadSlotById()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESaveManager_BPLoadSlotById_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USESaveManager_BPLoadSlotByInfo_Statics
	{
		struct SESaveManager_eventBPLoadSlotByInfo_Parms
		{
			const USESlotInfo* SlotInfo;
			ESELoadGameResult Result;
			FLatentActionInfo LatentInfo;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SlotInfo_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SlotInfo;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UECodeGen_Private::FStructPropertyParams NewProp_LatentInfo;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_BPLoadSlotByInfo_Statics::NewProp_SlotInfo_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USESaveManager_BPLoadSlotByInfo_Statics::NewProp_SlotInfo = { "SlotInfo", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventBPLoadSlotByInfo_Parms, SlotInfo), Z_Construct_UClass_USESlotInfo_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_BPLoadSlotByInfo_Statics::NewProp_SlotInfo_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_BPLoadSlotByInfo_Statics::NewProp_SlotInfo_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USESaveManager_BPLoadSlotByInfo_Statics::NewProp_Result_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USESaveManager_BPLoadSlotByInfo_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventBPLoadSlotByInfo_Parms, Result), Z_Construct_UEnum_SaveExtension_ESELoadGameResult, METADATA_PARAMS(nullptr, 0) }; // 4094298572
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USESaveManager_BPLoadSlotByInfo_Statics::NewProp_LatentInfo = { "LatentInfo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventBPLoadSlotByInfo_Parms, LatentInfo), Z_Construct_UScriptStruct_FLatentActionInfo, METADATA_PARAMS(nullptr, 0) }; // 2194022737
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESaveManager_BPLoadSlotByInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPLoadSlotByInfo_Statics::NewProp_SlotInfo,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPLoadSlotByInfo_Statics::NewProp_Result_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPLoadSlotByInfo_Statics::NewProp_Result,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPLoadSlotByInfo_Statics::NewProp_LatentInfo,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_BPLoadSlotByInfo_Statics::Function_MetaDataParams[] = {
		{ "Category", "SaveExtension|Loading" },
		{ "Comment", "/** Load game from a SlotInfo */" },
		{ "DisplayName", "Load Slot by Info" },
		{ "ExpandEnumAsExecs", "Result" },
		{ "Latent", "" },
		{ "LatentInfo", "LatentInfo" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
		{ "ToolTip", "Load game from a SlotInfo" },
		{ "UnsafeDuringActorConstruction", "" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESaveManager_BPLoadSlotByInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESaveManager, nullptr, "BPLoadSlotByInfo", nullptr, nullptr, sizeof(Z_Construct_UFunction_USESaveManager_BPLoadSlotByInfo_Statics::SESaveManager_eventBPLoadSlotByInfo_Parms), Z_Construct_UFunction_USESaveManager_BPLoadSlotByInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_BPLoadSlotByInfo_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_BPLoadSlotByInfo_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_BPLoadSlotByInfo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESaveManager_BPLoadSlotByInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESaveManager_BPLoadSlotByInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USESaveManager_BPReloadCurrentSlot_Statics
	{
		struct SESaveManager_eventBPReloadCurrentSlot_Parms
		{
			ESELoadGameResult Result;
			FLatentActionInfo LatentInfo;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UECodeGen_Private::FStructPropertyParams NewProp_LatentInfo;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USESaveManager_BPReloadCurrentSlot_Statics::NewProp_Result_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USESaveManager_BPReloadCurrentSlot_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventBPReloadCurrentSlot_Parms, Result), Z_Construct_UEnum_SaveExtension_ESELoadGameResult, METADATA_PARAMS(nullptr, 0) }; // 4094298572
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USESaveManager_BPReloadCurrentSlot_Statics::NewProp_LatentInfo = { "LatentInfo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventBPReloadCurrentSlot_Parms, LatentInfo), Z_Construct_UScriptStruct_FLatentActionInfo, METADATA_PARAMS(nullptr, 0) }; // 2194022737
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESaveManager_BPReloadCurrentSlot_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPReloadCurrentSlot_Statics::NewProp_Result_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPReloadCurrentSlot_Statics::NewProp_Result,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPReloadCurrentSlot_Statics::NewProp_LatentInfo,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_BPReloadCurrentSlot_Statics::Function_MetaDataParams[] = {
		{ "Category", "SaveExtension|Loading" },
		{ "Comment", "/** Reload the currently loaded slot if any */" },
		{ "DisplayName", "Reload Current Slot" },
		{ "ExpandEnumAsExecs", "Result" },
		{ "Latent", "" },
		{ "LatentInfo", "LatentInfo" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
		{ "ToolTip", "Reload the currently loaded slot if any" },
		{ "UnsafeDuringActorConstruction", "" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESaveManager_BPReloadCurrentSlot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESaveManager, nullptr, "BPReloadCurrentSlot", nullptr, nullptr, sizeof(Z_Construct_UFunction_USESaveManager_BPReloadCurrentSlot_Statics::SESaveManager_eventBPReloadCurrentSlot_Parms), Z_Construct_UFunction_USESaveManager_BPReloadCurrentSlot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_BPReloadCurrentSlot_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_BPReloadCurrentSlot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_BPReloadCurrentSlot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESaveManager_BPReloadCurrentSlot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESaveManager_BPReloadCurrentSlot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USESaveManager_BPSaveCurrentSlot_Statics
	{
		struct SESaveManager_eventBPSaveCurrentSlot_Parms
		{
			bool bScreenshot;
			FSEScreenshotSize Size;
			ESESaveGameResult Result;
			FLatentActionInfo LatentInfo;
		};
		static void NewProp_bScreenshot_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bScreenshot;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Size_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Size;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UECodeGen_Private::FStructPropertyParams NewProp_LatentInfo;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USESaveManager_BPSaveCurrentSlot_Statics::NewProp_bScreenshot_SetBit(void* Obj)
	{
		((SESaveManager_eventBPSaveCurrentSlot_Parms*)Obj)->bScreenshot = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USESaveManager_BPSaveCurrentSlot_Statics::NewProp_bScreenshot = { "bScreenshot", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(SESaveManager_eventBPSaveCurrentSlot_Parms), &Z_Construct_UFunction_USESaveManager_BPSaveCurrentSlot_Statics::NewProp_bScreenshot_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_BPSaveCurrentSlot_Statics::NewProp_Size_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USESaveManager_BPSaveCurrentSlot_Statics::NewProp_Size = { "Size", nullptr, (EPropertyFlags)0x0010040000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventBPSaveCurrentSlot_Parms, Size), Z_Construct_UScriptStruct_FSEScreenshotSize, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_BPSaveCurrentSlot_Statics::NewProp_Size_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_BPSaveCurrentSlot_Statics::NewProp_Size_MetaData)) }; // 379114064
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USESaveManager_BPSaveCurrentSlot_Statics::NewProp_Result_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USESaveManager_BPSaveCurrentSlot_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventBPSaveCurrentSlot_Parms, Result), Z_Construct_UEnum_SaveExtension_ESESaveGameResult, METADATA_PARAMS(nullptr, 0) }; // 1257066789
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USESaveManager_BPSaveCurrentSlot_Statics::NewProp_LatentInfo = { "LatentInfo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventBPSaveCurrentSlot_Parms, LatentInfo), Z_Construct_UScriptStruct_FLatentActionInfo, METADATA_PARAMS(nullptr, 0) }; // 2194022737
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESaveManager_BPSaveCurrentSlot_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPSaveCurrentSlot_Statics::NewProp_bScreenshot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPSaveCurrentSlot_Statics::NewProp_Size,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPSaveCurrentSlot_Statics::NewProp_Result_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPSaveCurrentSlot_Statics::NewProp_Result,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPSaveCurrentSlot_Statics::NewProp_LatentInfo,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_BPSaveCurrentSlot_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "bScreenshot, Size" },
		{ "Category", "SaveExtension|Saving" },
		{ "Comment", "/** Save the currently loaded Slot */" },
		{ "DisplayName", "Save Current Slot" },
		{ "ExpandEnumAsExecs", "Result" },
		{ "Latent", "" },
		{ "LatentInfo", "LatentInfo" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
		{ "ToolTip", "Save the currently loaded Slot" },
		{ "UnsafeDuringActorConstruction", "" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESaveManager_BPSaveCurrentSlot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESaveManager, nullptr, "BPSaveCurrentSlot", nullptr, nullptr, sizeof(Z_Construct_UFunction_USESaveManager_BPSaveCurrentSlot_Statics::SESaveManager_eventBPSaveCurrentSlot_Parms), Z_Construct_UFunction_USESaveManager_BPSaveCurrentSlot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_BPSaveCurrentSlot_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_BPSaveCurrentSlot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_BPSaveCurrentSlot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESaveManager_BPSaveCurrentSlot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESaveManager_BPSaveCurrentSlot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USESaveManager_BPSaveSlot_Statics
	{
		struct SESaveManager_eventBPSaveSlot_Parms
		{
			FName SlotName;
			bool bScreenshot;
			FSEScreenshotSize Size;
			ESESaveGameResult Result;
			FLatentActionInfo LatentInfo;
			bool bOverrideIfNeeded;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_SlotName;
		static void NewProp_bScreenshot_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bScreenshot;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Size_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Size;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UECodeGen_Private::FStructPropertyParams NewProp_LatentInfo;
		static void NewProp_bOverrideIfNeeded_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverrideIfNeeded;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_USESaveManager_BPSaveSlot_Statics::NewProp_SlotName = { "SlotName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventBPSaveSlot_Parms, SlotName), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USESaveManager_BPSaveSlot_Statics::NewProp_bScreenshot_SetBit(void* Obj)
	{
		((SESaveManager_eventBPSaveSlot_Parms*)Obj)->bScreenshot = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USESaveManager_BPSaveSlot_Statics::NewProp_bScreenshot = { "bScreenshot", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(SESaveManager_eventBPSaveSlot_Parms), &Z_Construct_UFunction_USESaveManager_BPSaveSlot_Statics::NewProp_bScreenshot_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_BPSaveSlot_Statics::NewProp_Size_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USESaveManager_BPSaveSlot_Statics::NewProp_Size = { "Size", nullptr, (EPropertyFlags)0x0010040000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventBPSaveSlot_Parms, Size), Z_Construct_UScriptStruct_FSEScreenshotSize, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_BPSaveSlot_Statics::NewProp_Size_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_BPSaveSlot_Statics::NewProp_Size_MetaData)) }; // 379114064
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USESaveManager_BPSaveSlot_Statics::NewProp_Result_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USESaveManager_BPSaveSlot_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventBPSaveSlot_Parms, Result), Z_Construct_UEnum_SaveExtension_ESESaveGameResult, METADATA_PARAMS(nullptr, 0) }; // 1257066789
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USESaveManager_BPSaveSlot_Statics::NewProp_LatentInfo = { "LatentInfo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventBPSaveSlot_Parms, LatentInfo), Z_Construct_UScriptStruct_FLatentActionInfo, METADATA_PARAMS(nullptr, 0) }; // 2194022737
	void Z_Construct_UFunction_USESaveManager_BPSaveSlot_Statics::NewProp_bOverrideIfNeeded_SetBit(void* Obj)
	{
		((SESaveManager_eventBPSaveSlot_Parms*)Obj)->bOverrideIfNeeded = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USESaveManager_BPSaveSlot_Statics::NewProp_bOverrideIfNeeded = { "bOverrideIfNeeded", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(SESaveManager_eventBPSaveSlot_Parms), &Z_Construct_UFunction_USESaveManager_BPSaveSlot_Statics::NewProp_bOverrideIfNeeded_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESaveManager_BPSaveSlot_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPSaveSlot_Statics::NewProp_SlotName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPSaveSlot_Statics::NewProp_bScreenshot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPSaveSlot_Statics::NewProp_Size,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPSaveSlot_Statics::NewProp_Result_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPSaveSlot_Statics::NewProp_Result,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPSaveSlot_Statics::NewProp_LatentInfo,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPSaveSlot_Statics::NewProp_bOverrideIfNeeded,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_BPSaveSlot_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "bScreenshot, Size" },
		{ "Category", "SaveExtension|Saving" },
		{ "Comment", "/** Save the Game into an specified Slot */" },
		{ "CPP_Default_bOverrideIfNeeded", "true" },
		{ "DisplayName", "Save Slot" },
		{ "ExpandEnumAsExecs", "Result" },
		{ "Latent", "" },
		{ "LatentInfo", "LatentInfo" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
		{ "ToolTip", "Save the Game into an specified Slot" },
		{ "UnsafeDuringActorConstruction", "" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESaveManager_BPSaveSlot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESaveManager, nullptr, "BPSaveSlot", nullptr, nullptr, sizeof(Z_Construct_UFunction_USESaveManager_BPSaveSlot_Statics::SESaveManager_eventBPSaveSlot_Parms), Z_Construct_UFunction_USESaveManager_BPSaveSlot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_BPSaveSlot_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_BPSaveSlot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_BPSaveSlot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESaveManager_BPSaveSlot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESaveManager_BPSaveSlot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USESaveManager_BPSaveSlotById_Statics
	{
		struct SESaveManager_eventBPSaveSlotById_Parms
		{
			int32 SlotId;
			bool bScreenshot;
			FSEScreenshotSize Size;
			ESESaveGameResult Result;
			FLatentActionInfo LatentInfo;
			bool bOverrideIfNeeded;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_SlotId;
		static void NewProp_bScreenshot_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bScreenshot;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Size_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Size;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UECodeGen_Private::FStructPropertyParams NewProp_LatentInfo;
		static void NewProp_bOverrideIfNeeded_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverrideIfNeeded;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USESaveManager_BPSaveSlotById_Statics::NewProp_SlotId = { "SlotId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventBPSaveSlotById_Parms, SlotId), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USESaveManager_BPSaveSlotById_Statics::NewProp_bScreenshot_SetBit(void* Obj)
	{
		((SESaveManager_eventBPSaveSlotById_Parms*)Obj)->bScreenshot = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USESaveManager_BPSaveSlotById_Statics::NewProp_bScreenshot = { "bScreenshot", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(SESaveManager_eventBPSaveSlotById_Parms), &Z_Construct_UFunction_USESaveManager_BPSaveSlotById_Statics::NewProp_bScreenshot_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_BPSaveSlotById_Statics::NewProp_Size_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USESaveManager_BPSaveSlotById_Statics::NewProp_Size = { "Size", nullptr, (EPropertyFlags)0x0010040000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventBPSaveSlotById_Parms, Size), Z_Construct_UScriptStruct_FSEScreenshotSize, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_BPSaveSlotById_Statics::NewProp_Size_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_BPSaveSlotById_Statics::NewProp_Size_MetaData)) }; // 379114064
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USESaveManager_BPSaveSlotById_Statics::NewProp_Result_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USESaveManager_BPSaveSlotById_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventBPSaveSlotById_Parms, Result), Z_Construct_UEnum_SaveExtension_ESESaveGameResult, METADATA_PARAMS(nullptr, 0) }; // 1257066789
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USESaveManager_BPSaveSlotById_Statics::NewProp_LatentInfo = { "LatentInfo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventBPSaveSlotById_Parms, LatentInfo), Z_Construct_UScriptStruct_FLatentActionInfo, METADATA_PARAMS(nullptr, 0) }; // 2194022737
	void Z_Construct_UFunction_USESaveManager_BPSaveSlotById_Statics::NewProp_bOverrideIfNeeded_SetBit(void* Obj)
	{
		((SESaveManager_eventBPSaveSlotById_Parms*)Obj)->bOverrideIfNeeded = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USESaveManager_BPSaveSlotById_Statics::NewProp_bOverrideIfNeeded = { "bOverrideIfNeeded", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(SESaveManager_eventBPSaveSlotById_Parms), &Z_Construct_UFunction_USESaveManager_BPSaveSlotById_Statics::NewProp_bOverrideIfNeeded_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESaveManager_BPSaveSlotById_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPSaveSlotById_Statics::NewProp_SlotId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPSaveSlotById_Statics::NewProp_bScreenshot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPSaveSlotById_Statics::NewProp_Size,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPSaveSlotById_Statics::NewProp_Result_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPSaveSlotById_Statics::NewProp_Result,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPSaveSlotById_Statics::NewProp_LatentInfo,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPSaveSlotById_Statics::NewProp_bOverrideIfNeeded,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_BPSaveSlotById_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "bScreenshot, Size" },
		{ "Category", "SaveExtension|Saving" },
		{ "Comment", "/** Save the Game into an specified Slot */" },
		{ "CPP_Default_bOverrideIfNeeded", "true" },
		{ "DisplayName", "Save Slot by Id" },
		{ "ExpandEnumAsExecs", "Result" },
		{ "Latent", "" },
		{ "LatentInfo", "LatentInfo" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
		{ "ToolTip", "Save the Game into an specified Slot" },
		{ "UnsafeDuringActorConstruction", "" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESaveManager_BPSaveSlotById_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESaveManager, nullptr, "BPSaveSlotById", nullptr, nullptr, sizeof(Z_Construct_UFunction_USESaveManager_BPSaveSlotById_Statics::SESaveManager_eventBPSaveSlotById_Parms), Z_Construct_UFunction_USESaveManager_BPSaveSlotById_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_BPSaveSlotById_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_BPSaveSlotById_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_BPSaveSlotById_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESaveManager_BPSaveSlotById()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESaveManager_BPSaveSlotById_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics
	{
		struct SESaveManager_eventBPSaveSlotByInfo_Parms
		{
			const USESlotInfo* SlotInfo;
			bool bScreenshot;
			FSEScreenshotSize Size;
			ESESaveGameResult Result;
			FLatentActionInfo LatentInfo;
			bool bOverrideIfNeeded;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SlotInfo_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SlotInfo;
		static void NewProp_bScreenshot_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bScreenshot;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Size_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Size;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Result_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Result;
		static const UECodeGen_Private::FStructPropertyParams NewProp_LatentInfo;
		static void NewProp_bOverrideIfNeeded_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverrideIfNeeded;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::NewProp_SlotInfo_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::NewProp_SlotInfo = { "SlotInfo", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventBPSaveSlotByInfo_Parms, SlotInfo), Z_Construct_UClass_USESlotInfo_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::NewProp_SlotInfo_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::NewProp_SlotInfo_MetaData)) };
	void Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::NewProp_bScreenshot_SetBit(void* Obj)
	{
		((SESaveManager_eventBPSaveSlotByInfo_Parms*)Obj)->bScreenshot = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::NewProp_bScreenshot = { "bScreenshot", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(SESaveManager_eventBPSaveSlotByInfo_Parms), &Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::NewProp_bScreenshot_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::NewProp_Size_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::NewProp_Size = { "Size", nullptr, (EPropertyFlags)0x0010040000000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventBPSaveSlotByInfo_Parms, Size), Z_Construct_UScriptStruct_FSEScreenshotSize, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::NewProp_Size_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::NewProp_Size_MetaData)) }; // 379114064
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::NewProp_Result_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventBPSaveSlotByInfo_Parms, Result), Z_Construct_UEnum_SaveExtension_ESESaveGameResult, METADATA_PARAMS(nullptr, 0) }; // 1257066789
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::NewProp_LatentInfo = { "LatentInfo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventBPSaveSlotByInfo_Parms, LatentInfo), Z_Construct_UScriptStruct_FLatentActionInfo, METADATA_PARAMS(nullptr, 0) }; // 2194022737
	void Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::NewProp_bOverrideIfNeeded_SetBit(void* Obj)
	{
		((SESaveManager_eventBPSaveSlotByInfo_Parms*)Obj)->bOverrideIfNeeded = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::NewProp_bOverrideIfNeeded = { "bOverrideIfNeeded", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(SESaveManager_eventBPSaveSlotByInfo_Parms), &Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::NewProp_bOverrideIfNeeded_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::NewProp_SlotInfo,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::NewProp_bScreenshot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::NewProp_Size,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::NewProp_Result_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::NewProp_Result,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::NewProp_LatentInfo,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::NewProp_bOverrideIfNeeded,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "bScreenshot, Size" },
		{ "Category", "SaveExtension|Saving" },
		{ "Comment", "/** Save the Game to a Slot */" },
		{ "CPP_Default_bOverrideIfNeeded", "true" },
		{ "DisplayName", "Save Slot by Info" },
		{ "ExpandEnumAsExecs", "Result" },
		{ "Latent", "" },
		{ "LatentInfo", "LatentInfo" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
		{ "ToolTip", "Save the Game to a Slot" },
		{ "UnsafeDuringActorConstruction", "" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESaveManager, nullptr, "BPSaveSlotByInfo", nullptr, nullptr, sizeof(Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::SESaveManager_eventBPSaveSlotByInfo_Parms), Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USESaveManager_DeleteSlot_Statics
	{
		struct SESaveManager_eventDeleteSlot_Parms
		{
			USESlotInfo* Slot;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Slot;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USESaveManager_DeleteSlot_Statics::NewProp_Slot = { "Slot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventDeleteSlot_Parms, Slot), Z_Construct_UClass_USESlotInfo_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USESaveManager_DeleteSlot_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SESaveManager_eventDeleteSlot_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USESaveManager_DeleteSlot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(SESaveManager_eventDeleteSlot_Parms), &Z_Construct_UFunction_USESaveManager_DeleteSlot_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESaveManager_DeleteSlot_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_DeleteSlot_Statics::NewProp_Slot,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_DeleteSlot_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_DeleteSlot_Statics::Function_MetaDataParams[] = {
		{ "Category", "SaveExtension" },
		{ "Comment", "/** Delete a saved game on an specified slot\n\x09 * Performance: Interacts with disk, can be slow\n\x09 */" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
		{ "ToolTip", "Delete a saved game on an specified slot\nPerformance: Interacts with disk, can be slow" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESaveManager_DeleteSlot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESaveManager, nullptr, "DeleteSlot", nullptr, nullptr, sizeof(Z_Construct_UFunction_USESaveManager_DeleteSlot_Statics::SESaveManager_eventDeleteSlot_Parms), Z_Construct_UFunction_USESaveManager_DeleteSlot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_DeleteSlot_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_DeleteSlot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_DeleteSlot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESaveManager_DeleteSlot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESaveManager_DeleteSlot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USESaveManager_DeleteSlotById_Statics
	{
		struct SESaveManager_eventDeleteSlotById_Parms
		{
			int32 SlotId;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_SlotId;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USESaveManager_DeleteSlotById_Statics::NewProp_SlotId = { "SlotId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventDeleteSlotById_Parms, SlotId), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USESaveManager_DeleteSlotById_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SESaveManager_eventDeleteSlotById_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USESaveManager_DeleteSlotById_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(SESaveManager_eventDeleteSlotById_Parms), &Z_Construct_UFunction_USESaveManager_DeleteSlotById_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESaveManager_DeleteSlotById_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_DeleteSlotById_Statics::NewProp_SlotId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_DeleteSlotById_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_DeleteSlotById_Statics::Function_MetaDataParams[] = {
		{ "Category", "SaveExtension" },
		{ "Comment", "/** Delete a saved game on an specified slot Id\n\x09 * Performance: Interacts with disk, can be slow\n\x09 */" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
		{ "ToolTip", "Delete a saved game on an specified slot Id\nPerformance: Interacts with disk, can be slow" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESaveManager_DeleteSlotById_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESaveManager, nullptr, "DeleteSlotById", nullptr, nullptr, sizeof(Z_Construct_UFunction_USESaveManager_DeleteSlotById_Statics::SESaveManager_eventDeleteSlotById_Parms), Z_Construct_UFunction_USESaveManager_DeleteSlotById_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_DeleteSlotById_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_DeleteSlotById_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_DeleteSlotById_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESaveManager_DeleteSlotById()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESaveManager_DeleteSlotById_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USESaveManager_DeserializeStreamingLevel_Statics
	{
		struct SESaveManager_eventDeserializeStreamingLevel_Parms
		{
			ULevelStreaming* LevelStreaming;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LevelStreaming;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USESaveManager_DeserializeStreamingLevel_Statics::NewProp_LevelStreaming = { "LevelStreaming", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventDeserializeStreamingLevel_Parms, LevelStreaming), Z_Construct_UClass_ULevelStreaming_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESaveManager_DeserializeStreamingLevel_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_DeserializeStreamingLevel_Statics::NewProp_LevelStreaming,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_DeserializeStreamingLevel_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESaveManager_DeserializeStreamingLevel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESaveManager, nullptr, "DeserializeStreamingLevel", nullptr, nullptr, sizeof(Z_Construct_UFunction_USESaveManager_DeserializeStreamingLevel_Statics::SESaveManager_eventDeserializeStreamingLevel_Parms), Z_Construct_UFunction_USESaveManager_DeserializeStreamingLevel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_DeserializeStreamingLevel_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_DeserializeStreamingLevel_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_DeserializeStreamingLevel_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESaveManager_DeserializeStreamingLevel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESaveManager_DeserializeStreamingLevel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USESaveManager_GetCurrentData_Statics
	{
		struct SESaveManager_eventGetCurrentData_Parms
		{
			USESlotData* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USESaveManager_GetCurrentData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventGetCurrentData_Parms, ReturnValue), Z_Construct_UClass_USESlotData_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESaveManager_GetCurrentData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_GetCurrentData_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_GetCurrentData_Statics::Function_MetaDataParams[] = {
		{ "Category", "SaveExtension" },
		{ "Comment", "/** Get the currently loaded SlotData. If game was never loaded returns an empty SlotData  */" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
		{ "ToolTip", "Get the currently loaded SlotData. If game was never loaded returns an empty SlotData" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESaveManager_GetCurrentData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESaveManager, nullptr, "GetCurrentData", nullptr, nullptr, sizeof(Z_Construct_UFunction_USESaveManager_GetCurrentData_Statics::SESaveManager_eventGetCurrentData_Parms), Z_Construct_UFunction_USESaveManager_GetCurrentData_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_GetCurrentData_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_GetCurrentData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_GetCurrentData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESaveManager_GetCurrentData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESaveManager_GetCurrentData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USESaveManager_GetCurrentInfo_Statics
	{
		struct SESaveManager_eventGetCurrentInfo_Parms
		{
			USESlotInfo* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USESaveManager_GetCurrentInfo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventGetCurrentInfo_Parms, ReturnValue), Z_Construct_UClass_USESlotInfo_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESaveManager_GetCurrentInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_GetCurrentInfo_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_GetCurrentInfo_Statics::Function_MetaDataParams[] = {
		{ "Category", "SaveExtension" },
		{ "Comment", "/** Get the currently loaded SlotInfo. If game was never loaded returns a new SlotInfo */" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
		{ "ToolTip", "Get the currently loaded SlotInfo. If game was never loaded returns a new SlotInfo" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESaveManager_GetCurrentInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESaveManager, nullptr, "GetCurrentInfo", nullptr, nullptr, sizeof(Z_Construct_UFunction_USESaveManager_GetCurrentInfo_Statics::SESaveManager_eventGetCurrentInfo_Parms), Z_Construct_UFunction_USESaveManager_GetCurrentInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_GetCurrentInfo_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_GetCurrentInfo_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_GetCurrentInfo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESaveManager_GetCurrentInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESaveManager_GetCurrentInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USESaveManager_GetSlotInfo_Statics
	{
		struct SESaveManager_eventGetSlotInfo_Parms
		{
			int32 SlotId;
			USESlotInfo* ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_SlotId;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USESaveManager_GetSlotInfo_Statics::NewProp_SlotId = { "SlotId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventGetSlotInfo_Parms, SlotId), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USESaveManager_GetSlotInfo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventGetSlotInfo_Parms, ReturnValue), Z_Construct_UClass_USESlotInfo_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESaveManager_GetSlotInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_GetSlotInfo_Statics::NewProp_SlotId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_GetSlotInfo_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_GetSlotInfo_Statics::Function_MetaDataParams[] = {
		{ "Category", "SaveExtension|Slots" },
		{ "Comment", "/**\n\x09 * Load and return an SlotInfo by Id if it exists\n\x09 * Performance: Interacts with disk, could be slow if called frequently\n\x09 * @param SlotId Id of the SlotInfo to be loaded\n\x09 * @return the SlotInfo associated with an Id\n\x09 */" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
		{ "ToolTip", "Load and return an SlotInfo by Id if it exists\nPerformance: Interacts with disk, could be slow if called frequently\n@param SlotId Id of the SlotInfo to be loaded\n@return the SlotInfo associated with an Id" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESaveManager_GetSlotInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESaveManager, nullptr, "GetSlotInfo", nullptr, nullptr, sizeof(Z_Construct_UFunction_USESaveManager_GetSlotInfo_Statics::SESaveManager_eventGetSlotInfo_Parms), Z_Construct_UFunction_USESaveManager_GetSlotInfo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_GetSlotInfo_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_GetSlotInfo_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_GetSlotInfo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESaveManager_GetSlotInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESaveManager_GetSlotInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USESaveManager_GetSlotNameFromId_Statics
	{
		struct SESaveManager_eventGetSlotNameFromId_Parms
		{
			int32 SlotId;
			FName ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SlotId_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_SlotId;
		static const UECodeGen_Private::FNamePropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_GetSlotNameFromId_Statics::NewProp_SlotId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USESaveManager_GetSlotNameFromId_Statics::NewProp_SlotId = { "SlotId", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventGetSlotNameFromId_Parms, SlotId), METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_GetSlotNameFromId_Statics::NewProp_SlotId_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_GetSlotNameFromId_Statics::NewProp_SlotId_MetaData)) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_USESaveManager_GetSlotNameFromId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventGetSlotNameFromId_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESaveManager_GetSlotNameFromId_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_GetSlotNameFromId_Statics::NewProp_SlotId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_GetSlotNameFromId_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_GetSlotNameFromId_Statics::Function_MetaDataParams[] = {
		{ "Category", "SaveExtension" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESaveManager_GetSlotNameFromId_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESaveManager, nullptr, "GetSlotNameFromId", nullptr, nullptr, sizeof(Z_Construct_UFunction_USESaveManager_GetSlotNameFromId_Statics::SESaveManager_eventGetSlotNameFromId_Parms), Z_Construct_UFunction_USESaveManager_GetSlotNameFromId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_GetSlotNameFromId_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_GetSlotNameFromId_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_GetSlotNameFromId_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESaveManager_GetSlotNameFromId()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESaveManager_GetSlotNameFromId_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USESaveManager_IsInSlot_Statics
	{
		struct SESaveManager_eventIsInSlot_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USESaveManager_IsInSlot_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SESaveManager_eventIsInSlot_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USESaveManager_IsInSlot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(SESaveManager_eventIsInSlot_Parms), &Z_Construct_UFunction_USESaveManager_IsInSlot_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESaveManager_IsInSlot_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_IsInSlot_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_IsInSlot_Statics::Function_MetaDataParams[] = {
		{ "Category", "SaveExtension|Slots" },
		{ "Comment", "/** Check if currently playing in a saved slot\n\x09 * @return true if currently playing in a saved slot\n\x09 */" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
		{ "ToolTip", "Check if currently playing in a saved slot\n@return true if currently playing in a saved slot" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESaveManager_IsInSlot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESaveManager, nullptr, "IsInSlot", nullptr, nullptr, sizeof(Z_Construct_UFunction_USESaveManager_IsInSlot_Statics::SESaveManager_eventIsInSlot_Parms), Z_Construct_UFunction_USESaveManager_IsInSlot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_IsInSlot_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_IsInSlot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_IsInSlot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESaveManager_IsInSlot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESaveManager_IsInSlot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USESaveManager_IsSavingOrLoading_Statics
	{
		struct SESaveManager_eventIsSavingOrLoading_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USESaveManager_IsSavingOrLoading_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SESaveManager_eventIsSavingOrLoading_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USESaveManager_IsSavingOrLoading_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(SESaveManager_eventIsSavingOrLoading_Parms), &Z_Construct_UFunction_USESaveManager_IsSavingOrLoading_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESaveManager_IsSavingOrLoading_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_IsSavingOrLoading_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_IsSavingOrLoading_Statics::Function_MetaDataParams[] = {
		{ "Category", "SaveExtension" },
		{ "Comment", "/** @return true when saving or loading anything, including levels */" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
		{ "ToolTip", "@return true when saving or loading anything, including levels" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESaveManager_IsSavingOrLoading_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESaveManager, nullptr, "IsSavingOrLoading", nullptr, nullptr, sizeof(Z_Construct_UFunction_USESaveManager_IsSavingOrLoading_Statics::SESaveManager_eventIsSavingOrLoading_Parms), Z_Construct_UFunction_USESaveManager_IsSavingOrLoading_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_IsSavingOrLoading_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_IsSavingOrLoading_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_IsSavingOrLoading_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESaveManager_IsSavingOrLoading()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESaveManager_IsSavingOrLoading_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USESaveManager_IsSlotSaved_Statics
	{
		struct SESaveManager_eventIsSlotSaved_Parms
		{
			FName SlotName;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_SlotName;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_USESaveManager_IsSlotSaved_Statics::NewProp_SlotName = { "SlotName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventIsSlotSaved_Parms, SlotName), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USESaveManager_IsSlotSaved_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SESaveManager_eventIsSlotSaved_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USESaveManager_IsSlotSaved_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(SESaveManager_eventIsSlotSaved_Parms), &Z_Construct_UFunction_USESaveManager_IsSlotSaved_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESaveManager_IsSlotSaved_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_IsSlotSaved_Statics::NewProp_SlotName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_IsSlotSaved_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_IsSlotSaved_Statics::Function_MetaDataParams[] = {
		{ "Category", "SaveExtension|Slots" },
		{ "Comment", "/** Check if an slot exists on disk\n\x09 * @return true if the slot exists\n\x09 */" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
		{ "ToolTip", "Check if an slot exists on disk\n@return true if the slot exists" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESaveManager_IsSlotSaved_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESaveManager, nullptr, "IsSlotSaved", nullptr, nullptr, sizeof(Z_Construct_UFunction_USESaveManager_IsSlotSaved_Statics::SESaveManager_eventIsSlotSaved_Parms), Z_Construct_UFunction_USESaveManager_IsSlotSaved_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_IsSlotSaved_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_IsSlotSaved_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_IsSlotSaved_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESaveManager_IsSlotSaved()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESaveManager_IsSlotSaved_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USESaveManager_IsSlotSavedById_Statics
	{
		struct SESaveManager_eventIsSlotSavedById_Parms
		{
			int32 SlotId;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_SlotId;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USESaveManager_IsSlotSavedById_Statics::NewProp_SlotId = { "SlotId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventIsSlotSavedById_Parms, SlotId), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USESaveManager_IsSlotSavedById_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SESaveManager_eventIsSlotSavedById_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USESaveManager_IsSlotSavedById_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(SESaveManager_eventIsSlotSavedById_Parms), &Z_Construct_UFunction_USESaveManager_IsSlotSavedById_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESaveManager_IsSlotSavedById_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_IsSlotSavedById_Statics::NewProp_SlotId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_IsSlotSavedById_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_IsSlotSavedById_Statics::Function_MetaDataParams[] = {
		{ "Category", "SaveExtension|Slots" },
		{ "Comment", "/** Check if an slot exists on disk\n\x09 * @return true if the slot exists\n\x09 */" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
		{ "ToolTip", "Check if an slot exists on disk\n@return true if the slot exists" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESaveManager_IsSlotSavedById_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESaveManager, nullptr, "IsSlotSavedById", nullptr, nullptr, sizeof(Z_Construct_UFunction_USESaveManager_IsSlotSavedById_Statics::SESaveManager_eventIsSlotSavedById_Parms), Z_Construct_UFunction_USESaveManager_IsSlotSavedById_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_IsSlotSavedById_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_IsSlotSavedById_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_IsSlotSavedById_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESaveManager_IsSlotSavedById()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESaveManager_IsSlotSavedById_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USESaveManager_SerializeStreamingLevel_Statics
	{
		struct SESaveManager_eventSerializeStreamingLevel_Parms
		{
			ULevelStreaming* LevelStreaming;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LevelStreaming;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USESaveManager_SerializeStreamingLevel_Statics::NewProp_LevelStreaming = { "LevelStreaming", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventSerializeStreamingLevel_Parms, LevelStreaming), Z_Construct_UClass_ULevelStreaming_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESaveManager_SerializeStreamingLevel_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_SerializeStreamingLevel_Statics::NewProp_LevelStreaming,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_SerializeStreamingLevel_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESaveManager_SerializeStreamingLevel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESaveManager, nullptr, "SerializeStreamingLevel", nullptr, nullptr, sizeof(Z_Construct_UFunction_USESaveManager_SerializeStreamingLevel_Statics::SESaveManager_eventSerializeStreamingLevel_Parms), Z_Construct_UFunction_USESaveManager_SerializeStreamingLevel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_SerializeStreamingLevel_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_SerializeStreamingLevel_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_SerializeStreamingLevel_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESaveManager_SerializeStreamingLevel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESaveManager_SerializeStreamingLevel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USESaveManager_SetActivePreset_Statics
	{
		struct SESaveManager_eventSetActivePreset_Parms
		{
			TSubclassOf<USESavePreset>  PresetClass;
			USESavePreset* ReturnValue;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_PresetClass;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_USESaveManager_SetActivePreset_Statics::NewProp_PresetClass = { "PresetClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventSetActivePreset_Parms, PresetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_USESavePreset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USESaveManager_SetActivePreset_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventSetActivePreset_Parms, ReturnValue), Z_Construct_UClass_USESavePreset_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESaveManager_SetActivePreset_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_SetActivePreset_Statics::NewProp_PresetClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_SetActivePreset_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_SetActivePreset_Statics::Function_MetaDataParams[] = {
		{ "Category", "SaveExtension" },
		{ "Comment", "/**\n\x09 * Set the preset to be used for saving and loading\n\x09 * @return true if the preset was set successfully\n\x09 */" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
		{ "ToolTip", "Set the preset to be used for saving and loading\n@return true if the preset was set successfully" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESaveManager_SetActivePreset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESaveManager, nullptr, "SetActivePreset", nullptr, nullptr, sizeof(Z_Construct_UFunction_USESaveManager_SetActivePreset_Statics::SESaveManager_eventSetActivePreset_Parms), Z_Construct_UFunction_USESaveManager_SetActivePreset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_SetActivePreset_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_SetActivePreset_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_SetActivePreset_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESaveManager_SetActivePreset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESaveManager_SetActivePreset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USESaveManager_SubscribeForEvents_Statics
	{
		struct SESaveManager_eventSubscribeForEvents_Parms
		{
			TScriptInterface<ISESaveInterface> Interface;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Interface_MetaData[];
#endif
		static const UECodeGen_Private::FInterfacePropertyParams NewProp_Interface;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_SubscribeForEvents_Statics::NewProp_Interface_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UFunction_USESaveManager_SubscribeForEvents_Statics::NewProp_Interface = { "Interface", nullptr, (EPropertyFlags)0x0014000008000182, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventSubscribeForEvents_Parms, Interface), Z_Construct_UClass_USESaveInterface_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_SubscribeForEvents_Statics::NewProp_Interface_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_SubscribeForEvents_Statics::NewProp_Interface_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESaveManager_SubscribeForEvents_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_SubscribeForEvents_Statics::NewProp_Interface,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_SubscribeForEvents_Statics::Function_MetaDataParams[] = {
		{ "Category", "SaveExtension" },
		{ "Comment", "/** Subscribe to receive save and load events on an Interface */" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
		{ "ToolTip", "Subscribe to receive save and load events on an Interface" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESaveManager_SubscribeForEvents_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESaveManager, nullptr, "SubscribeForEvents", nullptr, nullptr, sizeof(Z_Construct_UFunction_USESaveManager_SubscribeForEvents_Statics::SESaveManager_eventSubscribeForEvents_Parms), Z_Construct_UFunction_USESaveManager_SubscribeForEvents_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_SubscribeForEvents_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_SubscribeForEvents_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_SubscribeForEvents_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESaveManager_SubscribeForEvents()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESaveManager_SubscribeForEvents_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USESaveManager_UnsubscribeFromEvents_Statics
	{
		struct SESaveManager_eventUnsubscribeFromEvents_Parms
		{
			TScriptInterface<ISESaveInterface> Interface;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Interface_MetaData[];
#endif
		static const UECodeGen_Private::FInterfacePropertyParams NewProp_Interface;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_UnsubscribeFromEvents_Statics::NewProp_Interface_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UFunction_USESaveManager_UnsubscribeFromEvents_Statics::NewProp_Interface = { "Interface", nullptr, (EPropertyFlags)0x0014000008000182, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESaveManager_eventUnsubscribeFromEvents_Parms, Interface), Z_Construct_UClass_USESaveInterface_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_UnsubscribeFromEvents_Statics::NewProp_Interface_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_UnsubscribeFromEvents_Statics::NewProp_Interface_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESaveManager_UnsubscribeFromEvents_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveManager_UnsubscribeFromEvents_Statics::NewProp_Interface,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveManager_UnsubscribeFromEvents_Statics::Function_MetaDataParams[] = {
		{ "Category", "SaveExtension" },
		{ "Comment", "/** Unsubscribe to no longer receive save and load events on an Interface */" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
		{ "ToolTip", "Unsubscribe to no longer receive save and load events on an Interface" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESaveManager_UnsubscribeFromEvents_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESaveManager, nullptr, "UnsubscribeFromEvents", nullptr, nullptr, sizeof(Z_Construct_UFunction_USESaveManager_UnsubscribeFromEvents_Statics::SESaveManager_eventUnsubscribeFromEvents_Parms), Z_Construct_UFunction_USESaveManager_UnsubscribeFromEvents_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_UnsubscribeFromEvents_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESaveManager_UnsubscribeFromEvents_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveManager_UnsubscribeFromEvents_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESaveManager_UnsubscribeFromEvents()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESaveManager_UnsubscribeFromEvents_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USESaveManager);
	UClass* Z_Construct_UClass_USESaveManager_NoRegister()
	{
		return USESaveManager::StaticClass();
	}
	struct Z_Construct_UClass_USESaveManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bTickWithGameWorld_MetaData[];
#endif
		static void NewProp_bTickWithGameWorld_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bTickWithGameWorld;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ActivePreset_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ActivePreset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentInfo_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentInfo;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentData_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentData;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LevelStreamingNotifiers_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LevelStreamingNotifiers_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_LevelStreamingNotifiers;
		static const UECodeGen_Private::FInterfacePropertyParams NewProp_SubscribedInterfaces_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SubscribedInterfaces_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_SubscribedInterfaces;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SlotDataTasks_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SlotDataTasks_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_SlotDataTasks;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Savers_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Savers_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Savers;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnGameSaved_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnGameSaved;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnGameLoaded_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnGameLoaded;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USESaveManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_SaveExtension,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USESaveManager_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USESaveManager_BPDeleteAllSlots, "BPDeleteAllSlots" }, // 3912325786
		{ &Z_Construct_UFunction_USESaveManager_BPGetPreset, "BPGetPreset" }, // 606837236
		{ &Z_Construct_UFunction_USESaveManager_BPLoadAllSlotInfos, "BPLoadAllSlotInfos" }, // 2607977898
		{ &Z_Construct_UFunction_USESaveManager_BPLoadSlot, "BPLoadSlot" }, // 3362711827
		{ &Z_Construct_UFunction_USESaveManager_BPLoadSlotById, "BPLoadSlotById" }, // 2591784780
		{ &Z_Construct_UFunction_USESaveManager_BPLoadSlotByInfo, "BPLoadSlotByInfo" }, // 3887814019
		{ &Z_Construct_UFunction_USESaveManager_BPReloadCurrentSlot, "BPReloadCurrentSlot" }, // 2812198904
		{ &Z_Construct_UFunction_USESaveManager_BPSaveCurrentSlot, "BPSaveCurrentSlot" }, // 4288498740
		{ &Z_Construct_UFunction_USESaveManager_BPSaveSlot, "BPSaveSlot" }, // 1301422576
		{ &Z_Construct_UFunction_USESaveManager_BPSaveSlotById, "BPSaveSlotById" }, // 2052248298
		{ &Z_Construct_UFunction_USESaveManager_BPSaveSlotByInfo, "BPSaveSlotByInfo" }, // 1428501341
		{ &Z_Construct_UFunction_USESaveManager_DeleteSlot, "DeleteSlot" }, // 4234031819
		{ &Z_Construct_UFunction_USESaveManager_DeleteSlotById, "DeleteSlotById" }, // 490058326
		{ &Z_Construct_UFunction_USESaveManager_DeserializeStreamingLevel, "DeserializeStreamingLevel" }, // 681054340
		{ &Z_Construct_UFunction_USESaveManager_GetCurrentData, "GetCurrentData" }, // 2706970943
		{ &Z_Construct_UFunction_USESaveManager_GetCurrentInfo, "GetCurrentInfo" }, // 1106278303
		{ &Z_Construct_UFunction_USESaveManager_GetSlotInfo, "GetSlotInfo" }, // 1307423035
		{ &Z_Construct_UFunction_USESaveManager_GetSlotNameFromId, "GetSlotNameFromId" }, // 3600751495
		{ &Z_Construct_UFunction_USESaveManager_IsInSlot, "IsInSlot" }, // 1548184061
		{ &Z_Construct_UFunction_USESaveManager_IsSavingOrLoading, "IsSavingOrLoading" }, // 3352544924
		{ &Z_Construct_UFunction_USESaveManager_IsSlotSaved, "IsSlotSaved" }, // 3143823409
		{ &Z_Construct_UFunction_USESaveManager_IsSlotSavedById, "IsSlotSavedById" }, // 2520552796
		{ &Z_Construct_UFunction_USESaveManager_SerializeStreamingLevel, "SerializeStreamingLevel" }, // 752332331
		{ &Z_Construct_UFunction_USESaveManager_SetActivePreset, "SetActivePreset" }, // 2629406800
		{ &Z_Construct_UFunction_USESaveManager_SubscribeForEvents, "SubscribeForEvents" }, // 3344637471
		{ &Z_Construct_UFunction_USESaveManager_UnsubscribeFromEvents, "UnsubscribeFromEvents" }, // 2327231174
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESaveManager_Statics::Class_MetaDataParams[] = {
		{ "ClassGroupNames", "SaveExtension" },
		{ "Comment", "/**\n * Controls the complete saving and loading process\n */" },
		{ "DisplayName", "SaveManager" },
		{ "IncludePath", "SESaveManager.h" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
		{ "ToolTip", "Controls the complete saving and loading process" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESaveManager_Statics::NewProp_bTickWithGameWorld_MetaData[] = {
		{ "Category", "SaveManager" },
		{ "Comment", "// Loaded from settings. Can be changed at runtime\n" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
		{ "ToolTip", "Loaded from settings. Can be changed at runtime" },
	};
#endif
	void Z_Construct_UClass_USESaveManager_Statics::NewProp_bTickWithGameWorld_SetBit(void* Obj)
	{
		((USESaveManager*)Obj)->bTickWithGameWorld = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USESaveManager_Statics::NewProp_bTickWithGameWorld = { "bTickWithGameWorld", nullptr, (EPropertyFlags)0x0010000000002004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(USESaveManager), &Z_Construct_UClass_USESaveManager_Statics::NewProp_bTickWithGameWorld_SetBit, METADATA_PARAMS(Z_Construct_UClass_USESaveManager_Statics::NewProp_bTickWithGameWorld_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESaveManager_Statics::NewProp_bTickWithGameWorld_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESaveManager_Statics::NewProp_ActivePreset_MetaData[] = {
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USESaveManager_Statics::NewProp_ActivePreset = { "ActivePreset", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USESaveManager, ActivePreset), Z_Construct_UClass_USESavePreset_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USESaveManager_Statics::NewProp_ActivePreset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESaveManager_Statics::NewProp_ActivePreset_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESaveManager_Statics::NewProp_CurrentInfo_MetaData[] = {
		{ "Comment", "/** Currently loaded SaveInfo.\n\x09 * SaveInfo stores basic information about a saved game. Played time, levels,progress, etc.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
		{ "ToolTip", "Currently loaded SaveInfo.\nSaveInfo stores basic information about a saved game. Played time, levels,progress, etc." },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USESaveManager_Statics::NewProp_CurrentInfo = { "CurrentInfo", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USESaveManager, CurrentInfo), Z_Construct_UClass_USESlotInfo_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USESaveManager_Statics::NewProp_CurrentInfo_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESaveManager_Statics::NewProp_CurrentInfo_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESaveManager_Statics::NewProp_CurrentData_MetaData[] = {
		{ "Comment", "/** Currently loaded SaveData. SaveData stores all serialized info about the world. */" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
		{ "ToolTip", "Currently loaded SaveData. SaveData stores all serialized info about the world." },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USESaveManager_Statics::NewProp_CurrentData = { "CurrentData", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USESaveManager, CurrentData), Z_Construct_UClass_USESlotData_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USESaveManager_Statics::NewProp_CurrentData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESaveManager_Statics::NewProp_CurrentData_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USESaveManager_Statics::NewProp_LevelStreamingNotifiers_Inner = { "LevelStreamingNotifiers", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UClass_USELevelStreamingNotifier_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESaveManager_Statics::NewProp_LevelStreamingNotifiers_MetaData[] = {
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_USESaveManager_Statics::NewProp_LevelStreamingNotifiers = { "LevelStreamingNotifiers", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USESaveManager, LevelStreamingNotifiers), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_USESaveManager_Statics::NewProp_LevelStreamingNotifiers_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESaveManager_Statics::NewProp_LevelStreamingNotifiers_MetaData)) };
	const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UClass_USESaveManager_Statics::NewProp_SubscribedInterfaces_Inner = { "SubscribedInterfaces", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UClass_USESaveInterface_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESaveManager_Statics::NewProp_SubscribedInterfaces_MetaData[] = {
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_USESaveManager_Statics::NewProp_SubscribedInterfaces = { "SubscribedInterfaces", nullptr, (EPropertyFlags)0x0044000000002000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USESaveManager, SubscribedInterfaces), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_USESaveManager_Statics::NewProp_SubscribedInterfaces_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESaveManager_Statics::NewProp_SubscribedInterfaces_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USESaveManager_Statics::NewProp_SlotDataTasks_Inner = { "SlotDataTasks", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UClass_USESlotDataTask_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESaveManager_Statics::NewProp_SlotDataTasks_MetaData[] = {
		{ "Comment", "// \xe5\xbd\x93\xe5\x89\x8d\xe7\x9a\x84\xe6\xa7\xbd\xe6\x95\xb0\xe6\x8d\xae\xe4\xbb\xbb\xe5\x8a\xa1,\xe4\xbc\x9a\xe5\x9c\xa8Tick\xe4\xb8\xad\xe6\xaf\x8f\xe5\xb8\xa7\xe5\xa4\x84\xe7\x90\x86\xe5\x85\xb6\xe7\x8a\xb6\xe6\x80\x81\xe5\x8f\x98\xe5\x8c\x96\n" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
		{ "ToolTip", "\xe5\xbd\x93\xe5\x89\x8d\xe7\x9a\x84\xe6\xa7\xbd\xe6\x95\xb0\xe6\x8d\xae\xe4\xbb\xbb\xe5\x8a\xa1,\xe4\xbc\x9a\xe5\x9c\xa8Tick\xe4\xb8\xad\xe6\xaf\x8f\xe5\xb8\xa7\xe5\xa4\x84\xe7\x90\x86\xe5\x85\xb6\xe7\x8a\xb6\xe6\x80\x81\xe5\x8f\x98\xe5\x8c\x96" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_USESaveManager_Statics::NewProp_SlotDataTasks = { "SlotDataTasks", nullptr, (EPropertyFlags)0x0040000000002000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USESaveManager, SlotDataTasks), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_USESaveManager_Statics::NewProp_SlotDataTasks_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESaveManager_Statics::NewProp_SlotDataTasks_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USESaveManager_Statics::NewProp_Savers_Inner = { "Savers", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UClass_USESaverBase_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESaveManager_Statics::NewProp_Savers_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_USESaveManager_Statics::NewProp_Savers = { "Savers", nullptr, (EPropertyFlags)0x0040008000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USESaveManager, Savers), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_USESaveManager_Statics::NewProp_Savers_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESaveManager_Statics::NewProp_Savers_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESaveManager_Statics::NewProp_OnGameSaved_MetaData[] = {
		{ "Category", "SaveExtension" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USESaveManager_Statics::NewProp_OnGameSaved = { "OnGameSaved", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USESaveManager, OnGameSaved), Z_Construct_UDelegateFunction_SaveExtension_OnGameSavedMC__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USESaveManager_Statics::NewProp_OnGameSaved_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESaveManager_Statics::NewProp_OnGameSaved_MetaData)) }; // 1197413745
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESaveManager_Statics::NewProp_OnGameLoaded_MetaData[] = {
		{ "Category", "SaveExtension" },
		{ "ModuleRelativePath", "Public/SESaveManager.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USESaveManager_Statics::NewProp_OnGameLoaded = { "OnGameLoaded", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USESaveManager, OnGameLoaded), Z_Construct_UDelegateFunction_SaveExtension_OnGameLoadedMC__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USESaveManager_Statics::NewProp_OnGameLoaded_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESaveManager_Statics::NewProp_OnGameLoaded_MetaData)) }; // 3724055886
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USESaveManager_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESaveManager_Statics::NewProp_bTickWithGameWorld,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESaveManager_Statics::NewProp_ActivePreset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESaveManager_Statics::NewProp_CurrentInfo,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESaveManager_Statics::NewProp_CurrentData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESaveManager_Statics::NewProp_LevelStreamingNotifiers_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESaveManager_Statics::NewProp_LevelStreamingNotifiers,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESaveManager_Statics::NewProp_SubscribedInterfaces_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESaveManager_Statics::NewProp_SubscribedInterfaces,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESaveManager_Statics::NewProp_SlotDataTasks_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESaveManager_Statics::NewProp_SlotDataTasks,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESaveManager_Statics::NewProp_Savers_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESaveManager_Statics::NewProp_Savers,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESaveManager_Statics::NewProp_OnGameSaved,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESaveManager_Statics::NewProp_OnGameLoaded,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USESaveManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USESaveManager>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USESaveManager_Statics::ClassParams = {
		&USESaveManager::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_USESaveManager_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_USESaveManager_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USESaveManager_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USESaveManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USESaveManager()
	{
		if (!Z_Registration_Info_UClass_USESaveManager.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USESaveManager.OuterSingleton, Z_Construct_UClass_USESaveManager_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USESaveManager.OuterSingleton;
	}
	template<> SAVEEXTENSION_API UClass* StaticClass<USESaveManager>()
	{
		return USESaveManager::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USESaveManager);
	USESaveManager::~USESaveManager() {}
	struct Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h_Statics::ScriptStructInfo[] = {
		{ FSEScreenshotSize::StaticStruct, Z_Construct_UScriptStruct_FSEScreenshotSize_Statics::NewStructOps, TEXT("SEScreenshotSize"), &Z_Registration_Info_UScriptStruct_SEScreenshotSize, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSEScreenshotSize), 379114064U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USESaveManager, USESaveManager::StaticClass, TEXT("USESaveManager"), &Z_Registration_Info_UClass_USESaveManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USESaveManager), 3316709539U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h_1261906505(TEXT("/Script/SaveExtension"),
		Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveManager_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
