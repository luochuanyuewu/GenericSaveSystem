// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#pragma once

#include "UObject/Interface.h"

#include "GSS_LevelFilter.h"
#include "GSS_SaveInterface.generated.h"

UINTERFACE(BlueprintType)
class GENERICSAVESYSTEM_API UGSS_SaveInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class GENERICSAVESYSTEM_API IGSS_SaveInterface
{

	GENERATED_BODY()

public:
	/** BP API **/

	// Event called when Save process starts
	UFUNCTION(Category = Save, BlueprintImplementableEvent, meta = (DisplayName = "On Save Began"))
	void ReceiveOnSaveBegan();

	// Event called when Save process ends
	UFUNCTION(Category = Save, BlueprintImplementableEvent, meta = (DisplayName = "On Save Finished"))
	void ReceiveOnSaveFinished(bool bError);

	// Event called when Load process starts
	UFUNCTION(Category = Save, BlueprintImplementableEvent, meta = (DisplayName = "On Load Began"))
	void ReceiveOnLoadBegan();

	// Event called when Load process ends
	UFUNCTION(Category = Save, BlueprintImplementableEvent, meta = (DisplayName = "On Load Finished"))
	void ReceiveOnLoadFinished(bool bError);

	/** C++ API **/

	// Event called when Save process starts
	virtual void OnSaveBegan() {}

	// Event called when Save process ends
	virtual void OnSaveFinished(bool bError) {}

	// Event called when Load process starts
	virtual void OnLoadBegan() {}

	// Event called when Load process ends
	virtual void OnLoadFinished(bool bError) {}
};
