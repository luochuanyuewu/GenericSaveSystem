// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/EngineVersion.h"
#include "Serialization/CustomVersion.h"
#include "IGenericSaveSystem.h"


class UGSS_SavePreset;
class UGSS_SlotInfo;
class UGSS_SlotData;
class FMemoryReader;
class FMemoryWriter;


struct FGSS_ScopedFileWriter
{
private:
	FArchive* Writer = nullptr;

public:
	FGSS_ScopedFileWriter(FStringView Filename, int32 Flags = 0);
	~FGSS_ScopedFileWriter()
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
struct FGSS_SaveFile
{
	int32 FileTypeTag = 0;
	int32 SaveGameFileVersion = 0;
	FPackageFileVersion PackageFileUEVersion {};
	
	FEngineVersion SavedEngineVersion;
	int32 CustomVersionFormat = int32(ECustomVersionSerializationFormat::Unknown);
	FCustomVersionContainer CustomVersions;

	FString InfoClassName;
	TArray<uint8> InfoBytes;

	FString DataClassName;
	bool bIsDataCompressed = false;
	TArray<uint8> DataBytes;


	FGSS_SaveFile();

	void Empty();
	bool IsEmpty() const;

	void Read(FSEScopedFileReader& Reader, bool bSkipData);
	void Write(FGSS_ScopedFileWriter& Writer, bool bCompressData);

	void SerializeInfo(UGSS_SlotInfo* SlotInfo);
	void SerializeData(UGSS_SlotData* SlotData);
	UGSS_SlotInfo* CreateAndDeserializeInfo(const UObject* Outer) const;
	UGSS_SlotData* CreateAndDeserializeData(const UObject* Outer) const;
};


/** Based on GameplayStatics to add multi-threading */
class GENERICSAVESYSTEM_API FGSS_FileAdapter
{
public:

	static bool SaveFile(FStringView SlotName, UGSS_SlotInfo* Info, UGSS_SlotData* Data, const bool bUseCompression);

	// Not safe for Multi-threading
	static bool LoadFile(FStringView SlotName, UGSS_SlotInfo*& Info, UGSS_SlotData*& Data, bool bLoadData, const UObject* Outer);

	static bool DeleteFile(FStringView SlotName);
	static bool DoesFileExist(FStringView SlotName);

	static const FString& GetSaveFolder();
	static FString GetSlotPath(FStringView SlotName);
	static FString GetThumbnailPath(FStringView SlotName);

	static void DeserializeObject(UObject*& Object, FStringView ClassName, const UObject* Outer, const TArray<uint8>& Bytes);
};
