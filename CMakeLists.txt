cmake_minimum_required(VERSION 3.5.1)
project(digitaldesign)

set(CMAKE_CXX_STANDARD 14)

############################################################
# Find BOOST, GTest package
############################################################

find_package(Boost 1.32)
find_package(GTest REQUIRED)

############################################################
# Target Include Directories
############################################################
    
include_directories(${GTEST_INCLUDE_DIRS})
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
#  Create an executable for DigitalDesign Unit Test
############################################################

add_executable(digitaldesign-google-unit-test
        ${PROJECT_SOURCE_DIR}/unit-test-google/digitaldesign-google-unit-test.cpp
    	${PROJECT_SOURCE_DIR}/src/Circuits.cpp
    	${PROJECT_SOURCE_DIR}/src/ReadData.cpp
    	${PROJECT_SOURCE_DIR}/include/Circuits.h
    	${PROJECT_SOURCE_DIR}/include/ReadData.h)

############################################################
# Target Link Libaries
############################################################

# Link runTests with what we want to test and the GTest and pthread library
target_link_libraries(executeTests ${GTEST_LIBRARIES} pthread)
target_link_libraries(digitaldesign ${Boost_LIBRARIES})



