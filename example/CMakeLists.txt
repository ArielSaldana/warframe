cmake_minimum_required(VERSION 3.25)
project(example)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

add_executable(example main.cpp)
target_link_libraries(example PRIVATE ${CMAKE_BINARY_DIR}/libwarframe.dylib)
