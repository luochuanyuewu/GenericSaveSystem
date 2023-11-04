// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#pragma once

#include "Multithreading/GSS_Task_LoadSlotInfos.h"


/** Called when game has been saved
 * @param SlotInfo the saved slot. Null if save failed
 */
DECLARE_DELEGATE_OneParam(FGSS_OnGameSavedSignature, UGSS_SlotInfo*);

/** Called when game has been loaded
 * @param SlotInfo the loaded slot. Null if load failed
 */
DECLARE_DELEGATE_OneParam(FGSS_OnGameLoadedSignature, UGSS_SlotInfo*);

