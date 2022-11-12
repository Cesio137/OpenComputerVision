// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FOpenComputerVisionModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	/** Handle to the test dll we will load */
	void* OpenCVLibraryHandle;
	void* opencv_worldLibraryHandle;
	void* opencv_videoioLibraryHandle;
	void* opencv_videoio_ffmpegLibraryHandle;
};
