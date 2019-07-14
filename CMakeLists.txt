cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 14)
project(hls_streamer)

find_package(Boost REQUIRED system)
find_package(PkgConfig)
find_package(OpenCV REQUIRED)
pkg_check_modules(served REQUIRED served)

include_directories(${HEADER_SEARCH_PATHS})
add_executable(hls_streamer
    main.cpp
    multiplexer.cpp
    encoder.cpp
)
target_link_libraries(hls_streamer
    ${Boost_LIBRARIES}
    ${served_LIBRARIES}
    ${OpenCV_LIBS}
)
