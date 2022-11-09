cmake_minimum_required(VERSION 3.23)
project(OpenCV)

set(CMAKE_CXX_STANDARD 17)

add_executable(OpenCV main.cpp)

if(WIN32)
    target_include_directories(OpenCV PUBLIC ${CMAKE_SOURCE_DIR}/Win64/include)
    target_link_libraries(OpenCV ${CMAKE_SOURCE_DIR}/Win64/lib/opencv_world460.lib ${CMAKE_SOURCE_DIR}/Win64/lib/opencv_world460d.lib)
endif()
