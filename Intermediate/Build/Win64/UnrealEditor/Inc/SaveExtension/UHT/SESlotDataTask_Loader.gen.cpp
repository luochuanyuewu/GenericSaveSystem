// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveExtension/Public/Serialization/SESlotDataTask_Loader.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSESlotDataTask_Loader() {}
// Cross Module References
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESlotDataTask();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESlotDataTask_Loader();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESlotDataTask_Loader_NoRegister();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESlotInfo_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SaveExtension();
// End Cross Module References
	void USESlotDataTask_Loader::StaticRegisterNativesUSESlotDataTask_Loader()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USESlotDataTask_Loader);
	UClass* Z_Construct_UClass_USESlotDataTask_Loader_NoRegister()
	{
		return USESlotDataTask_Loader::StaticClass();
	}
	struct Z_Construct_UClass_USESlotDataTask_Loader_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NewSlotInfo_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_NewSlotInfo;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USESlotDataTask_Loader_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USESlotDataTask,
		(UObject* (*)())Z_Construct_UPackage__Script_SaveExtension,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESlotDataTask_Loader_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n* Manages the loading process of a SaveData file\n* \xe7\xae\xa1\xe7\x90\x86\xe5\xad\x98\xe6\xa1\xa3\xe6\x95\xb0\xe6\x8d\xae\xe6\x96\x87\xe4\xbb\xb6\xe7\x9a\x84\xe5\x8a\xa0\xe8\xbd\xbd\xe8\xbf\x87\xe7\xa8\x8b\xe3\x80\x82\n*/" },
		{ "IncludePath", "Serialization/SESlotDataTask_Loader.h" },
		{ "ModuleRelativePath", "Public/Serialization/SESlotDataTask_Loader.h" },
		{ "ToolTip", "Manages the loading process of a SaveData file\n\xe7\xae\xa1\xe7\x90\x86\xe5\xad\x98\xe6\xa1\xa3\xe6\x95\xb0\xe6\x8d\xae\xe6\x96\x87\xe4\xbb\xb6\xe7\x9a\x84\xe5\x8a\xa0\xe8\xbd\xbd\xe8\xbf\x87\xe7\xa8\x8b\xe3\x80\x82" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESlotDataTask_Loader_Statics::NewProp_NewSlotInfo_MetaData[] = {
		{ "ModuleRelativePath", "Public/Serialization/SESlotDataTask_Loader.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USESlotDataTask_Loader_Statics::NewProp_NewSlotInfo = { "NewSlotInfo", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USESlotDataTask_Loader, NewSlotInfo), Z_Construct_UClass_USESlotInfo_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USESlotDataTask_Loader_Statics::NewProp_NewSlotInfo_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESlotDataTask_Loader_Statics::NewProp_NewSlotInfo_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USESlotDataTask_Loader_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESlotDataTask_Loader_Statics::NewProp_NewSlotInfo,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USESlotDataTask_Loader_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USESlotDataTask_Loader>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USESlotDataTask_Loader_Statics::ClassParams = {
		&USESlotDataTask_Loader::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_USESlotDataTask_Loader_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_USESlotDataTask_Loader_Statics::PropPointers),
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USESlotDataTask_Loader_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USESlotDataTask_Loader_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USESlotDataTask_Loader()
	{
		if (!Z_Registration_Info_UClass_USESlotDataTask_Loader.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USESlotDataTask_Loader.OuterSingleton, Z_Construct_UClass_USESlotDataTask_Loader_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USESlotDataTask_Loader.OuterSingleton;
	}
	template<> SAVEEXTENSION_API UClass* StaticClass<USESlotDataTask_Loader>()
	{
		return USESlotDataTask_Loader::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USESlotDataTask_Loader);
	USESlotDataTask_Loader::~USESlotDataTask_Loader() {}
	struct Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SESlotDataTask_Loader_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SESlotDataTask_Loader_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USESlotDataTask_Loader, USESlotDataTask_Loader::StaticClass, TEXT("USESlotDataTask_Loader"), &Z_Registration_Info_UClass_USESlotDataTask_Loader, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USESlotDataTask_Loader), 1087611670U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SESlotDataTask_Loader_h_4283440974(TEXT("/Script/SaveExtension"),
		Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SESlotDataTask_Loader_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SESlotDataTask_Loader_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
