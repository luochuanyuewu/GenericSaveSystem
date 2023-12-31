﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "GSS_SaveSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"


void UGSS_SaveSubsystem::RegisterCmds()
{
#if !UE_BUILD_SHIPPING
	SaveSlotCmd = IConsoleManager::Get().RegisterConsoleCommand(
		TEXT("Save.SaveSlot"),TEXT("保存游戏,Save.SaveSlot SlotName"),
		FConsoleCommandWithArgsDelegate::CreateUObject(this, &UGSS_SaveSubsystem::CmdSaveSlot));
	LoadSlotCmd = IConsoleManager::Get().RegisterConsoleCommand(
		TEXT("Save.LoadSlot"),TEXT("加载游戏,Save.LoadSlot 1(重载地图)/0(不重载地图) SlotName"),
		FConsoleCommandWithArgsDelegate::CreateUObject(this, &UGSS_SaveSubsystem::CmdLoadSlot));
#endif
}

void UGSS_SaveSubsystem::UnregisterCmds()
{
#if !UE_BUILD_SHIPPING
	IConsoleManager::Get().UnregisterConsoleObject(SaveSlotCmd);
	IConsoleManager::Get().UnregisterConsoleObject(LoadSlotCmd);

#endif
}

void UGSS_SaveSubsystem::CmdLoadSlot(const TArray<FString>& Args)
{
	FName SlotName = TEXT("SETestSlot");


	bool bLoadMap = false;
	if (Args.IsValidIndex(0))
	{
		bLoadMap = static_cast<bool>(UKismetStringLibrary::Conv_StringToInt(Args[0]));
	}
	if (Args.IsValidIndex(1))
	{
		SlotName = FName(Args[1]);
	}
	LoadSlot(SlotName, FGSS_OnGameLoadedSignature::CreateLambda([&](const UGSS_SlotInfo* SlotInfo)
	{
		//SlotInfo 在由LoadTask处理地图加载时，会传null
		if (bLoadMap && SlotInfo != nullptr)
		{
			UGameplayStatics::OpenLevel(this, SlotInfo->Map);
		}
	}));
}


void UGSS_SaveSubsystem::CmdSaveSlot(const TArray<FString>& Args)
{
	FName SlotName = TEXT("SETestSlot");
	if (Args.IsValidIndex(0))
	{
		SlotName = FName(Args[0]);
	}
	SaveSlot(SlotName, true, false);
}
