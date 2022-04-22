// Copyright 2015-2020 Piperift. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Containers/StringView.h"
#include "GameFramework/SaveGame.h"
#include "Misc/EngineVersion.h"
#include "Templates/SubclassOf.h"
#include "Serialization/CustomVersion.h"
#include "Serialization/ObjectAndNameAsStringProxyArchive.h"
#include "PlatformFeatures.h"

#include "ISaveExtension.h"


class USESavePreset;
class USESlotInfo;
class USESlotData;
class FMemoryReader;
class FMemoryWriter;


struct FSEScopedFileWriter
{
private:
	FArchive* Writer = nullptr;

public:
	FSEScopedFileWriter(FStringView Filename, int32 Flags = 0);
	~FSEScopedFileWriter()
	{
		delete Writer;
	}

	FArchive& GetArchive() { return *Writer; }
	bool IsValid() const { return Writer != nullptr; }
	bool IsError() const { return Writer && (Writer->IsError() || Writer->IsCriticalError()); }
};


struct FSEScopedFileReader
{
private:
	FScopedLoadingState ScopedLoadingState;
	FArchive* Reader = nullptr;

public:
	FSEScopedFileReader(FStringView Filename, int32 Flags = 0);
	~FSEScopedFileReader()
	{
		delete Reader;
	}

	FArchive& GetArchive() { return *Reader; }
	bool IsValid() const { return Reader != nullptr; }
};


/** Based on GameplayStatics to add multi-threading */
struct FSESaveFile
{
	int32 FileTypeTag = 0;
	int32 SaveGameFileVersion = 0;
	int32 PackageFileUE4Version = 0;
	
	FEngineVersion SavedEngineVersion;
	int32 CustomVersionFormat = int32(ECustomVersionSerializationFormat::Unknown);
	FCustomVersionContainer CustomVersions;

	FString InfoClassName;
	TArray<uint8> InfoBytes;

	FString DataClassName;
	bool bIsDataCompressed = false;
	TArray<uint8> DataBytes;


	FSESaveFile();

	void Empty();
	bool IsEmpty() const;

	void Read(FSEScopedFileReader& Reader, bool bSkipData);
	void Write(FSEScopedFileWriter& Writer, bool bCompressData);

	void SerializeInfo(USESlotInfo* SlotInfo);
	void SerializeData(USESlotData* SlotData);
	USESlotInfo* CreateAndDeserializeInfo(const UObject* Outer) const;
	USESlotData* CreateAndDeserializeData(const UObject* Outer) const;
};


/** Based on GameplayStatics to add multi-threading */
class SAVEEXTENSION_API FSEFileAdapter
{
public:

	static bool SaveFile(FStringView SlotName, USESlotInfo* Info, USESlotData* Data, const bool bUseCompression);

	// Not safe for Multi-threading
	static bool LoadFile(FStringView SlotName, USESlotInfo*& Info, USESlotData*& Data, bool bLoadData, const UObject* Outer);

	static bool DeleteFile(FStringView SlotName);
	static bool DoesFileExist(FStringView SlotName);

	static const FString& GetSaveFolder();
	static FString GetSlotPath(FStringView SlotName);
	static FString GetThumbnailPath(FStringView SlotName);

	static void DeserializeObject(UObject*& Object, FStringView ClassName, const UObject* Outer, const TArray<uint8>& Bytes);
};
