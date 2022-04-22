// Copyright 2015-2020 Piperift. All Rights Reserved.

#pragma once

#include "SESlotInfo.h"


/** Called when game has been saved
 * @param SlotInfo the saved slot. Null if save failed
 */
DECLARE_DELEGATE_OneParam(FOnSEGameSaved, USESlotInfo*);

/** Called when game has been loaded
 * @param SlotInfo the loaded slot. Null if load failed
 */
DECLARE_DELEGATE_OneParam(FOnSEGameLoaded, USESlotInfo*);
