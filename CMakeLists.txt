cmake_minimum_required(VERSION 3.5.1)
project(digitaldesign)

set(CMAKE_CXX_STANDARD 14)
############################################################
# Find BOOST Package
############################################################
find_package(Boost 1.32)

if (Boost_FOUND)
############################################################
# Target Include Directories
############################################################
    include_directories(${Boost_INCLUDE_DIRS})

############################################################
# Create a executable for digitaldesign
############################################################
    add_executable(digitaldesign
            ${PROJECT_SOURCE_DIR}/main.cpp
            ${PROJECT_SOURCE_DIR}/src/Circuits.cpp
            ${PROJECT_SOURCE_DIR}/src/ReadData.cpp
            ${PROJECT_SOURCE_DIR}/include/Circuits.h
            ${PROJECT_SOURCE_DIR}/include/ReadData.h)

############################################################
# Target Link Libaries
############################################################
    target_link_libraries(digitaldesign ${Boost_LIBRARIES})

endif ()

