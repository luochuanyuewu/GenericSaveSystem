// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveExtension/Public/LatentActions/SEAction_LoadGame.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSEAction_LoadGame() {}
// Cross Module References
	SAVEEXTENSION_API UEnum* Z_Construct_UEnum_SaveExtension_ESELoadGameResult();
	UPackage* Z_Construct_UPackage__Script_SaveExtension();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESELoadGameResult;
	static UEnum* ESELoadGameResult_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ESELoadGameResult.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ESELoadGameResult.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SaveExtension_ESELoadGameResult, Z_Construct_UPackage__Script_SaveExtension(), TEXT("ESELoadGameResult"));
		}
		return Z_Registration_Info_UEnum_ESELoadGameResult.OuterSingleton;
	}
	template<> SAVEEXTENSION_API UEnum* StaticEnum<ESELoadGameResult>()
	{
		return ESELoadGameResult_StaticEnum();
	}
	struct Z_Construct_UEnum_SaveExtension_ESELoadGameResult_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_SaveExtension_ESELoadGameResult_Statics::Enumerators[] = {
		{ "ESELoadGameResult::Loading", (int64)ESELoadGameResult::Loading },
		{ "ESELoadGameResult::Continue", (int64)ESELoadGameResult::Continue },
		{ "ESELoadGameResult::Failed", (int64)ESELoadGameResult::Failed },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_SaveExtension_ESELoadGameResult_Statics::Enum_MetaDataParams[] = {
		{ "Comment", "/**\n * Enum used to indicate quote execution results\n */" },
		{ "Continue.Name", "ESELoadGameResult::Continue" },
		{ "Failed.Name", "ESELoadGameResult::Failed" },
		{ "Loading.Hidden", "" },
		{ "Loading.Name", "ESELoadGameResult::Loading" },
		{ "ModuleRelativePath", "Public/LatentActions/SEAction_LoadGame.h" },
		{ "ToolTip", "Enum used to indicate quote execution results" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SaveExtension_ESELoadGameResult_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_SaveExtension,
		nullptr,
		"ESELoadGameResult",
		"ESELoadGameResult",
		Z_Construct_UEnum_SaveExtension_ESELoadGameResult_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_SaveExtension_ESELoadGameResult_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_SaveExtension_ESELoadGameResult_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_SaveExtension_ESELoadGameResult_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_SaveExtension_ESELoadGameResult()
	{
		if (!Z_Registration_Info_UEnum_ESELoadGameResult.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESELoadGameResult.InnerSingleton, Z_Construct_UEnum_SaveExtension_ESELoadGameResult_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ESELoadGameResult.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_LatentActions_SEAction_LoadGame_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_LatentActions_SEAction_LoadGame_h_Statics::EnumInfo[] = {
		{ ESELoadGameResult_StaticEnum, TEXT("ESELoadGameResult"), &Z_Registration_Info_UEnum_ESELoadGameResult, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4094298572U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_LatentActions_SEAction_LoadGame_h_1186715799(TEXT("/Script/SaveExtension"),
		nullptr, 0,
		nullptr, 0,
		Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_LatentActions_SEAction_LoadGame_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_LatentActions_SEAction_LoadGame_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
