// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveExtension/Public/SELevelStreamingNotifier.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSELevelStreamingNotifier() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USELevelStreamingNotifier();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USELevelStreamingNotifier_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SaveExtension();
// End Cross Module References
	DEFINE_FUNCTION(USELevelStreamingNotifier::execOnHidden)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnHidden();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USELevelStreamingNotifier::execOnShown)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnShown();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USELevelStreamingNotifier::execOnUnloaded)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnUnloaded();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USELevelStreamingNotifier::execOnLoaded)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnLoaded();
		P_NATIVE_END;
	}
	void USELevelStreamingNotifier::StaticRegisterNativesUSELevelStreamingNotifier()
	{
		UClass* Class = USELevelStreamingNotifier::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnHidden", &USELevelStreamingNotifier::execOnHidden },
			{ "OnLoaded", &USELevelStreamingNotifier::execOnLoaded },
			{ "OnShown", &USELevelStreamingNotifier::execOnShown },
			{ "OnUnloaded", &USELevelStreamingNotifier::execOnUnloaded },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USELevelStreamingNotifier_OnHidden_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USELevelStreamingNotifier_OnHidden_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SELevelStreamingNotifier.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USELevelStreamingNotifier_OnHidden_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USELevelStreamingNotifier, nullptr, "OnHidden", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USELevelStreamingNotifier_OnHidden_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USELevelStreamingNotifier_OnHidden_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USELevelStreamingNotifier_OnHidden()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USELevelStreamingNotifier_OnHidden_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USELevelStreamingNotifier_OnLoaded_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USELevelStreamingNotifier_OnLoaded_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SELevelStreamingNotifier.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USELevelStreamingNotifier_OnLoaded_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USELevelStreamingNotifier, nullptr, "OnLoaded", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USELevelStreamingNotifier_OnLoaded_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USELevelStreamingNotifier_OnLoaded_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USELevelStreamingNotifier_OnLoaded()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USELevelStreamingNotifier_OnLoaded_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USELevelStreamingNotifier_OnShown_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USELevelStreamingNotifier_OnShown_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SELevelStreamingNotifier.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USELevelStreamingNotifier_OnShown_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USELevelStreamingNotifier, nullptr, "OnShown", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USELevelStreamingNotifier_OnShown_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USELevelStreamingNotifier_OnShown_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USELevelStreamingNotifier_OnShown()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USELevelStreamingNotifier_OnShown_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USELevelStreamingNotifier_OnUnloaded_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USELevelStreamingNotifier_OnUnloaded_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SELevelStreamingNotifier.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USELevelStreamingNotifier_OnUnloaded_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USELevelStreamingNotifier, nullptr, "OnUnloaded", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USELevelStreamingNotifier_OnUnloaded_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USELevelStreamingNotifier_OnUnloaded_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USELevelStreamingNotifier_OnUnloaded()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USELevelStreamingNotifier_OnUnloaded_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USELevelStreamingNotifier);
	UClass* Z_Construct_UClass_USELevelStreamingNotifier_NoRegister()
	{
		return USELevelStreamingNotifier::StaticClass();
	}
	struct Z_Construct_UClass_USELevelStreamingNotifier_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USELevelStreamingNotifier_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_SaveExtension,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USELevelStreamingNotifier_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USELevelStreamingNotifier_OnHidden, "OnHidden" }, // 940384162
		{ &Z_Construct_UFunction_USELevelStreamingNotifier_OnLoaded, "OnLoaded" }, // 3450458502
		{ &Z_Construct_UFunction_USELevelStreamingNotifier_OnShown, "OnShown" }, // 1247682197
		{ &Z_Construct_UFunction_USELevelStreamingNotifier_OnUnloaded, "OnUnloaded" }, // 3321087273
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USELevelStreamingNotifier_Statics::Class_MetaDataParams[] = {
		{ "ClassGroupNames", "SaveExtension" },
		{ "Comment", "/** ULevelStreamingNotifier is an adapter that expands UE4's native\n * level streaming delegates adding a ptr to the level to each delegate\n */" },
		{ "IncludePath", "SELevelStreamingNotifier.h" },
		{ "ModuleRelativePath", "Public/SELevelStreamingNotifier.h" },
		{ "ToolTip", "ULevelStreamingNotifier is an adapter that expands UE4's native\nlevel streaming delegates adding a ptr to the level to each delegate" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USELevelStreamingNotifier_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USELevelStreamingNotifier>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USELevelStreamingNotifier_Statics::ClassParams = {
		&USELevelStreamingNotifier::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A8u,
		METADATA_PARAMS(Z_Construct_UClass_USELevelStreamingNotifier_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USELevelStreamingNotifier_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USELevelStreamingNotifier()
	{
		if (!Z_Registration_Info_UClass_USELevelStreamingNotifier.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USELevelStreamingNotifier.OuterSingleton, Z_Construct_UClass_USELevelStreamingNotifier_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USELevelStreamingNotifier.OuterSingleton;
	}
	template<> SAVEEXTENSION_API UClass* StaticClass<USELevelStreamingNotifier>()
	{
		return USELevelStreamingNotifier::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USELevelStreamingNotifier);
	USELevelStreamingNotifier::~USELevelStreamingNotifier() {}
	struct Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SELevelStreamingNotifier_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SELevelStreamingNotifier_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USELevelStreamingNotifier, USELevelStreamingNotifier::StaticClass, TEXT("USELevelStreamingNotifier"), &Z_Registration_Info_UClass_USELevelStreamingNotifier, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USELevelStreamingNotifier), 3665870756U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SELevelStreamingNotifier_h_1150994262(TEXT("/Script/SaveExtension"),
		Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SELevelStreamingNotifier_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SELevelStreamingNotifier_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
