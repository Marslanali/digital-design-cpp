cmake_minimum_required(VERSION 3.5.1)
project(digitaldesign)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(adder64  ${PROJECT_SOURCE_DIR}/src/adder64.cpp)
    add_executable(sub64  ${PROJECT_SOURCE_DIR}/src/sub64.cpp)

    target_link_libraries(adder64 ${Boost_LIBRARIES})
    target_link_libraries(sub64 ${Boost_LIBRARIES})
endif()

