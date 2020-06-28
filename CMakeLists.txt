cmake_minimum_required(VERSION 3.5.1)
project(digitaldesign)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(digitaldesign  ${PROJECT_SOURCE_DIR}/main.cpp)

    target_link_libraries(digitaldesign ${Boost_LIBRARIES})

endif()

