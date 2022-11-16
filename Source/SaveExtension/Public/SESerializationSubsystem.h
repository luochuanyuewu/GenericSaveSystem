// "// Copyright 2021 luochuanyuewu. All Rights Reserved."

#pragma once

#include "CoreMinimal.h"
#include "Serialization/SERecords.h"
#include "SESerializationSubsystem.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogSerializationSubsystem, Log, All);

/**
 * 
 */
UCLASS()
class SAVEEXTENSION_API USESerializationSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()


public:
	void SerializeActor(AActor* Actor, FSEActorRecord& OutData);
	void DeserializeActor(AActor* Actor, const FSEActorRecord& InData);

	void SerializeComponents(TArray<UActorComponent*> SourceComps, TArray<FSEComponentRecord>& OutComponents);
	void DeserializeComponents(TArray<UActorComponent*> SourceComps, const TArray<FSEComponentRecord>& InComponents);

	UFUNCTION(BlueprintCallable,Category="Serialization")
	void SerializeToBinary(UObject* Object, TArray<uint8>& OutData);
	UFUNCTION(BlueprintCallable,Category="Serialization")
	void SerializeFromBinary(UObject* Object, const TArray<uint8>& InData);

	UFUNCTION(BlueprintCallable,Category="Serialization")
	TArray<uint8> BytesFromString(const FString& String) const;
	UFUNCTION(BlueprintCallable,Category="Serialization")
	FString StringFromBytes(const TArray<uint8>& Bytes) const;

protected:

	bool IsActorSerializable(const AActor* Actor) const;
	bool IsComponentSerializable(const UActorComponent* Component) const;
	TArray<UActorComponent*> GetSerializableComponents(const AActor* Actor) const;
};



