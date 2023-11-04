// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#pragma once

#include "GSS_LevelFilter.generated.h"

class UGSS_SaveSubsystem;


/**
 * Contains all settings that affect saving.
 * This information is saved to be restored while loading.
 */
UCLASS(Blueprintable)
class UGSS_SaveFilter : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static FName TagNoTransform();
	static FName TagNoPhysics();
	static FName TagNoTags();
	static FName TagSerializable();
	static FName TagTransform();


	static bool ShouldSave(const AActor* Actor)
	{
		return IsValid(Actor) && Actor->ActorHasTag(TagSerializable());
	}

	static bool ShouldLoad(const AActor* Actor)
	{
		return IsValid(Actor) && Actor->ActorHasTag(TagSerializable());
	}

	static bool ShouldSave(const UActorComponent* Component)
	{
		return IsValid(Component)
			&& Component->ComponentHasTag(TagSerializable());
	}

	static bool ShouldLoad(const UActorComponent* Component)
	{
		return IsValid(Component)
			&& Component->ComponentHasTag(TagSerializable());
	}


	static bool StoresTransform(const UActorComponent* Component)
	{
		return Component->GetClass()->IsChildOf<USceneComponent>()
			&& HasTag(Component, TagTransform());
	}

	static bool StoresTags(const UActorComponent* Component)
	{
		return !HasTag(Component, TagNoTags());
	}

	static bool IsSaveTag(const FName& Tag)
	{
		return Tag == TagNoTransform() || Tag == TagNoPhysics() || Tag == TagNoTags() || Tag == TagSerializable();
	}

	static FORCEINLINE bool StoresTransform(const AActor* Actor) { return Actor->IsRootComponentMovable() && !HasTag(Actor, TagNoTransform()); }
	static FORCEINLINE bool StoresPhysics(const AActor* Actor) { return !HasTag(Actor, TagNoPhysics()); }
	static FORCEINLINE bool StoresTags(const AActor* Actor) { return !HasTag(Actor, TagNoTags()); }
	static FORCEINLINE bool IsProcedural(const AActor* Actor) { return Actor->HasAnyFlags(RF_WasLoaded | RF_LoadCompleted); }

	static FORCEINLINE bool HasTag(const AActor* Actor, const FName Tag)
	{
		check(Actor);
		return Actor->ActorHasTag(Tag);
	}

	static FORCEINLINE bool HasTag(const UActorComponent* Component, const FName Tag)
	{
		check(Component);
		return Component->ComponentHasTag(Tag);
	}
};
