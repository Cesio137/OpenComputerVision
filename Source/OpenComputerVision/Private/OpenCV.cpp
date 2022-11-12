// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenCV.h"

int UOpenCV::GetDeviceCount()
{
	return context.ndevices();
}

bool UOpenCV::CreateContext()
{
	return context.create(device.TYPE_ALL);
}
