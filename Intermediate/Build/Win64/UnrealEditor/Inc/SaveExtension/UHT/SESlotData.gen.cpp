// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveExtension/Public/SESlotData.h"
#include "Serialization/ArchiveUObjectFromStructuredArchive.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSESlotData() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_USaveGame();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESlotData();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESlotData_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SaveExtension();
// End Cross Module References
	void USESlotData::StaticRegisterNativesUSESlotData()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USESlotData);
	UClass* Z_Construct_UClass_USESlotData_NoRegister()
	{
		return USESlotData::StaticClass();
	}
	struct Z_Construct_UClass_USESlotData_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Map_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_Map;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TimeSeconds_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TimeSeconds;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USESlotData_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USaveGame,
		(UObject* (*)())Z_Construct_UPackage__Script_SaveExtension,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESlotData_Statics::Class_MetaDataParams[] = {
		{ "ClassGroupNames", "SaveExtension" },
		{ "Comment", "/**\n * USaveData stores all information that can be accessible only while the game is loaded.\n * Works like a common SaveGame object\n * E.g: Items, Quests, Enemies, World Actors, AI, Physics\n */" },
		{ "HideCategories", "Activation Actor Tick Actor Input Rendering Replication Socket Thumbnail" },
		{ "IncludePath", "SESlotData.h" },
		{ "ModuleRelativePath", "Public/SESlotData.h" },
		{ "ToolTip", "USaveData stores all information that can be accessible only while the game is loaded.\nWorks like a common SaveGame object\nE.g: Items, Quests, Enemies, World Actors, AI, Physics" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESlotData_Statics::NewProp_Map_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "SaveData" },
		{ "Comment", "/** Full Name of the Map where this SlotData was saved */" },
		{ "ModuleRelativePath", "Public/SESlotData.h" },
		{ "ToolTip", "Full Name of the Map where this SlotData was saved" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_USESlotData_Statics::NewProp_Map = { "Map", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USESlotData, Map), METADATA_PARAMS(Z_Construct_UClass_USESlotData_Statics::NewProp_Map_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESlotData_Statics::NewProp_Map_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESlotData_Statics::NewProp_TimeSeconds_MetaData[] = {
		{ "Category", "SaveData" },
		{ "Comment", "/** Game world time since game started in seconds */" },
		{ "ModuleRelativePath", "Public/SESlotData.h" },
		{ "ToolTip", "Game world time since game started in seconds" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USESlotData_Statics::NewProp_TimeSeconds = { "TimeSeconds", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USESlotData, TimeSeconds), METADATA_PARAMS(Z_Construct_UClass_USESlotData_Statics::NewProp_TimeSeconds_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESlotData_Statics::NewProp_TimeSeconds_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USESlotData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESlotData_Statics::NewProp_Map,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESlotData_Statics::NewProp_TimeSeconds,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USESlotData_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USESlotData>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USESlotData_Statics::ClassParams = {
		&USESlotData::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_USESlotData_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_USESlotData_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USESlotData_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USESlotData_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USESlotData()
	{
		if (!Z_Registration_Info_UClass_USESlotData.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USESlotData.OuterSingleton, Z_Construct_UClass_USESlotData_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USESlotData.OuterSingleton;
	}
	template<> SAVEEXTENSION_API UClass* StaticClass<USESlotData>()
	{
		return USESlotData::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USESlotData);
	USESlotData::~USESlotData() {}
	IMPLEMENT_FSTRUCTUREDARCHIVE_SERIALIZER(USESlotData)
	struct Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESlotData_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESlotData_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USESlotData, USESlotData::StaticClass, TEXT("USESlotData"), &Z_Registration_Info_UClass_USESlotData, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USESlotData), 3044670795U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESlotData_h_3362623723(TEXT("/Script/SaveExtension"),
		Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESlotData_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESlotData_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
