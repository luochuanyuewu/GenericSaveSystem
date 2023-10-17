// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Saver/SESaverBase.h"
#include "Serialization/SERecords.h"
#include "SEActorSaver.generated.h"

UCLASS()
class SAVEEXTENSION_API USEActorSaveData : public UObject
{
	GENERATED_BODY()

	UPROPERTY(SaveGame)
	FName Name;
	UPROPERTY(SaveGame)
	UClass* Class;
	UPROPERTY(SaveGame)
	TArray<uint8> Data;
	UPROPERTY(SaveGame)
	TArray<FName> Tags;

	bool IsValid() const;
};

/**
 * 
 */
UCLASS(ClassGroup=(SaveExtension), meta=(BlueprintSpawnableComponent))
class SAVEEXTENSION_API USEActorSaver : public USESaverBase
{
	GENERATED_BODY()

public:
	virtual void PostInitProperties() override;

protected:
	void FetchSaveKey();

	virtual bool SerializeData(TArray<uint8>& SerializedData) override;
	virtual void DeserializeData(const TArray<uint8>& SerializedData) override;

	/** Serializes an actor into this Actor Record */
	bool SerializeActor(const AActor* Actor, FSEActorRecord& Record) const;

	/** Serializes the components of an actor into a provided Actor Record */
	void SerializeActorComponents(const AActor* Actor, FSEActorRecord& ActorRecord, int8 indent = 0) const;

	bool ShouldSaveComponent(UObject* Component) const;

	bool DeserializeActor(AActor* Actor, const FSEActorRecord& Record);
	void DeserializeActorComponents(AActor* Actor, const FSEActorRecord& ActorRecord, int8 indent = 0);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SaveExtension")
	bool bSaveComponents = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SaveExtension", meta=(EditConditionHides, EditCondition="bSaveComponents"))
	TArray<TSoftClassPtr<UObject>> AllowedComponents;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SaveExtension")
	bool bSaveTransform = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SaveExtension")
	bool bSavePhysics = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SaveExtension")
	bool bSaveTags = true;
};
