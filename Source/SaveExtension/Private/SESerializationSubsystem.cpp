// "// Copyright 2021 luochuanyuewu. All Rights Reserved."


#include "SESerializationSubsystem.h"

#include "SELevelFilter.h"
#include "SESaveSettings.h"
#include "Serialization/SEArchive.h"

DEFINE_LOG_CATEGORY(LogSerializationSubsystem);

void USESerializationSubsystem::SerializeActor(AActor* Actor, FSEActorRecord& OutData)
{
	if (Actor == nullptr)
		return;
	OutData.Name = Actor->GetFName();
	OutData.Class = Actor->GetClass();
	OutData.bIsProcedural = Actor->HasAnyFlags(RF_WasLoaded);
	OutData.bHiddenInGame = Actor->IsHidden();
	
	if (FSELevelFilter::StoresTags(Actor))
	{
		OutData.Tags = Actor->Tags;
	}
	else
	{
		for (const auto& Tag : Actor->Tags)
		{
			if (FSELevelFilter::IsSaveTag(Tag))
			{
				OutData.Tags.Add(Tag);
			}
		}
	}

	if (FSELevelFilter::StoresTransform(Actor))
	{
		OutData.Transform = Actor->GetTransform();
		
		if (FSELevelFilter::StoresPhysics(Actor))
		{
			USceneComponent* const Root = Actor->GetRootComponent();
			if (Root && Root->Mobility == EComponentMobility::Movable)
			{
				if (auto* const Primitive = Cast<UPrimitiveComponent>(Root))
				{
					OutData.LinearVelocity = Primitive->GetPhysicsLinearVelocity();
					OutData.AngularVelocity = Primitive->GetPhysicsAngularVelocityInRadians();
				}
				else
				{
					OutData.LinearVelocity = Root->GetComponentVelocity();
				}
			}
		}
	}
	
	SerializeToBinary(Actor,OutData.Data);
	
	TArray<UActorComponent*> Components = GetSerializableComponents(Actor);

	SerializeComponents(Components,OutData.ComponentRecords);
}

void USESerializationSubsystem::DeserializeActor(AActor* Actor, const FSEActorRecord& InData)
{
	Actor->Tags = InData.Tags;
	if (FSELevelFilter::StoresTransform(Actor))
	{
		Actor->SetActorTransform(InData.Transform);

		if (FSELevelFilter::StoresPhysics(Actor))
		{
			USceneComponent* Root = Actor->GetRootComponent();
			if (auto* Primitive = Cast<UPrimitiveComponent>(Root))
			{
				Primitive->SetPhysicsLinearVelocity(InData.LinearVelocity);
				Primitive->SetPhysicsAngularVelocityInRadians(InData.AngularVelocity);
			}
			else
			{
				Root->ComponentVelocity = InData.LinearVelocity;
			}
		}
	}
	Actor->SetActorHiddenInGame(InData.bHiddenInGame);

	TArray<UActorComponent*> Components = GetSerializableComponents(Actor);
	
	DeserializeComponents(Components,InData.ComponentRecords);
	
	SerializeFromBinary(Actor,InData.Data);
}

void USESerializationSubsystem::SerializeComponents(TArray<UActorComponent*> SourceComps, TArray<FSEComponentRecord>& OutComponents)
{
	if (SourceComps.IsEmpty())
		return;
	for (UActorComponent* Component : SourceComps)
	{
		if (Component == nullptr || !Component->IsRegistered())
			continue;
		FSEComponentRecord ComponentArray;
		ComponentArray.Name = Component->GetFName();
		ComponentArray.Class = Component->GetClass();
		ComponentArray.Tags = Component->ComponentTags;

		if (FSELevelFilter::StoresTransform(Component))
		{
			const USceneComponent* SceneComp = Cast<USceneComponent>(Component);
			if (SceneComp)
			{
				ComponentArray.Transform = SceneComp->GetRelativeTransform();
			}
		}

		if (FSELevelFilter::StoresTags(Component))
		{
			ComponentArray.Tags = Component->ComponentTags;
		}

		SerializeToBinary(Component, ComponentArray.Data);

		OutComponents.Add(ComponentArray);
	}
}

void USESerializationSubsystem::DeserializeComponents(TArray<UActorComponent*> SourceComps, const TArray<FSEComponentRecord>& InComponents)
{
	if (SourceComps.IsEmpty())
		return;

	for (UActorComponent* Component : SourceComps)
	{
		if (Component == nullptr || !Component->IsRegistered())
			continue;
		for (const FSEComponentRecord& ComponentArray : InComponents)
		{
			if (ComponentArray.Name == Component->GetFName())
			{
				if (FSELevelFilter::StoresTransform(Component))
				{
					USceneComponent* SceneComp = Cast<USceneComponent>(Component);
					if (SceneComp)
					{
						if (SceneComp->Mobility == EComponentMobility::Movable)
						{
							SceneComp->SetRelativeTransform(ComponentArray.Transform, false, nullptr, ETeleportType::TeleportPhysics);
						}
					}
				}

				if (FSELevelFilter::StoresTags(Component))
				{
					Component->ComponentTags = ComponentArray.Tags;
				}
				SerializeFromBinary(Component, ComponentArray.Data);
			}
		}
	}
}


void USESerializationSubsystem::SerializeToBinary(UObject* Object, TArray<uint8>& OutData)
{
	FMemoryWriter MemoryWriter(OutData, true);
	FSEArchive Ar(MemoryWriter, true);
	Object->Serialize(Ar);

	MemoryWriter.FlushCache();
	MemoryWriter.Close();
}

void USESerializationSubsystem::SerializeFromBinary(UObject* Object, const TArray<uint8>& InData)
{
	FMemoryReader MemoryReader(InData, true);
	FSEArchive Ar(MemoryReader, true);
	Object->Serialize(Ar);

	MemoryReader.FlushCache();
	MemoryReader.Close();
}

TArray<uint8> USESerializationSubsystem::BytesFromString(const FString& String) const
{
	const uint32 Size = String.Len();

	TArray<uint8> Bytes;
	Bytes.AddUninitialized(Size);
	StringToBytes(String, Bytes.GetData(), Size);

	return Bytes;
}

FString USESerializationSubsystem::StringFromBytes(const TArray<uint8>& Bytes) const
{
	return BytesToString(Bytes.GetData(), Bytes.Num());
}

bool USESerializationSubsystem::IsActorSerializable(const AActor* Actor) const
{
	return Actor && Actor->ActorHasTag(USESaveSettings::Get()->SerializableTag);
}

bool USESerializationSubsystem::IsComponentSerializable(const UActorComponent* Component) const
{
	return Component && Component->ComponentHasTag(USESaveSettings::Get()->SerializableTag);
}

TArray<UActorComponent*> USESerializationSubsystem::GetSerializableComponents(const AActor* Actor) const
{
	TArray<UActorComponent*> Components;
	Actor->GetComponents(UActorComponent::StaticClass(),Components);

	TArray<UActorComponent*> RetComponents;
	for (auto Component : Components)
	{
		if (IsComponentSerializable(Component))
			RetComponents.AddUnique(Component);
	}
	return Components;
}