// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Saver/GSS_SaverBase.h"
#include "Serialization/GSS_Records.h"
#include "GSS_ActorSaver.generated.h"

UCLASS()
class GENERICSAVESYSTEM_API UGSS_ActorSaveData : public UObject
{
	GENERATED_BODY()

	UPROPERTY(SaveGame)
	FName Name;
	UPROPERTY(SaveGame)
	UClass *Class;
	UPROPERTY(SaveGame)
	TArray<uint8> Data;
	UPROPERTY(SaveGame)
	TArray<FName> Tags;

	bool IsValid() const;
};

/**
 *
 */
UCLASS(ClassGroup = GenericSaveSystem, meta = (BlueprintSpawnableComponent))
class GENERICSAVESYSTEM_API UGSS_ActorSaver : public UGSS_SaverBase
{
	GENERATED_BODY()

public:
	virtual void PostInitProperties() override;

protected:
	void FetchSaveKey();

	virtual bool SerializeData(TArray<uint8> &SerializedData) override;
	virtual void DeserializeData(const TArray<uint8> &SerializedData) override;

	/** Serializes an actor into this Actor Record */
	bool SerializeActor(const AActor *Actor, FGSS_ActorRecord &Record) const;

	/** Serializes the components of an actor into a provided Actor Record */
	void SerializeActorComponents(const AActor *Actor, FGSS_ActorRecord &ActorRecord, int8 indent = 0) const;

	bool ShouldSaveComponent(UObject *Component) const;

	bool DeserializeActor(AActor *Actor, const FGSS_ActorRecord &Record);
	void DeserializeActorComponents(AActor *Actor, const FGSS_ActorRecord &ActorRecord, int8 indent = 0);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GenericSaveSystem")
	bool bSaveComponents = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GenericSaveSystem", meta = (EditConditionHides, EditCondition = "bSaveComponents"))
	TArray<TSoftClassPtr<UObject>> AllowedComponents;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GenericSaveSystem")
	bool bSaveTransform = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GenericSaveSystem")
	bool bSavePhysics = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GenericSaveSystem")
	bool bSaveTags = true;
};
