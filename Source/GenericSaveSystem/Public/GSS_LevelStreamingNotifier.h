// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelStreaming.h"
#include "GSS_LevelStreamingNotifier.generated.h"


DECLARE_DELEGATE_OneParam(FLevelNotifierLoaded,   ULevelStreaming* );
DECLARE_DELEGATE_OneParam(FLevelNotifierUnloaded, ULevelStreaming* );
DECLARE_DELEGATE_OneParam(FLevelNotifierShown,    ULevelStreaming* );
DECLARE_DELEGATE_OneParam(FLevelNotifierHidden,   ULevelStreaming* );


/** ULevelStreamingNotifier is an adapter that expands UE4's native
 * level streaming delegates adding a ptr to the level to each delegate
 */
UCLASS(ClassGroup = GenericSaveSystem, Transient)
class GENERICSAVESYSTEM_API UGSS_LevelStreamingNotifier : public UObject
{
	GENERATED_BODY()

public:

	void SetLevelStreaming(ULevelStreaming* InLevelStreaming)
	{
		UnBind();

		LevelStreaming = InLevelStreaming;

		if (IsValid(InLevelStreaming))
		{
			InLevelStreaming->OnLevelLoaded.AddDynamic(this, &UGSS_LevelStreamingNotifier::OnLoaded);
			InLevelStreaming->OnLevelUnloaded.AddDynamic(this, &UGSS_LevelStreamingNotifier::OnUnloaded);
			InLevelStreaming->OnLevelShown.AddDynamic(this, &UGSS_LevelStreamingNotifier::OnShown);
			InLevelStreaming->OnLevelHidden.AddDynamic(this, &UGSS_LevelStreamingNotifier::OnHidden);
		}
	}

	FLevelNotifierLoaded&   OnLevelLoaded()   { return LoadedDelegate;   }
	FLevelNotifierUnloaded& OnLevelUnloaded() { return UnloadedDelegate; }
	FLevelNotifierShown&    OnLevelShown()    { return ShownDelegate;    }
	FLevelNotifierHidden&   OnLevelHidden()   { return HiddenDelegate;   }

private:

	void UnBind()
	{
		if (LevelStreaming.IsValid())
		{
			ULevelStreaming* Level = LevelStreaming.Get();

			Level->OnLevelLoaded.RemoveDynamic(this, &UGSS_LevelStreamingNotifier::OnLoaded);
			Level->OnLevelUnloaded.RemoveDynamic(this, &UGSS_LevelStreamingNotifier::OnUnloaded);
			Level->OnLevelShown.RemoveDynamic(this, &UGSS_LevelStreamingNotifier::OnShown);
			Level->OnLevelHidden.RemoveDynamic(this, &UGSS_LevelStreamingNotifier::OnHidden);
		}
	}

	virtual void BeginDestroy() override
	{
		UnBind();
		Super::BeginDestroy();
	}


	// Associated Level Streaming
	TWeakObjectPtr<ULevelStreaming> LevelStreaming;

	FLevelNotifierLoaded   LoadedDelegate;
	FLevelNotifierUnloaded UnloadedDelegate;
	FLevelNotifierShown    ShownDelegate;
	FLevelNotifierHidden   HiddenDelegate;


	UFUNCTION()
	void OnLoaded() {
		LoadedDelegate.ExecuteIfBound(LevelStreaming.Get());
	}

	UFUNCTION()
	void OnUnloaded() {
		UnloadedDelegate.ExecuteIfBound(LevelStreaming.Get());
	}

	UFUNCTION()
	void OnShown() {
		ShownDelegate.ExecuteIfBound(LevelStreaming.Get());
	}

	UFUNCTION()
	void OnHidden() {
		HiddenDelegate.ExecuteIfBound(LevelStreaming.Get());
	}
};
