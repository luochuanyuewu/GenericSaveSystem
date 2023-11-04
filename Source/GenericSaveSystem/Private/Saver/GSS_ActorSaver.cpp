// Fill out your copyright notice in the Description page of Project Settings.

#include "Saver/GSS_ActorSaver.h"
#include "Serialization/GSS_Archive.h"

bool UGSS_ActorSaveData::IsValid() const
{
	return !Name.IsNone() && Class && Data.Num() > 0;
}

void UGSS_ActorSaver::FetchSaveKey()
{
}

void UGSS_ActorSaver::PostInitProperties()
{
	Super::PostInitProperties();
	FetchSaveKey();
}


bool UGSS_ActorSaver::SerializeData(TArray<uint8>& SerializedData)
{
	TArray<uint8> Data;

	//Actor保存到ActorRecord
	FGSS_ActorRecord ActorRecord;
	SerializeActor(GetOwner(), ActorRecord);

	//ActorRecord序列化到ObjectRecord
	{
		FMemoryWriter MemoryWriter(Data, true);
		FGSS_Archive Archive(MemoryWriter, false);
		ActorRecord.Serialize(Archive);
	}
	SerializedData = Data;
	return true;
}

void UGSS_ActorSaver::DeserializeData(const TArray<uint8>& SerializedData)
{
	FMemoryReader MemoryReader(SerializedData, true);
	FGSS_Archive Archive(MemoryReader, false);
	FGSS_ActorRecord ActorRecord;
	ActorRecord.Serialize(Archive);
	DeserializeActor(GetOwner(), ActorRecord);
}

bool UGSS_ActorSaver::SerializeActor(const AActor* Actor, FGSS_ActorRecord& Record) const
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
	FGSS_Archive Archive(MemoryWriter, false);
	const_cast<AActor*>(Actor)->Serialize(Archive);

	return true;
}

void UGSS_ActorSaver::SerializeActorComponents(const AActor* Actor, FGSS_ActorRecord& ActorRecord, int8 indent) const
{
	TRACE_CPUPROFILER_EVENT_SCOPE(USEActorSaver::SerializeActorComponents);

	const TSet<UActorComponent*>& Components = Actor->GetComponents();
	for (auto* Component : Components)
	{
		TRACE_CPUPROFILER_EVENT_SCOPE(FMTTask_SerializeActors::SerializeActorComponents|Component);
		if (ShouldSaveComponent(Component))
		{
			FGSS_ComponentRecord ComponentRecord;
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
				FGSS_Archive Archive(MemoryWriter, false);
				Component->Serialize(Archive);
			}
			ActorRecord.ComponentRecords.Add(ComponentRecord);
		}
	}
}

bool UGSS_ActorSaver::ShouldSaveComponent(UObject* Component) const
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

bool UGSS_ActorSaver::DeserializeActor(AActor* Actor, const FGSS_ActorRecord& Record)
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
		FGSS_Archive Archive(MemoryReader, false);
		Actor->Serialize(Archive);
	}

	return true;
}

void UGSS_ActorSaver::DeserializeActorComponents(AActor* Actor, const FGSS_ActorRecord& ActorRecord, int8 indent)
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
			const FGSS_ComponentRecord* Record = ActorRecord.ComponentRecords.FindByKey(Component);
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
				FGSS_Archive Archive(MemoryReader, false);
				Component->Serialize(Archive);
			}
		}
	}
}
