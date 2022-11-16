// Fill out your copyright notice in the Description page of Project Settings.


#include "Saver/SESaverBase.h"

#include "SESaveManager.h"


// Sets default values for this component's properties
USESaverBase::USESaverBase()
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

void USESaverBase::PostEditImport()
{
	Super::PostEditImport();

	if (!SaveId.IsValid())
		SaveId = FGuid::NewGuid();
}

void USESaverBase::Serialize(FArchive& Ar)
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


void USESaverBase::OnSaveBegan()
{
	// Saved.Broadcast();
}

void USESaverBase::OnLoadFinished(bool bError)
{
	// Resume.Broadcast();
}

void USESaverBase::SaveData()
{
	if (USESaveManager* SE = GetSaveManager())
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

void USESaverBase::LoadData()
{
	if (Timer.IsValid())
	{
		Timer.Invalidate();
	}
	if (USESaveManager* SE = GetSaveManager())
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

FString USESaverBase::GetFullKey() const
{
	if (bUseGuid)
	{
		return FString::Format(TEXT("{0}_{1}"), {GetClass()->GetName(), SaveId.ToString()});
	}
	return FString::Format(TEXT("{0}_{1}"), {GetClass()->GetName(), SaveKey});
}

bool USESaverBase::SerializeData(TArray<uint8>& SerializedData)
{
	return false;
}

void USESaverBase::DeserializeData(const TArray<uint8>& SerializedData)
{
}


void USESaverBase::TryLoadOnBeginPlay()
{
	if (USESaveManager* Manager = GetSaveManager())
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

void USESaverBase::BeginPlay()
{
	Super::BeginPlay();
	TryLoadOnBeginPlay();
}

void USESaverBase::TrySaveOnEndplay()
{
	if (USESaveManager* Manager = GetSaveManager())
	{
		if (bSaveOnEndPlay)
			SaveData();
		// if (!Manager->IsLoading()) { Finish.Broadcast(); }
		Manager->UnregisterSaver(this);
	}
}

void USESaverBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	TrySaveOnEndplay();
}

USESaveManager* USESaverBase::GetSaveManager()
{
	return GetWorld()->GetGameInstance()->GetSubsystem<USESaveManager>();
}
