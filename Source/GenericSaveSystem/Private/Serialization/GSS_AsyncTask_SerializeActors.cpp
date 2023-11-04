// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#include "Serialization/GSS_AsyncTask_SerializeActors.h"
#include "Serialization/MemoryWriter.h"
#include "Components/PrimitiveComponent.h"
#include "GSS_SaveSubsystem.h"
#include "GSS_SlotData.h"
#include "GSS_SavePreset.h"
#include "Serialization/GSS_Archive.h"


/////////////////////////////////////////////////////
// FMTTask_SerializeActors
void FGSS_AsyncTask_SerializeActors::DoWork()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(FSETask_SerializeActors::DoWork);
	if (bStoreGameInstance)
	{
		SerializeGameInstance();
	}

	for (int32 I = 0; I < Num; ++I)
	{
		const AActor* const Actor = (*LevelActors)[StartIndex + I];
		if (Actor && UGSS_SaveFilter::ShouldSave(Actor))
		{
			FGSS_ActorRecord& Record = ActorRecords.AddDefaulted_GetRef();
			SerializeActor(Actor, Record);
		}
	}
}

void FGSS_AsyncTask_SerializeActors::SerializeGameInstance()
{
	TRACE_CPUPROFILER_EVENT_SCOPE(FMTTask_SerializeActors::SerializeGameInstance);
	if (UGameInstance* GameInstance = World->GetGameInstance())
	{
		FGSS_ObjectRecord Record{ GameInstance };

		//Serialize into Record Data
		FMemoryWriter MemoryWriter(Record.Data, true);
		FGSS_Archive Archive(MemoryWriter, false);
		GameInstance->Serialize(Archive);

		SlotData->GameInstance = MoveTemp(Record);
	}
}

bool FGSS_AsyncTask_SerializeActors::SerializeActor(const AActor* Actor, FGSS_ActorRecord& Record) const
{
	TRACE_CPUPROFILER_EVENT_SCOPE(FMTTask_SerializeActors::SerializeActor);

	//Clean the record
	Record = { Actor };

	Record.bHiddenInGame = Actor->IsHidden();
	Record.bIsProcedural = UGSS_SaveFilter::IsProcedural(Actor);

	if (UGSS_SaveFilter::StoresTags(Actor))
	{
		Record.Tags = Actor->Tags;
	}
	else
	{
		// Only save save-tags
		for (const auto& Tag : Actor->Tags)
		{
			if (UGSS_SaveFilter::IsSaveTag(Tag))
			{
				Record.Tags.Add(Tag);
			}
		}
	}

	if (UGSS_SaveFilter::StoresTransform(Actor))
	{
		Record.Transform = Actor->GetTransform();

		if (UGSS_SaveFilter::StoresPhysics(Actor))
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
	FGSS_Archive Archive(MemoryWriter, false);
	const_cast<AActor*>(Actor)->Serialize(Archive);

	return true;
}

void FGSS_AsyncTask_SerializeActors::SerializeActorComponents(const AActor* Actor, FGSS_ActorRecord& ActorRecord, int8 Indent /*= 0*/) const
{
	TRACE_CPUPROFILER_EVENT_SCOPE(FMTTask_SerializeActors::SerializeActorComponents);

	const TSet<UActorComponent*>& Components = Actor->GetComponents();
	for (auto* Component : Components)
	{
		TRACE_CPUPROFILER_EVENT_SCOPE(FMTTask_SerializeActors::SerializeActorComponents|Component);
		if (UGSS_SaveFilter::ShouldSave(Component))
		{
			FGSS_ComponentRecord ComponentRecord;
			ComponentRecord.Name = Component->GetFName();
			ComponentRecord.Class = Component->GetClass();

			if (UGSS_SaveFilter::StoresTransform(Component))
			{
				const USceneComponent* Scene = CastChecked<USceneComponent>(Component);
				if (Scene->Mobility == EComponentMobility::Movable)
				{
					ComponentRecord.Transform = Scene->GetRelativeTransform();
				}
			}

			if (UGSS_SaveFilter::StoresTags(Component))
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
