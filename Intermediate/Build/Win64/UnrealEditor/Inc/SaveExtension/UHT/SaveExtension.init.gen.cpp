// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSaveExtension_init() {}
	SAVEEXTENSION_API UFunction* Z_Construct_UDelegateFunction_SaveExtension_OnGameLoadedMC__DelegateSignature();
	SAVEEXTENSION_API UFunction* Z_Construct_UDelegateFunction_SaveExtension_OnGameSavedMC__DelegateSignature();
	SAVEEXTENSION_API UFunction* Z_Construct_UDelegateFunction_SaveExtension_SELifetimeFinishSignature__DelegateSignature();
	SAVEEXTENSION_API UFunction* Z_Construct_UDelegateFunction_SaveExtension_SELifetimeResumeSignature__DelegateSignature();
	SAVEEXTENSION_API UFunction* Z_Construct_UDelegateFunction_SaveExtension_SELifetimeSavedSignature__DelegateSignature();
	SAVEEXTENSION_API UFunction* Z_Construct_UDelegateFunction_SaveExtension_SELifetimeStartSignature__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_SaveExtension;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_SaveExtension()
	{
		if (!Z_Registration_Info_UPackage__Script_SaveExtension.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_SaveExtension_OnGameLoadedMC__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SaveExtension_OnGameSavedMC__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SaveExtension_SELifetimeFinishSignature__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SaveExtension_SELifetimeResumeSignature__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SaveExtension_SELifetimeSavedSignature__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SaveExtension_SELifetimeStartSignature__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/SaveExtension",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x7E56FC5D,
				0x7B907AE9,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_SaveExtension.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_SaveExtension.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_SaveExtension(Z_Construct_UPackage__Script_SaveExtension, TEXT("/Script/SaveExtension"), Z_Registration_Info_UPackage__Script_SaveExtension, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x7E56FC5D, 0x7B907AE9));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
