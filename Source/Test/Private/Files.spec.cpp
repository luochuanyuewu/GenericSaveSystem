// Copyright 2015-2020 Piperift. All Rights Reserved.

#include "Automatron.h"
#include "Helpers/TestActor.h"
#include "SESaveManager.h"
#include "SEFileAdapter.h"


class FSaveSpec_Files : public Automatron::FTestSpec
{
	GENERATE_SPEC(FSaveSpec_Files, "SaveExtension.Files",
		EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter);

	USESaveManager* SaveManager = nullptr;
	ATestActor* TestActor = nullptr;
	USESavePreset* TestPreset = nullptr;

	// Helper for some test delegates
	bool bFinishTick = false;

	FSaveSpec_Files() : Automatron::FTestSpec()
	{
		bReuseWorldForAllTests = false;
		bCanUsePIEWorld = false;
	}
};


void FSaveSpec_Files::Define()
{
	BeforeEach([this]() {
		SaveManager = USESaveManager::Get(GetMainWorld());
		TestNotNull(TEXT("SaveManager"), SaveManager);

		SaveManager->bTickWithGameWorld = true;

		// Set test preset
		TestPreset = SaveManager->SetActivePreset(USESavePreset::StaticClass());
		TestPreset->MultithreadedSerialization = ESaveASyncMode::OnlySync;
	});

	It("Can save files synchronously", [this]() {
		TestPreset->MultithreadedFiles = ESaveASyncMode::OnlySync;

		TestTrue("Saved", SaveManager->SaveSlot(0));

		TestTrue("Info File exists in disk", FSEFileAdapter::DoesFileExist(TEXT("0")));
	});

	It("Can save files asynchronously", [this]() {
		TestPreset->MultithreadedFiles = ESaveASyncMode::SaveAsync;
		bFinishTick = false;

		bool bSaving = SaveManager->SaveSlot(0, true, false, {}, FOnSEGameSaved::CreateLambda([this](auto* Info) {
			// Notified that files have been saved asynchronously
			TestTrue("Info File exists in disk", FSEFileAdapter::DoesFileExist(TEXT("0")));
			bFinishTick = true;
		}));
		TestTrue("Started Saving", bSaving);

		// Files shouldn't exist yet
		TestFalse("Info File exists in disk", FSEFileAdapter::DoesFileExist(TEXT("0")));

		TickWorldUntil(GetMainWorld(), true, [this](float) {
			return !bFinishTick;
		});
	});

	It("Can load files synchronously", [this]() {
		TestPreset->MultithreadedFiles = ESaveASyncMode::OnlySync;

		TestTrue("Saved", SaveManager->SaveSlot(0));

		USESlotInfo* Info = nullptr;
		USESlotData* Data = nullptr;
		TestTrue("File was loaded", FSEFileAdapter::LoadFile(TEXT("0"), Info, Data, true, SaveManager));
		TestNotNull("Info is valid", Info);
		TestNotNull("Data is valid", Data);
	});

	AfterEach([this]() {
		if (SaveManager)
		{
			bFinishTick = false;
			SaveManager->DeleteAllSlots(FOnSlotsDeleted::CreateLambda([this]() {
				bFinishTick = true;
			}));
			TickWorldUntil(GetMainWorld(), true, [this](float) {
				return !bFinishTick;
			});
		}
		SaveManager = nullptr;
	});
}
