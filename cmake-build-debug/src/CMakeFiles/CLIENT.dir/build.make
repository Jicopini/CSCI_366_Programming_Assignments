# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /mnt/c/Users/fireh/OneDrive/Documents/GitHub/CSCI_366_Programming_Assignments

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/fireh/OneDrive/Documents/GitHub/CSCI_366_Programming_Assignments/cmake-build-debug

# Include any dependencies generated for this target.
include src/CMakeFiles/CLIENT.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/CLIENT.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/CLIENT.dir/flags.make

src/CMakeFiles/CLIENT.dir/Client.cpp.o: src/CMakeFiles/CLIENT.dir/flags.make
src/CMakeFiles/CLIENT.dir/Client.cpp.o: ../src/Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/fireh/OneDrive/Documents/GitHub/CSCI_366_Programming_Assignments/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/CLIENT.dir/Client.cpp.o"
	cd /mnt/c/Users/fireh/OneDrive/Documents/GitHub/CSCI_366_Programming_Assignments/cmake-build-debug/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CLIENT.dir/Client.cpp.o -c /mnt/c/Users/fireh/OneDrive/Documents/GitHub/CSCI_366_Programming_Assignments/src/Client.cpp

src/CMakeFiles/CLIENT.dir/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CLIENT.dir/Client.cpp.i"
	cd /mnt/c/Users/fireh/OneDrive/Documents/GitHub/CSCI_366_Programming_Assignments/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/fireh/OneDrive/Documents/GitHub/CSCI_366_Programming_Assignments/src/Client.cpp > CMakeFiles/CLIENT.dir/Client.cpp.i

src/CMakeFiles/CLIENT.dir/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CLIENT.dir/Client.cpp.s"
	cd /mnt/c/Users/fireh/OneDrive/Documents/GitHub/CSCI_366_Programming_Assignments/cmake-build-debug/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/fireh/OneDrive/Documents/GitHub/CSCI_366_Programming_Assignments/src/Client.cpp -o CMakeFiles/CLIENT.dir/Client.cpp.s

src/CMakeFiles/CLIENT.dir/Client.cpp.o.requires:

.PHONY : src/CMakeFiles/CLIENT.dir/Client.cpp.o.requires

src/CMakeFiles/CLIENT.dir/Client.cpp.o.provides: src/CMakeFiles/CLIENT.dir/Client.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/CLIENT.dir/build.make src/CMakeFiles/CLIENT.dir/Client.cpp.o.provides.build
.PHONY : src/CMakeFiles/CLIENT.dir/Client.cpp.o.provides

src/CMakeFiles/CLIENT.dir/Client.cpp.o.provides.build: src/CMakeFiles/CLIENT.dir/Client.cpp.o


# Object files for target CLIENT
CLIENT_OBJECTS = \
"CMakeFiles/CLIENT.dir/Client.cpp.o"

# External object files for target CLIENT
CLIENT_EXTERNAL_OBJECTS =

src/libCLIENT.a: src/CMakeFiles/CLIENT.dir/Client.cpp.o
src/libCLIENT.a: src/CMakeFiles/CLIENT.dir/build.make
src/libCLIENT.a: src/CMakeFiles/CLIENT.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/fireh/OneDrive/Documents/GitHub/CSCI_366_Programming_Assignments/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libCLIENT.a"
	cd /mnt/c/Users/fireh/OneDrive/Documents/GitHub/CSCI_366_Programming_Assignments/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/CLIENT.dir/cmake_clean_target.cmake
	cd /mnt/c/Users/fireh/OneDrive/Documents/GitHub/CSCI_366_Programming_Assignments/cmake-build-debug/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CLIENT.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/CLIENT.dir/build: src/libCLIENT.a

.PHONY : src/CMakeFiles/CLIENT.dir/build

src/CMakeFiles/CLIENT.dir/requires: src/CMakeFiles/CLIENT.dir/Client.cpp.o.requires

.PHONY : src/CMakeFiles/CLIENT.dir/requires

src/CMakeFiles/CLIENT.dir/clean:
	cd /mnt/c/Users/fireh/OneDrive/Documents/GitHub/CSCI_366_Programming_Assignments/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/CLIENT.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/CLIENT.dir/clean

src/CMakeFiles/CLIENT.dir/depend:
	cd /mnt/c/Users/fireh/OneDrive/Documents/GitHub/CSCI_366_Programming_Assignments/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/fireh/OneDrive/Documents/GitHub/CSCI_366_Programming_Assignments /mnt/c/Users/fireh/OneDrive/Documents/GitHub/CSCI_366_Programming_Assignments/src /mnt/c/Users/fireh/OneDrive/Documents/GitHub/CSCI_366_Programming_Assignments/cmake-build-debug /mnt/c/Users/fireh/OneDrive/Documents/GitHub/CSCI_366_Programming_Assignments/cmake-build-debug/src /mnt/c/Users/fireh/OneDrive/Documents/GitHub/CSCI_366_Programming_Assignments/cmake-build-debug/src/CMakeFiles/CLIENT.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/CLIENT.dir/depend

