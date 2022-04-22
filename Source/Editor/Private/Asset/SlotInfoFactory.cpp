// Copyright 2015-2020 Piperift. All Rights Reserved.

#include "SlotInfoFactory.h"
#include "Kismet2/KismetEditorUtilities.h"


USlotInfoFactory::USlotInfoFactory() : Super() {
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = USESlotInfo::StaticClass();
}

UObject* USlotInfoFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) {
	check(Class->IsChildOf(USESlotInfo::StaticClass()));

	if (!FKismetEditorUtilities::CanCreateBlueprintOfClass(Class))
	{
		return nullptr;
	}
	return FKismetEditorUtilities::CreateBlueprint(Class, InParent, Name, BPTYPE_Normal, UBlueprint::StaticClass(), UBlueprintGeneratedClass::StaticClass(), TEXT("AssetTypeActions"));
}
