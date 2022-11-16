// Copyright 2015-2020 Piperift. All Rights Reserved.

#include "Serialization/SEAsyncTask_SerializeActors.h"
#include "Serialization/MemoryWriter.h"
#include "Components/PrimitiveComponent.h"
#include "SESaveManager.h"
#include "SESlotData.h"
#include "SESavePreset.h"
#include "Serialization/SEArchive.h"


/////////////////////////////////////////////////////
// FMTTask_SerializeActors
void FSEAsyncTask_SerializeActors::DoWork()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(FSETask_SerializeActors::DoWork);
	if (bStoreGameInstance)
	{
		SerializeGameInstance();
	}

	for (int32 I = 0; I < Num; ++I)
	{
		const AActor* const Actor = (*LevelActors)[StartIndex + I];
		if (Actor && FSELevelFilter::ShouldSave(Actor))
		{
			FSEActorRecord& Record = ActorRecords.AddDefaulted_GetRef();
			SerializeActor(Actor, Record);
		}
	}
}

void FSEAsyncTask_SerializeActors::SerializeGameInstance()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(FMTTask_SerializeActors::SerializeGameInstance);
	if (UGameInstance* GameInstance = World->GetGameInstance())
	{
		FSEObjectRecord Record{ GameInstance };

		//Serialize into Record Data
		FMemoryWriter MemoryWriter(Record.Data, true);
		FSEArchive Archive(MemoryWriter, false);
		GameInstance->Serialize(Archive);

		SlotData->GameInstance = MoveTemp(Record);
	}
}

bool FSEAsyncTask_SerializeActors::SerializeActor(const AActor* Actor, FSEActorRecord& Record) const
{
	TRACE_CPUPROFILER_EVENT_SCOPE(FMTTask_SerializeActors::SerializeActor);

	//Clean the record
	Record = { Actor };

	Record.bHiddenInGame = Actor->IsHidden();
	Record.bIsProcedural = FSELevelFilter::IsProcedural(Actor);

	if (FSELevelFilter::StoresTags(Actor))
	{
		Record.Tags = Actor->Tags;
	}
	else
	{
		// Only save save-tags
		for (const auto& Tag : Actor->Tags)
		{
			if (FSELevelFilter::IsSaveTag(Tag))
			{
				Record.Tags.Add(Tag);
			}
		}
	}

	if (FSELevelFilter::StoresTransform(Actor))
	{
		Record.Transform = Actor->GetTransform();

		if (FSELevelFilter::StoresPhysics(Actor))
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

	SerializeActorComponents(Actor, Record, 1);

	TRACE_CPUPROFILER_EVENT_SCOPE(Serialize);
	FMemoryWriter MemoryWriter(Record.Data, true);
	FSEArchive Archive(MemoryWriter, false);
	const_cast<AActor*>(Actor)->Serialize(Archive);

	return true;
}

void FSEAsyncTask_SerializeActors::SerializeActorComponents(const AActor* Actor, FSEActorRecord& ActorRecord, int8 Indent /*= 0*/) const
{
	TRACE_CPUPROFILER_EVENT_SCOPE(FMTTask_SerializeActors::SerializeActorComponents);

	const TSet<UActorComponent*>& Components = Actor->GetComponents();
	for (auto* Component : Components)
	{
		TRACE_CPUPROFILER_EVENT_SCOPE(FMTTask_SerializeActors::SerializeActorComponents|Component);
		if (FSELevelFilter::ShouldSave(Component))
		{
			FSEComponentRecord ComponentRecord;
			ComponentRecord.Name = Component->GetFName();
			ComponentRecord.Class = Component->GetClass();

			if (FSELevelFilter::StoresTransform(Component))
			{
				const USceneComponent* Scene = CastChecked<USceneComponent>(Component);
				if (Scene->Mobility == EComponentMobility::Movable)
				{
					ComponentRecord.Transform = Scene->GetRelativeTransform();
				}
			}

			if (FSELevelFilter::StoresTags(Component))
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
