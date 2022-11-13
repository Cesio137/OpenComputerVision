// Fill out your copyright notice in the Description page of Project Settings.context()


#include "OpenCV.h"

bool UOpenCV::CreateContext(EDeviceType Type)
{
	switch (Type)
	{
	case EDeviceType::TYPE_DEFAULT:
		return opencl::context.create(opencl::device.TYPE_DEFAULT);

	case EDeviceType::TYPE_CPU:
		return opencl::context.create(opencl::device.TYPE_CPU);

	case EDeviceType::TYPE_GPU:
		return opencl::context.create(opencl::device.TYPE_GPU);

	case EDeviceType::TYPE_ACCELERATOR:
		return opencl::context.create(opencl::device.TYPE_ACCELERATOR);

	case EDeviceType::TYPE_DGPU:
		return opencl::context.create(opencl::device.TYPE_DGPU);

	case EDeviceType::TYPE_IGPU:
		return opencl::context.create(opencl::device.TYPE_IGPU);

	case EDeviceType::TYPE_ALL:
		return opencl::context.create(opencl::device.TYPE_ALL);
	}

	return opencl::context.create(opencl::device.TYPE_DEFAULT);
}

int UOpenCV::GetDeviceCount()
{
	return opencl::context.ndevices();
}

FCVOpenCLDevice UOpenCV::GetDeviceInfo(int Index)
{
	FCVOpenCLDevice deviceinfo;

	deviceinfo.DeviceName = ANSI_TO_TCHAR(opencl::context.device(Index).name().c_str());
	deviceinfo.VendorName = ANSI_TO_TCHAR(opencl::context.device(Index).vendorName().c_str());
	deviceinfo.bIsAvaliable = opencl::context.device(Index).available();
	deviceinfo.bHasImageSuport = opencl::context.device(Index).imageSupport();
	deviceinfo.OpenCLVersion = ANSI_TO_TCHAR(opencl::context.device(Index).OpenCLVersion().c_str());
	deviceinfo.DriverVersion = ANSI_TO_TCHAR(opencl::context.device(Index).driverVersion().c_str());
	deviceinfo.Index = Index;

	

	return deviceinfo;
}
