// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SESaveInterface.h"
#include "Components/ActorComponent.h"
#include "Serialization/SERecords.h"
#include "SESaverBase.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSESaverStartSignature);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSESaverSavedSignature);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSESaverResumeSignature);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSESaverFinishSignature);


class USESaveManager;
UCLASS(Abstract, ClassGroup=(SaveExtension), meta=(BlueprintSpawnableComponent))
class SAVEEXTENSION_API USESaverBase : public UActorComponent, public ISESaveInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USESaverBase();
	virtual void PostEditImport() override;
	virtual void Serialize(FArchive& Ar) override;

	UPROPERTY(EditAnywhere, Category="SaveExtension")
	bool bUseGuid = false;
	UPROPERTY(EditAnywhere, Category="SaveExtension", meta=(EditCondition="!bUseGuid", EditConditionHides))
	FString SaveKey;
	UPROPERTY(EditAnywhere, Category="SaveExtension", meta=(EditCondition="bUseGuid", EditConditionHides))
	FGuid SaveId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SaveExtension")
	int32 SavePriority = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SaveExtension")
	int32 LoadPriority = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SaveExtension")
	bool bLoadOnBeginPlay = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SaveExtension")
	bool bSaveOnEndPlay = true;


	// 在要保存存档数据之前会被调用，这时候可以更新一些要存储的值。
	virtual void OnSaveBegan(const FSELevelFilter& Filter) override;

	// 存档数据读取完毕后会被调用，这时候可以根据还原回的数据进行游戏逻辑上的应用数据。
	virtual void OnLoadFinished(const FSELevelFilter& Filter, bool bError);

	void SaveData();
	void LoadData();

	virtual FString GetFullKey() const;

protected:
	//序列化数据，可能会在另外的线程调用，所以注意线程安全。
	virtual bool SerializeData(TArray<uint8>& SerializedData);
	//反序列化数据，可能会在另外的线程调用，所以注意线程安全。
	virtual void DeserializeData(const TArray<uint8>& SerializedData);

	// Called when the game starts
	virtual void InitializeComponent() override;
	virtual void BeginPlay() override;
	UFUNCTION()
	virtual void TrySaveOnEndplay();
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void UninitializeComponent() override;
	UFUNCTION()
	virtual void TryLoadOnBeginPlay();

	USESaveManager* GetSaveManager();


private:
	FTimerHandle Timer;

	/***********************************************************************/
	/* EVENTS															   */
	/***********************************************************************/
protected:
	// // Called once when this actor gets created for the first time. Similar to BeginPlay
	// UPROPERTY(BlueprintAssignable, Category = SaveExtension)
	// FSESaverStartSignature Start;
	//
	// // Called when game is saved
	// UPROPERTY(BlueprintAssignable, Category = SaveExtension)
	// FSESaverSavedSignature Saved;
	//
	// // Called when game loaded
	// UPROPERTY(BlueprintAssignable, Category = SaveExtension)
	// FSESaverResumeSignature Resume;
	//
	// // Called when this actor gets destroyed for ever
	// UPROPERTY(BlueprintAssignable, Category = SaveExtension)
	// FSESaverFinishSignature Finish;


public:
	// FSESaverStartSignature& OnStart() { return Start; }
	// FSESaverSavedSignature& OnSaved() { return Saved; }
	// FSESaverResumeSignature& OnResume() { return Resume; }
	// FSESaverFinishSignature& OnFinish() { return Finish; }
};
