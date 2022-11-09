// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OpenCVObject.h"
#include "Components/ActorComponent.h"
#include "OpenCVActorComponent.generated.h"


UCLASS( Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UOPENCV_API UOpenCVActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenCVActorComponent();

protected:
	// Called before the game starts
	virtual void InitializeComponent() override;
	
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadOnly, Category="OpenCVActorComponent || OpenCV")
	UOpenCVObject* OpenCV;
};
