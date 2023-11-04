// Fill out your copyright notice in the Description page of Project Settings.


#include "Saver/GSS_SaverBase.h"

#include "GSS_SaveSubsystem.h"


// Sets default values for this component's properties
UGSS_SaverBase::UGSS_SaverBase()
{
	PrimaryComponentTick.bCanEverTick = false;
	//if (HasAnyFlags(RF_ClassDefaultObject) || IsTemplate())
	//{
	//	if (bUseGuid && SaveId.IsValid())
	//	{
	//		SaveId.Invalidate();
	//	}
	//}
	//else
	//{
	//	if (bUseGuid && !SaveId.IsValid())
	//	{
	//		SaveId = FGuid::NewGuid();
	//	}
	//}
}

void UGSS_SaverBase::PostEditImport()
{
	Super::PostEditImport();

	if (!SaveId.IsValid())
		SaveId = FGuid::NewGuid();
}

void UGSS_SaverBase::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);
	//
	//#if WITH_EDITOR
	//	// 确保在加载的时候生成唯一ID，加载表示：比如Actor放在关卡中，打开所在关卡的时候就会加载;以及读档
	//	if (Ar.IsLoading())
	//	{
	//		if (HasAnyFlags(RF_ClassDefaultObject) || IsTemplate())
	//
	//		{
	//			if (bUseGuid && SaveId.IsValid())
	//			{
	//				SaveId.Invalidate();
	//			}
	//		}
	//		else if ((Ar.GetPortFlags() & PPF_Duplicate) || (Ar.IsPersistent() && !SaveId.IsValid()))
	//		{
	//			SaveId = FGuid::NewGuid();
	//		}
	//	}
	//#endif
}


void UGSS_SaverBase::OnSaveBegan()
{
	// Saved.Broadcast();
}

void UGSS_SaverBase::OnLoadFinished(bool bError)
{
	// Resume.Broadcast();
}

void UGSS_SaverBase::SaveData()
{
	if (UGSS_SaveSubsystem* SE = GetSaveManager())
	{
		TArray<uint8> Data;
		if (SerializeData(Data) && !Data.IsEmpty())
		{
			const FName Key = FName(GetFullKey());
			SE->AddToSaverDataV2(Key, Data);
			UE_LOG(LogTemp, Display, TEXT("Actor:%s Saved With Key:%s"), *GetOwner()->GetName(), *Key.ToString());
		}
	}
}

void UGSS_SaverBase::LoadData()
{
	if (Timer.IsValid())
	{
		Timer.Invalidate();
	}
	if (UGSS_SaveSubsystem* SE = GetSaveManager())
	{
		TArray<uint8> Data;
		const FName Key = FName(GetFullKey());
		if (GetSaveManager()->TryGetSaverDataV2(Key, Data))
		{
			if (!Data.IsEmpty())
			{
				DeserializeData(Data);
				UE_LOG(LogTemp, Display, TEXT("Actor:%s Loaded With Key:%s"), *GetOwner()->GetName(), *Key.ToString());
			}
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("Actor:%s Has no SavedData With Key:%s"), *GetOwner()->GetName(), *Key.ToString());
		}
	}
}

FString UGSS_SaverBase::GetFullKey() const
{
	if (bUseGuid)
	{
		return FString::Format(TEXT("{0}_{1}"), {GetClass()->GetName(), SaveId.ToString()});
	}
	return FString::Format(TEXT("{0}_{1}"), {GetClass()->GetName(), SaveKey});
}

bool UGSS_SaverBase::SerializeData(TArray<uint8>& SerializedData)
{
	return false;
}

void UGSS_SaverBase::DeserializeData(const TArray<uint8>& SerializedData)
{
}


void UGSS_SaverBase::TryLoadOnBeginPlay()
{
	if (UGSS_SaveSubsystem* Manager = GetSaveManager())
	{
		Manager->RegisterSaver(this);
		// if (!Manager->IsLoading()) { Start.Broadcast(); }
		if (bLoadOnBeginPlay)
		{
			Timer = GetWorld()->GetTimerManager().SetTimerForNextTick(this, &ThisClass::LoadData);
			// LoadData();
		}
	}
}

void UGSS_SaverBase::BeginPlay()
{
	Super::BeginPlay();
	TryLoadOnBeginPlay();
}

void UGSS_SaverBase::TrySaveOnEndplay()
{
	if (UGSS_SaveSubsystem* Manager = GetSaveManager())
	{
		if (bSaveOnEndPlay)
			SaveData();
		// if (!Manager->IsLoading()) { Finish.Broadcast(); }
		Manager->UnregisterSaver(this);
	}
}

void UGSS_SaverBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	TrySaveOnEndplay();
}

UGSS_SaveSubsystem* UGSS_SaverBase::GetSaveManager()
{
	return GetWorld()->GetGameInstance()->GetSubsystem<UGSS_SaveSubsystem>();
}
