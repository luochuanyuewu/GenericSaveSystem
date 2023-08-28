// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveExtension/Public/Serialization/SERecords.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSERecords() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	SAVEEXTENSION_API UScriptStruct* Z_Construct_UScriptStruct_FSEActorRecord();
	SAVEEXTENSION_API UScriptStruct* Z_Construct_UScriptStruct_FSEBaseRecord();
	SAVEEXTENSION_API UScriptStruct* Z_Construct_UScriptStruct_FSEComponentRecord();
	SAVEEXTENSION_API UScriptStruct* Z_Construct_UScriptStruct_FSEObjectRecord();
	UPackage* Z_Construct_UPackage__Script_SaveExtension();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SEBaseRecord;
class UScriptStruct* FSEBaseRecord::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SEBaseRecord.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SEBaseRecord.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSEBaseRecord, Z_Construct_UPackage__Script_SaveExtension(), TEXT("SEBaseRecord"));
	}
	return Z_Registration_Info_UScriptStruct_SEBaseRecord.OuterSingleton;
}
template<> SAVEEXTENSION_API UScriptStruct* StaticStruct<FSEBaseRecord>()
{
	return FSEBaseRecord::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FSEBaseRecord_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSEBaseRecord_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Serialization/SERecords.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSEBaseRecord_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSEBaseRecord>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSEBaseRecord_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SaveExtension,
		nullptr,
		&NewStructOps,
		"SEBaseRecord",
		sizeof(FSEBaseRecord),
		alignof(FSEBaseRecord),
		nullptr,
		0,
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSEBaseRecord_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSEBaseRecord_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSEBaseRecord()
	{
		if (!Z_Registration_Info_UScriptStruct_SEBaseRecord.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SEBaseRecord.InnerSingleton, Z_Construct_UScriptStruct_FSEBaseRecord_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_SEBaseRecord.InnerSingleton;
	}

static_assert(std::is_polymorphic<FSEObjectRecord>() == std::is_polymorphic<FSEBaseRecord>(), "USTRUCT FSEObjectRecord cannot be polymorphic unless super FSEBaseRecord is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SEObjectRecord;
class UScriptStruct* FSEObjectRecord::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SEObjectRecord.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SEObjectRecord.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSEObjectRecord, Z_Construct_UPackage__Script_SaveExtension(), TEXT("SEObjectRecord"));
	}
	return Z_Registration_Info_UScriptStruct_SEObjectRecord.OuterSingleton;
}
template<> SAVEEXTENSION_API UScriptStruct* StaticStruct<FSEObjectRecord>()
{
	return FSEObjectRecord::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FSEObjectRecord_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Class_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_Class;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSEObjectRecord_Statics::Struct_MetaDataParams[] = {
		{ "Comment", "/** Represents a serialized Object */" },
		{ "ModuleRelativePath", "Public/Serialization/SERecords.h" },
		{ "ToolTip", "Represents a serialized Object" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSEObjectRecord_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSEObjectRecord>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSEObjectRecord_Statics::NewProp_Class_MetaData[] = {
		{ "ModuleRelativePath", "Public/Serialization/SERecords.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FSEObjectRecord_Statics::NewProp_Class = { "Class", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSEObjectRecord, Class), Z_Construct_UClass_UClass, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FSEObjectRecord_Statics::NewProp_Class_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSEObjectRecord_Statics::NewProp_Class_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSEObjectRecord_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSEObjectRecord_Statics::NewProp_Class,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSEObjectRecord_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SaveExtension,
		Z_Construct_UScriptStruct_FSEBaseRecord,
		&NewStructOps,
		"SEObjectRecord",
		sizeof(FSEObjectRecord),
		alignof(FSEObjectRecord),
		Z_Construct_UScriptStruct_FSEObjectRecord_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSEObjectRecord_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSEObjectRecord_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSEObjectRecord_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSEObjectRecord()
	{
		if (!Z_Registration_Info_UScriptStruct_SEObjectRecord.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SEObjectRecord.InnerSingleton, Z_Construct_UScriptStruct_FSEObjectRecord_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_SEObjectRecord.InnerSingleton;
	}

static_assert(std::is_polymorphic<FSEComponentRecord>() == std::is_polymorphic<FSEObjectRecord>(), "USTRUCT FSEComponentRecord cannot be polymorphic unless super FSEObjectRecord is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SEComponentRecord;
class UScriptStruct* FSEComponentRecord::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SEComponentRecord.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SEComponentRecord.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSEComponentRecord, Z_Construct_UPackage__Script_SaveExtension(), TEXT("SEComponentRecord"));
	}
	return Z_Registration_Info_UScriptStruct_SEComponentRecord.OuterSingleton;
}
template<> SAVEEXTENSION_API UScriptStruct* StaticStruct<FSEComponentRecord>()
{
	return FSEComponentRecord::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FSEComponentRecord_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSEComponentRecord_Statics::Struct_MetaDataParams[] = {
		{ "Comment", "/** Represents a serialized Component */" },
		{ "ModuleRelativePath", "Public/Serialization/SERecords.h" },
		{ "ToolTip", "Represents a serialized Component" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSEComponentRecord_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSEComponentRecord>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSEComponentRecord_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SaveExtension,
		Z_Construct_UScriptStruct_FSEObjectRecord,
		&NewStructOps,
		"SEComponentRecord",
		sizeof(FSEComponentRecord),
		alignof(FSEComponentRecord),
		nullptr,
		0,
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSEComponentRecord_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSEComponentRecord_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSEComponentRecord()
	{
		if (!Z_Registration_Info_UScriptStruct_SEComponentRecord.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SEComponentRecord.InnerSingleton, Z_Construct_UScriptStruct_FSEComponentRecord_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_SEComponentRecord.InnerSingleton;
	}

static_assert(std::is_polymorphic<FSEActorRecord>() == std::is_polymorphic<FSEObjectRecord>(), "USTRUCT FSEActorRecord cannot be polymorphic unless super FSEObjectRecord is polymorphic");

	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SEActorRecord;
class UScriptStruct* FSEActorRecord::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SEActorRecord.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SEActorRecord.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSEActorRecord, Z_Construct_UPackage__Script_SaveExtension(), TEXT("SEActorRecord"));
	}
	return Z_Registration_Info_UScriptStruct_SEActorRecord.OuterSingleton;
}
template<> SAVEEXTENSION_API UScriptStruct* StaticStruct<FSEActorRecord>()
{
	return FSEActorRecord::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FSEActorRecord_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSEActorRecord_Statics::Struct_MetaDataParams[] = {
		{ "Comment", "/** Represents a serialized Actor */" },
		{ "ModuleRelativePath", "Public/Serialization/SERecords.h" },
		{ "ToolTip", "Represents a serialized Actor" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSEActorRecord_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSEActorRecord>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSEActorRecord_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SaveExtension,
		Z_Construct_UScriptStruct_FSEObjectRecord,
		&NewStructOps,
		"SEActorRecord",
		sizeof(FSEActorRecord),
		alignof(FSEActorRecord),
		nullptr,
		0,
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSEActorRecord_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSEActorRecord_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSEActorRecord()
	{
		if (!Z_Registration_Info_UScriptStruct_SEActorRecord.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SEActorRecord.InnerSingleton, Z_Construct_UScriptStruct_FSEActorRecord_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_SEActorRecord.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SERecords_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SERecords_h_Statics::ScriptStructInfo[] = {
		{ FSEBaseRecord::StaticStruct, Z_Construct_UScriptStruct_FSEBaseRecord_Statics::NewStructOps, TEXT("SEBaseRecord"), &Z_Registration_Info_UScriptStruct_SEBaseRecord, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSEBaseRecord), 2869491429U) },
		{ FSEObjectRecord::StaticStruct, Z_Construct_UScriptStruct_FSEObjectRecord_Statics::NewStructOps, TEXT("SEObjectRecord"), &Z_Registration_Info_UScriptStruct_SEObjectRecord, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSEObjectRecord), 3704310507U) },
		{ FSEComponentRecord::StaticStruct, Z_Construct_UScriptStruct_FSEComponentRecord_Statics::NewStructOps, TEXT("SEComponentRecord"), &Z_Registration_Info_UScriptStruct_SEComponentRecord, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSEComponentRecord), 3280038922U) },
		{ FSEActorRecord::StaticStruct, Z_Construct_UScriptStruct_FSEActorRecord_Statics::NewStructOps, TEXT("SEActorRecord"), &Z_Registration_Info_UScriptStruct_SEActorRecord, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSEActorRecord), 755025656U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SERecords_h_314075030(TEXT("/Script/SaveExtension"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SERecords_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Serialization_SERecords_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
