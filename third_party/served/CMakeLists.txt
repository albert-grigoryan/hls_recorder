cmake_minimum_required(VERSION 2.8)
include(ExternalProject)

set(SERVED_VERSION 1.6.0)
message (STATUS "Adding Served ${SERVED_VERSION} as an external project.")

ExternalProject_Add(served
  URL https://github.com/meltwater/served/archive/v${SERVED_VERSION}.tar.gz
  CMAKE_ARGS
    "-DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/Dependencies/served"
    "-DCMAKE_BUILD_TYPE:STRING=Release"
    "-DSERVED_BUILD_TESTS:BOOL=OFF"
)

set(Served_INCLUDE_DIR ${EP_DEPENDENCIES_PATH}/served/include PARENT_SCOPE)
set(Served_LIB_DIR ${EP_DEPENDENCIES_PATH}/served/lib PARENT_SCOPE)
set(Served_LIBRARIES 
  -lserved PARENT_SCOPE
)

add_library(lib_served SHARED IMPORTED)

set_target_properties(lib_served PROPERTIES IMPORTED_LOCATION
    ${SERVED_LIB_DIR}/libserved.so
)
