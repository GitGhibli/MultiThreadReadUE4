// Copyright (c) 2018 Isara Technologies. All Rights Reserved.

#pragma once

#include "ModuleManager.h"

class FShapefileLibModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};