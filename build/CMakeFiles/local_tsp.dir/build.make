# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/etudiant/projects/local_TSP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/etudiant/projects/local_TSP/build

# Include any dependencies generated for this target.
include CMakeFiles/local_tsp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/local_tsp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/local_tsp.dir/flags.make

CMakeFiles/local_tsp.dir/city.o: CMakeFiles/local_tsp.dir/flags.make
CMakeFiles/local_tsp.dir/city.o: ../city.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/etudiant/projects/local_TSP/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/local_tsp.dir/city.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/local_tsp.dir/city.o -c /home/etudiant/projects/local_TSP/city.cpp

CMakeFiles/local_tsp.dir/city.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/local_tsp.dir/city.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/etudiant/projects/local_TSP/city.cpp > CMakeFiles/local_tsp.dir/city.i

CMakeFiles/local_tsp.dir/city.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/local_tsp.dir/city.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/etudiant/projects/local_TSP/city.cpp -o CMakeFiles/local_tsp.dir/city.s

CMakeFiles/local_tsp.dir/city.o.requires:
.PHONY : CMakeFiles/local_tsp.dir/city.o.requires

CMakeFiles/local_tsp.dir/city.o.provides: CMakeFiles/local_tsp.dir/city.o.requires
	$(MAKE) -f CMakeFiles/local_tsp.dir/build.make CMakeFiles/local_tsp.dir/city.o.provides.build
.PHONY : CMakeFiles/local_tsp.dir/city.o.provides

CMakeFiles/local_tsp.dir/city.o.provides.build: CMakeFiles/local_tsp.dir/city.o

CMakeFiles/local_tsp.dir/Loader.o: CMakeFiles/local_tsp.dir/flags.make
CMakeFiles/local_tsp.dir/Loader.o: ../Loader.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/etudiant/projects/local_TSP/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/local_tsp.dir/Loader.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/local_tsp.dir/Loader.o -c /home/etudiant/projects/local_TSP/Loader.cpp

CMakeFiles/local_tsp.dir/Loader.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/local_tsp.dir/Loader.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/etudiant/projects/local_TSP/Loader.cpp > CMakeFiles/local_tsp.dir/Loader.i

CMakeFiles/local_tsp.dir/Loader.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/local_tsp.dir/Loader.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/etudiant/projects/local_TSP/Loader.cpp -o CMakeFiles/local_tsp.dir/Loader.s

CMakeFiles/local_tsp.dir/Loader.o.requires:
.PHONY : CMakeFiles/local_tsp.dir/Loader.o.requires

CMakeFiles/local_tsp.dir/Loader.o.provides: CMakeFiles/local_tsp.dir/Loader.o.requires
	$(MAKE) -f CMakeFiles/local_tsp.dir/build.make CMakeFiles/local_tsp.dir/Loader.o.provides.build
.PHONY : CMakeFiles/local_tsp.dir/Loader.o.provides

CMakeFiles/local_tsp.dir/Loader.o.provides.build: CMakeFiles/local_tsp.dir/Loader.o

CMakeFiles/local_tsp.dir/main.o: CMakeFiles/local_tsp.dir/flags.make
CMakeFiles/local_tsp.dir/main.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/etudiant/projects/local_TSP/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/local_tsp.dir/main.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/local_tsp.dir/main.o -c /home/etudiant/projects/local_TSP/main.cpp

CMakeFiles/local_tsp.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/local_tsp.dir/main.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/etudiant/projects/local_TSP/main.cpp > CMakeFiles/local_tsp.dir/main.i

CMakeFiles/local_tsp.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/local_tsp.dir/main.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/etudiant/projects/local_TSP/main.cpp -o CMakeFiles/local_tsp.dir/main.s

CMakeFiles/local_tsp.dir/main.o.requires:
.PHONY : CMakeFiles/local_tsp.dir/main.o.requires

CMakeFiles/local_tsp.dir/main.o.provides: CMakeFiles/local_tsp.dir/main.o.requires
	$(MAKE) -f CMakeFiles/local_tsp.dir/build.make CMakeFiles/local_tsp.dir/main.o.provides.build
.PHONY : CMakeFiles/local_tsp.dir/main.o.provides

CMakeFiles/local_tsp.dir/main.o.provides.build: CMakeFiles/local_tsp.dir/main.o

# Object files for target local_tsp
local_tsp_OBJECTS = \
"CMakeFiles/local_tsp.dir/city.o" \
"CMakeFiles/local_tsp.dir/Loader.o" \
"CMakeFiles/local_tsp.dir/main.o"

# External object files for target local_tsp
local_tsp_EXTERNAL_OBJECTS =

local_tsp: CMakeFiles/local_tsp.dir/city.o
local_tsp: CMakeFiles/local_tsp.dir/Loader.o
local_tsp: CMakeFiles/local_tsp.dir/main.o
local_tsp: CMakeFiles/local_tsp.dir/build.make
local_tsp: CMakeFiles/local_tsp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable local_tsp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/local_tsp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/local_tsp.dir/build: local_tsp
.PHONY : CMakeFiles/local_tsp.dir/build

CMakeFiles/local_tsp.dir/requires: CMakeFiles/local_tsp.dir/city.o.requires
CMakeFiles/local_tsp.dir/requires: CMakeFiles/local_tsp.dir/Loader.o.requires
CMakeFiles/local_tsp.dir/requires: CMakeFiles/local_tsp.dir/main.o.requires
.PHONY : CMakeFiles/local_tsp.dir/requires

CMakeFiles/local_tsp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/local_tsp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/local_tsp.dir/clean

CMakeFiles/local_tsp.dir/depend:
	cd /home/etudiant/projects/local_TSP/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/etudiant/projects/local_TSP /home/etudiant/projects/local_TSP /home/etudiant/projects/local_TSP/build /home/etudiant/projects/local_TSP/build /home/etudiant/projects/local_TSP/build/CMakeFiles/local_tsp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/local_tsp.dir/depend

