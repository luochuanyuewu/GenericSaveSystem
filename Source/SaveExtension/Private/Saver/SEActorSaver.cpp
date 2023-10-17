// Fill out your copyright notice in the Description page of Project Settings.

#include "Saver/SEActorSaver.h"
#include "Serialization/SEArchive.h"

bool USEActorSaveData::IsValid() const
{
	return !Name.IsNone() && Class && Data.Num() > 0;
}

void USEActorSaver::FetchSaveKey()
{
}

void USEActorSaver::PostInitProperties()
{
	Super::PostInitProperties();
	FetchSaveKey();
}


bool USEActorSaver::SerializeData(TArray<uint8>& SerializedData)
{
	TArray<uint8> Data;

	//Actor保存到ActorRecord
	FSEActorRecord ActorRecord;
	SerializeActor(GetOwner(), ActorRecord);

	//ActorRecord序列化到ObjectRecord
	{
		FMemoryWriter MemoryWriter(Data, true);
		FSEArchive Archive(MemoryWriter, false);
		ActorRecord.Serialize(Archive);
	}
	SerializedData = Data;
	return true;
}

void USEActorSaver::DeserializeData(const TArray<uint8>& SerializedData)
{
	FMemoryReader MemoryReader(SerializedData, true);
	FSEArchive Archive(MemoryReader, false);
	FSEActorRecord ActorRecord;
	ActorRecord.Serialize(Archive);
	DeserializeActor(GetOwner(), ActorRecord);
}

bool USEActorSaver::SerializeActor(const AActor* Actor, FSEActorRecord& Record) const
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USEActorSaver::SerializeActor);

	//Clean the record
	Record = {Actor};

	Record.bHiddenInGame = Actor->IsHidden();
	Record.bIsProcedural = Actor->HasAnyFlags(RF_WasLoaded | RF_LoadCompleted);

	if (bSaveTags)
	{
		Record.Tags = Actor->Tags;
	}

	if (bSaveTransform)
	{
		Record.Transform = Actor->GetTransform();

		if (bSavePhysics)
		{
			USceneComponent* const Root = Actor->GetRootComponent();
			if (Root && Root->Mobility == EComponentMobility::Movable)
			{
				if (auto* const Primitive = Cast<UPrimitiveComponent>(Root))
				{
					Record.LinearVelocity = Primitive->GetPhysicsLinearVelocity();
					Record.AngularVelocity = Primitive->GetPhysicsAngularVelocityInRadians();
				}
				else
				{
					Record.LinearVelocity = Root->GetComponentVelocity();
				}
			}
		}
	}

	if (bSaveComponents)
	{
		SerializeActorComponents(Actor, Record, 1);
	}

	TRACE_CPUPROFILER_EVENT_SCOPE(Serialize);
	FMemoryWriter MemoryWriter(Record.Data, true);
	FSEArchive Archive(MemoryWriter, false);
	const_cast<AActor*>(Actor)->Serialize(Archive);

	return true;
}

void USEActorSaver::SerializeActorComponents(const AActor* Actor, FSEActorRecord& ActorRecord, int8 indent) const
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USEActorSaver::SerializeActorComponents);

	const TSet<UActorComponent*>& Components = Actor->GetComponents();
	for (auto* Component : Components)
	{
		TRACE_CPUPROFILER_EVENT_SCOPE(FMTTask_SerializeActors::SerializeActorComponents|Component);
		if (ShouldSaveComponent(Component))
		{
			FSEComponentRecord ComponentRecord;
			ComponentRecord.Name = Component->GetFName();
			ComponentRecord.Class = Component->GetClass();

			if (bSaveTransform)
			{
				const USceneComponent* Scene = Cast<USceneComponent>(Component);
				if (Scene && Scene->Mobility == EComponentMobility::Movable)
				{
					ComponentRecord.Transform = Scene->GetRelativeTransform();
				}
			}

			if (bSaveTags)
			{
				ComponentRecord.Tags = Component->ComponentTags;
			}

			if (!Component->GetClass()->IsChildOf<UPrimitiveComponent>())
			{
				FMemoryWriter MemoryWriter(ComponentRecord.Data, true);
				FSEArchive Archive(MemoryWriter, false);
				Component->Serialize(Archive);
			}
			ActorRecord.ComponentRecords.Add(ComponentRecord);
		}
	}
}

bool USEActorSaver::ShouldSaveComponent(UObject* Component) const
{
	for (auto AllowedComponent : AllowedComponents)
	{
		if (AllowedComponent.IsNull()) continue;;
		if (Component->GetClass()->IsChildOf(AllowedComponent.LoadSynchronous()))
		{
			return true;
		}
	}
	return false;
}

bool USEActorSaver::DeserializeActor(AActor* Actor, const FSEActorRecord& Record)
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USEActorSaver::DeserializeActor);

	// Always load saved tags
	Actor->Tags = Record.Tags;

	if (bSaveTransform)
	{
		Actor->SetActorTransform(Record.Transform);

		if (bSavePhysics)
		{
			USceneComponent* Root = Actor->GetRootComponent();
			if (auto* Primitive = Cast<UPrimitiveComponent>(Root))
			{
				Primitive->SetPhysicsLinearVelocity(Record.LinearVelocity);
				Primitive->SetPhysicsAngularVelocityInRadians(Record.AngularVelocity);
			}
			else
			{
				Root->ComponentVelocity = Record.LinearVelocity;
			}
		}
	}

	Actor->SetActorHiddenInGame(Record.bHiddenInGame);

	DeserializeActorComponents(Actor, Record, 2);

	{
		//Serialize from Record Data
		FMemoryReader MemoryReader(Record.Data, true);
		FSEArchive Archive(MemoryReader, false);
		Actor->Serialize(Archive);
	}

	return true;
}

void USEActorSaver::DeserializeActorComponents(AActor* Actor, const FSEActorRecord& ActorRecord, int8 indent)
{
	if (bSaveComponents)
	{
		TRACE_CPUPROFILER_EVENT_SCOPE(USEActorSaver::DeserializeActorComponents);

		const TSet<UActorComponent*>& Components = Actor->GetComponents();
		for (auto* Component : Components)
		{
			if (ShouldSaveComponent(Component))
			{
				continue;
			}

			// Find the record
			const FSEComponentRecord* Record = ActorRecord.ComponentRecords.FindByKey(Component);
			if (!Record)
			{
				// SELog(Preset, "Component '" + Component->GetFName().ToString() + "' - Record not found", FColor::Red, false, Indent + 1);
				continue;
			}

			if (bSaveTransform)
			{
				USceneComponent* Scene = Cast<USceneComponent>(Component);
				if (Scene && Scene->Mobility == EComponentMobility::Movable)
				{
					Scene->SetRelativeTransform(Record->Transform);
				}
			}

			if (bSaveTags)
			{
				Component->ComponentTags = Record->Tags;
			}

			if (!Component->GetClass()->IsChildOf<UPrimitiveComponent>())
			{
				FMemoryReader MemoryReader(Record->Data, true);
				FSEArchive Archive(MemoryReader, false);
				Component->Serialize(Archive);
			}
		}
	}
}
