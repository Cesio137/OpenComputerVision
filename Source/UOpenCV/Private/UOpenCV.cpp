// Copyright Epic Games, Inc. All Rights Reserved.

#include "UOpenCV.h"
#include "Core.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "opencv2/core.hpp"

using namespace cv;

#define LOCTEXT_NAMESPACE "FUOpenCVModule"

void FUOpenCVModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// Get the base directory of this plugin
	FString BaseDir = IPluginManager::Get().FindPlugin("UOpenCV")->GetBaseDir();

	// Add on the relative location of the third party dll and load it
	FString opencv_world;
	FString opencv_world_d;
	FString opencv_videoio;
	FString opencv_videoio_d;
	FString opencv_videoio_ffmpeg;
#if PLATFORM_WINDOWS && UE_BUILD_DEBUG
	opencv_world_d = FPaths::Combine(*BaseDir, TEXT("Binaries/ThirdParty/UOpenCVLibrary/Win64/opencv_world460d.dll"));
	opencv_videoio_d = FPaths::Combine(*BaseDir, TEXT("Binaries/ThirdParty/UOpenCVLibrary/Win64/opencv_videoio_msmf460_64d.dll"));
	opencv_videoio_ffmpeg = FPaths::Combine(*BaseDir, TEXT("Binaries/ThirdParty/UOpenCVLibrary/Win64/opencv_videoio_ffmpeg460_64.dll"));

	opencv_world_dLibraryHandle = !opencv_world_d.IsEmpty() ? FPlatformProcess::GetDllHandle(*opencv_world_d) : nullptr;
	opencv_videoio_dLibraryHandle = !opencv_videoio_d.IsEmpty() ? FPlatformProcess::GetDllHandle(*opencv_videoio_d) : nullptr;
	opencv_videoio_ffmpegLibraryHandle = !opencv_videoio_ffmpeg.IsEmpty() ? FPlatformProcess::GetDllHandle(*opencv_videoio_ffmpeg) : nullptr;

	if (opencv_world_dLibraryHandle && opencv_videoio_dLibraryHandle && opencv_videoio_ffmpegLibraryHandle)
	{
		// Call the test function in the third party library that opens a message box
		FString msg = "Loaded OpenCVLibrary_Debug " + FString::FromInt(cv::getVersionMajor())+"."+FString::FromInt(cv::getVersionMinor())+"."+FString::FromInt(cv::getVersionRevision());
		FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(msg));
	}
	else
	{
		FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("OpenCVLibraryError", "Failed to load OpenCV library"));
	}

#elif PLATFORM_WINDOWS && !UE_BUILD_DEBUG
	opencv_world = FPaths::Combine(*BaseDir, TEXT("Binaries/ThirdParty/UOpenCVLibrary/Win64/opencv_world460.dll"));
	opencv_videoio = FPaths::Combine(*BaseDir, TEXT("Binaries/ThirdParty/UOpenCVLibrary/Win64/opencv_videoio_msmf460_64.dll"));
	opencv_videoio_ffmpeg = FPaths::Combine(*BaseDir, TEXT("Binaries/ThirdParty/UOpenCVLibrary/Win64/opencv_videoio_ffmpeg460_64.dll"));
	
	opencv_worldLibraryHandle = !opencv_world.IsEmpty() ? FPlatformProcess::GetDllHandle(*opencv_world) : nullptr;
	opencv_videoioLibraryHandle = !opencv_videoio.IsEmpty() ? FPlatformProcess::GetDllHandle(*opencv_videoio) : nullptr;
	opencv_videoio_ffmpegLibraryHandle = !opencv_videoio_ffmpeg.IsEmpty() ? FPlatformProcess::GetDllHandle(*opencv_videoio_ffmpeg) : nullptr;

	if (opencv_worldLibraryHandle && opencv_videoioLibraryHandle && opencv_videoio_ffmpegLibraryHandle)
	{
		// Call the test function in the third party library that opens a message box
		FString msg = "Loaded OpenCVLibrary " + FString::FromInt(cv::getVersionMajor())+"."+FString::FromInt(cv::getVersionMinor())+"."+FString::FromInt(cv::getVersionRevision());
		FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(msg));
	}
	else
	{
		FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("OpenCVLibraryError", "Failed to load OpenCV library"));
	}

#endif // PLATFORM_WINDOWS
	
}

void FUOpenCVModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	// Free the dll handle
#if PLATFORM_WINDOWS && UE_BUILD_DEBUG

	FPlatformProcess::FreeDllHandle(opencv_world_dLibraryHandle);
	opencv_world_dLibraryHandle = nullptr;

	FPlatformProcess::FreeDllHandle(opencv_videoio_dLibraryHandle);
	opencv_videoio_dLibraryHandle = nullptr;
	
	FPlatformProcess::FreeDllHandle(opencv_videoio_ffmpegLibraryHandle);
	opencv_videoio_ffmpegLibraryHandle = nullptr;

#elif PLATFORM_WINDOWS && !UE_BUILD_DEBUG

	FPlatformProcess::FreeDllHandle(opencv_worldLibraryHandle);
	opencv_worldLibraryHandle = nullptr;

	FPlatformProcess::FreeDllHandle(opencv_videoioLibraryHandle);
	opencv_videoioLibraryHandle = nullptr;

	FPlatformProcess::FreeDllHandle(opencv_videoio_ffmpegLibraryHandle);
	opencv_videoio_ffmpegLibraryHandle = nullptr;

#endif 
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FUOpenCVModule, UOpenCV)
