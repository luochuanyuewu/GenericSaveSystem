// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#include "Multithreading/GSS_Task_LoadSlotInfos.h"

#include "HAL/PlatformFilemanager.h"

#include "GSS_FileAdapter.h"
#include "GSS_SavePreset.h"
#include "GSS_SaveSubsystem.h"
#include "Misc/GSS_SlotHelpers.h"


void FGSS_Task_LoadSlotInfos::DoWork()
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
		FGSS_SlotHelpers::FindSlotFileNames(FileNames);
	}

	TArray<FGSS_SaveFile> LoadedFiles;
	LoadedFiles.Reserve(FileNames.Num());
	for (const FString& FileName : FileNames)
	{
		// Load all files
		FSEScopedFileReader Reader(FGSS_FileAdapter::GetSlotPath(FileName));
		if(Reader.IsValid())
		{
			auto& File = LoadedFiles.AddDefaulted_GetRef();
			File.Read(Reader, true);
		}
	}

	// For cache friendlyness, we deserialize infos after loading all the files
	// LoadedSlots.Reserve(LoadedFiles.Num());
	LoadedSlots.Empty();
	for (const auto& File : LoadedFiles)
	{
		UGSS_SlotInfo* Info = File.CreateAndDeserializeInfo(Manager);
		if (Info != nullptr)
		{
			LoadedSlots.Add(Info);
		}
	}

	if (!bLoadingSingleInfo && bSortByRecent)
	{
		LoadedSlots.Sort([](const UGSS_SlotInfo& A, const UGSS_SlotInfo& B) {
			return A.SaveDate > B.SaveDate;
		});
	}
}

void FGSS_Task_LoadSlotInfos::AfterFinish()
{
	for(auto& Slot : LoadedSlots)
	{
		if (!IsValid(Slot))
		{
			//以防关闭编辑器崩溃
			continue;
		}
		Slot->ClearInternalFlags(EInternalObjectFlags::Async);
	}
	Delegate.ExecuteIfBound(LoadedSlots);
}
