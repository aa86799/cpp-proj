# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/stone/CLionProjects/cpp-proj

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/stone/CLionProjects/cpp-proj/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cppproj.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cppproj.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cppproj.dir/flags.make

CMakeFiles/cppproj.dir/a01/Sales.cpp.o: CMakeFiles/cppproj.dir/flags.make
CMakeFiles/cppproj.dir/a01/Sales.cpp.o: ../a01/Sales.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/stone/CLionProjects/cpp-proj/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cppproj.dir/a01/Sales.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cppproj.dir/a01/Sales.cpp.o -c /Users/stone/CLionProjects/cpp-proj/a01/Sales.cpp

CMakeFiles/cppproj.dir/a01/Sales.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cppproj.dir/a01/Sales.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/stone/CLionProjects/cpp-proj/a01/Sales.cpp > CMakeFiles/cppproj.dir/a01/Sales.cpp.i

CMakeFiles/cppproj.dir/a01/Sales.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cppproj.dir/a01/Sales.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/stone/CLionProjects/cpp-proj/a01/Sales.cpp -o CMakeFiles/cppproj.dir/a01/Sales.cpp.s

CMakeFiles/cppproj.dir/a01/SalesSub.cpp.o: CMakeFiles/cppproj.dir/flags.make
CMakeFiles/cppproj.dir/a01/SalesSub.cpp.o: ../a01/SalesSub.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/stone/CLionProjects/cpp-proj/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cppproj.dir/a01/SalesSub.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cppproj.dir/a01/SalesSub.cpp.o -c /Users/stone/CLionProjects/cpp-proj/a01/SalesSub.cpp

CMakeFiles/cppproj.dir/a01/SalesSub.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cppproj.dir/a01/SalesSub.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/stone/CLionProjects/cpp-proj/a01/SalesSub.cpp > CMakeFiles/cppproj.dir/a01/SalesSub.cpp.i

CMakeFiles/cppproj.dir/a01/SalesSub.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cppproj.dir/a01/SalesSub.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/stone/CLionProjects/cpp-proj/a01/SalesSub.cpp -o CMakeFiles/cppproj.dir/a01/SalesSub.cpp.s

# Object files for target cppproj
cppproj_OBJECTS = \
"CMakeFiles/cppproj.dir/a01/Sales.cpp.o" \
"CMakeFiles/cppproj.dir/a01/SalesSub.cpp.o"

# External object files for target cppproj
cppproj_EXTERNAL_OBJECTS =

cppproj: CMakeFiles/cppproj.dir/a01/Sales.cpp.o
cppproj: CMakeFiles/cppproj.dir/a01/SalesSub.cpp.o
cppproj: CMakeFiles/cppproj.dir/build.make
cppproj: CMakeFiles/cppproj.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/stone/CLionProjects/cpp-proj/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable cppproj"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cppproj.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cppproj.dir/build: cppproj

.PHONY : CMakeFiles/cppproj.dir/build

CMakeFiles/cppproj.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cppproj.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cppproj.dir/clean

CMakeFiles/cppproj.dir/depend:
	cd /Users/stone/CLionProjects/cpp-proj/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/stone/CLionProjects/cpp-proj /Users/stone/CLionProjects/cpp-proj /Users/stone/CLionProjects/cpp-proj/cmake-build-debug /Users/stone/CLionProjects/cpp-proj/cmake-build-debug /Users/stone/CLionProjects/cpp-proj/cmake-build-debug/CMakeFiles/cppproj.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cppproj.dir/depend

