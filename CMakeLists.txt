cmake_minimum_required(VERSION 2.8)

project(PTAM-SLAM)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

find_package(GVars3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(CVD REQUIRED)
find_package(TooN REQUIRED)
find_package(OpenCV REQUIRED)

include_directories(
    include/
    ${GVARS3_INCLUDE_DIRS}
    ${OPENGL_INCLUDE_DIRS}
    ${CVD_INCLUDE_DIRS}
    ${TOON_INCLUDE_DIRS}
    )

add_subdirectory(apps)
