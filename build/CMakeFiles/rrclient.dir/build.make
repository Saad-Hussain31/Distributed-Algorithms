# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alma/DistributedAlgorithms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alma/DistributedAlgorithms/build

# Include any dependencies generated for this target.
include CMakeFiles/rrclient.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/rrclient.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/rrclient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rrclient.dir/flags.make

CMakeFiles/rrclient.dir/zmq/rrclient.cpp.o: CMakeFiles/rrclient.dir/flags.make
CMakeFiles/rrclient.dir/zmq/rrclient.cpp.o: ../zmq/rrclient.cpp
CMakeFiles/rrclient.dir/zmq/rrclient.cpp.o: CMakeFiles/rrclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alma/DistributedAlgorithms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rrclient.dir/zmq/rrclient.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/rrclient.dir/zmq/rrclient.cpp.o -MF CMakeFiles/rrclient.dir/zmq/rrclient.cpp.o.d -o CMakeFiles/rrclient.dir/zmq/rrclient.cpp.o -c /home/alma/DistributedAlgorithms/zmq/rrclient.cpp

CMakeFiles/rrclient.dir/zmq/rrclient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rrclient.dir/zmq/rrclient.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alma/DistributedAlgorithms/zmq/rrclient.cpp > CMakeFiles/rrclient.dir/zmq/rrclient.cpp.i

CMakeFiles/rrclient.dir/zmq/rrclient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rrclient.dir/zmq/rrclient.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alma/DistributedAlgorithms/zmq/rrclient.cpp -o CMakeFiles/rrclient.dir/zmq/rrclient.cpp.s

# Object files for target rrclient
rrclient_OBJECTS = \
"CMakeFiles/rrclient.dir/zmq/rrclient.cpp.o"

# External object files for target rrclient
rrclient_EXTERNAL_OBJECTS =

rrclient: CMakeFiles/rrclient.dir/zmq/rrclient.cpp.o
rrclient: CMakeFiles/rrclient.dir/build.make
rrclient: /usr/local/lib64/libzmq.so.5.2.5
rrclient: CMakeFiles/rrclient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alma/DistributedAlgorithms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable rrclient"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rrclient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rrclient.dir/build: rrclient
.PHONY : CMakeFiles/rrclient.dir/build

CMakeFiles/rrclient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rrclient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rrclient.dir/clean

CMakeFiles/rrclient.dir/depend:
	cd /home/alma/DistributedAlgorithms/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alma/DistributedAlgorithms /home/alma/DistributedAlgorithms /home/alma/DistributedAlgorithms/build /home/alma/DistributedAlgorithms/build /home/alma/DistributedAlgorithms/build/CMakeFiles/rrclient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rrclient.dir/depend
