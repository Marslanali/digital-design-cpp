cmake_minimum_required(VERSION 3.5.1)
project(digitaldesign)

set(CMAKE_CXX_STANDARD 14)

############################################################
# Find BOOST, GTest package
############################################################

find_package(Boost 1.32)
find_package(GTest REQUIRED)

############################################################
# Create a library for digitaldesign circuits
############################################################

#[[
#Generate the shared library from the library sources
add_library(circuits_library SHARED
		${PROJECT_SOURCE_DIR}/shared-lib/src/Circuits.cpp
		${PROJECT_SOURCE_DIR}/shared-lib/src/ReadData.cpp
		)
add_library(circuits::library ALIAS circuits_library)
]]

############################################################
# Target Include Directories
############################################################
    
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})

#[[
target_include_directories(circuits_library
		PUBLIC
		${PROJECT_SOURCE_DIR}/include
		)
]]

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
#  Create an executable for DigitalDesign Unit Test
############################################################

#[[
add_executable(digitaldesign-google-unit-test
        ${PROJECT_SOURCE_DIR}/unit-test-google/digitaldesign-google-unit-test.cpp
		)
]]

############################################################
# Target Link Libaries
############################################################

target_link_libraries(digitaldesign ${Boost_LIBRARIES})
#[[
# link the new circuits::library target with the digitaldesign-google-unit-test target
target_link_libraries( digitaldesign-google-unit-test
		PRIVATE
		circuits::library
		PUBLIC
		${GTEST_LIBRARIES} pthread
		)
]]
