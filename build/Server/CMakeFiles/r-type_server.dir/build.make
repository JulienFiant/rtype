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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/Julien/Epitech/TEK3/CPP/CPP_rtype_2019

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/Julien/Epitech/TEK3/CPP/CPP_rtype_2019/build

# Include any dependencies generated for this target.
include Server/CMakeFiles/r-type_server.dir/depend.make

# Include the progress variables for this target.
include Server/CMakeFiles/r-type_server.dir/progress.make

# Include the compile flags for this target's objects.
include Server/CMakeFiles/r-type_server.dir/flags.make

Server/CMakeFiles/r-type_server.dir/src/main_server.cpp.o: Server/CMakeFiles/r-type_server.dir/flags.make
Server/CMakeFiles/r-type_server.dir/src/main_server.cpp.o: ../Server/src/main_server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Julien/Epitech/TEK3/CPP/CPP_rtype_2019/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Server/CMakeFiles/r-type_server.dir/src/main_server.cpp.o"
	cd /home/Julien/Epitech/TEK3/CPP/CPP_rtype_2019/build/Server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/r-type_server.dir/src/main_server.cpp.o -c /home/Julien/Epitech/TEK3/CPP/CPP_rtype_2019/Server/src/main_server.cpp

Server/CMakeFiles/r-type_server.dir/src/main_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/r-type_server.dir/src/main_server.cpp.i"
	cd /home/Julien/Epitech/TEK3/CPP/CPP_rtype_2019/build/Server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Julien/Epitech/TEK3/CPP/CPP_rtype_2019/Server/src/main_server.cpp > CMakeFiles/r-type_server.dir/src/main_server.cpp.i

Server/CMakeFiles/r-type_server.dir/src/main_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/r-type_server.dir/src/main_server.cpp.s"
	cd /home/Julien/Epitech/TEK3/CPP/CPP_rtype_2019/build/Server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Julien/Epitech/TEK3/CPP/CPP_rtype_2019/Server/src/main_server.cpp -o CMakeFiles/r-type_server.dir/src/main_server.cpp.s

# Object files for target r-type_server
r__type_server_OBJECTS = \
"CMakeFiles/r-type_server.dir/src/main_server.cpp.o"

# External object files for target r-type_server
r__type_server_EXTERNAL_OBJECTS =

bin/r-type_server: Server/CMakeFiles/r-type_server.dir/src/main_server.cpp.o
bin/r-type_server: Server/CMakeFiles/r-type_server.dir/build.make
bin/r-type_server: lib/libgame-engine.a
bin/r-type_server: Server/CMakeFiles/r-type_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/Julien/Epitech/TEK3/CPP/CPP_rtype_2019/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/r-type_server"
	cd /home/Julien/Epitech/TEK3/CPP/CPP_rtype_2019/build/Server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/r-type_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Server/CMakeFiles/r-type_server.dir/build: bin/r-type_server

.PHONY : Server/CMakeFiles/r-type_server.dir/build

Server/CMakeFiles/r-type_server.dir/clean:
	cd /home/Julien/Epitech/TEK3/CPP/CPP_rtype_2019/build/Server && $(CMAKE_COMMAND) -P CMakeFiles/r-type_server.dir/cmake_clean.cmake
.PHONY : Server/CMakeFiles/r-type_server.dir/clean

Server/CMakeFiles/r-type_server.dir/depend:
	cd /home/Julien/Epitech/TEK3/CPP/CPP_rtype_2019/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/Julien/Epitech/TEK3/CPP/CPP_rtype_2019 /home/Julien/Epitech/TEK3/CPP/CPP_rtype_2019/Server /home/Julien/Epitech/TEK3/CPP/CPP_rtype_2019/build /home/Julien/Epitech/TEK3/CPP/CPP_rtype_2019/build/Server /home/Julien/Epitech/TEK3/CPP/CPP_rtype_2019/build/Server/CMakeFiles/r-type_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Server/CMakeFiles/r-type_server.dir/depend
