# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/arslan/CLionProjects/digitaldesign

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arslan/CLionProjects/digitaldesign/build

# Include any dependencies generated for this target.
include CMakeFiles/sub64.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sub64.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sub64.dir/flags.make

CMakeFiles/sub64.dir/src/sub64.cpp.o: CMakeFiles/sub64.dir/flags.make
CMakeFiles/sub64.dir/src/sub64.cpp.o: ../src/sub64.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arslan/CLionProjects/digitaldesign/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sub64.dir/src/sub64.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sub64.dir/src/sub64.cpp.o -c /home/arslan/CLionProjects/digitaldesign/src/sub64.cpp

CMakeFiles/sub64.dir/src/sub64.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sub64.dir/src/sub64.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arslan/CLionProjects/digitaldesign/src/sub64.cpp > CMakeFiles/sub64.dir/src/sub64.cpp.i

CMakeFiles/sub64.dir/src/sub64.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sub64.dir/src/sub64.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arslan/CLionProjects/digitaldesign/src/sub64.cpp -o CMakeFiles/sub64.dir/src/sub64.cpp.s

CMakeFiles/sub64.dir/src/sub64.cpp.o.requires:

.PHONY : CMakeFiles/sub64.dir/src/sub64.cpp.o.requires

CMakeFiles/sub64.dir/src/sub64.cpp.o.provides: CMakeFiles/sub64.dir/src/sub64.cpp.o.requires
	$(MAKE) -f CMakeFiles/sub64.dir/build.make CMakeFiles/sub64.dir/src/sub64.cpp.o.provides.build
.PHONY : CMakeFiles/sub64.dir/src/sub64.cpp.o.provides

CMakeFiles/sub64.dir/src/sub64.cpp.o.provides.build: CMakeFiles/sub64.dir/src/sub64.cpp.o


# Object files for target sub64
sub64_OBJECTS = \
"CMakeFiles/sub64.dir/src/sub64.cpp.o"

# External object files for target sub64
sub64_EXTERNAL_OBJECTS =

sub64: CMakeFiles/sub64.dir/src/sub64.cpp.o
sub64: CMakeFiles/sub64.dir/build.make
sub64: CMakeFiles/sub64.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/arslan/CLionProjects/digitaldesign/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sub64"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sub64.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sub64.dir/build: sub64

.PHONY : CMakeFiles/sub64.dir/build

CMakeFiles/sub64.dir/requires: CMakeFiles/sub64.dir/src/sub64.cpp.o.requires

.PHONY : CMakeFiles/sub64.dir/requires

CMakeFiles/sub64.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sub64.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sub64.dir/clean

CMakeFiles/sub64.dir/depend:
	cd /home/arslan/CLionProjects/digitaldesign/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arslan/CLionProjects/digitaldesign /home/arslan/CLionProjects/digitaldesign /home/arslan/CLionProjects/digitaldesign/build /home/arslan/CLionProjects/digitaldesign/build /home/arslan/CLionProjects/digitaldesign/build/CMakeFiles/sub64.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sub64.dir/depend
