cmake_minimum_required(VERSION 3.5.1)
project(digitaldesign)
set(CMAKE_CXX_STANDARD 14)

message(STATUS "CMake version   : " ${CMAKE_SYSTEM_VERSION})
message(STATUS "Compiler        : " ${CMAKE_CXX_COMPILER})
message(STATUS "Operating System: " ${CMAKE_SYSTEM})

############################################################
# Find BOOST, GTest package
############################################################
find_package(Boost 1.32 )

if(WIN32)
	# for Windows operating system in general
	ADD_SUBDIRECTORY (googletest)
	enable_testing()
endif()

if (UNIX)
	# for Linux
	find_package(GTest REQUIRED)
endif (UNIX)

############################################################
# Create a library for digitaldesign circuits
############################################################
#Generate the library from the library sources
add_library(circuits_library STATIC
		${PROJECT_SOURCE_DIR}/src/Circuits.cpp
		${PROJECT_SOURCE_DIR}/src/ReadData.cpp
		)

############################################################
# Target Include Directories
############################################################
if(WIN32)
	include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
endif()

if (UNIX)
	include_directories(${GTEST_INCLUDE_DIRS})
endif()
	
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
SET( digitaldesign-google-unit-test StaticTest )
add_executable(digitaldesign-google-unit-test
		${PROJECT_SOURCE_DIR}/unit-test-google/digitaldesign-google-unit-test.cpp
		)

############################################################
# Target Link Libaries
############################################################
target_link_libraries(digitaldesign ${Boost_LIBRARIES})
if (WIN32)
	# link the new circuits::library target with the digitaldesign-google-unit-test target
	target_link_libraries( digitaldesign-google-unit-test
			PRIVATE
			circuits_library
			PUBLIC
			gtest gtest_main pthread
			)
	add_test( digitaldesign-google-unit-test digitaldesign-google-unit-test)
endif ()

if (UNIX)
	# link the new circuits::library target with the digitaldesign-google-unit-test target
	target_link_libraries( digitaldesign-google-unit-test
			PRIVATE
			circuits_library
			PUBLIC
			${GTEST_LIBRARIES} pthread
			)
endif ()
