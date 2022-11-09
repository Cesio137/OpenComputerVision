// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenCVActorComponent.h"

// Sets default values for this component's properties
UOpenCVActorComponent::UOpenCVActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UOpenCVActorComponent::InitializeComponent()
{
	Super::InitializeComponent();
	OpenCV = NewObject<UOpenCVObject>(this, UOpenCVObject::StaticClass(), FName("OpenCV"));
}


// Called when the game starts
void UOpenCVActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UOpenCVActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

