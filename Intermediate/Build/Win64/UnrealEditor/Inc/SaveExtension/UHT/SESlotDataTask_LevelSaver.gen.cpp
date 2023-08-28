// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveExtension/Public/Serialization/SESlotDataTask_LevelSaver.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSESlotDataTask_LevelSaver() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_ULevelStreaming_NoRegister();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESlotDataTask_LevelSaver();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESlotDataTask_LevelSaver_NoRegister();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESlotDataTask_Saver();
	UPackage* Z_Construct_UPackage__Script_SaveExtension();
// End Cross Module References
	void USESlotDataTask_LevelSaver::StaticRegisterNativesUSESlotDataTask_LevelSaver()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USESlotDataTask_LevelSaver);
	UClass* Z_Construct_UClass_USESlotDataTask_LevelSaver_NoRegister()
	{
		return USESlotDataTask_LevelSaver::StaticClass();
	}
	struct Z_Construct_UClass_USESlotDataTask_LevelSaver_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StreamingLevel_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_StreamingLevel;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USESlotDataTask_LevelSaver_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USESlotDataTask_Saver,
		(UObject* (*)())Z_Construct_UPackage__Script_SaveExtension,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESlotDataTask_LevelSaver_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n* Manages the serializing process of a single level\n* \xe7\xae\xa1\xe7\x90\x86\xe4\xb8\x80\xe4\xb8\xaa\xe6\xb5\x81\xe9\x80\x81\xe5\x85\xb3\xe5\x8d\xa1\xe7\x9a\x84\xe5\xba\x8f\xe5\x88\x97\xe5\x8c\x96\xe8\xbf\x87\xe7\xa8\x8b\xe3\x80\x82\n*/" },
		{ "IncludePath", "Serialization/SESlotDataTask_LevelSaver.h" },
		{ "ModuleRelativePath", "Public/Serialization/SESlotDataTask_LevelSaver.h" },
		{ "ToolTip", "Manages the serializing process of a single level\n\xe7\xae\xa1\xe7\x90\x86\xe4\xb8\x80\xe4\xb8\xaa\xe6\xb5\x81\xe9\x80\x81\xe5\x85\xb3\xe5\x8d\xa1\xe7\x9a\x84\xe5\xba\x8f\xe5\x88\x97\xe5\x8c\x96\xe8\xbf\x87\xe7\xa8\x8b\xe3\x80\x82" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESlotDataTask_LevelSaver_Statics::NewProp_StreamingLevel_MetaData[] = {
		{ "ModuleRelativePath", "Public/Serialization/SESlotDataTask_LevelSaver.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_USESlotDataTask_LevelSaver_Statics::NewProp_StreamingLevel = { "StreamingLevel", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USESlotDataTask_LevelSaver, StreamingLevel), Z_Construct_UClass_ULevelStreaming_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USESlotDataTask_LevelSaver_Statics::NewProp_StreamingLevel_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESlotDataTask_LevelSaver_Statics::NewProp_StreamingLevel_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USESlotDataTask_LevelSaver_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESlotDataTask_LevelSaver_Statics::NewProp_StreamingLevel,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USESlotDataTask_LevelSaver_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USESlotDataTask_LevelSaver>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USESlotDataTask_LevelSaver_Statics::ClassParams = {
		&USESlotDataTask_LevelSaver::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_USESlotDataTask_LevelSaver_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_USESlotDataTask_LevelSaver_Statics::PropPointers),
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USESlotDataTask_LevelSaver_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USESlotDataTask_LevelSaver_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USESlotDataTask_LevelSaver()
	{
		if (!Z_Registration_Info_UClass_USESlotDataTask_LevelSaver.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USESlotDataTask_LevelSaver.OuterSingleton, Z_Construct_UClass_USESlotDataTask_LevelSaver_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USESlotDataTask_LevelSaver.OuterSingleton;
	}
	template<> SAVEEXTENSION_API UClass* StaticClass<USESlotDataTask_LevelSaver>()
	{
		return USESlotDataTask_LevelSaver::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USESlotDataTask_LevelSaver);
	USESlotDataTask_LevelSaver::~USESlotDataTask_LevelSaver() {}
	struct Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SESlotDataTask_LevelSaver_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SESlotDataTask_LevelSaver_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USESlotDataTask_LevelSaver, USESlotDataTask_LevelSaver::StaticClass, TEXT("USESlotDataTask_LevelSaver"), &Z_Registration_Info_UClass_USESlotDataTask_LevelSaver, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USESlotDataTask_LevelSaver), 2478921488U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SESlotDataTask_LevelSaver_h_4243252459(TEXT("/Script/SaveExtension"),
		Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SESlotDataTask_LevelSaver_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SESlotDataTask_LevelSaver_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
