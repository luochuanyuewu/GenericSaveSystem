// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GSS_SaveListenerComponent.h"
#include "GSS_SaverBase.generated.h"


class UGSS_SaveSubsystem;
UCLASS(Abstract, ClassGroup=(GenericSaveSystem), meta=(BlueprintSpawnableComponent))
class GENERICSAVESYSTEM_API UGSS_SaverBase : public UGSS_SaveListenerComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UGSS_SaverBase();
	virtual void PostEditImport() override;
	virtual void Serialize(FArchive& Ar) override;

	int32 GetSavePriority() const { return SavePriority; }
	int32 GetLoadPriority() const { return LoadPriority; }


	// 在要保存存档数据之前会被调用，这时候可以更新一些要存储的值。
	virtual void OnSaveBegan() override;

	// 存档数据读取完毕后会被调用，这时候可以根据还原回的数据进行游戏逻辑上的应用数据。
	virtual void OnLoadFinished(bool bError);

	void SaveData();
	void LoadData();

	virtual FString GetFullKey() const;

protected:
	//序列化数据，可能会在另外的线程调用，所以注意线程安全。
	virtual bool SerializeData(TArray<uint8>& SerializedData);
	//反序列化数据，可能会在另外的线程调用，所以注意线程安全。
	virtual void DeserializeData(const TArray<uint8>& SerializedData);

	// Called when the game starts
	virtual void BeginPlay() override;
	
	UFUNCTION()
	virtual void TrySaveOnEndplay();
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
	UFUNCTION()
	virtual void TryLoadOnBeginPlay();

	UGSS_SaveSubsystem* GetSaveManager();

	UPROPERTY(EditAnywhere, Category="Save")
	bool bUseGuid = false;
	UPROPERTY(EditAnywhere, Category="Save", meta=(EditCondition="!bUseGuid", EditConditionHides))
	FString SaveKey;
	UPROPERTY(EditAnywhere, Category="Save", meta=(EditCondition="bUseGuid", EditConditionHides))
	FGuid SaveId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Save")
	int32 SavePriority = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Save")
	int32 LoadPriority = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Save")
	bool bLoadOnBeginPlay = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Save")
	bool bSaveOnEndPlay = true;


private:
	FTimerHandle Timer;
};
