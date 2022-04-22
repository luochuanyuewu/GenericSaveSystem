// Copyright 2015-2020 Piperift. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"


DECLARE_DELEGATE_OneParam(FOnSESlotInfosLoaded, const TArray<class USESlotInfo*>&);

// @param Amount of slots removed
DECLARE_DELEGATE(FOnSlotsDeleted);
