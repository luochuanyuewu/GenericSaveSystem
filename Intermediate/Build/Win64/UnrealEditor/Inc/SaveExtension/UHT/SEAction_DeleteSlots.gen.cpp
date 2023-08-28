// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveExtension/Public/LatentActions/SEAction_DeleteSlots.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSEAction_DeleteSlots() {}
// Cross Module References
	SAVEEXTENSION_API UEnum* Z_Construct_UEnum_SaveExtension_ESEDeleteSlotsResult();
	UPackage* Z_Construct_UPackage__Script_SaveExtension();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESEDeleteSlotsResult;
	static UEnum* ESEDeleteSlotsResult_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ESEDeleteSlotsResult.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ESEDeleteSlotsResult.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SaveExtension_ESEDeleteSlotsResult, Z_Construct_UPackage__Script_SaveExtension(), TEXT("ESEDeleteSlotsResult"));
		}
		return Z_Registration_Info_UEnum_ESEDeleteSlotsResult.OuterSingleton;
	}
	template<> SAVEEXTENSION_API UEnum* StaticEnum<ESEDeleteSlotsResult>()
	{
		return ESEDeleteSlotsResult_StaticEnum();
	}
	struct Z_Construct_UEnum_SaveExtension_ESEDeleteSlotsResult_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_SaveExtension_ESEDeleteSlotsResult_Statics::Enumerators[] = {
		{ "ESEDeleteSlotsResult::Completed", (int64)ESEDeleteSlotsResult::Completed },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_SaveExtension_ESEDeleteSlotsResult_Statics::Enum_MetaDataParams[] = {
		{ "Comment", "/**\n * Enum used to indicate quote execution results\n */" },
		{ "Completed.Name", "ESEDeleteSlotsResult::Completed" },
		{ "ModuleRelativePath", "Public/LatentActions/SEAction_DeleteSlots.h" },
		{ "ToolTip", "Enum used to indicate quote execution results" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SaveExtension_ESEDeleteSlotsResult_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_SaveExtension,
		nullptr,
		"ESEDeleteSlotsResult",
		"ESEDeleteSlotsResult",
		Z_Construct_UEnum_SaveExtension_ESEDeleteSlotsResult_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_SaveExtension_ESEDeleteSlotsResult_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_SaveExtension_ESEDeleteSlotsResult_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_SaveExtension_ESEDeleteSlotsResult_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_SaveExtension_ESEDeleteSlotsResult()
	{
		if (!Z_Registration_Info_UEnum_ESEDeleteSlotsResult.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESEDeleteSlotsResult.InnerSingleton, Z_Construct_UEnum_SaveExtension_ESEDeleteSlotsResult_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ESEDeleteSlotsResult.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_LatentActions_SEAction_DeleteSlots_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_LatentActions_SEAction_DeleteSlots_h_Statics::EnumInfo[] = {
		{ ESEDeleteSlotsResult_StaticEnum, TEXT("ESEDeleteSlotsResult"), &Z_Registration_Info_UEnum_ESEDeleteSlotsResult, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1661764414U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_LatentActions_SEAction_DeleteSlots_h_573784823(TEXT("/Script/SaveExtension"),
		nullptr, 0,
		nullptr, 0,
		Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_LatentActions_SEAction_DeleteSlots_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_LatentActions_SEAction_DeleteSlots_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
