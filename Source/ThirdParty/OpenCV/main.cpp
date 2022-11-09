#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core/ocl.hpp"
#include "opencv2/core/cuda.hpp"

using namespace cv;
using namespace std;

int main() {
    cv::ocl::Context context;
    std::cout << context.create(cv::ocl::Device::TYPE_ALL) << std::endl;
    std::cout << "Devices: " << context.ndevices() << std::endl;

    for (int i = 0; i < context.ndevices(); i++)
    {
        cv::ocl::Device device = context.device(i);
        std::cout << "Name:           " << device.name().c_str() << std::endl;
        std::cout << "Avaliable:      " << device.available() << std::endl;
        std::cout << "Driver Version: " << device.driverVersion().c_str() << std::endl;
        std::cout << "OpenCL Version: " << device.OpenCLVersion() << std::endl;
        std::cout << "VRAM:           " << device.globalMemSize() << std::endl;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
