# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/emilia/search_engine/Crawler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/emilia/search_engine/Crawler/build

# Include any dependencies generated for this target.
include Parser/CMakeFiles/Parser.dir/depend.make

# Include the progress variables for this target.
include Parser/CMakeFiles/Parser.dir/progress.make

# Include the compile flags for this target's objects.
include Parser/CMakeFiles/Parser.dir/flags.make

Parser/CMakeFiles/Parser.dir/Parser.cpp.o: Parser/CMakeFiles/Parser.dir/flags.make
Parser/CMakeFiles/Parser.dir/Parser.cpp.o: ../Parser/Parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/emilia/search_engine/Crawler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Parser/CMakeFiles/Parser.dir/Parser.cpp.o"
	cd /home/emilia/search_engine/Crawler/build/Parser && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Parser.dir/Parser.cpp.o -c /home/emilia/search_engine/Crawler/Parser/Parser.cpp

Parser/CMakeFiles/Parser.dir/Parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Parser.dir/Parser.cpp.i"
	cd /home/emilia/search_engine/Crawler/build/Parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/emilia/search_engine/Crawler/Parser/Parser.cpp > CMakeFiles/Parser.dir/Parser.cpp.i

Parser/CMakeFiles/Parser.dir/Parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Parser.dir/Parser.cpp.s"
	cd /home/emilia/search_engine/Crawler/build/Parser && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/emilia/search_engine/Crawler/Parser/Parser.cpp -o CMakeFiles/Parser.dir/Parser.cpp.s

# Object files for target Parser
Parser_OBJECTS = \
"CMakeFiles/Parser.dir/Parser.cpp.o"

# External object files for target Parser
Parser_EXTERNAL_OBJECTS =

Parser/libParser.so: Parser/CMakeFiles/Parser.dir/Parser.cpp.o
Parser/libParser.so: Parser/CMakeFiles/Parser.dir/build.make
Parser/libParser.so: Parser/CMakeFiles/Parser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/emilia/search_engine/Crawler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libParser.so"
	cd /home/emilia/search_engine/Crawler/build/Parser && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Parser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Parser/CMakeFiles/Parser.dir/build: Parser/libParser.so

.PHONY : Parser/CMakeFiles/Parser.dir/build

Parser/CMakeFiles/Parser.dir/clean:
	cd /home/emilia/search_engine/Crawler/build/Parser && $(CMAKE_COMMAND) -P CMakeFiles/Parser.dir/cmake_clean.cmake
.PHONY : Parser/CMakeFiles/Parser.dir/clean

Parser/CMakeFiles/Parser.dir/depend:
	cd /home/emilia/search_engine/Crawler/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/emilia/search_engine/Crawler /home/emilia/search_engine/Crawler/Parser /home/emilia/search_engine/Crawler/build /home/emilia/search_engine/Crawler/build/Parser /home/emilia/search_engine/Crawler/build/Parser/CMakeFiles/Parser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Parser/CMakeFiles/Parser.dir/depend
