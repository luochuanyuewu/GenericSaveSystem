// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GSS_FileAdapter.h"


struct FGSS_SlotHelpers
{
	static void FindSlotFileNames(TArray<FString>& FoundSlots);

	/** Used to find next available slot id */
	class FFindSlotVisitor : public IPlatformFile::FDirectoryVisitor
	{
	public:
		TArray<FString>& FoundSlots;

		FFindSlotVisitor(TArray<FString>& FoundSlots)
			: FoundSlots(FoundSlots)
		{}

		virtual bool Visit(const TCHAR* FilenameOrDirectory, bool bIsDirectory) override;
	};

	static FString GetWorldName(const UWorld* World)
	{
		check(World);
		const FString MapName = World->GetOutermost()->GetName();
		if (World->IsPlayInEditor())
		{
			return UWorld::RemovePIEPrefix(MapName);
		}
		return MapName;
	}
};
