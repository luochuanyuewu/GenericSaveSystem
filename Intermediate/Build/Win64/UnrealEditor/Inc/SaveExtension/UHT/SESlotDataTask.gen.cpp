// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveExtension/Public/Serialization/SESlotDataTask.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSESlotDataTask() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESavePreset_NoRegister();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESlotData_NoRegister();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESlotDataTask();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESlotDataTask_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SaveExtension();
// End Cross Module References
	void USESlotDataTask::StaticRegisterNativesUSESlotDataTask()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USESlotDataTask);
	UClass* Z_Construct_UClass_USESlotDataTask_NoRegister()
	{
		return USESlotDataTask::StaticClass();
	}
	struct Z_Construct_UClass_USESlotDataTask_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SlotData_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SlotData;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Preset_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Preset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxFrameMs_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxFrameMs;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USESlotDataTask_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_SaveExtension,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESlotDataTask_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n* @brief Base class for managing a SaveData file.\xe7\xae\xa1\xe7\x90\x86\xe4\xb8\x80\xe4\xb8\xaa\xe5\xad\x98\xe6\xa1\xa3\xe6\x95\xb0\xe6\x8d\xae\xe6\x96\x87\xe4\xbb\xb6\xe7\x9a\x84\xe5\x9f\xba\xe7\xb1\xbb\n* @attention SlotDataTask\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x94\xb1SaveManager\xe7\xae\xa1\xe7\x90\x86\xef\xbc\x8c\xe4\xb8\x94\xe9\x83\xbd\xe5\x9c\xa8\xe4\xb8\xbb\xe7\xba\xbf\xe7\xa8\x8b\xe6\x93\x8d\xe4\xbd\x9c\xef\xbc\x8c\xe5\x85\xb6\xe5\x86\x85\xe9\x83\xa8\xe4\xbc\x9a\xe7\xae\xa1\xe7\x90\x86\xe5\x90\x84\xe7\xa7\x8d\xe5\xbc\x82\xe6\xad\xa5Task\xe3\x80\x82\n*/" },
		{ "IncludePath", "Serialization/SESlotDataTask.h" },
		{ "ModuleRelativePath", "Public/Serialization/SESlotDataTask.h" },
		{ "ToolTip", "@brief Base class for managing a SaveData file.\xe7\xae\xa1\xe7\x90\x86\xe4\xb8\x80\xe4\xb8\xaa\xe5\xad\x98\xe6\xa1\xa3\xe6\x95\xb0\xe6\x8d\xae\xe6\x96\x87\xe4\xbb\xb6\xe7\x9a\x84\xe5\x9f\xba\xe7\xb1\xbb\n@attention SlotDataTask\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x94\xb1SaveManager\xe7\xae\xa1\xe7\x90\x86\xef\xbc\x8c\xe4\xb8\x94\xe9\x83\xbd\xe5\x9c\xa8\xe4\xb8\xbb\xe7\xba\xbf\xe7\xa8\x8b\xe6\x93\x8d\xe4\xbd\x9c\xef\xbc\x8c\xe5\x85\xb6\xe5\x86\x85\xe9\x83\xa8\xe4\xbc\x9a\xe7\xae\xa1\xe7\x90\x86\xe5\x90\x84\xe7\xa7\x8d\xe5\xbc\x82\xe6\xad\xa5Task\xe3\x80\x82" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESlotDataTask_Statics::NewProp_SlotData_MetaData[] = {
		{ "ModuleRelativePath", "Public/Serialization/SESlotDataTask.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USESlotDataTask_Statics::NewProp_SlotData = { "SlotData", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USESlotDataTask, SlotData), Z_Construct_UClass_USESlotData_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USESlotDataTask_Statics::NewProp_SlotData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESlotDataTask_Statics::NewProp_SlotData_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESlotDataTask_Statics::NewProp_Preset_MetaData[] = {
		{ "ModuleRelativePath", "Public/Serialization/SESlotDataTask.h" },
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USESlotDataTask_Statics::NewProp_Preset = { "Preset", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USESlotDataTask, Preset), Z_Construct_UClass_USESavePreset_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USESlotDataTask_Statics::NewProp_Preset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESlotDataTask_Statics::NewProp_Preset_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESlotDataTask_Statics::NewProp_MaxFrameMs_MetaData[] = {
		{ "ModuleRelativePath", "Public/Serialization/SESlotDataTask.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USESlotDataTask_Statics::NewProp_MaxFrameMs = { "MaxFrameMs", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USESlotDataTask, MaxFrameMs), METADATA_PARAMS(Z_Construct_UClass_USESlotDataTask_Statics::NewProp_MaxFrameMs_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESlotDataTask_Statics::NewProp_MaxFrameMs_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USESlotDataTask_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESlotDataTask_Statics::NewProp_SlotData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESlotDataTask_Statics::NewProp_Preset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESlotDataTask_Statics::NewProp_MaxFrameMs,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USESlotDataTask_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USESlotDataTask>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USESlotDataTask_Statics::ClassParams = {
		&USESlotDataTask::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_USESlotDataTask_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_USESlotDataTask_Statics::PropPointers),
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USESlotDataTask_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USESlotDataTask_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USESlotDataTask()
	{
		if (!Z_Registration_Info_UClass_USESlotDataTask.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USESlotDataTask.OuterSingleton, Z_Construct_UClass_USESlotDataTask_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USESlotDataTask.OuterSingleton;
	}
	template<> SAVEEXTENSION_API UClass* StaticClass<USESlotDataTask>()
	{
		return USESlotDataTask::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USESlotDataTask);
	USESlotDataTask::~USESlotDataTask() {}
	struct Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SESlotDataTask_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SESlotDataTask_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USESlotDataTask, USESlotDataTask::StaticClass, TEXT("USESlotDataTask"), &Z_Registration_Info_UClass_USESlotDataTask, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USESlotDataTask), 2305231087U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SESlotDataTask_h_1959134876(TEXT("/Script/SaveExtension"),
		Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SESlotDataTask_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SESlotDataTask_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
