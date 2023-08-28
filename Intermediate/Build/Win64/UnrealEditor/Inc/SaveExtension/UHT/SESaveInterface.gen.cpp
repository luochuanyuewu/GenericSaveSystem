// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveExtension/Public/SESaveInterface.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSESaveInterface() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESaveInterface();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESaveInterface_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SaveExtension();
// End Cross Module References
	struct SESaveInterface_eventReceiveOnLoadFinished_Parms
	{
		bool bError;
	};
	struct SESaveInterface_eventReceiveOnSaveFinished_Parms
	{
		bool bError;
	};
	void ISESaveInterface::ReceiveOnLoadBegan()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_ReceiveOnLoadBegan instead.");
	}
	void ISESaveInterface::ReceiveOnLoadFinished(bool bError)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_ReceiveOnLoadFinished instead.");
	}
	void ISESaveInterface::ReceiveOnSaveBegan()
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_ReceiveOnSaveBegan instead.");
	}
	void ISESaveInterface::ReceiveOnSaveFinished(bool bError)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_ReceiveOnSaveFinished instead.");
	}
	void USESaveInterface::StaticRegisterNativesUSESaveInterface()
	{
	}
	struct Z_Construct_UFunction_USESaveInterface_ReceiveOnLoadBegan_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveInterface_ReceiveOnLoadBegan_Statics::Function_MetaDataParams[] = {
		{ "Category", "Save" },
		{ "Comment", "// Event called when Load process starts\n" },
		{ "DisplayName", "On Load Began" },
		{ "ModuleRelativePath", "Public/SESaveInterface.h" },
		{ "ToolTip", "Event called when Load process starts" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESaveInterface_ReceiveOnLoadBegan_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESaveInterface, nullptr, "ReceiveOnLoadBegan", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESaveInterface_ReceiveOnLoadBegan_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveInterface_ReceiveOnLoadBegan_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESaveInterface_ReceiveOnLoadBegan()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESaveInterface_ReceiveOnLoadBegan_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USESaveInterface_ReceiveOnLoadFinished_Statics
	{
		static void NewProp_bError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bError;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USESaveInterface_ReceiveOnLoadFinished_Statics::NewProp_bError_SetBit(void* Obj)
	{
		((SESaveInterface_eventReceiveOnLoadFinished_Parms*)Obj)->bError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USESaveInterface_ReceiveOnLoadFinished_Statics::NewProp_bError = { "bError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(SESaveInterface_eventReceiveOnLoadFinished_Parms), &Z_Construct_UFunction_USESaveInterface_ReceiveOnLoadFinished_Statics::NewProp_bError_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESaveInterface_ReceiveOnLoadFinished_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveInterface_ReceiveOnLoadFinished_Statics::NewProp_bError,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveInterface_ReceiveOnLoadFinished_Statics::Function_MetaDataParams[] = {
		{ "Category", "Save" },
		{ "Comment", "// Event called when Load process ends\n" },
		{ "DisplayName", "On Load Finished" },
		{ "ModuleRelativePath", "Public/SESaveInterface.h" },
		{ "ToolTip", "Event called when Load process ends" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESaveInterface_ReceiveOnLoadFinished_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESaveInterface, nullptr, "ReceiveOnLoadFinished", nullptr, nullptr, sizeof(SESaveInterface_eventReceiveOnLoadFinished_Parms), Z_Construct_UFunction_USESaveInterface_ReceiveOnLoadFinished_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveInterface_ReceiveOnLoadFinished_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESaveInterface_ReceiveOnLoadFinished_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveInterface_ReceiveOnLoadFinished_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESaveInterface_ReceiveOnLoadFinished()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESaveInterface_ReceiveOnLoadFinished_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USESaveInterface_ReceiveOnSaveBegan_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveInterface_ReceiveOnSaveBegan_Statics::Function_MetaDataParams[] = {
		{ "Category", "Save" },
		{ "Comment", "/** BP API **/// Event called when Save process starts\n" },
		{ "DisplayName", "On Save Began" },
		{ "ModuleRelativePath", "Public/SESaveInterface.h" },
		{ "ToolTip", "BP API *// Event called when Save process starts" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESaveInterface_ReceiveOnSaveBegan_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESaveInterface, nullptr, "ReceiveOnSaveBegan", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESaveInterface_ReceiveOnSaveBegan_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveInterface_ReceiveOnSaveBegan_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESaveInterface_ReceiveOnSaveBegan()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESaveInterface_ReceiveOnSaveBegan_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USESaveInterface_ReceiveOnSaveFinished_Statics
	{
		static void NewProp_bError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bError;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USESaveInterface_ReceiveOnSaveFinished_Statics::NewProp_bError_SetBit(void* Obj)
	{
		((SESaveInterface_eventReceiveOnSaveFinished_Parms*)Obj)->bError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USESaveInterface_ReceiveOnSaveFinished_Statics::NewProp_bError = { "bError", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(SESaveInterface_eventReceiveOnSaveFinished_Parms), &Z_Construct_UFunction_USESaveInterface_ReceiveOnSaveFinished_Statics::NewProp_bError_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESaveInterface_ReceiveOnSaveFinished_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESaveInterface_ReceiveOnSaveFinished_Statics::NewProp_bError,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESaveInterface_ReceiveOnSaveFinished_Statics::Function_MetaDataParams[] = {
		{ "Category", "Save" },
		{ "Comment", "// Event called when Save process ends\n" },
		{ "DisplayName", "On Save Finished" },
		{ "ModuleRelativePath", "Public/SESaveInterface.h" },
		{ "ToolTip", "Event called when Save process ends" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESaveInterface_ReceiveOnSaveFinished_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESaveInterface, nullptr, "ReceiveOnSaveFinished", nullptr, nullptr, sizeof(SESaveInterface_eventReceiveOnSaveFinished_Parms), Z_Construct_UFunction_USESaveInterface_ReceiveOnSaveFinished_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveInterface_ReceiveOnSaveFinished_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESaveInterface_ReceiveOnSaveFinished_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESaveInterface_ReceiveOnSaveFinished_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESaveInterface_ReceiveOnSaveFinished()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESaveInterface_ReceiveOnSaveFinished_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USESaveInterface);
	UClass* Z_Construct_UClass_USESaveInterface_NoRegister()
	{
		return USESaveInterface::StaticClass();
	}
	struct Z_Construct_UClass_USESaveInterface_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USESaveInterface_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_SaveExtension,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USESaveInterface_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USESaveInterface_ReceiveOnLoadBegan, "ReceiveOnLoadBegan" }, // 1309762718
		{ &Z_Construct_UFunction_USESaveInterface_ReceiveOnLoadFinished, "ReceiveOnLoadFinished" }, // 1907853425
		{ &Z_Construct_UFunction_USESaveInterface_ReceiveOnSaveBegan, "ReceiveOnSaveBegan" }, // 2017996029
		{ &Z_Construct_UFunction_USESaveInterface_ReceiveOnSaveFinished, "ReceiveOnSaveFinished" }, // 2212054841
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESaveInterface_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Category", "SaveExtension" },
		{ "ModuleRelativePath", "Public/SESaveInterface.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USESaveInterface_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ISESaveInterface>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USESaveInterface_Statics::ClassParams = {
		&USESaveInterface::StaticClass,
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
		0x001040A1u,
		METADATA_PARAMS(Z_Construct_UClass_USESaveInterface_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USESaveInterface_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USESaveInterface()
	{
		if (!Z_Registration_Info_UClass_USESaveInterface.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USESaveInterface.OuterSingleton, Z_Construct_UClass_USESaveInterface_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USESaveInterface.OuterSingleton;
	}
	template<> SAVEEXTENSION_API UClass* StaticClass<USESaveInterface>()
	{
		return USESaveInterface::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USESaveInterface);
	USESaveInterface::~USESaveInterface() {}
	static FName NAME_USESaveInterface_ReceiveOnLoadBegan = FName(TEXT("ReceiveOnLoadBegan"));
	void ISESaveInterface::Execute_ReceiveOnLoadBegan(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(USESaveInterface::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_USESaveInterface_ReceiveOnLoadBegan);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
	}
	static FName NAME_USESaveInterface_ReceiveOnLoadFinished = FName(TEXT("ReceiveOnLoadFinished"));
	void ISESaveInterface::Execute_ReceiveOnLoadFinished(UObject* O, bool bError)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(USESaveInterface::StaticClass()));
		SESaveInterface_eventReceiveOnLoadFinished_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_USESaveInterface_ReceiveOnLoadFinished);
		if (Func)
		{
			Parms.bError=bError;
			O->ProcessEvent(Func, &Parms);
		}
	}
	static FName NAME_USESaveInterface_ReceiveOnSaveBegan = FName(TEXT("ReceiveOnSaveBegan"));
	void ISESaveInterface::Execute_ReceiveOnSaveBegan(UObject* O)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(USESaveInterface::StaticClass()));
		UFunction* const Func = O->FindFunction(NAME_USESaveInterface_ReceiveOnSaveBegan);
		if (Func)
		{
			O->ProcessEvent(Func, NULL);
		}
	}
	static FName NAME_USESaveInterface_ReceiveOnSaveFinished = FName(TEXT("ReceiveOnSaveFinished"));
	void ISESaveInterface::Execute_ReceiveOnSaveFinished(UObject* O, bool bError)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(USESaveInterface::StaticClass()));
		SESaveInterface_eventReceiveOnSaveFinished_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_USESaveInterface_ReceiveOnSaveFinished);
		if (Func)
		{
			Parms.bError=bError;
			O->ProcessEvent(Func, &Parms);
		}
	}
	struct Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USESaveInterface, USESaveInterface::StaticClass, TEXT("USESaveInterface"), &Z_Registration_Info_UClass_USESaveInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USESaveInterface), 1395536236U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_781894300(TEXT("/Script/SaveExtension"),
		Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESaveInterface_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
