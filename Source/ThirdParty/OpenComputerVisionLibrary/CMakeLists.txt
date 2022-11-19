cmake_minimum_required(VERSION 3.20)
project(OpenCVLibrary)

set(CMAKE_CXX_STANDARD 14)


add_library(OpenCVLibrary SHARED OpenCVLibrary.h OpenCVLibrary.cpp)

target_include_directories(OpenCVLibrary PUBLIC ${CMAKE_SOURCE_DIR}/Win64/include)
target_link_libraries(OpenCVLibrary ${CMAKE_SOURCE_DIR}/Win64/lib/opencv_world460.lib ${CMAKE_SOURCE_DIR}/Win64/lib/opencv_world460d.lib)

add_custom_command(TARGET OpenCVLibrary POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:OpenCVLibrary> ${CMAKE_SOURCE_DIR}/../../../Binaries/ThirdParty/OpenComputerVisionLibrary/Win64/OpenCVLibrary.dll
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE_DIR:OpenCVLibrary>/OpenCVLibrary.lib ${CMAKE_SOURCE_DIR}/Win64/lib/OpenCVLibrary.lib
        )