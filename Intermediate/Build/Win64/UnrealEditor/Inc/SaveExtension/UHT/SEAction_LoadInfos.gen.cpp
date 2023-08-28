// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveExtension/Public/LatentActions/SEAction_LoadInfos.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSEAction_LoadInfos() {}
// Cross Module References
	SAVEEXTENSION_API UEnum* Z_Construct_UEnum_SaveExtension_ESELoadInfoResult();
	UPackage* Z_Construct_UPackage__Script_SaveExtension();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESELoadInfoResult;
	static UEnum* ESELoadInfoResult_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ESELoadInfoResult.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ESELoadInfoResult.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SaveExtension_ESELoadInfoResult, Z_Construct_UPackage__Script_SaveExtension(), TEXT("ESELoadInfoResult"));
		}
		return Z_Registration_Info_UEnum_ESELoadInfoResult.OuterSingleton;
	}
	template<> SAVEEXTENSION_API UEnum* StaticEnum<ESELoadInfoResult>()
	{
		return ESELoadInfoResult_StaticEnum();
	}
	struct Z_Construct_UEnum_SaveExtension_ESELoadInfoResult_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_SaveExtension_ESELoadInfoResult_Statics::Enumerators[] = {
		{ "ESELoadInfoResult::Completed", (int64)ESELoadInfoResult::Completed },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_SaveExtension_ESELoadInfoResult_Statics::Enum_MetaDataParams[] = {
		{ "Comment", "/**\n * Enum used to indicate quote execution results\n */" },
		{ "Completed.Name", "ESELoadInfoResult::Completed" },
		{ "ModuleRelativePath", "Public/LatentActions/SEAction_LoadInfos.h" },
		{ "ToolTip", "Enum used to indicate quote execution results" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SaveExtension_ESELoadInfoResult_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_SaveExtension,
		nullptr,
		"ESELoadInfoResult",
		"ESELoadInfoResult",
		Z_Construct_UEnum_SaveExtension_ESELoadInfoResult_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_SaveExtension_ESELoadInfoResult_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_SaveExtension_ESELoadInfoResult_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_SaveExtension_ESELoadInfoResult_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_SaveExtension_ESELoadInfoResult()
	{
		if (!Z_Registration_Info_UEnum_ESELoadInfoResult.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESELoadInfoResult.InnerSingleton, Z_Construct_UEnum_SaveExtension_ESELoadInfoResult_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ESELoadInfoResult.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_LatentActions_SEAction_LoadInfos_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_LatentActions_SEAction_LoadInfos_h_Statics::EnumInfo[] = {
		{ ESELoadInfoResult_StaticEnum, TEXT("ESELoadInfoResult"), &Z_Registration_Info_UEnum_ESELoadInfoResult, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2864278528U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_LatentActions_SEAction_LoadInfos_h_4011700214(TEXT("/Script/SaveExtension"),
		nullptr, 0,
		nullptr, 0,
		Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_LatentActions_SEAction_LoadInfos_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_LatentActions_SEAction_LoadInfos_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
