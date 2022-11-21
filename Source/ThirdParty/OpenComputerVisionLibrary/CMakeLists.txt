cmake_minimum_required(VERSION 3.20)
project(opencv)

set(CMAKE_CXX_STANDARD 14)


add_library(opencv SHARED OpenCVLibrary.h OpenCVLibrary.cpp)

target_include_directories(opencv PUBLIC ${CMAKE_SOURCE_DIR}/Win64/include)
target_link_libraries(opencv ${CMAKE_SOURCE_DIR}/Win64/lib/opencv_world460.lib ${CMAKE_SOURCE_DIR}/Win64/lib/opencv_world460d.lib)

add_custom_command(TARGET opencv POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:opencv> ${CMAKE_SOURCE_DIR}/../../../Binaries/ThirdParty/OpenComputerVisionLibrary/Win64/opencv.dll
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE_DIR:opencv>/opencv.lib ${CMAKE_SOURCE_DIR}/Win64/lib/opencv.lib
        )