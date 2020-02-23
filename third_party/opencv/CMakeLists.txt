cmake_minimum_required(VERSION 2.8)
include(ExternalProject)

set(OPENCV_VERSION 3.4.6)
message (STATUS "Adding OpenCV ${OPENCV_VERSION} as an external project.")

ExternalProject_Add(opencv_contrib
  URL https://github.com/opencv/opencv_contrib/archive/3.4.9.tar.gz
  PREFIX ${EP_DEPENDENCIES_PATH}/opencv_contrib
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ""
  INSTALL_COMMAND ""
)
ExternalProject_Get_Property(opencv_contrib source_dir)
set(opencv_contrib_modules_dir ${source_dir}/modules)

ExternalProject_Add(opencv
  URL https://github.com/opencv/opencv/archive/${OPENCV_VERSION}.tar.gz
  CMAKE_ARGS
    "-DCMAKE_INSTALL_PREFIX=${EP_DEPENDENCIES_PATH}/opencv"
    "-DOPENCV_EXTRA_MODULES_PATH=${opencv_contrib_modules_dir}"
    "-DCMAKE_BUILD_TYPE:STRING=Release"
    "-DBUILD_EXAMPLES:BOOL=OFF"
    "-DBUILD_TESTS:BOOL=OFF"
    "-DBUILD_opencv_calib3d:BOOL=ON"
    "-DBUILD_opencv_ccalib:BOOL=ON"
    "-DBUILD_opencv_core:BOOL=ON"
    "-DBUILD_opencv_dnn_objdetect:BOOL=ON"
    "-DBUILD_opencv_features2d:BOOL=ON"
    "-DBUILD_opencv_highgui:BOOL=ON"
    "-DBUILD_opencv_imgcodecs:BOOL=ON"
    "-DBUILD_opencv_imgproc:BOOL=ON"
    "-DBUILD_opencv_photo:BOOL=ON"
    "-DBUILD_opencv_video:BOOL=ON"
    "-DBUILD_opencv_videoio:BOOL=ON"
    "-DBUILD_opencv_ximgproc:BOOL=ON"
    "-DBUILD_opencv_xphoto:BOOL=ON"
    "-DBUILD_opencv_aruco:BOOL=OFF"
    "-DBUILD_opencv_bgsegm:BOOL=OFF"
    "-DBUILD_opencv_bioinspired:BOOL=OFF"
    "-DBUILD_opencv_datasets:BOOL=OFF"
    "-DBUILD_opencv_dnn:BOOL=OFF"
    "-DBUILD_opencv_dpm:BOOL=OFF"
    "-DBUILD_opencv_face:BOOL=OFF"
    "-DBUILD_opencv_flann:BOOL=OFF"
    "-DBUILD_opencv_freetype:BOOL=OFF"
    "-DBUILD_opencv_fuzzy:BOOL=OFF"
    "-DBUILD_opencv_hdf:BOOL=OFF"
    "-DBUILD_opencv_hfs:BOOL=OFF"
    "-DBUILD_opencv_img_hash:BOOL=OFF"
    "-DBUILD_opencv_java_bindings_generator:BOOL=OFF"
    "-DBUILD_opencv_line_descriptor:BOOL=OFF"
    "-DBUILD_opencv_ml:BOOL=OFF"
    "-DBUILD_opencv_objdetect:BOOL=OFF"
    "-DBUILD_opencv_optflow:BOOL=OFF"
    "-DBUILD_opencv_phase_unwrapping:BOOL=OFF"
    "-DBUILD_opencv_plot:BOOL=OFF"
    "-DBUILD_opencv_python_bindings_generator:BOOL=OFF"
    "-DBUILD_opencv_python_tests:BOOL=OFF"
    "-DBUILD_opencv_reg:BOOL=OFF"
    "-DBUILD_opencv_rgbd:BOOL=OFF"
    "-DBUILD_opencv_saliency:BOOL=OFF"
    "-DBUILD_opencv_sfm:BOOL=OFF"
    "-DBUILD_opencv_shape:BOOL=OFF"
    "-DBUILD_opencv_stereo:BOOL=OFF"
    "-DBUILD_opencv_stitching:BOOL=OFF"
    "-DBUILD_opencv_structured_light:BOOL=OFF"
    "-DBUILD_opencv_superres:BOOL=OFF"
    "-DBUILD_opencv_surface_matching:BOOL=OFF"
    "-DBUILD_opencv_text:BOOL=OFF"
    "-DBUILD_opencv_tracking:BOOL=OFF"
    "-DBUILD_opencv_videostab:BOOL=OFF"
    "-DBUILD_opencv_world:BOOL=OFF"
    "-DBUILD_opencv_xfeatures2d:BOOL=OFF"
    "-DBUILD_opencv_xobjdetect:BOOL=OFF"
)

set(OpenCV_INCLUDE_DIR ${EP_DEPENDENCIES_PATH}/opencv/include PARENT_SCOPE)
set(OpenCV_LIB_DIR ${EP_DEPENDENCIES_PATH}/opencv/lib PARENT_SCOPE)
set(OpenCV_LIBRARIES 
  -lopencv_video 
  -lopencv_ccalib 
  -lopencv_ximgproc
  -lopencv_calib3d 
  -lopencv_features2d 
  -lopencv_highgui
  -lopencv_videoio
  -lopencv_imgcodecs
  -lopencv_xphoto
  -lopencv_photo
  -lopencv_imgproc
  -lopencv_core PARENT_SCOPE
)

add_library(lib_opencv SHARED IMPORTED)

set_target_properties(lib_opencv PROPERTIES IMPORTED_LOCATION
    ${GTEST_LIB_DIR}/libopencv_core.so
)
