// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FUOpenCVModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	/** Handle to the test dll we will load */
	void*	opencv_worldLibraryHandle;
	void*	opencv_world_dLibraryHandle;
	void*	opencv_videoioLibraryHandle;
	void*	opencv_videoio_dLibraryHandle;
	void*	opencv_videoio_ffmpegLibraryHandle;
};
