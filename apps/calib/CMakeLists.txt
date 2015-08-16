file(GLOB_RECURSE CALIB_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    "src/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/ATANCamera.cpp"
    "${CMAKE_SOURCE_DIR}/src/GLWindow2.cpp"
    "${CMAKE_SOURCE_DIR}/src/GLWindowMenu.cpp"
    "${CMAKE_SOURCE_DIR}/src/VideoOpenCVSource.cpp"
	)

add_executable(CameraCalibrator
    ${CALIB_SOURCES}
    )

target_include_directories(CameraCalibrator PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/include")

set(CALIB_LIBS
    ${GVARS3_LIBRARIES}
    ${OPENGL_LIBRARIES}
    ${CVD_LIBRARIES}
    ${TOON_LIBRARIES}
    ${OpenCV_LIBS}
    )

target_link_libraries(CameraCalibrator ${CALIB_LIBS})

install(
    TARGETS CameraCalibrator
    DESTINATION "${CMAKE_SOURCE_DIR}/bin"
    )
