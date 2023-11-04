// Copyright 2015-2019 Piperift. All Rights Reserved
#pragma once

#include "CoreMinimal.h"
#include "Serialization/ObjectAndNameAsStringProxyArchive.h"


/** Serializes world data */
struct GENERICSAVESYSTEM_API FGSS_Archive : public FObjectAndNameAsStringProxyArchive
{
public:

	FGSS_Archive(FArchive &InInnerArchive, bool bInLoadIfFindFails)
		: FObjectAndNameAsStringProxyArchive(InInnerArchive,bInLoadIfFindFails)
	{
		ArIsSaveGame = true;
		ArNoDelta = true;
	}

	virtual FArchive& operator<<(UObject*& Obj) override;
};
