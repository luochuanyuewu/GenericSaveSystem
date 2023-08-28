// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveExtension/Public/Serialization/SELevelRecords.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSELevelRecords() {}
// Cross Module References
	SAVEEXTENSION_API UScriptStruct* Z_Construct_UScriptStruct_FSEBaseRecord();
	SAVEEXTENSION_API UScriptStruct* Z_Construct_UScriptStruct_FSELevelRecord();
	SAVEEXTENSION_API UScriptStruct* Z_Construct_UScriptStruct_FSEPersistentLevelRecord();
	SAVEEXTENSION_API UScriptStruct* Z_Construct_UScriptStruct_FSEStreamingLevelRecord();
	UPackage* Z_Construct_UPackage__Script_SaveExtension();
// End Cross Module References

static_assert(std::is_polymorphic<FSELevelRecord>() == std::is_polymorphic<FSEBaseRecord>(), "USTRUCT FSELevelRecord cannot be polymorphic unless super FSEBaseRecord is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SELevelRecord;
class UScriptStruct* FSELevelRecord::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SELevelRecord.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SELevelRecord.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSELevelRecord, Z_Construct_UPackage__Script_SaveExtension(), TEXT("SELevelRecord"));
	}
	return Z_Registration_Info_UScriptStruct_SELevelRecord.OuterSingleton;
}
template<> SAVEEXTENSION_API UScriptStruct* StaticStruct<FSELevelRecord>()
{
	return FSELevelRecord::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FSELevelRecord_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSELevelRecord_Statics::Struct_MetaDataParams[] = {
		{ "Comment", "/** Represents a level in the world (streaming or persistent) */" },
		{ "ModuleRelativePath", "Public/Serialization/SELevelRecords.h" },
		{ "ToolTip", "Represents a level in the world (streaming or persistent)" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSELevelRecord_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSELevelRecord>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSELevelRecord_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SaveExtension,
		Z_Construct_UScriptStruct_FSEBaseRecord,
		&NewStructOps,
		"SELevelRecord",
		sizeof(FSELevelRecord),
		alignof(FSELevelRecord),
		nullptr,
		0,
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSELevelRecord_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSELevelRecord_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSELevelRecord()
	{
		if (!Z_Registration_Info_UScriptStruct_SELevelRecord.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SELevelRecord.InnerSingleton, Z_Construct_UScriptStruct_FSELevelRecord_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_SELevelRecord.InnerSingleton;
	}

static_assert(std::is_polymorphic<FSEPersistentLevelRecord>() == std::is_polymorphic<FSELevelRecord>(), "USTRUCT FSEPersistentLevelRecord cannot be polymorphic unless super FSELevelRecord is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SEPersistentLevelRecord;
class UScriptStruct* FSEPersistentLevelRecord::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SEPersistentLevelRecord.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SEPersistentLevelRecord.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSEPersistentLevelRecord, Z_Construct_UPackage__Script_SaveExtension(), TEXT("SEPersistentLevelRecord"));
	}
	return Z_Registration_Info_UScriptStruct_SEPersistentLevelRecord.OuterSingleton;
}
template<> SAVEEXTENSION_API UScriptStruct* StaticStruct<FSEPersistentLevelRecord>()
{
	return FSEPersistentLevelRecord::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FSEPersistentLevelRecord_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSEPersistentLevelRecord_Statics::Struct_MetaDataParams[] = {
		{ "Comment", "/** Represents a persistent level in the world */" },
		{ "ModuleRelativePath", "Public/Serialization/SELevelRecords.h" },
		{ "ToolTip", "Represents a persistent level in the world" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSEPersistentLevelRecord_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSEPersistentLevelRecord>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSEPersistentLevelRecord_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SaveExtension,
		Z_Construct_UScriptStruct_FSELevelRecord,
		&NewStructOps,
		"SEPersistentLevelRecord",
		sizeof(FSEPersistentLevelRecord),
		alignof(FSEPersistentLevelRecord),
		nullptr,
		0,
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSEPersistentLevelRecord_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSEPersistentLevelRecord_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSEPersistentLevelRecord()
	{
		if (!Z_Registration_Info_UScriptStruct_SEPersistentLevelRecord.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SEPersistentLevelRecord.InnerSingleton, Z_Construct_UScriptStruct_FSEPersistentLevelRecord_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_SEPersistentLevelRecord.InnerSingleton;
	}

static_assert(std::is_polymorphic<FSEStreamingLevelRecord>() == std::is_polymorphic<FSELevelRecord>(), "USTRUCT FSEStreamingLevelRecord cannot be polymorphic unless super FSELevelRecord is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SEStreamingLevelRecord;
class UScriptStruct* FSEStreamingLevelRecord::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SEStreamingLevelRecord.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SEStreamingLevelRecord.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSEStreamingLevelRecord, Z_Construct_UPackage__Script_SaveExtension(), TEXT("SEStreamingLevelRecord"));
	}
	return Z_Registration_Info_UScriptStruct_SEStreamingLevelRecord.OuterSingleton;
}
template<> SAVEEXTENSION_API UScriptStruct* StaticStruct<FSEStreamingLevelRecord>()
{
	return FSEStreamingLevelRecord::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FSEStreamingLevelRecord_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSEStreamingLevelRecord_Statics::Struct_MetaDataParams[] = {
		{ "Comment", "/** Represents a serialized streaming level in the world */" },
		{ "ModuleRelativePath", "Public/Serialization/SELevelRecords.h" },
		{ "ToolTip", "Represents a serialized streaming level in the world" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSEStreamingLevelRecord_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSEStreamingLevelRecord>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSEStreamingLevelRecord_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SaveExtension,
		Z_Construct_UScriptStruct_FSELevelRecord,
		&NewStructOps,
		"SEStreamingLevelRecord",
		sizeof(FSEStreamingLevelRecord),
		alignof(FSEStreamingLevelRecord),
		nullptr,
		0,
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSEStreamingLevelRecord_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSEStreamingLevelRecord_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSEStreamingLevelRecord()
	{
		if (!Z_Registration_Info_UScriptStruct_SEStreamingLevelRecord.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SEStreamingLevelRecord.InnerSingleton, Z_Construct_UScriptStruct_FSEStreamingLevelRecord_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_SEStreamingLevelRecord.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SELevelRecords_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SELevelRecords_h_Statics::ScriptStructInfo[] = {
		{ FSELevelRecord::StaticStruct, Z_Construct_UScriptStruct_FSELevelRecord_Statics::NewStructOps, TEXT("SELevelRecord"), &Z_Registration_Info_UScriptStruct_SELevelRecord, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSELevelRecord), 3547139020U) },
		{ FSEPersistentLevelRecord::StaticStruct, Z_Construct_UScriptStruct_FSEPersistentLevelRecord_Statics::NewStructOps, TEXT("SEPersistentLevelRecord"), &Z_Registration_Info_UScriptStruct_SEPersistentLevelRecord, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSEPersistentLevelRecord), 1410107222U) },
		{ FSEStreamingLevelRecord::StaticStruct, Z_Construct_UScriptStruct_FSEStreamingLevelRecord_Statics::NewStructOps, TEXT("SEStreamingLevelRecord"), &Z_Registration_Info_UScriptStruct_SEStreamingLevelRecord, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSEStreamingLevelRecord), 2304662077U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SELevelRecords_h_2360716828(TEXT("/Script/SaveExtension"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SELevelRecords_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SELevelRecords_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
