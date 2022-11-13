// Copyright Epic Games, Inc. All Rights Reserved.

#include "OpenComputerVision.h"
#include "Core.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"

#pragma push_macro("check")
#undef check
#include "OpenCV/library.h"
#pragma pop_macro("check")

#define LOCTEXT_NAMESPACE "FOpenComputerVisionModule"

using namespace opencv;

void FOpenComputerVisionModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// Get the base directory of this plugin
	FString BaseDir = IPluginManager::Get().FindPlugin("OpenComputerVision")->GetBaseDir();

	// Add on the relative location of the third party dll and load it
	FString LibraryPath;
	FString opencv_world;
	FString opencv_videoio;
	FString opencv_videoio_ffmpeg;
#if PLATFORM_WINDOWS && UE_BUILD_DEBUG
	LibraryPath = FPaths::Combine(*BaseDir, TEXT("Binaries/ThirdParty/OpenComputerVisionLibrary/Win64/OpenCV.dll"));
	opencv_world = FPaths::Combine(*BaseDir, TEXT("Binaries/ThirdParty/OpenComputerVisionLibrary/Win64/opencv_world460d.dll"));
	opencv_videoio = FPaths::Combine(*BaseDir, TEXT("Binaries/ThirdParty/OpenComputerVisionLibrary/Win64/opencv_videoio_msmf460_64d.dll"));
	opencv_videoio_ffmpeg = FPaths::Combine(*BaseDir, TEXT("Binaries/ThirdParty/OpenComputerVisionLibrary/Win64/opencv_videoio_ffmpeg460_64.dll"));
#elif PLATFORM_WINDOWS && !UE_BUILD_DEBUG
	LibraryPath = FPaths::Combine(*BaseDir, TEXT("Binaries/ThirdParty/OpenComputerVisionLibrary/Win64/OpenCV.dll"));
	opencv_world = FPaths::Combine(*BaseDir, TEXT("Binaries/ThirdParty/OpenComputerVisionLibrary/Win64/opencv_world460.dll"));
	opencv_videoio = FPaths::Combine(*BaseDir, TEXT("Binaries/ThirdParty/OpenComputerVisionLibrary/Win64/opencv_videoio_msmf460_64.dll"));
	opencv_videoio_ffmpeg = FPaths::Combine(*BaseDir, TEXT("Binaries/ThirdParty/OpenComputerVisionLibrary/Win64/opencv_videoio_ffmpeg460_64.dll"));
#endif // PLATFORM_WINDOWS

	OpenCVLibraryHandle = !LibraryPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*LibraryPath) : nullptr;
	opencv_worldLibraryHandle = !opencv_world.IsEmpty() ? FPlatformProcess::GetDllHandle(*opencv_world) : nullptr;
	opencv_videoioLibraryHandle = !opencv_videoio.IsEmpty() ? FPlatformProcess::GetDllHandle(*opencv_videoio) : nullptr;
	opencv_videoio_ffmpegLibraryHandle = !opencv_videoio_ffmpeg.IsEmpty() ? FPlatformProcess::GetDllHandle(*opencv_videoio_ffmpeg) : nullptr;

	if (OpenCVLibraryHandle && opencv_worldLibraryHandle && opencv_videoioLibraryHandle && opencv_videoio_ffmpegLibraryHandle )
	{
		// Call the test function in the third party library that opens a message box
		UOpenCVLibrary();
	}
	else
	{
		FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("OpenCV Library Error", "Failed to load OpenCV third party library"));
	}
}

void FOpenComputerVisionModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	// Free the dll handle
	FPlatformProcess::FreeDllHandle(OpenCVLibraryHandle);
	OpenCVLibraryHandle = nullptr;

	FPlatformProcess::FreeDllHandle(opencv_worldLibraryHandle);
	opencv_worldLibraryHandle = nullptr;

	FPlatformProcess::FreeDllHandle(opencv_videoioLibraryHandle);
	opencv_videoioLibraryHandle = nullptr;

	FPlatformProcess::FreeDllHandle(opencv_videoio_ffmpegLibraryHandle);
	opencv_videoio_ffmpegLibraryHandle = nullptr;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FOpenComputerVisionModule, OpenComputerVision)
