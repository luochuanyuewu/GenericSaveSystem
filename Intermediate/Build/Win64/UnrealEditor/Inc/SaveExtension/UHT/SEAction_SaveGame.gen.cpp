// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveExtension/Public/LatentActions/SEAction_SaveGame.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSEAction_SaveGame() {}
// Cross Module References
	SAVEEXTENSION_API UEnum* Z_Construct_UEnum_SaveExtension_ESESaveGameResult();
	UPackage* Z_Construct_UPackage__Script_SaveExtension();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESESaveGameResult;
	static UEnum* ESESaveGameResult_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ESESaveGameResult.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ESESaveGameResult.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SaveExtension_ESESaveGameResult, Z_Construct_UPackage__Script_SaveExtension(), TEXT("ESESaveGameResult"));
		}
		return Z_Registration_Info_UEnum_ESESaveGameResult.OuterSingleton;
	}
	template<> SAVEEXTENSION_API UEnum* StaticEnum<ESESaveGameResult>()
	{
		return ESESaveGameResult_StaticEnum();
	}
	struct Z_Construct_UEnum_SaveExtension_ESESaveGameResult_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_SaveExtension_ESESaveGameResult_Statics::Enumerators[] = {
		{ "ESESaveGameResult::Saving", (int64)ESESaveGameResult::Saving },
		{ "ESESaveGameResult::Continue", (int64)ESESaveGameResult::Continue },
		{ "ESESaveGameResult::Failed", (int64)ESESaveGameResult::Failed },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_SaveExtension_ESESaveGameResult_Statics::Enum_MetaDataParams[] = {
		{ "Comment", "/**\n * Enum used to indicate quote execution results\n */" },
		{ "Continue.Name", "ESESaveGameResult::Continue" },
		{ "Failed.Name", "ESESaveGameResult::Failed" },
		{ "ModuleRelativePath", "Public/LatentActions/SEAction_SaveGame.h" },
		{ "Saving.Hidden", "" },
		{ "Saving.Name", "ESESaveGameResult::Saving" },
		{ "ToolTip", "Enum used to indicate quote execution results" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SaveExtension_ESESaveGameResult_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_SaveExtension,
		nullptr,
		"ESESaveGameResult",
		"ESESaveGameResult",
		Z_Construct_UEnum_SaveExtension_ESESaveGameResult_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_SaveExtension_ESESaveGameResult_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_SaveExtension_ESESaveGameResult_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_SaveExtension_ESESaveGameResult_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_SaveExtension_ESESaveGameResult()
	{
		if (!Z_Registration_Info_UEnum_ESESaveGameResult.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESESaveGameResult.InnerSingleton, Z_Construct_UEnum_SaveExtension_ESESaveGameResult_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ESESaveGameResult.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_LatentActions_SEAction_SaveGame_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_LatentActions_SEAction_SaveGame_h_Statics::EnumInfo[] = {
		{ ESESaveGameResult_StaticEnum, TEXT("ESESaveGameResult"), &Z_Registration_Info_UEnum_ESESaveGameResult, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1257066789U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_LatentActions_SEAction_SaveGame_h_889606627(TEXT("/Script/SaveExtension"),
		nullptr, 0,
		nullptr, 0,
		Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_LatentActions_SEAction_SaveGame_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_LatentActions_SEAction_SaveGame_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
