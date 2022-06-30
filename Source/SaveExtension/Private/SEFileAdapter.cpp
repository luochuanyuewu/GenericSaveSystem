// Copyright 2015-2020 Piperift. All Rights Reserved.

#include "SEFileAdapter.h"

#include "UObject/UObjectGlobals.h"
#include "UObject/Package.h"
#include "Serialization/MemoryReader.h"
#include "Serialization/MemoryWriter.h"
#include "Serialization/ArchiveSaveCompressedProxy.h"
#include "Serialization/ArchiveLoadCompressedProxy.h"
#include "SaveGameSystem.h"

#include "SESavePreset.h"
#include "SESlotInfo.h"
#include "SESlotData.h"
#include "Multithreading/SETask_SaveFile.h"
#include "Serialization/ObjectAndNameAsStringProxyArchive.h"


static const int SE_SAVEGAME_FILE_TYPE_TAG = 0x0001;		// "sAvG"

struct FSaveGameFileVersion
{
	enum Type
	{
		InitialVersion = 1,
		// serializing custom versions into the savegame data to handle that type of versioning
		AddedCustomVersions = 2,

		// -----<new versions can be added above this line>-------------------------------------------------
		VersionPlusOne,
		LatestVersion = VersionPlusOne - 1
	};
};

FSEScopedFileWriter::FSEScopedFileWriter(FStringView Filename, int32 Flags)
{
	if (!Filename.IsEmpty())
	{
		Writer = IFileManager::Get().CreateFileWriter(Filename.GetData(), Flags);
	}
}

FSEScopedFileReader::FSEScopedFileReader(FStringView Filename, int32 Flags)
	: ScopedLoadingState(Filename.GetData())
{
	if (!Filename.IsEmpty())
	{
		Reader = IFileManager::Get().CreateFileReader(Filename.GetData(), Flags);
		if (!Reader && !(Flags & FILEREAD_Silent))
		{
			UE_LOG(LogSaveExtension, Warning, TEXT("Failed to read file '%s' error."), Filename.GetData());
		}
	}
}

/*********************
 * FSaveFile
 */

FSESaveFile::FSESaveFile()
	: FileTypeTag(SE_SAVEGAME_FILE_TYPE_TAG)
	, SaveGameFileVersion(FSaveGameFileVersion::LatestVersion)
	, PackageFileUE4Version(GPackageFileUE4Version)
	, SavedEngineVersion(FEngineVersion::Current())
	, CustomVersionFormat(static_cast<int32>(ECustomVersionSerializationFormat::Latest))
	, CustomVersions(FCurrentCustomVersions::GetAll())
{}

void FSESaveFile::Empty()
{
	*this = {};
}

bool FSESaveFile::IsEmpty() const
{
	return FileTypeTag == 0;
}

void FSESaveFile::Read(FSEScopedFileReader& Reader, bool bSkipData)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(FSaveFile::Read);

	Empty();
	FArchive& Ar = Reader.GetArchive();

	{ // Header information
		Ar << FileTypeTag;
		if (FileTypeTag != SE_SAVEGAME_FILE_TYPE_TAG)
		{
			// this is an old saved game, back up the file pointer to the beginning and assume version 1
			Ar.Seek(0);
			SaveGameFileVersion = FSaveGameFileVersion::InitialVersion;
			return;
		}

		// Read version for this file format
		Ar << SaveGameFileVersion;
		// Read engine and UE4 version information
		Ar << PackageFileUE4Version;
		Ar << SavedEngineVersion;
		Ar.SetUE4Ver(PackageFileUE4Version);
		Ar.SetEngineVer(SavedEngineVersion);

		if (SaveGameFileVersion >= FSaveGameFileVersion::AddedCustomVersions)
		{
			Ar << CustomVersionFormat;
			CustomVersions.Serialize(Ar, static_cast<ECustomVersionSerializationFormat::Type>(CustomVersionFormat));
			Ar.SetCustomVersions(CustomVersions);
		}
	}

	Ar << InfoClassName;
	Ar << InfoBytes;

	Ar << DataClassName;
	if(bSkipData || DataClassName.IsEmpty())
	{
		return;
	}

	Ar << bIsDataCompressed;
	if(bIsDataCompressed)
	{
		TArray<uint8> CompressedDataBytes;
		Ar << CompressedDataBytes;

		TRACE_CPUPROFILER_EVENT_SCOPE(Decompression);
		FArchiveLoadCompressedProxy Decompressor(CompressedDataBytes, NAME_Zlib);
		if (!Decompressor.GetError())
		{
			Decompressor << DataBytes;
			Decompressor.Close();
		}
		else
		{
			UE_LOG(LogSaveExtension, Warning, TEXT("Failed to decompress data"));
		}
	}
	else
	{
		Ar << DataBytes;
	}
}

void FSESaveFile::Write(FSEScopedFileWriter& Writer, bool bCompressData)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(FSaveFile::Write);

	bIsDataCompressed = bCompressData;
	FArchive& Ar = Writer.GetArchive();

	{ // Header information
		Ar << FileTypeTag;
		Ar << SaveGameFileVersion;
		Ar << PackageFileUE4Version;
		Ar << SavedEngineVersion;
		Ar << CustomVersionFormat;
		CustomVersions.Serialize(Ar, static_cast<ECustomVersionSerializationFormat::Type>(CustomVersionFormat));
	}

	Ar << InfoClassName;
	Ar << InfoBytes;

	Ar << DataClassName;
	if(!DataClassName.IsEmpty())
	{
		Ar << bIsDataCompressed;
		if(bIsDataCompressed)
		{
			TArray<uint8> CompressedDataBytes;
			{ // Compression
				TRACE_CPUPROFILER_EVENT_SCOPE(Compression);
				// Compress Object data
				FArchiveSaveCompressedProxy Compressor(CompressedDataBytes, NAME_Zlib);
				Compressor << DataBytes;
				Compressor.Close();
			}
			Ar << CompressedDataBytes;
		}
		else
		{
			Ar << DataBytes;
		}
	}
	Ar.Close();
}

