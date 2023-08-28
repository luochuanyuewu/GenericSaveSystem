// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveExtension/Public/Saver/SESaverBase.h"
#include "Serialization/ArchiveUObjectFromStructuredArchive.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSESaverBase() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FGuid();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USELifetimeComponent();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESaverBase();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESaverBase_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SaveExtension();
// End Cross Module References
	DEFINE_FUNCTION(USESaverBase::execTryLoadOnBeginPlay)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->TryLoadOnBeginPlay();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USESaverBase::execTrySaveOnEndplay)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->TrySaveOnEndplay();
		P_NATIVE_END;
	}
	void USESaverBase::StaticRegisterNativesUSESaverBase()
	{
		UClass* Class = USESaverBase::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "TryLoadOnBeginPlay", &USESaverBase::execTryLoadOnBeginPlay },
			{ "TrySaveOnEndplay", &USESaverBase::execTrySaveOnEndplay },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USESaverBase_TryLoadOnBeginPlay_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaverBase_TryLoadOnBeginPlay_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Saver/SESaverBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESaverBase_TryLoadOnBeginPlay_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESaverBase, nullptr, "TryLoadOnBeginPlay", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESaverBase_TryLoadOnBeginPlay_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaverBase_TryLoadOnBeginPlay_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESaverBase_TryLoadOnBeginPlay()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESaverBase_TryLoadOnBeginPlay_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USESaverBase_TrySaveOnEndplay_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaverBase_TrySaveOnEndplay_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Saver/SESaverBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESaverBase_TrySaveOnEndplay_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESaverBase, nullptr, "TrySaveOnEndplay", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESaverBase_TrySaveOnEndplay_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaverBase_TrySaveOnEndplay_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESaverBase_TrySaveOnEndplay()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESaverBase_TrySaveOnEndplay_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USESaverBase);
	UClass* Z_Construct_UClass_USESaverBase_NoRegister()
	{
		return USESaverBase::StaticClass();
	}
	struct Z_Construct_UClass_USESaverBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUseGuid_MetaData[];
#endif
		static void NewProp_bUseGuid_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseGuid;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SaveKey_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_SaveKey;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SaveId_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SaveId;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SavePriority_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_SavePriority;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LoadPriority_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_LoadPriority;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bLoadOnBeginPlay_MetaData[];
#endif
		static void NewProp_bLoadOnBeginPlay_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bLoadOnBeginPlay;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bSaveOnEndPlay_MetaData[];
#endif
		static void NewProp_bSaveOnEndPlay_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSaveOnEndPlay;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USESaverBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USELifetimeComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_SaveExtension,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USESaverBase_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USESaverBase_TryLoadOnBeginPlay, "TryLoadOnBeginPlay" }, // 1622259287
		{ &Z_Construct_UFunction_USESaverBase_TrySaveOnEndplay, "TrySaveOnEndplay" }, // 2405178758
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESaverBase_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "SaveExtension" },
		{ "IncludePath", "Saver/SESaverBase.h" },
		{ "ModuleRelativePath", "Public/Saver/SESaverBase.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESaverBase_Statics::NewProp_bUseGuid_MetaData[] = {
		{ "Category", "Save" },
		{ "ModuleRelativePath", "Public/Saver/SESaverBase.h" },
	};
