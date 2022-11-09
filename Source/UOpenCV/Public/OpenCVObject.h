// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OpenCVData.h"
#include "opencv2/core.hpp"
#include "opencv2/core/ocl.hpp"
#include "OpenCVObject.generated.h"

using namespace cv;

/**
 * 
 */
UCLASS(Blueprintable)
class UOPENCV_API UOpenCVObject : public UObject
{
	GENERATED_BODY()
	UOpenCVObject();

	class FOpenCL
	{
		FOpenCL();
		
	public:
		/*OPENCL*/
		UFUNCTION(BlueprintCallable, Category="OpenCV || OpenCL")
		bool CreateOpenCLContext(EDeviceType Type);
	
		UFUNCTION(BlueprintCallable, Category="OpenCV || OpenCL")
		void SetUseOpenCL(bool flag);

		UFUNCTION(BlueprintCallable, BlueprintPure, Category="OpenCV || OpenCL")
		bool GetUseOpenCL();

		UFUNCTION(BlueprintCallable, BlueprintPure, Category="OpenCV || info")
		int GetNDevices();

		UFUNCTION(BlueprintCallable, BlueprintPure, Category="OpenCV || info")
		FCVOpenCLDevice GetDeviceByID(int Index);

		UFUNCTION(BlueprintCallable, BlueprintPure, Category="OpenCV || info")
		FString GetOpenCVVersion();

	private:
		ocl::Context CVContext;
		ocl::Device CVDevice;
		
	};

public:

	
private:
	
};