void FSESaveFile::SerializeInfo(USESlotInfo* SlotInfo)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(FSaveFile::SerializeInfo);
	check(SlotInfo);
	InfoBytes.Reset();
	InfoClassName = SlotInfo->GetClass()->GetPathName();

	FMemoryWriter BytesWriter(InfoBytes);
	FObjectAndNameAsStringProxyArchive Ar(BytesWriter, false);
	SlotInfo->Serialize(Ar);
}
void FSESaveFile::SerializeData(USESlotData* SlotData)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(FSaveFile::SerializeData);
	check(SlotData);
	DataBytes.Reset();
	DataClassName = SlotData->GetClass()->GetPathName();

	FMemoryWriter BytesWriter(DataBytes);
	FObjectAndNameAsStringProxyArchive Ar(BytesWriter, false);
	SlotData->Serialize(Ar);
}

USESlotInfo* FSESaveFile::CreateAndDeserializeInfo(const UObject* Outer) const
{
	TRACE_CPUPROFILER_EVENT_SCOPE(FSaveFile::CreateAndDeserializeInfo);
	UObject* Object = nullptr;
	FSEFileAdapter::DeserializeObject(Object, InfoClassName, Outer, InfoBytes);
	return Cast<USESlotInfo>(Object);
}

USESlotData* FSESaveFile::CreateAndDeserializeData(const UObject* Outer) const
{
	TRACE_CPUPROFILER_EVENT_SCOPE(FSaveFile::CreateAndDeserializeData);
	UObject* Object = nullptr;
	FSEFileAdapter::DeserializeObject(Object, DataClassName, Outer, DataBytes);
	return Cast<USESlotData>(Object);
}

bool FSEFileAdapter::SaveFile(FStringView SlotName, USESlotInfo* Info, USESlotData* Data, const bool bUseCompression)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(FFileAdapter::SaveFile);

	if (SlotName.IsEmpty())
	{
		return false;
	}

	if (!ensureMsgf(Info, TEXT("Info object must be valid")) ||
		!ensureMsgf(Data, TEXT("Data object must be valid")))
	{
		return false;
	}

	FSEScopedFileWriter FileWriter(GetSlotPath(SlotName));
	if(FileWriter.IsValid())
	{
		FSESaveFile File{};
		File.SerializeInfo(Info);
		File.SerializeData(Data);
		File.Write(FileWriter, bUseCompression);
		return !FileWriter.IsError();
	}
	return false;
}

bool FSEFileAdapter::LoadFile(FStringView SlotName, USESlotInfo*& Info, USESlotData*& Data, bool bLoadData, const UObject* Outer)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(FFileAdapter::LoadFile);

	FSEScopedFileReader Reader(GetSlotPath(SlotName));
	if(Reader.IsValid())
	{
		FSESaveFile File{};
		File.Read(Reader, !bLoadData);
		Info = File.CreateAndDeserializeInfo(Outer);
		Data = File.CreateAndDeserializeData(Outer);
		return true;
	}
	return false;
}

bool FSEFileAdapter::DeleteFile(FStringView SlotName)
{
	return IFileManager::Get().Delete(*GetSlotPath(SlotName), true, false, true);
}

bool FSEFileAdapter::DoesFileExist(FStringView SlotName)
{
	return IFileManager::Get().FileSize(*GetSlotPath(SlotName)) >= 0;
}

const FString& FSEFileAdapter::GetSaveFolder()
{
	static const FString Folder = FString::Printf(TEXT("%sSaveGames/"), *FPaths::ProjectSavedDir());
	return Folder;
}

FString FSEFileAdapter::GetSlotPath(FStringView SlotName)
{
	return GetSaveFolder() / FString::Printf(TEXT("%s.sav"), SlotName.GetData());
}

FString FSEFileAdapter::GetThumbnailPath(FStringView SlotName)
{
	return GetSaveFolder() / FString::Printf(TEXT("%s.png"), SlotName.GetData());
}

void FSEFileAdapter::DeserializeObject(UObject*& Object, FStringView ClassName, const UObject* Outer, const TArray<uint8>& Bytes)
{
	if (ClassName.IsEmpty() || Bytes.Num() <= 0)
	{
		return;
	}

	UClass* ObjectClass = FindObject<UClass>(ANY_PACKAGE, ClassName.GetData());
	if (!ObjectClass)
	{
		ObjectClass = LoadObject<UClass>(nullptr, ClassName.GetData());
	}
	if (!ObjectClass)
	{
		return;
	}

	if(!Object)
	{
		if(!Outer)
		{
			Outer = GetTransientPackage();
		}

		Object = NewObject<UObject>(const_cast<UObject*>(Outer), ObjectClass);
	}
	// Can only reuse object if class matches
	else if(Object->GetClass() != ObjectClass)
	{
		return;
	}

	if(Object)
	{
		FMemoryReader Reader{ Bytes };
		FObjectAndNameAsStringProxyArchive Ar(Reader, true);
		Ar.bLoadIfFindFails = false;
		Object->Serialize(Ar);
	}
}