#endif
	void Z_Construct_UClass_USESaverBase_Statics::NewProp_bUseGuid_SetBit(void* Obj)
	{
		((USESaverBase*)Obj)->bUseGuid = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USESaverBase_Statics::NewProp_bUseGuid = { "bUseGuid", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(USESaverBase), &Z_Construct_UClass_USESaverBase_Statics::NewProp_bUseGuid_SetBit, METADATA_PARAMS(Z_Construct_UClass_USESaverBase_Statics::NewProp_bUseGuid_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESaverBase_Statics::NewProp_bUseGuid_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESaverBase_Statics::NewProp_SaveKey_MetaData[] = {
		{ "Category", "Save" },
		{ "EditCondition", "!bUseGuid" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Saver/SESaverBase.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_USESaverBase_Statics::NewProp_SaveKey = { "SaveKey", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USESaverBase, SaveKey), METADATA_PARAMS(Z_Construct_UClass_USESaverBase_Statics::NewProp_SaveKey_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESaverBase_Statics::NewProp_SaveKey_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESaverBase_Statics::NewProp_SaveId_MetaData[] = {
		{ "Category", "Save" },
		{ "EditCondition", "bUseGuid" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/Saver/SESaverBase.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USESaverBase_Statics::NewProp_SaveId = { "SaveId", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USESaverBase, SaveId), Z_Construct_UScriptStruct_FGuid, METADATA_PARAMS(Z_Construct_UClass_USESaverBase_Statics::NewProp_SaveId_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESaverBase_Statics::NewProp_SaveId_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESaverBase_Statics::NewProp_SavePriority_MetaData[] = {
		{ "Category", "Save" },
		{ "ModuleRelativePath", "Public/Saver/SESaverBase.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_USESaverBase_Statics::NewProp_SavePriority = { "SavePriority", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USESaverBase, SavePriority), METADATA_PARAMS(Z_Construct_UClass_USESaverBase_Statics::NewProp_SavePriority_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESaverBase_Statics::NewProp_SavePriority_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESaverBase_Statics::NewProp_LoadPriority_MetaData[] = {
		{ "Category", "Save" },
		{ "ModuleRelativePath", "Public/Saver/SESaverBase.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_USESaverBase_Statics::NewProp_LoadPriority = { "LoadPriority", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USESaverBase, LoadPriority), METADATA_PARAMS(Z_Construct_UClass_USESaverBase_Statics::NewProp_LoadPriority_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESaverBase_Statics::NewProp_LoadPriority_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESaverBase_Statics::NewProp_bLoadOnBeginPlay_MetaData[] = {
		{ "Category", "Save" },
		{ "ModuleRelativePath", "Public/Saver/SESaverBase.h" },
	};
#endif
	void Z_Construct_UClass_USESaverBase_Statics::NewProp_bLoadOnBeginPlay_SetBit(void* Obj)
	{
		((USESaverBase*)Obj)->bLoadOnBeginPlay = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USESaverBase_Statics::NewProp_bLoadOnBeginPlay = { "bLoadOnBeginPlay", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(USESaverBase), &Z_Construct_UClass_USESaverBase_Statics::NewProp_bLoadOnBeginPlay_SetBit, METADATA_PARAMS(Z_Construct_UClass_USESaverBase_Statics::NewProp_bLoadOnBeginPlay_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESaverBase_Statics::NewProp_bLoadOnBeginPlay_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESaverBase_Statics::NewProp_bSaveOnEndPlay_MetaData[] = {
		{ "Category", "Save" },
		{ "ModuleRelativePath", "Public/Saver/SESaverBase.h" },
	};
#endif
	void Z_Construct_UClass_USESaverBase_Statics::NewProp_bSaveOnEndPlay_SetBit(void* Obj)
	{
		((USESaverBase*)Obj)->bSaveOnEndPlay = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USESaverBase_Statics::NewProp_bSaveOnEndPlay = { "bSaveOnEndPlay", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(USESaverBase), &Z_Construct_UClass_USESaverBase_Statics::NewProp_bSaveOnEndPlay_SetBit, METADATA_PARAMS(Z_Construct_UClass_USESaverBase_Statics::NewProp_bSaveOnEndPlay_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USESaverBase_Statics::NewProp_bSaveOnEndPlay_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USESaverBase_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESaverBase_Statics::NewProp_bUseGuid,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESaverBase_Statics::NewProp_SaveKey,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESaverBase_Statics::NewProp_SaveId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESaverBase_Statics::NewProp_SavePriority,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESaverBase_Statics::NewProp_LoadPriority,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESaverBase_Statics::NewProp_bLoadOnBeginPlay,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USESaverBase_Statics::NewProp_bSaveOnEndPlay,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USESaverBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USESaverBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USESaverBase_Statics::ClassParams = {
		&USESaverBase::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_USESaverBase_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_USESaverBase_Statics::PropPointers),
		0,
		0x00B000A5u,
		METADATA_PARAMS(Z_Construct_UClass_USESaverBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USESaverBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USESaverBase()
	{
		if (!Z_Registration_Info_UClass_USESaverBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USESaverBase.OuterSingleton, Z_Construct_UClass_USESaverBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USESaverBase.OuterSingleton;
	}
	template<> SAVEEXTENSION_API UClass* StaticClass<USESaverBase>()
	{
		return USESaverBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USESaverBase);
	USESaverBase::~USESaverBase() {}
	IMPLEMENT_FSTRUCTUREDARCHIVE_SERIALIZER(USESaverBase)
	struct Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Saver_SESaverBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Saver_SESaverBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USESaverBase, USESaverBase::StaticClass, TEXT("USESaverBase"), &Z_Registration_Info_UClass_USESaverBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USESaverBase), 1227424030U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Saver_SESaverBase_h_4078966563(TEXT("/Script/SaveExtension"),
		Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Saver_SESaverBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_Saver_SESaverBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
