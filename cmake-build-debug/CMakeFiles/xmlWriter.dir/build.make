# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /snap/clion/73/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/73/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/spandan/CLionProjects/xmlWriter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/spandan/CLionProjects/xmlWriter/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/xmlWriter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/xmlWriter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/xmlWriter.dir/flags.make

CMakeFiles/xmlWriter.dir/main.cpp.o: CMakeFiles/xmlWriter.dir/flags.make
CMakeFiles/xmlWriter.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spandan/CLionProjects/xmlWriter/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/xmlWriter.dir/main.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/xmlWriter.dir/main.cpp.o -c /home/spandan/CLionProjects/xmlWriter/main.cpp

CMakeFiles/xmlWriter.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xmlWriter.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spandan/CLionProjects/xmlWriter/main.cpp > CMakeFiles/xmlWriter.dir/main.cpp.i

CMakeFiles/xmlWriter.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xmlWriter.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spandan/CLionProjects/xmlWriter/main.cpp -o CMakeFiles/xmlWriter.dir/main.cpp.s

CMakeFiles/xmlWriter.dir/xmlWriter.cpp.o: CMakeFiles/xmlWriter.dir/flags.make
CMakeFiles/xmlWriter.dir/xmlWriter.cpp.o: ../xmlWriter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spandan/CLionProjects/xmlWriter/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/xmlWriter.dir/xmlWriter.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/xmlWriter.dir/xmlWriter.cpp.o -c /home/spandan/CLionProjects/xmlWriter/xmlWriter.cpp

CMakeFiles/xmlWriter.dir/xmlWriter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/xmlWriter.dir/xmlWriter.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spandan/CLionProjects/xmlWriter/xmlWriter.cpp > CMakeFiles/xmlWriter.dir/xmlWriter.cpp.i

CMakeFiles/xmlWriter.dir/xmlWriter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/xmlWriter.dir/xmlWriter.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spandan/CLionProjects/xmlWriter/xmlWriter.cpp -o CMakeFiles/xmlWriter.dir/xmlWriter.cpp.s

# Object files for target xmlWriter
xmlWriter_OBJECTS = \
"CMakeFiles/xmlWriter.dir/main.cpp.o" \
"CMakeFiles/xmlWriter.dir/xmlWriter.cpp.o"

# External object files for target xmlWriter
xmlWriter_EXTERNAL_OBJECTS =

xmlWriter: CMakeFiles/xmlWriter.dir/main.cpp.o
xmlWriter: CMakeFiles/xmlWriter.dir/xmlWriter.cpp.o
xmlWriter: CMakeFiles/xmlWriter.dir/build.make
xmlWriter: CMakeFiles/xmlWriter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/spandan/CLionProjects/xmlWriter/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable xmlWriter"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/xmlWriter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/xmlWriter.dir/build: xmlWriter

.PHONY : CMakeFiles/xmlWriter.dir/build

CMakeFiles/xmlWriter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/xmlWriter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/xmlWriter.dir/clean

CMakeFiles/xmlWriter.dir/depend:
	cd /home/spandan/CLionProjects/xmlWriter/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/spandan/CLionProjects/xmlWriter /home/spandan/CLionProjects/xmlWriter /home/spandan/CLionProjects/xmlWriter/cmake-build-debug /home/spandan/CLionProjects/xmlWriter/cmake-build-debug /home/spandan/CLionProjects/xmlWriter/cmake-build-debug/CMakeFiles/xmlWriter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/xmlWriter.dir/depend

