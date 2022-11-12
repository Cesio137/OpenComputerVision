// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#pragma push_macro("check")
#undef check
#include "OpenCV/library.h"
#include "opencv2/core.hpp"
#include "opencv2/core/ocl.hpp"
#pragma pop_macro("check")
#include "OpenCV.generated.h"

using namespace cv;

/**
 * 
 */
UCLASS()
class OPENCOMPUTERVISION_API UOpenCV : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="OpenCV || OpenCL || info")
	int GetDeviceCount();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "OpenCV || OpenCL || Context")
	bool CreateContext();

private:
	
};
