// Copyright 2015-2020 Piperift. All Rights Reserved.

#include "Multithreading/SETask_DeleteSlots.h"

#include "HAL/PlatformFilemanager.h"

#include "SEFileAdapter.h"
#include "SESavePreset.h"
#include "SESaveManager.h"
#include "Misc/SESlotHelpers.h"
#include "HAL/FileManager.h"


FSETask_DeleteSlots::FSETask_DeleteSlots(const USESaveManager* InManager, FName SlotName)
	: Manager(InManager)
{
	check(Manager);
	if(!SlotName.IsNone())
	{
		SpecificSlotName = SlotName.ToString();
	}
}

void FSETask_DeleteSlots::DoWork()
{
	if (!SpecificSlotName.IsEmpty())
	{
		// Delete a single slot by id
		const FString ScreenshotPath = FSEFileAdapter::GetThumbnailPath(SpecificSlotName);
		bool bIsDeleteSlotSuccess = FSEFileAdapter::DeleteFile(SpecificSlotName);
		bool bIsDeleteScreenshotSuccess = IFileManager::Get().Delete(*ScreenshotPath, true);
		bSuccess = bIsDeleteSlotSuccess || bIsDeleteScreenshotSuccess;
	}
	else
	{
		TArray<FString> FoundSlots;
		FSESlotHelpers::FindSlotFileNames(FoundSlots);

		for (const FString& File : FoundSlots)
		{
			FSEFileAdapter::DeleteFile(File);
		}
		bSuccess = true;
	}
}
