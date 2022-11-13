// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OpenCVData.h"
#pragma push_macro("check")
#undef check
#include "OpenCV/library.h"
#pragma pop_macro("check")
#include "OpenCV.generated.h"

using namespace opencv;

/**
 * 
 */
UCLASS(Blueprintable)
class OPENCOMPUTERVISION_API UOpenCV : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category ="OpenCV || OpenCL || Context")
	bool CreateContext(EDeviceType Type);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "OpenCV || OpenCL || Device")
	int GetDeviceCount();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "OpenCV || OpenCL || Device")
	FCVOpenCLDevice GetDeviceInfo(int Index);

private:
	
};
