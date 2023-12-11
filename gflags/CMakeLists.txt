cmake_minimum_required(VERSION 3.16.3)
project(l_gflags)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(third_party/gflags)

add_executable(l_gflags main.cpp)

target_link_libraries(l_gflags gflags_nothreads_static)
