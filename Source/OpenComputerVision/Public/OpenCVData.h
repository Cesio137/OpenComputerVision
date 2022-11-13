// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OpenCVData.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum EDeviceType
{
	TYPE_DEFAULT     UMETA(DisplayName = "Default"),
	TYPE_CPU         UMETA(DisplayName = "CPU"),
	TYPE_GPU         UMETA(DisplayName = "GPU"),
	TYPE_ACCELERATOR UMETA(DisplayName = "Accelerator"),
	TYPE_DGPU        UMETA(DisplayName = "DGPU"),
	TYPE_IGPU        UMETA(DisplayName = "IGPU"),
	TYPE_ALL         UMETA(DisplayName = "ALL"),
};

USTRUCT(BlueprintType)
struct FCVOpenCLDevice
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FString DeviceName;

	UPROPERTY(BlueprintReadWrite)
	FString VendorName;

	UPROPERTY(BlueprintReadWrite)
	bool bIsAvaliable;

	UPROPERTY(BlueprintReadWrite)
	bool bHasImageSuport;

	UPROPERTY(BlueprintReadWrite)
	FString OpenCLVersion;

	UPROPERTY(BlueprintReadWrite)
	FString DriverVersion;

	UPROPERTY(BlueprintReadWrite)
	int Index;

};
