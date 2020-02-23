cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Release)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(EP_DEPENDENCIES_PATH "${CMAKE_BINARY_DIR}/Dependencies")

# Project Properties
set(PROJECT_NAME         "HLS_Recorder")
set(PROJECT_VERSION      "1.0.0")
set(PROJECT_AUTHOR_NAME  "Albert Grigoryan")
set(PROJECT_AUTHOR_EMAIL "albert_grigoryan@yahoo.com")

# Configurable Options
option(BUILD_TESTS "Build unit test suite"      ON)
option(BUILD_DOCS "Build Doxygen documentation" ON)

if (DEFINED BUILD_TESTS)
  add_subdirectory(third_party/gtest)
  add_subdirectory(test)
endif()
if (DEFINED BUILD_DOCS)
  add_subdirectory(third_party/doxygen)
  add_subdirectory(docs)
endif()

add_subdirectory(third_party/opencv)
add_subdirectory(third_party/served)
add_subdirectory(src)
