// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveExtension/Public/SESavePreset.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSESavePreset() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESavePreset();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESavePreset_NoRegister();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESlotData_NoRegister();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESlotInfo_NoRegister();
	SAVEEXTENSION_API UEnum* Z_Construct_UEnum_SaveExtension_ESaveASyncMode();
	UPackage* Z_Construct_UPackage__Script_SaveExtension();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESaveASyncMode;
	static UEnum* ESaveASyncMode_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ESaveASyncMode.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ESaveASyncMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SaveExtension_ESaveASyncMode, Z_Construct_UPackage__Script_SaveExtension(), TEXT("ESaveASyncMode"));
		}
		return Z_Registration_Info_UEnum_ESaveASyncMode.OuterSingleton;
	}
	template<> SAVEEXTENSION_API UEnum* StaticEnum<ESaveASyncMode>()
	{
		return ESaveASyncMode_StaticEnum();
	}
	struct Z_Construct_UEnum_SaveExtension_ESaveASyncMode_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_SaveExtension_ESaveASyncMode_Statics::Enumerators[] = {
		{ "ESaveASyncMode::OnlySync", (int64)ESaveASyncMode::OnlySync },
		{ "ESaveASyncMode::LoadAsync", (int64)ESaveASyncMode::LoadAsync },
		{ "ESaveASyncMode::SaveAsync", (int64)ESaveASyncMode::SaveAsync },
		{ "ESaveASyncMode::SaveAndLoadAsync", (int64)ESaveASyncMode::SaveAndLoadAsync },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_SaveExtension_ESaveASyncMode_Statics::Enum_MetaDataParams[] = {
		{ "Comment", "/**\n* Specifies the behavior while saving or loading\n*/" },
		{ "LoadAsync.Name", "ESaveASyncMode::LoadAsync" },
		{ "ModuleRelativePath", "Public/SESavePreset.h" },
		{ "OnlySync.Name", "ESaveASyncMode::OnlySync" },
		{ "SaveAndLoadAsync.Name", "ESaveASyncMode::SaveAndLoadAsync" },
		{ "SaveAsync.Name", "ESaveASyncMode::SaveAsync" },
		{ "ToolTip", "Specifies the behavior while saving or loading" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SaveExtension_ESaveASyncMode_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_SaveExtension,
		nullptr,
		"ESaveASyncMode",
		"ESaveASyncMode",
		Z_Construct_UEnum_SaveExtension_ESaveASyncMode_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_SaveExtension_ESaveASyncMode_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_SaveExtension_ESaveASyncMode_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_SaveExtension_ESaveASyncMode_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_SaveExtension_ESaveASyncMode()
	{
		if (!Z_Registration_Info_UEnum_ESaveASyncMode.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESaveASyncMode.InnerSingleton, Z_Construct_UEnum_SaveExtension_ESaveASyncMode_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ESaveASyncMode.InnerSingleton;
	}
	DEFINE_FUNCTION(USESavePreset::execBPGetSlotNameFromId)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Id);
		P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_Name);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BPGetSlotNameFromId_Implementation(Z_Param_Id,Z_Param_Out_Name);
		P_NATIVE_END;
	}
	struct SESavePreset_eventBPGetSlotNameFromId_Parms
	{
		int32 Id;
		FName Name;
	};
	static FName NAME_USESavePreset_BPGetSlotNameFromId = FName(TEXT("BPGetSlotNameFromId"));
	void USESavePreset::BPGetSlotNameFromId(int32 Id, FName& Name) const
	{
		SESavePreset_eventBPGetSlotNameFromId_Parms Parms;
		Parms.Id=Id;
		Parms.Name=Name;
		const_cast<USESavePreset*>(this)->ProcessEvent(FindFunctionChecked(NAME_USESavePreset_BPGetSlotNameFromId),&Parms);
		Name=Parms.Name;
	}
	void USESavePreset::StaticRegisterNativesUSESavePreset()
	{
		UClass* Class = USESavePreset::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BPGetSlotNameFromId", &USESavePreset::execBPGetSlotNameFromId },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USESavePreset_BPGetSlotNameFromId_Statics
	{
		static const UECodeGen_Private::FIntPropertyParams NewProp_Id;
		static const UECodeGen_Private::FNamePropertyParams NewProp_Name;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USESavePreset_BPGetSlotNameFromId_Statics::NewProp_Id = { "Id", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESavePreset_eventBPGetSlotNameFromId_Parms, Id), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_USESavePreset_BPGetSlotNameFromId_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESavePreset_eventBPGetSlotNameFromId_Parms, Name), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESavePreset_BPGetSlotNameFromId_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESavePreset_BPGetSlotNameFromId_Statics::NewProp_Id,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESavePreset_BPGetSlotNameFromId_Statics::NewProp_Name,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESavePreset_BPGetSlotNameFromId_Statics::Function_MetaDataParams[] = {
		{ "Category", "Slots" },
		{ "DisplayName", "Get Slot Name from Id" },
		{ "ModuleRelativePath", "Public/SESavePreset.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESavePreset_BPGetSlotNameFromId_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESavePreset, nullptr, "BPGetSlotNameFromId", nullptr, nullptr, sizeof(SESavePreset_eventBPGetSlotNameFromId_Parms), Z_Construct_UFunction_USESavePreset_BPGetSlotNameFromId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESavePreset_BPGetSlotNameFromId_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x48420C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESavePreset_BPGetSlotNameFromId_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESavePreset_BPGetSlotNameFromId_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESavePreset_BPGetSlotNameFromId()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESavePreset_BPGetSlotNameFromId_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USESavePreset);
	UClass* Z_Construct_UClass_USESavePreset_NoRegister()
	{
		return USESavePreset::StaticClass();
	}
	struct Z_Construct_UClass_USESavePreset_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SlotInfoClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_SlotInfoClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SlotDataClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_SlotDataClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxSlots_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_MaxSlots;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAutoSave_MetaData[];
#endif
		static void NewProp_bAutoSave_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoSave;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AutoSaveInterval_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_AutoSaveInterval;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bSaveOnExit_MetaData[];
#endif
		static void NewProp_bSaveOnExit_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSaveOnExit;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAutoLoad_MetaData[];
#endif
		static void NewProp_bAutoLoad_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoLoad;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDebug_MetaData[];
#endif
		static void NewProp_bDebug_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDebug;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDebugInScreen_MetaData[];
#endif
		static void NewProp_bDebugInScreen_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDebugInScreen;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseCompression_MetaData[];
#endif
		static void NewProp_bUseCompression_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseCompression;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bStoreGameInstance_MetaData[];
#endif
		static void NewProp_bStoreGameInstance_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bStoreGameInstance;
		static const UECodeGen_Private::FBytePropertyParams NewProp_MultithreadedSerialization_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MultithreadedSerialization_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_MultithreadedSerialization;
		static const UECodeGen_Private::FBytePropertyParams NewProp_FrameSplittedSerialization_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FrameSplittedSerialization_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_FrameSplittedSerialization;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxFrameMs_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxFrameMs;
		static const UECodeGen_Private::FBytePropertyParams NewProp_MultithreadedFiles_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MultithreadedFiles_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_MultithreadedFiles;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bSaveAndLoadSublevels_MetaData[];
#endif
		static void NewProp_bSaveAndLoadSublevels_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSaveAndLoadSublevels;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USESavePreset_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_SaveExtension,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USESavePreset_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USESavePreset_BPGetSlotNameFromId, "BPGetSlotNameFromId" }, // 1081905276
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESavePreset_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "SaveExtension" },
		{ "Comment", "/**\n * What to save, how to save it, when, every x minutes, what info file, what data file, save by level streaming?\n */" },
		{ "IncludePath", "SESavePreset.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/SESavePreset.h" },
		{ "ToolTip", "What to save, how to save it, when, every x minutes, what info file, what data file, save by level streaming?" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESavePreset_Statics::NewProp_SlotInfoClass_MetaData[] = {
		{ "Category", "Gameplay" },
		{ "Comment", "/**\n\x09* Specify the SaveInfo object to be used with this preset\n\x09*/" },
		{ "ModuleRelativePath", "Public/SESavePreset.h" },
		{ "ToolTip", "Specify the SaveInfo object to be used with this preset" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_USESavePreset_Statics::NewProp_SlotInfoClass = { "SlotInfoClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USESavePreset, SlotInfoClass), Z_Construct_UClass_UClass, Z_Construct_UClass_USESlotInfo_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USESavePreset_Statics::NewProp_SlotInfoClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESavePreset_Statics::NewProp_SlotInfoClass_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESavePreset_Statics::NewProp_SlotDataClass_MetaData[] = {
		{ "Category", "Gameplay" },
		{ "Comment", "/**\n\x09* Specify the SaveData object to be used with this preset\n\x09*/" },
		{ "ModuleRelativePath", "Public/SESavePreset.h" },
		{ "ToolTip", "Specify the SaveData object to be used with this preset" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_USESavePreset_Statics::NewProp_SlotDataClass = { "SlotDataClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USESavePreset, SlotDataClass), Z_Construct_UClass_UClass, Z_Construct_UClass_USESlotData_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USESavePreset_Statics::NewProp_SlotDataClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESavePreset_Statics::NewProp_SlotDataClass_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESavePreset_Statics::NewProp_MaxSlots_MetaData[] = {
		{ "Category", "Gameplay" },
		{ "ClampMin", "0" },
		{ "Comment", "/** Maximum amount of saved slots at the same time */" },
		{ "ModuleRelativePath", "Public/SESavePreset.h" },
		{ "ToolTip", "Maximum amount of saved slots at the same time" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_USESavePreset_Statics::NewProp_MaxSlots = { "MaxSlots", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USESavePreset, MaxSlots), METADATA_PARAMS(Z_Construct_UClass_USESavePreset_Statics::NewProp_MaxSlots_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESavePreset_Statics::NewProp_MaxSlots_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESavePreset_Statics::NewProp_bAutoSave_MetaData[] = {
		{ "Category", "Gameplay" },
		{ "Comment", "/** If checked, will attempt to Save Game to first Slot found, timed event. */" },
		{ "ModuleRelativePath", "Public/SESavePreset.h" },
		{ "ToolTip", "If checked, will attempt to Save Game to first Slot found, timed event." },
	};
#endif
	void Z_Construct_UClass_USESavePreset_Statics::NewProp_bAutoSave_SetBit(void* Obj)
	{
		((USESavePreset*)Obj)->bAutoSave = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USESavePreset_Statics::NewProp_bAutoSave = { "bAutoSave", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(USESavePreset), &Z_Construct_UClass_USESavePreset_Statics::NewProp_bAutoSave_SetBit, METADATA_PARAMS(Z_Construct_UClass_USESavePreset_Statics::NewProp_bAutoSave_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESavePreset_Statics::NewProp_bAutoSave_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESavePreset_Statics::NewProp_AutoSaveInterval_MetaData[] = {
		{ "Category", "Gameplay" },
		{ "Comment", "/** Interval in seconds for auto saving */" },
		{ "EditCondition", "bAutoSave" },
		{ "ModuleRelativePath", "Public/SESavePreset.h" },
		{ "ToolTip", "Interval in seconds for auto saving" },
		{ "UIMax", "3600" },
		{ "UIMin", "15" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_USESavePreset_Statics::NewProp_AutoSaveInterval = { "AutoSaveInterval", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USESavePreset, AutoSaveInterval), METADATA_PARAMS(Z_Construct_UClass_USESavePreset_Statics::NewProp_AutoSaveInterval_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESavePreset_Statics::NewProp_AutoSaveInterval_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESavePreset_Statics::NewProp_bSaveOnExit_MetaData[] = {
		{ "Category", "Gameplay" },
		{ "Comment", "/** If checked, will attempt to Save Game to first Slot found, timed event. */" },
		{ "EditCondition", "bAutoSave" },
		{ "ModuleRelativePath", "Public/SESavePreset.h" },
		{ "ToolTip", "If checked, will attempt to Save Game to first Slot found, timed event." },
	};
#endif
	void Z_Construct_UClass_USESavePreset_Statics::NewProp_bSaveOnExit_SetBit(void* Obj)
	{
		((USESavePreset*)Obj)->bSaveOnExit = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USESavePreset_Statics::NewProp_bSaveOnExit = { "bSaveOnExit", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(USESavePreset), &Z_Construct_UClass_USESavePreset_Statics::NewProp_bSaveOnExit_SetBit, METADATA_PARAMS(Z_Construct_UClass_USESavePreset_Statics::NewProp_bSaveOnExit_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESavePreset_Statics::NewProp_bSaveOnExit_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESavePreset_Statics::NewProp_bAutoLoad_MetaData[] = {
		{ "Category", "Gameplay" },
		{ "Comment", "/** If checked, will attempt to Load Game from last Slot found, when game starts\n\x09 * \xe4\xbc\x9a\xe5\x9c\xa8\xe5\xad\x98\xe6\xa1\xa3\xe5\xad\x90\xe7\xb3\xbb\xe7\xbb\x9fInitialize\xe6\x97\xb6\xe8\xb0\x83\xe7\x94\xa8.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SESavePreset.h" },
		{ "ToolTip", "If checked, will attempt to Load Game from last Slot found, when game starts\n\xe4\xbc\x9a\xe5\x9c\xa8\xe5\xad\x98\xe6\xa1\xa3\xe5\xad\x90\xe7\xb3\xbb\xe7\xbb\x9fInitialize\xe6\x97\xb6\xe8\xb0\x83\xe7\x94\xa8." },
	};
#endif
	void Z_Construct_UClass_USESavePreset_Statics::NewProp_bAutoLoad_SetBit(void* Obj)
	{
		((USESavePreset*)Obj)->bAutoLoad = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USESavePreset_Statics::NewProp_bAutoLoad = { "bAutoLoad", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(USESavePreset), &Z_Construct_UClass_USESavePreset_Statics::NewProp_bAutoLoad_SetBit, METADATA_PARAMS(Z_Construct_UClass_USESavePreset_Statics::NewProp_bAutoLoad_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESavePreset_Statics::NewProp_bAutoLoad_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESavePreset_Statics::NewProp_bDebug_MetaData[] = {
		{ "Category", "Gameplay" },
		{ "Comment", "/**\n\x09 * If checked, will print messages to Log, and Viewport if DebugInScreen is enabled.\n\x09 * Ignored in package or Shipping mode.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SESavePreset.h" },
		{ "ToolTip", "If checked, will print messages to Log, and Viewport if DebugInScreen is enabled.\nIgnored in package or Shipping mode." },
	};
#endif
	void Z_Construct_UClass_USESavePreset_Statics::NewProp_bDebug_SetBit(void* Obj)
	{
		((USESavePreset*)Obj)->bDebug = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USESavePreset_Statics::NewProp_bDebug = { "bDebug", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(USESavePreset), &Z_Construct_UClass_USESavePreset_Statics::NewProp_bDebug_SetBit, METADATA_PARAMS(Z_Construct_UClass_USESavePreset_Statics::NewProp_bDebug_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESavePreset_Statics::NewProp_bDebug_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESavePreset_Statics::NewProp_bDebugInScreen_MetaData[] = {
		{ "Category", "Gameplay" },
		{ "Comment", "/**\n\x09 * If checked and Debug is enabled, will print messages to Viewport.\n\x09 * Ignored in package or Shipping mode.\n\x09 */" },
		{ "EditCondition", "bDebug" },
		{ "ModuleRelativePath", "Public/SESavePreset.h" },
		{ "ToolTip", "If checked and Debug is enabled, will print messages to Viewport.\nIgnored in package or Shipping mode." },
	};
#endif
	void Z_Construct_UClass_USESavePreset_Statics::NewProp_bDebugInScreen_SetBit(void* Obj)
	{
		((USESavePreset*)Obj)->bDebugInScreen = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USESavePreset_Statics::NewProp_bDebugInScreen = { "bDebugInScreen", nullptr, (EPropertyFlags)0x0010040000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(USESavePreset), &Z_Construct_UClass_USESavePreset_Statics::NewProp_bDebugInScreen_SetBit, METADATA_PARAMS(Z_Construct_UClass_USESavePreset_Statics::NewProp_bDebugInScreen_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESavePreset_Statics::NewProp_bDebugInScreen_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESavePreset_Statics::NewProp_bUseCompression_MetaData[] = {
		{ "Category", "Serialization" },
		{ "Comment", "/** If true save files will be compressed\n\x09 * Performance: Can add from 10ms to 20ms to loading and saving (estimate) but reduce file sizes making them up to 30x smaller\n\x09 */" },
		{ "ModuleRelativePath", "Public/SESavePreset.h" },
		{ "ToolTip", "If true save files will be compressed\nPerformance: Can add from 10ms to 20ms to loading and saving (estimate) but reduce file sizes making them up to 30x smaller" },
	};
#endif
	void Z_Construct_UClass_USESavePreset_Statics::NewProp_bUseCompression_SetBit(void* Obj)
	{
		((USESavePreset*)Obj)->bUseCompression = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USESavePreset_Statics::NewProp_bUseCompression = { "bUseCompression", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(USESavePreset), &Z_Construct_UClass_USESavePreset_Statics::NewProp_bUseCompression_SetBit, METADATA_PARAMS(Z_Construct_UClass_USESavePreset_Statics::NewProp_bUseCompression_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESavePreset_Statics::NewProp_bUseCompression_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESavePreset_Statics::NewProp_bStoreGameInstance_MetaData[] = {
		{ "Category", "Serialization" },
		{ "Comment", "/** If true will store the game instance */" },
		{ "ModuleRelativePath", "Public/SESavePreset.h" },
		{ "ToolTip", "If true will store the game instance" },
	};
#endif
	void Z_Construct_UClass_USESavePreset_Statics::NewProp_bStoreGameInstance_SetBit(void* Obj)
	{
		((USESavePreset*)Obj)->bStoreGameInstance = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USESavePreset_Statics::NewProp_bStoreGameInstance = { "bStoreGameInstance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(USESavePreset), &Z_Construct_UClass_USESavePreset_Statics::NewProp_bStoreGameInstance_SetBit, METADATA_PARAMS(Z_Construct_UClass_USESavePreset_Statics::NewProp_bStoreGameInstance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESavePreset_Statics::NewProp_bStoreGameInstance_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_USESavePreset_Statics::NewProp_MultithreadedSerialization_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESavePreset_Statics::NewProp_MultithreadedSerialization_MetaData[] = {
		{ "Category", "Asynchronous" },
		{ "Comment", "/** Serialization will be multi-threaded between all available cores. */" },
		{ "ModuleRelativePath", "Public/SESavePreset.h" },
		{ "ToolTip", "Serialization will be multi-threaded between all available cores." },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_USESavePreset_Statics::NewProp_MultithreadedSerialization = { "MultithreadedSerialization", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USESavePreset, MultithreadedSerialization), Z_Construct_UEnum_SaveExtension_ESaveASyncMode, METADATA_PARAMS(Z_Construct_UClass_USESavePreset_Statics::NewProp_MultithreadedSerialization_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESavePreset_Statics::NewProp_MultithreadedSerialization_MetaData)) }; // 1871373247
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_USESavePreset_Statics::NewProp_FrameSplittedSerialization_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESavePreset_Statics::NewProp_FrameSplittedSerialization_MetaData[] = {
		{ "Category", "Asynchronous" },
		{ "Comment", "/** Split serialization between multiple frames. Ignored if MultithreadedSerialization is used\n\x09 * Currently only implemented on Loading\n\x09 */" },
		{ "ModuleRelativePath", "Public/SESavePreset.h" },
		{ "ToolTip", "Split serialization between multiple frames. Ignored if MultithreadedSerialization is used\nCurrently only implemented on Loading" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_USESavePreset_Statics::NewProp_FrameSplittedSerialization = { "FrameSplittedSerialization", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USESavePreset, FrameSplittedSerialization), Z_Construct_UEnum_SaveExtension_ESaveASyncMode, METADATA_PARAMS(Z_Construct_UClass_USESavePreset_Statics::NewProp_FrameSplittedSerialization_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESavePreset_Statics::NewProp_FrameSplittedSerialization_MetaData)) }; // 1871373247
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESavePreset_Statics::NewProp_MaxFrameMs_MetaData[] = {
		{ "Category", "Asynchronous" },
		{ "Comment", "/** Max milliseconds to use every frame in an asynchronous operation.\n\x09 * If running at 60Fps (16.6ms), loading or saving asynchronously will add MaxFrameMS:\n\x09 * 16.6ms + 5MS = 21.6ms -> 46Fps\n\x09 * This means gameplay will not be stopped nor have frame drops while saving or loading. Works best for non multi-threaded platforms\n\x09 */" },
		{ "ModuleRelativePath", "Public/SESavePreset.h" },
		{ "ToolTip", "Max milliseconds to use every frame in an asynchronous operation.\nIf running at 60Fps (16.6ms), loading or saving asynchronously will add MaxFrameMS:\n16.6ms + 5MS = 21.6ms -> 46Fps\nThis means gameplay will not be stopped nor have frame drops while saving or loading. Works best for non multi-threaded platforms" },
		{ "UIMax", "10" },
		{ "UIMin", "3" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USESavePreset_Statics::NewProp_MaxFrameMs = { "MaxFrameMs", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USESavePreset, MaxFrameMs), METADATA_PARAMS(Z_Construct_UClass_USESavePreset_Statics::NewProp_MaxFrameMs_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESavePreset_Statics::NewProp_MaxFrameMs_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_USESavePreset_Statics::NewProp_MultithreadedFiles_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESavePreset_Statics::NewProp_MultithreadedFiles_MetaData[] = {
		{ "Category", "Asynchronous" },
		{ "Comment", "/** Files will be loaded or saved on a secondary thread while game continues */" },
		{ "ModuleRelativePath", "Public/SESavePreset.h" },
		{ "ToolTip", "Files will be loaded or saved on a secondary thread while game continues" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_USESavePreset_Statics::NewProp_MultithreadedFiles = { "MultithreadedFiles", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USESavePreset, MultithreadedFiles), Z_Construct_UEnum_SaveExtension_ESaveASyncMode, METADATA_PARAMS(Z_Construct_UClass_USESavePreset_Statics::NewProp_MultithreadedFiles_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESavePreset_Statics::NewProp_MultithreadedFiles_MetaData)) }; // 1871373247
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESavePreset_Statics::NewProp_bSaveAndLoadSublevels_MetaData[] = {
		{ "Category", "Level Streaming" },
		{ "Comment", "/** If true, will Save and Load levels when they are shown or hidden.\n\x09 * This includes level streaming and world composition.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SESavePreset.h" },
		{ "ToolTip", "If true, will Save and Load levels when they are shown or hidden.\nThis includes level streaming and world composition." },
	};
#endif
	void Z_Construct_UClass_USESavePreset_Statics::NewProp_bSaveAndLoadSublevels_SetBit(void* Obj)
	{
		((USESavePreset*)Obj)->bSaveAndLoadSublevels = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USESavePreset_Statics::NewProp_bSaveAndLoadSublevels = { "bSaveAndLoadSublevels", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(USESavePreset), &Z_Construct_UClass_USESavePreset_Statics::NewProp_bSaveAndLoadSublevels_SetBit, METADATA_PARAMS(Z_Construct_UClass_USESavePreset_Statics::NewProp_bSaveAndLoadSublevels_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESavePreset_Statics::NewProp_bSaveAndLoadSublevels_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USESavePreset_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESavePreset_Statics::NewProp_SlotInfoClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESavePreset_Statics::NewProp_SlotDataClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESavePreset_Statics::NewProp_MaxSlots,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESavePreset_Statics::NewProp_bAutoSave,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESavePreset_Statics::NewProp_AutoSaveInterval,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESavePreset_Statics::NewProp_bSaveOnExit,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESavePreset_Statics::NewProp_bAutoLoad,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESavePreset_Statics::NewProp_bDebug,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESavePreset_Statics::NewProp_bDebugInScreen,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESavePreset_Statics::NewProp_bUseCompression,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESavePreset_Statics::NewProp_bStoreGameInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESavePreset_Statics::NewProp_MultithreadedSerialization_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESavePreset_Statics::NewProp_MultithreadedSerialization,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESavePreset_Statics::NewProp_FrameSplittedSerialization_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESavePreset_Statics::NewProp_FrameSplittedSerialization,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESavePreset_Statics::NewProp_MaxFrameMs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESavePreset_Statics::NewProp_MultithreadedFiles_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESavePreset_Statics::NewProp_MultithreadedFiles,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESavePreset_Statics::NewProp_bSaveAndLoadSublevels,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USESavePreset_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USESavePreset>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USESavePreset_Statics::ClassParams = {
		&USESavePreset::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_USESavePreset_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_USESavePreset_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USESavePreset_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USESavePreset_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USESavePreset()
	{
		if (!Z_Registration_Info_UClass_USESavePreset.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USESavePreset.OuterSingleton, Z_Construct_UClass_USESavePreset_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USESavePreset.OuterSingleton;
	}
	template<> SAVEEXTENSION_API UClass* StaticClass<USESavePreset>()
	{
		return USESavePreset::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USESavePreset);
	USESavePreset::~USESavePreset() {}
	struct Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h_Statics::EnumInfo[] = {
		{ ESaveASyncMode_StaticEnum, TEXT("ESaveASyncMode"), &Z_Registration_Info_UEnum_ESaveASyncMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1871373247U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USESavePreset, USESavePreset::StaticClass, TEXT("USESavePreset"), &Z_Registration_Info_UClass_USESavePreset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USESavePreset), 3419228372U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h_3983445586(TEXT("/Script/SaveExtension"),
		Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESavePreset_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
