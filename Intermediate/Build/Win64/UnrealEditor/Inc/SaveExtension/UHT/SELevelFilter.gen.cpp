// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveExtension/Public/SELevelFilter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSELevelFilter() {}
// Cross Module References
	SAVEEXTENSION_API UScriptStruct* Z_Construct_UScriptStruct_FSELevelFilter();
	UPackage* Z_Construct_UPackage__Script_SaveExtension();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SELevelFilter;
class UScriptStruct* FSELevelFilter::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SELevelFilter.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SELevelFilter.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSELevelFilter, Z_Construct_UPackage__Script_SaveExtension(), TEXT("SELevelFilter"));
	}
	return Z_Registration_Info_UScriptStruct_SELevelFilter.OuterSingleton;
}
template<> SAVEEXTENSION_API UScriptStruct* StaticStruct<FSELevelFilter>()
{
	return FSELevelFilter::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FSELevelFilter_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSELevelFilter_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Contains all settings that affect saving.\n * This information is saved to be restored while loading.\n */" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/SELevelFilter.h" },
		{ "ToolTip", "Contains all settings that affect saving.\nThis information is saved to be restored while loading." },
	};
#endif
	void* Z_Construct_UScriptStruct_FSELevelFilter_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSELevelFilter>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSELevelFilter_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SaveExtension,
		nullptr,
		&NewStructOps,
		"SELevelFilter",
		sizeof(FSELevelFilter),
		alignof(FSELevelFilter),
		nullptr,
		0,
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSELevelFilter_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSELevelFilter_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSELevelFilter()
	{
		if (!Z_Registration_Info_UScriptStruct_SELevelFilter.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SELevelFilter.InnerSingleton, Z_Construct_UScriptStruct_FSELevelFilter_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_SELevelFilter.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SELevelFilter_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SELevelFilter_h_Statics::ScriptStructInfo[] = {
		{ FSELevelFilter::StaticStruct, Z_Construct_UScriptStruct_FSELevelFilter_Statics::NewStructOps, TEXT("SELevelFilter"), &Z_Registration_Info_UScriptStruct_SELevelFilter, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSELevelFilter), 4041083245U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SELevelFilter_h_3934446954(TEXT("/Script/SaveExtension"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SELevelFilter_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SELevelFilter_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
