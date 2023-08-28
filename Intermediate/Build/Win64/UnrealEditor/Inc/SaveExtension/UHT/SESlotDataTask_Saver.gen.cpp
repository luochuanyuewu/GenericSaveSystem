// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveExtension/Public/Serialization/SESlotDataTask_Saver.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSESlotDataTask_Saver() {}
// Cross Module References
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESlotDataTask();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESlotDataTask_Saver();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESlotDataTask_Saver_NoRegister();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESlotInfo_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SaveExtension();
// End Cross Module References
	void USESlotDataTask_Saver::StaticRegisterNativesUSESlotDataTask_Saver()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USESlotDataTask_Saver);
	UClass* Z_Construct_UClass_USESlotDataTask_Saver_NoRegister()
	{
		return USESlotDataTask_Saver::StaticClass();
	}
	struct Z_Construct_UClass_USESlotDataTask_Saver_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SlotInfo_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SlotInfo;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USESlotDataTask_Saver_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USESlotDataTask,
		(UObject* (*)())Z_Construct_UPackage__Script_SaveExtension,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESlotDataTask_Saver_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n* Manages the saving process of a SaveData file\n* \xe7\xae\xa1\xe7\x90\x86\xe5\xad\x98\xe6\xa1\xa3\xe6\x95\xb0\xe6\x8d\xae\xe7\x9a\x84\xe4\xbf\x9d\xe5\xad\x98\xe8\xbf\x87\xe7\xa8\x8b.\n*/" },
		{ "IncludePath", "Serialization/SESlotDataTask_Saver.h" },
		{ "ModuleRelativePath", "Public/Serialization/SESlotDataTask_Saver.h" },
		{ "ToolTip", "Manages the saving process of a SaveData file\n\xe7\xae\xa1\xe7\x90\x86\xe5\xad\x98\xe6\xa1\xa3\xe6\x95\xb0\xe6\x8d\xae\xe7\x9a\x84\xe4\xbf\x9d\xe5\xad\x98\xe8\xbf\x87\xe7\xa8\x8b." },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESlotDataTask_Saver_Statics::NewProp_SlotInfo_MetaData[] = {
		{ "ModuleRelativePath", "Public/Serialization/SESlotDataTask_Saver.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USESlotDataTask_Saver_Statics::NewProp_SlotInfo = { "SlotInfo", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USESlotDataTask_Saver, SlotInfo), Z_Construct_UClass_USESlotInfo_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USESlotDataTask_Saver_Statics::NewProp_SlotInfo_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESlotDataTask_Saver_Statics::NewProp_SlotInfo_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USESlotDataTask_Saver_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESlotDataTask_Saver_Statics::NewProp_SlotInfo,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USESlotDataTask_Saver_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USESlotDataTask_Saver>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USESlotDataTask_Saver_Statics::ClassParams = {
		&USESlotDataTask_Saver::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_USESlotDataTask_Saver_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_USESlotDataTask_Saver_Statics::PropPointers),
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USESlotDataTask_Saver_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USESlotDataTask_Saver_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USESlotDataTask_Saver()
	{
		if (!Z_Registration_Info_UClass_USESlotDataTask_Saver.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USESlotDataTask_Saver.OuterSingleton, Z_Construct_UClass_USESlotDataTask_Saver_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USESlotDataTask_Saver.OuterSingleton;
	}
	template<> SAVEEXTENSION_API UClass* StaticClass<USESlotDataTask_Saver>()
	{
		return USESlotDataTask_Saver::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USESlotDataTask_Saver);
	USESlotDataTask_Saver::~USESlotDataTask_Saver() {}
	struct Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SESlotDataTask_Saver_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SESlotDataTask_Saver_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USESlotDataTask_Saver, USESlotDataTask_Saver::StaticClass, TEXT("USESlotDataTask_Saver"), &Z_Registration_Info_UClass_USESlotDataTask_Saver, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USESlotDataTask_Saver), 2957914619U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SESlotDataTask_Saver_h_4080824196(TEXT("/Script/SaveExtension"),
		Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SESlotDataTask_Saver_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SESlotDataTask_Saver_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
