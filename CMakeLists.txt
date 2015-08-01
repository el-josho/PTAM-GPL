cmake_minimum_required(VERSION 2.8)

project(PTAM-SLAM)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(OpenGL REQUIRED)

find_library(CVD_LIBRARY
    NAMES libcvd.so
    )

# TODO automatically locate include directories
set(TOON_INCLUDE_DIR /usr/include/TooN/)
set(CVD_INCLUDE_DIR /usr/include/cvd/)

include_directories(
    "Src/"
    ${OPENGL_INCLUDE_DIRS}
    ${TOON_INCLUDE_DIR}
    ${CVD_INCLUDE_DIR}
)

add_executable(ptam
    "Src/main.cc"
    )

set(LIBS ${CVD_LIBRARY} ${OPENGL_LIBRARIES})

target_link_libraries(ptam ${LIBS})
