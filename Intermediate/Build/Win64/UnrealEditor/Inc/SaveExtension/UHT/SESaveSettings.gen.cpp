// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveExtension/Public/SESaveSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSESaveSettings() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESavePreset_NoRegister();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESaveSettings();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESaveSettings_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SaveExtension();
// End Cross Module References
	void USESaveSettings::StaticRegisterNativesUSESaveSettings()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USESaveSettings);
	UClass* Z_Construct_UClass_USESaveSettings_NoRegister()
	{
		return USESaveSettings::StaticClass();
	}
	struct Z_Construct_UClass_USESaveSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Preset_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_Preset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GuidPropertyName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_GuidPropertyName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SerializableTag_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_SerializableTag;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bTickWithGameWorld_MetaData[];
#endif
		static void NewProp_bTickWithGameWorld_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bTickWithGameWorld;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USESaveSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
		(UObject* (*)())Z_Construct_UPackage__Script_SaveExtension,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESaveSettings_Statics::Class_MetaDataParams[] = {
		{ "ClassGroupNames", "SaveExtension" },
		{ "DisplayName", "Save Extension" },
		{ "IncludePath", "SESaveSettings.h" },
		{ "ModuleRelativePath", "Public/SESaveSettings.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESaveSettings_Statics::NewProp_Preset_MetaData[] = {
		{ "Category", "Save Extension" },
		{ "DisplayName", "Preset" },
		{ "ModuleRelativePath", "Public/SESaveSettings.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_USESaveSettings_Statics::NewProp_Preset = { "Preset", nullptr, (EPropertyFlags)0x0014000000004001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USESaveSettings, Preset), Z_Construct_UClass_UClass, Z_Construct_UClass_USESavePreset_NoRegister, METADATA_PARAMS(Z_Construct_UClass_USESaveSettings_Statics::NewProp_Preset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESaveSettings_Statics::NewProp_Preset_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESaveSettings_Statics::NewProp_GuidPropertyName_MetaData[] = {
		{ "Category", "Save Extension" },
		{ "Comment", "/**\n\x09 * \xe5\xae\x9a\xe4\xb9\x89\xe7\x94\xa8\xe4\xbd\x9c\xe5\x94\xaf\xe4\xb8\x80ID\xe7\x9a\x84\xe5\xb1\x9e\xe6\x80\xa7\xe7\x9a\x84\xe5\x90\x8d\xe5\xad\x97\xef\xbc\x8c\xe4\xbc\x9a\xe9\x80\x9a\xe8\xbf\x87\xe5\x8f\x8d\xe5\xb0\x84\xe6\x9f\xa5\xe6\x89\xbe""Actor\xe6\x98\xaf\xe5\x90\xa6\xe6\x9c\x89\xe6\xad\xa4\xe5\xb1\x9e\xe6\x80\xa7\xe6\x9d\xa5\xe5\x88\xa4\xe5\xae\x9a\xe5\x94\xaf\xe4\xb8\x80\xe6\x80\xa7\xe3\x80\x82\n\x09 */" },
		{ "ModuleRelativePath", "Public/SESaveSettings.h" },
		{ "ToolTip", "\xe5\xae\x9a\xe4\xb9\x89\xe7\x94\xa8\xe4\xbd\x9c\xe5\x94\xaf\xe4\xb8\x80ID\xe7\x9a\x84\xe5\xb1\x9e\xe6\x80\xa7\xe7\x9a\x84\xe5\x90\x8d\xe5\xad\x97\xef\xbc\x8c\xe4\xbc\x9a\xe9\x80\x9a\xe8\xbf\x87\xe5\x8f\x8d\xe5\xb0\x84\xe6\x9f\xa5\xe6\x89\xbe""Actor\xe6\x98\xaf\xe5\x90\xa6\xe6\x9c\x89\xe6\xad\xa4\xe5\xb1\x9e\xe6\x80\xa7\xe6\x9d\xa5\xe5\x88\xa4\xe5\xae\x9a\xe5\x94\xaf\xe4\xb8\x80\xe6\x80\xa7\xe3\x80\x82" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_USESaveSettings_Statics::NewProp_GuidPropertyName = { "GuidPropertyName", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USESaveSettings, GuidPropertyName), METADATA_PARAMS(Z_Construct_UClass_USESaveSettings_Statics::NewProp_GuidPropertyName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESaveSettings_Statics::NewProp_GuidPropertyName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESaveSettings_Statics::NewProp_SerializableTag_MetaData[] = {
		{ "Category", "Save Extension" },
		{ "Comment", "/**\n\x09 * @brief actor/component with this tag will be serializable.\n\x09 */" },
		{ "ModuleRelativePath", "Public/SESaveSettings.h" },
		{ "ToolTip", "@brief actor/component with this tag will be serializable." },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_USESaveSettings_Statics::NewProp_SerializableTag = { "SerializableTag", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USESaveSettings, SerializableTag), METADATA_PARAMS(Z_Construct_UClass_USESaveSettings_Statics::NewProp_SerializableTag_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESaveSettings_Statics::NewProp_SerializableTag_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESaveSettings_Statics::NewProp_bTickWithGameWorld_MetaData[] = {
		{ "Category", "Save Extension" },
		{ "Comment", "// If true SaveManager will tick with the world. If game is paused, saving process may be interrupted.\n" },
		{ "ModuleRelativePath", "Public/SESaveSettings.h" },
		{ "ToolTip", "If true SaveManager will tick with the world. If game is paused, saving process may be interrupted." },
	};
#endif
	void Z_Construct_UClass_USESaveSettings_Statics::NewProp_bTickWithGameWorld_SetBit(void* Obj)
	{
		((USESaveSettings*)Obj)->bTickWithGameWorld = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USESaveSettings_Statics::NewProp_bTickWithGameWorld = { "bTickWithGameWorld", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(USESaveSettings), &Z_Construct_UClass_USESaveSettings_Statics::NewProp_bTickWithGameWorld_SetBit, METADATA_PARAMS(Z_Construct_UClass_USESaveSettings_Statics::NewProp_bTickWithGameWorld_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESaveSettings_Statics::NewProp_bTickWithGameWorld_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USESaveSettings_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESaveSettings_Statics::NewProp_Preset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESaveSettings_Statics::NewProp_GuidPropertyName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESaveSettings_Statics::NewProp_SerializableTag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESaveSettings_Statics::NewProp_bTickWithGameWorld,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USESaveSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USESaveSettings>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USESaveSettings_Statics::ClassParams = {
		&USESaveSettings::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_USESaveSettings_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_USESaveSettings_Statics::PropPointers),
		0,
		0x001000A6u,
		METADATA_PARAMS(Z_Construct_UClass_USESaveSettings_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USESaveSettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USESaveSettings()
	{
		if (!Z_Registration_Info_UClass_USESaveSettings.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USESaveSettings.OuterSingleton, Z_Construct_UClass_USESaveSettings_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USESaveSettings.OuterSingleton;
	}
	template<> SAVEEXTENSION_API UClass* StaticClass<USESaveSettings>()
	{
		return USESaveSettings::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USESaveSettings);
	USESaveSettings::~USESaveSettings() {}
	struct Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveSettings_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveSettings_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USESaveSettings, USESaveSettings::StaticClass, TEXT("USESaveSettings"), &Z_Registration_Info_UClass_USESaveSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USESaveSettings), 4084181308U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveSettings_h_3160028315(TEXT("/Script/SaveExtension"),
		Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveSettings_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
