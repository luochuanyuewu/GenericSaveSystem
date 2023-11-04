// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#include "Misc/GSS_SlotHelpers.h"
#include "Misc/Paths.h"
#include "HAL/PlatformFilemanager.h"


void FGSS_SlotHelpers::FindSlotFileNames(TArray<FString>& FoundSlots)
{
	FFindSlotVisitor Visitor{ FoundSlots };
	FPlatformFileManager::Get().GetPlatformFile().IterateDirectory(*FGSS_FileAdapter::GetSaveFolder(), Visitor);
}

bool FGSS_SlotHelpers::FFindSlotVisitor::Visit(const TCHAR* FilenameOrDirectory, bool bIsDirectory)
{
	if (bIsDirectory)
	{
		return true;
	}

	const FString FullFilePath(FilenameOrDirectory);

	FString Folder;
	FString Filename;
	FString Extension;
	FPaths::Split(FullFilePath, Folder, Filename, Extension);
	if (Extension == TEXT("sav"))
	{
		FoundSlots.Add(Filename);
	}
	return true;
}

