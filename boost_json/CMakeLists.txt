cmake_minimum_required(VERSION 3.16)
project(boost_json)

set(CMAKE_CXX_STANDARD 17)

set(EXAMPLE_TXT_PATH ${CMAKE_SOURCE_DIR}/example.txt)

find_package(Boost REQUIRED COMPONENTS json)
find_package(Boost REQUIRED COMPONENTS filesystem)

add_executable(boost_json main.cpp)

target_link_libraries(boost_json
        Boost::json
        Boost::filesystem)

#file(COPY ${CMAKE_SOURCE_DIR}/example.txt DESTINATION ${CMAKE_BINARY_DIR})
configure_file(${EXAMPLE_TXT_PATH} ${CMAKE_BINARY_DIR}/example.txt COPYONLY)