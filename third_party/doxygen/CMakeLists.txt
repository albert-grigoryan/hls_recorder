cmake_minimum_required(VERSION 2.8)
include(ExternalProject)

set(DOXYGEN_VERSION 1_8_17)
message (STATUS "Adding Doxygen ${DOXYGEN_VERSION} as an external project.")

ExternalProject_Add(doxygen
  URL https://github.com/doxygen/doxygen/archive/Release_${DOXYGEN_VERSION}.tar.gz
  CMAKE_ARGS
    "-DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/Dependencies/doxygen"
    "-DCMAKE_BUILD_TYPE:STRING=Release"
)

set(DOXYGEN_EXECUTABLE ${EP_DEPENDENCIES_PATH}/doxygen/bin/doxygen PARENT_SCOPE)
