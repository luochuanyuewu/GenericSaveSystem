// Copyright 2020-2024 luochuanyuewu. All Rights Reserved.

#pragma once

#include "IGenericSaveSystem.h"

class FGenericSaveSystem : public IGenericSaveSystem
{
public:
	virtual void StartupModule() override {}
	virtual void ShutdownModule() override {}

	virtual bool SupportsDynamicReloading() override { return true; }
};
