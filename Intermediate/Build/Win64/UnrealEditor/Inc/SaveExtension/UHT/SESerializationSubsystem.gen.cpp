// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SaveExtension/Public/SESerializationSubsystem.h"
#include "Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSESerializationSubsystem() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESerializationSubsystem();
	SAVEEXTENSION_API UClass* Z_Construct_UClass_USESerializationSubsystem_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SaveExtension();
// End Cross Module References
	DEFINE_FUNCTION(USESerializationSubsystem::execStringFromBytes)
	{
		P_GET_TARRAY_REF(uint8,Z_Param_Out_Bytes);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->StringFromBytes(Z_Param_Out_Bytes);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USESerializationSubsystem::execBytesFromString)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_String);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<uint8>*)Z_Param__Result=P_THIS->BytesFromString(Z_Param_String);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USESerializationSubsystem::execSerializeFromBinary)
	{
		P_GET_OBJECT(UObject,Z_Param_Object);
		P_GET_TARRAY_REF(uint8,Z_Param_Out_InData);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SerializeFromBinary(Z_Param_Object,Z_Param_Out_InData);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USESerializationSubsystem::execSerializeToBinary)
	{
		P_GET_OBJECT(UObject,Z_Param_Object);
		P_GET_TARRAY_REF(uint8,Z_Param_Out_OutData);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SerializeToBinary(Z_Param_Object,Z_Param_Out_OutData);
		P_NATIVE_END;
	}
	void USESerializationSubsystem::StaticRegisterNativesUSESerializationSubsystem()
	{
		UClass* Class = USESerializationSubsystem::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BytesFromString", &USESerializationSubsystem::execBytesFromString },
			{ "SerializeFromBinary", &USESerializationSubsystem::execSerializeFromBinary },
			{ "SerializeToBinary", &USESerializationSubsystem::execSerializeToBinary },
			{ "StringFromBytes", &USESerializationSubsystem::execStringFromBytes },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USESerializationSubsystem_BytesFromString_Statics
	{
		struct SESerializationSubsystem_eventBytesFromString_Parms
		{
			FString String;
			TArray<uint8> ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_String_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_String;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESerializationSubsystem_BytesFromString_Statics::NewProp_String_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USESerializationSubsystem_BytesFromString_Statics::NewProp_String = { "String", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESerializationSubsystem_eventBytesFromString_Parms, String), METADATA_PARAMS(Z_Construct_UFunction_USESerializationSubsystem_BytesFromString_Statics::NewProp_String_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USESerializationSubsystem_BytesFromString_Statics::NewProp_String_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USESerializationSubsystem_BytesFromString_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USESerializationSubsystem_BytesFromString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESerializationSubsystem_eventBytesFromString_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESerializationSubsystem_BytesFromString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESerializationSubsystem_BytesFromString_Statics::NewProp_String,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESerializationSubsystem_BytesFromString_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESerializationSubsystem_BytesFromString_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESerializationSubsystem_BytesFromString_Statics::Function_MetaDataParams[] = {
		{ "Category", "Serialization" },
		{ "ModuleRelativePath", "Public/SESerializationSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESerializationSubsystem_BytesFromString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESerializationSubsystem, nullptr, "BytesFromString", nullptr, nullptr, sizeof(Z_Construct_UFunction_USESerializationSubsystem_BytesFromString_Statics::SESerializationSubsystem_eventBytesFromString_Parms), Z_Construct_UFunction_USESerializationSubsystem_BytesFromString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESerializationSubsystem_BytesFromString_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESerializationSubsystem_BytesFromString_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESerializationSubsystem_BytesFromString_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESerializationSubsystem_BytesFromString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESerializationSubsystem_BytesFromString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USESerializationSubsystem_SerializeFromBinary_Statics
	{
		struct SESerializationSubsystem_eventSerializeFromBinary_Parms
		{
			UObject* Object;
			TArray<uint8> InData;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Object;
		static const UECodeGen_Private::FBytePropertyParams NewProp_InData_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InData_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_InData;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USESerializationSubsystem_SerializeFromBinary_Statics::NewProp_Object = { "Object", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESerializationSubsystem_eventSerializeFromBinary_Parms, Object), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USESerializationSubsystem_SerializeFromBinary_Statics::NewProp_InData_Inner = { "InData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESerializationSubsystem_SerializeFromBinary_Statics::NewProp_InData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USESerializationSubsystem_SerializeFromBinary_Statics::NewProp_InData = { "InData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESerializationSubsystem_eventSerializeFromBinary_Parms, InData), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_USESerializationSubsystem_SerializeFromBinary_Statics::NewProp_InData_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USESerializationSubsystem_SerializeFromBinary_Statics::NewProp_InData_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESerializationSubsystem_SerializeFromBinary_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESerializationSubsystem_SerializeFromBinary_Statics::NewProp_Object,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESerializationSubsystem_SerializeFromBinary_Statics::NewProp_InData_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESerializationSubsystem_SerializeFromBinary_Statics::NewProp_InData,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESerializationSubsystem_SerializeFromBinary_Statics::Function_MetaDataParams[] = {
		{ "Category", "Serialization" },
		{ "ModuleRelativePath", "Public/SESerializationSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESerializationSubsystem_SerializeFromBinary_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESerializationSubsystem, nullptr, "SerializeFromBinary", nullptr, nullptr, sizeof(Z_Construct_UFunction_USESerializationSubsystem_SerializeFromBinary_Statics::SESerializationSubsystem_eventSerializeFromBinary_Parms), Z_Construct_UFunction_USESerializationSubsystem_SerializeFromBinary_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESerializationSubsystem_SerializeFromBinary_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESerializationSubsystem_SerializeFromBinary_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESerializationSubsystem_SerializeFromBinary_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESerializationSubsystem_SerializeFromBinary()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESerializationSubsystem_SerializeFromBinary_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USESerializationSubsystem_SerializeToBinary_Statics
	{
		struct SESerializationSubsystem_eventSerializeToBinary_Parms
		{
			UObject* Object;
			TArray<uint8> OutData;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Object;
		static const UECodeGen_Private::FBytePropertyParams NewProp_OutData_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_OutData;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USESerializationSubsystem_SerializeToBinary_Statics::NewProp_Object = { "Object", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESerializationSubsystem_eventSerializeToBinary_Parms, Object), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USESerializationSubsystem_SerializeToBinary_Statics::NewProp_OutData_Inner = { "OutData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USESerializationSubsystem_SerializeToBinary_Statics::NewProp_OutData = { "OutData", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESerializationSubsystem_eventSerializeToBinary_Parms, OutData), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESerializationSubsystem_SerializeToBinary_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESerializationSubsystem_SerializeToBinary_Statics::NewProp_Object,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESerializationSubsystem_SerializeToBinary_Statics::NewProp_OutData_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESerializationSubsystem_SerializeToBinary_Statics::NewProp_OutData,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESerializationSubsystem_SerializeToBinary_Statics::Function_MetaDataParams[] = {
		{ "Category", "Serialization" },
		{ "ModuleRelativePath", "Public/SESerializationSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESerializationSubsystem_SerializeToBinary_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESerializationSubsystem, nullptr, "SerializeToBinary", nullptr, nullptr, sizeof(Z_Construct_UFunction_USESerializationSubsystem_SerializeToBinary_Statics::SESerializationSubsystem_eventSerializeToBinary_Parms), Z_Construct_UFunction_USESerializationSubsystem_SerializeToBinary_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESerializationSubsystem_SerializeToBinary_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESerializationSubsystem_SerializeToBinary_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESerializationSubsystem_SerializeToBinary_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESerializationSubsystem_SerializeToBinary()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESerializationSubsystem_SerializeToBinary_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USESerializationSubsystem_StringFromBytes_Statics
	{
		struct SESerializationSubsystem_eventStringFromBytes_Parms
		{
			TArray<uint8> Bytes;
			FString ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_Bytes_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Bytes_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Bytes;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USESerializationSubsystem_StringFromBytes_Statics::NewProp_Bytes_Inner = { "Bytes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESerializationSubsystem_StringFromBytes_Statics::NewProp_Bytes_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USESerializationSubsystem_StringFromBytes_Statics::NewProp_Bytes = { "Bytes", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESerializationSubsystem_eventStringFromBytes_Parms, Bytes), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_USESerializationSubsystem_StringFromBytes_Statics::NewProp_Bytes_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USESerializationSubsystem_StringFromBytes_Statics::NewProp_Bytes_MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USESerializationSubsystem_StringFromBytes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SESerializationSubsystem_eventStringFromBytes_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USESerializationSubsystem_StringFromBytes_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESerializationSubsystem_StringFromBytes_Statics::NewProp_Bytes_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESerializationSubsystem_StringFromBytes_Statics::NewProp_Bytes,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USESerializationSubsystem_StringFromBytes_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USESerializationSubsystem_StringFromBytes_Statics::Function_MetaDataParams[] = {
		{ "Category", "Serialization" },
		{ "ModuleRelativePath", "Public/SESerializationSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USESerializationSubsystem_StringFromBytes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USESerializationSubsystem, nullptr, "StringFromBytes", nullptr, nullptr, sizeof(Z_Construct_UFunction_USESerializationSubsystem_StringFromBytes_Statics::SESerializationSubsystem_eventStringFromBytes_Parms), Z_Construct_UFunction_USESerializationSubsystem_StringFromBytes_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USESerializationSubsystem_StringFromBytes_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USESerializationSubsystem_StringFromBytes_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USESerializationSubsystem_StringFromBytes_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USESerializationSubsystem_StringFromBytes()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USESerializationSubsystem_StringFromBytes_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USESerializationSubsystem);
	UClass* Z_Construct_UClass_USESerializationSubsystem_NoRegister()
	{
		return USESerializationSubsystem::StaticClass();
	}
	struct Z_Construct_UClass_USESerializationSubsystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USESerializationSubsystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_SaveExtension,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USESerializationSubsystem_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USESerializationSubsystem_BytesFromString, "BytesFromString" }, // 3033038621
		{ &Z_Construct_UFunction_USESerializationSubsystem_SerializeFromBinary, "SerializeFromBinary" }, // 2021440699
		{ &Z_Construct_UFunction_USESerializationSubsystem_SerializeToBinary, "SerializeToBinary" }, // 3070518022
		{ &Z_Construct_UFunction_USESerializationSubsystem_StringFromBytes, "StringFromBytes" }, // 3500428805
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USESerializationSubsystem_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "SESerializationSubsystem.h" },
		{ "ModuleRelativePath", "Public/SESerializationSubsystem.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USESerializationSubsystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USESerializationSubsystem>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USESerializationSubsystem_Statics::ClassParams = {
		&USESerializationSubsystem::StaticClass,
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
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USESerializationSubsystem_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USESerializationSubsystem_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USESerializationSubsystem()
	{
		if (!Z_Registration_Info_UClass_USESerializationSubsystem.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USESerializationSubsystem.OuterSingleton, Z_Construct_UClass_USESerializationSubsystem_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USESerializationSubsystem.OuterSingleton;
	}
	template<> SAVEEXTENSION_API UClass* StaticClass<USESerializationSubsystem>()
	{
		return USESerializationSubsystem::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USESerializationSubsystem);
	USESerializationSubsystem::~USESerializationSubsystem() {}
	struct Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESerializationSubsystem_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESerializationSubsystem_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USESerializationSubsystem, USESerializationSubsystem::StaticClass, TEXT("USESerializationSubsystem"), &Z_Registration_Info_UClass_USESerializationSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USESerializationSubsystem), 41744964U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESerializationSubsystem_h_1974916000(TEXT("/Script/SaveExtension"),
		Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESerializationSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEGame_Plugins_Custom_SaveExtension_Source_SaveExtension_Public_SESerializationSubsystem_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
