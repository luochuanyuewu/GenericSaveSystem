// Copyright 2015-2020 Piperift. All Rights Reserved.

#pragma once

#include "ISaveExtension.h"


class FSaveExtension : public ISaveExtension
{
public:

	virtual void StartupModule() override {}
	virtual void ShutdownModule() override {}

	virtual bool SupportsDynamicReloading() override { return true; }
};
