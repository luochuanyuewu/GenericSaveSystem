// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#include "Multithreading/GSS_Task_DeleteSlots.h"

#include "HAL/PlatformFilemanager.h"

#include "GSS_FileAdapter.h"
#include "GSS_SavePreset.h"
#include "GSS_SaveSubsystem.h"
#include "Misc/GSS_SlotHelpers.h"
#include "HAL/FileManager.h"


FGSS_Task_DeleteSlots::FGSS_Task_DeleteSlots(const UGSS_SaveSubsystem* InManager, FName SlotName)
	: Manager(InManager)
{
	check(Manager);
	if(!SlotName.IsNone())
	{
		SpecificSlotName = SlotName.ToString();
	}
}

void FGSS_Task_DeleteSlots::DoWork()
{
	if (!SpecificSlotName.IsEmpty())
	{
		// Delete a single slot by id
		const FString ScreenshotPath = FGSS_FileAdapter::GetThumbnailPath(SpecificSlotName);
		bool bIsDeleteSlotSuccess = FGSS_FileAdapter::DeleteFile(SpecificSlotName);
		bool bIsDeleteScreenshotSuccess = IFileManager::Get().Delete(*ScreenshotPath, true);
		bSuccess = bIsDeleteSlotSuccess || bIsDeleteScreenshotSuccess;
	}
	else
	{
		TArray<FString> FoundSlots;
		FGSS_SlotHelpers::FindSlotFileNames(FoundSlots);

		for (const FString& File : FoundSlots)
		{
			FGSS_FileAdapter::DeleteFile(File);
		}
		bSuccess = true;
	}
}
