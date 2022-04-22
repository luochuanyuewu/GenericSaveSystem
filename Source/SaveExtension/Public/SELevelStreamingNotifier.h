// Copyright 2015-2020 Piperift. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelStreaming.h"
#include "SELevelStreamingNotifier.generated.h"


DECLARE_DELEGATE_OneParam(FLevelNotifierLoaded,   ULevelStreaming* );
DECLARE_DELEGATE_OneParam(FLevelNotifierUnloaded, ULevelStreaming* );
DECLARE_DELEGATE_OneParam(FLevelNotifierShown,    ULevelStreaming* );
DECLARE_DELEGATE_OneParam(FLevelNotifierHidden,   ULevelStreaming* );


/** ULevelStreamingNotifier is an adapter that expands UE4's native
 * level streaming delegates adding a ptr to the level to each delegate
 */
UCLASS(ClassGroup = SaveExtension, Transient)
class SAVEEXTENSION_API USELevelStreamingNotifier : public UObject
{
	GENERATED_BODY()

public:

	void SetLevelStreaming(ULevelStreaming* InLevelStreaming)
	{
		UnBind();

		LevelStreaming = InLevelStreaming;

		if (IsValid(InLevelStreaming))
		{
			InLevelStreaming->OnLevelLoaded.AddDynamic(this, &USELevelStreamingNotifier::OnLoaded);
			InLevelStreaming->OnLevelUnloaded.AddDynamic(this, &USELevelStreamingNotifier::OnUnloaded);
			InLevelStreaming->OnLevelShown.AddDynamic(this, &USELevelStreamingNotifier::OnShown);
			InLevelStreaming->OnLevelHidden.AddDynamic(this, &USELevelStreamingNotifier::OnHidden);
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

			Level->OnLevelLoaded.RemoveDynamic(this, &USELevelStreamingNotifier::OnLoaded);
			Level->OnLevelUnloaded.RemoveDynamic(this, &USELevelStreamingNotifier::OnUnloaded);
			Level->OnLevelShown.RemoveDynamic(this, &USELevelStreamingNotifier::OnShown);
			Level->OnLevelHidden.RemoveDynamic(this, &USELevelStreamingNotifier::OnHidden);
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
