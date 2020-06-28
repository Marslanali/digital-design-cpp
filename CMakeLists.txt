cmake_minimum_required(VERSION 3.5.1)
project(digitaldesign)

set(CMAKE_CXX_STANDARD 14)

add_executable(adder64  ${PROJECT_SOURCE_DIR}/src/adder64.cpp)
add_executable(sub64  ${PROJECT_SOURCE_DIR}/src/sub64.cpp)
