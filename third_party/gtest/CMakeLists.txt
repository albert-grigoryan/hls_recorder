cmake_minimum_required(VERSION 2.8)
include(ExternalProject)

set(GTEST_VERSION 1.10.0)
message (STATUS "Adding GTest ${GTEST_VERSION} as an external project.")

ExternalProject_Add(gtest
  URL https://github.com/google/googletest/archive/release-${GTEST_VERSION}.tar.gz
  CMAKE_ARGS
    "-DCMAKE_INSTALL_PREFIX=${EP_DEPENDENCIES_PATH}/gtest"
    "-DCMAKE_BUILD_TYPE:STRING=Release"
)

set(GTEST_INCLUDE_DIR ${EP_DEPENDENCIES_PATH}/gtest/include PARENT_SCOPE)
set(GTEST_LIB_DIR ${EP_DEPENDENCIES_PATH}/gtest/lib PARENT_SCOPE)

add_library(lib_gtest STATIC IMPORTED)
add_library(lib_gmock STATIC IMPORTED)

set_target_properties(lib_gtest PROPERTIES IMPORTED_LOCATION
    ${GTEST_LIB_DIR}/libgtest.a
)
set_target_properties(lib_gmock PROPERTIES IMPORTED_LOCATION
    ${GTEST_LIB_DIR}/libgmock.a
)
