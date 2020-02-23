find_package(Boost REQUIRED system)


include_directories(
  include
  ${Served_INCLUDE_DIR}
  ${OpenCV_INCLUDE_DIR}
)

link_directories(
  ${OpenCV_LIB_DIR}
  ${Served_LIB_DIR}
)

file(GLOB source_list "src/*.cpp")
add_executable(hls_recorder ${source_list})

target_link_libraries(hls_recorder
  ${Boost_LIBRARIES}
  ${OpenCV_LIBRARIES}
  ${Served_LIBRARIES}
)

add_dependencies(hls_recorder served)
add_dependencies(hls_recorder opencv)
