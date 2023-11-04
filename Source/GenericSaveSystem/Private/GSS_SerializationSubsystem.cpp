// "// Copyright 2021 luochuanyuewu. All Rights Reserved."


#include "GSS_SerializationSubsystem.h"

#include "GSS_LevelFilter.h"
#include "GSS_GenericSaveSystemSettings.h"
#include "Serialization/GSS_Archive.h"

DEFINE_LOG_CATEGORY(LogSerializationSubsystem);

void UGSS_SerializationSubsystem::SerializeActor(AActor* Actor, FGSS_ActorRecord& OutData)
{
	if (Actor == nullptr)
		return;
	OutData.Name = Actor->GetFName();
	OutData.Class = Actor->GetClass();
	OutData.bIsProcedural = Actor->HasAnyFlags(RF_WasLoaded);
	OutData.bHiddenInGame = Actor->IsHidden();
	
	if (UGSS_SaveFilter::StoresTags(Actor))
	{
		OutData.Tags = Actor->Tags;
	}
	else
	{
		for (const auto& Tag : Actor->Tags)
		{
			if (UGSS_SaveFilter::IsSaveTag(Tag))
			{
				OutData.Tags.Add(Tag);
			}
		}
	}

	if (UGSS_SaveFilter::StoresTransform(Actor))
	{
		OutData.Transform = Actor->GetTransform();
		
		if (UGSS_SaveFilter::StoresPhysics(Actor))
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

void UGSS_SerializationSubsystem::DeserializeActor(AActor* Actor, const FGSS_ActorRecord& InData)
{
	Actor->Tags = InData.Tags;
	if (UGSS_SaveFilter::StoresTransform(Actor))
	{
		Actor->SetActorTransform(InData.Transform);

		if (UGSS_SaveFilter::StoresPhysics(Actor))
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

void UGSS_SerializationSubsystem::SerializeComponents(TArray<UActorComponent*> SourceComps, TArray<FGSS_ComponentRecord>& OutComponents)
{
	if (SourceComps.IsEmpty())
		return;
	for (UActorComponent* Component : SourceComps)
	{
		if (Component == nullptr || !Component->IsRegistered())
			continue;
		FGSS_ComponentRecord ComponentArray;
		ComponentArray.Name = Component->GetFName();
		ComponentArray.Class = Component->GetClass();
		ComponentArray.Tags = Component->ComponentTags;

		if (UGSS_SaveFilter::StoresTransform(Component))
		{
			const USceneComponent* SceneComp = Cast<USceneComponent>(Component);
			if (SceneComp)
			{
				ComponentArray.Transform = SceneComp->GetRelativeTransform();
			}
		}

		if (UGSS_SaveFilter::StoresTags(Component))
		{
			ComponentArray.Tags = Component->ComponentTags;
		}

		SerializeToBinary(Component, ComponentArray.Data);

		OutComponents.Add(ComponentArray);
	}
}

void UGSS_SerializationSubsystem::DeserializeComponents(TArray<UActorComponent*> SourceComps, const TArray<FGSS_ComponentRecord>& InComponents)
{
	if (SourceComps.IsEmpty())
		return;

	for (UActorComponent* Component : SourceComps)
	{
		if (Component == nullptr || !Component->IsRegistered())
			continue;
		for (const FGSS_ComponentRecord& ComponentArray : InComponents)
		{
			if (ComponentArray.Name == Component->GetFName())
			{
				if (UGSS_SaveFilter::StoresTransform(Component))
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

				if (UGSS_SaveFilter::StoresTags(Component))
				{
					Component->ComponentTags = ComponentArray.Tags;
				}
				SerializeFromBinary(Component, ComponentArray.Data);
			}
		}
	}
}


void UGSS_SerializationSubsystem::SerializeToBinary(UObject* Object, TArray<uint8>& OutData)
{
	FMemoryWriter MemoryWriter(OutData, true);
	FGSS_Archive Ar(MemoryWriter, true);
	Object->Serialize(Ar);

	MemoryWriter.FlushCache();
	MemoryWriter.Close();
}

void UGSS_SerializationSubsystem::SerializeFromBinary(UObject* Object, const TArray<uint8>& InData)
{
	FMemoryReader MemoryReader(InData, true);
	FGSS_Archive Ar(MemoryReader, true);
	Object->Serialize(Ar);

	MemoryReader.FlushCache();
	MemoryReader.Close();
}

TArray<uint8> UGSS_SerializationSubsystem::BytesFromString(const FString& String) const
{
	const uint32 Size = String.Len();

	TArray<uint8> Bytes;
	Bytes.AddUninitialized(Size);
	StringToBytes(String, Bytes.GetData(), Size);

	return Bytes;
}

FString UGSS_SerializationSubsystem::StringFromBytes(const TArray<uint8>& Bytes) const
{
	return BytesToString(Bytes.GetData(), Bytes.Num());
}

bool UGSS_SerializationSubsystem::IsActorSerializable(const AActor* Actor) const
{
	return Actor && Actor->ActorHasTag(UGSS_GenericSaveSystemSettings::Get()->SerializableTag);
}

bool UGSS_SerializationSubsystem::IsComponentSerializable(const UActorComponent* Component) const
{
	return Component && Component->ComponentHasTag(UGSS_GenericSaveSystemSettings::Get()->SerializableTag);
}

TArray<UActorComponent*> UGSS_SerializationSubsystem::GetSerializableComponents(const AActor* Actor) const
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