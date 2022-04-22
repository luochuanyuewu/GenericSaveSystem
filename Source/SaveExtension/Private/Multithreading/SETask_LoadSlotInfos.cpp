// Copyright 2015-2020 Piperift. All Rights Reserved.

#include "Multithreading/SETask_LoadSlotInfos.h"

#include "HAL/PlatformFilemanager.h"

#include "SEFileAdapter.h"
#include "SESavePreset.h"
#include "SESaveManager.h"
#include "Misc/SESlotHelpers.h"


void FSETask_LoadSlotInfos::DoWork()
{
	if (!Manager)
	{
		return;
	}

	TArray<FString> FileNames;
	const bool bLoadingSingleInfo = !SlotName.IsNone();
	if(bLoadingSingleInfo)
	{
		FileNames.Add(SlotName.ToString());
	}
	else
	{
		FSESlotHelpers::FindSlotFileNames(FileNames);
	}

	TArray<FSESaveFile> LoadedFiles;
	LoadedFiles.Reserve(FileNames.Num());
	for (const FString& FileName : FileNames)
	{
		// Load all files
		FSEScopedFileReader Reader(FSEFileAdapter::GetSlotPath(FileName));
		if(Reader.IsValid())
		{
			auto& File = LoadedFiles.AddDefaulted_GetRef();
			File.Read(Reader, true);
		}
	}

	// For cache friendlyness, we deserialize infos after loading all the files
	LoadedSlots.Reserve(LoadedFiles.Num());
	for (const auto& File : LoadedFiles)
	{
		LoadedSlots.Add(File.CreateAndDeserializeInfo(Manager));
	}

	if (!bLoadingSingleInfo && bSortByRecent)
	{
		LoadedSlots.Sort([](const USESlotInfo& A, const USESlotInfo& B) {
			return A.SaveDate > B.SaveDate;
		});
	}
}

void FSETask_LoadSlotInfos::AfterFinish()
{
	for(auto& Slot : LoadedSlots)
	{
		Slot->ClearInternalFlags(EInternalObjectFlags::Async);
	}
	Delegate.ExecuteIfBound(LoadedSlots);
}
