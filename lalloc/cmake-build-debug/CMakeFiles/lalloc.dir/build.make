# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\barre\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.7660.37\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\barre\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.7660.37\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\barre\Desktop\Github\advcs-labs\lalloc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\barre\Desktop\Github\advcs-labs\lalloc\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lalloc.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lalloc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lalloc.dir/flags.make

CMakeFiles/lalloc.dir/main.cpp.obj: CMakeFiles/lalloc.dir/flags.make
CMakeFiles/lalloc.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\barre\Desktop\Github\advcs-labs\lalloc\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lalloc.dir/main.cpp.obj"
	C:\MinGW-w64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\lalloc.dir\main.cpp.obj -c C:\Users\barre\Desktop\Github\advcs-labs\lalloc\main.cpp

CMakeFiles/lalloc.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lalloc.dir/main.cpp.i"
	C:\MinGW-w64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\barre\Desktop\Github\advcs-labs\lalloc\main.cpp > CMakeFiles\lalloc.dir\main.cpp.i

CMakeFiles/lalloc.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lalloc.dir/main.cpp.s"
	C:\MinGW-w64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\barre\Desktop\Github\advcs-labs\lalloc\main.cpp -o CMakeFiles\lalloc.dir\main.cpp.s

CMakeFiles/lalloc.dir/LASAalloc.cpp.obj: CMakeFiles/lalloc.dir/flags.make
CMakeFiles/lalloc.dir/LASAalloc.cpp.obj: ../LASAalloc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\barre\Desktop\Github\advcs-labs\lalloc\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lalloc.dir/LASAalloc.cpp.obj"
	C:\MinGW-w64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\lalloc.dir\LASAalloc.cpp.obj -c C:\Users\barre\Desktop\Github\advcs-labs\lalloc\LASAalloc.cpp

CMakeFiles/lalloc.dir/LASAalloc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lalloc.dir/LASAalloc.cpp.i"
	C:\MinGW-w64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\barre\Desktop\Github\advcs-labs\lalloc\LASAalloc.cpp > CMakeFiles\lalloc.dir\LASAalloc.cpp.i

CMakeFiles/lalloc.dir/LASAalloc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lalloc.dir/LASAalloc.cpp.s"
	C:\MinGW-w64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\barre\Desktop\Github\advcs-labs\lalloc\LASAalloc.cpp -o CMakeFiles\lalloc.dir\LASAalloc.cpp.s

# Object files for target lalloc
lalloc_OBJECTS = \
"CMakeFiles/lalloc.dir/main.cpp.obj" \
"CMakeFiles/lalloc.dir/LASAalloc.cpp.obj"

# External object files for target lalloc
lalloc_EXTERNAL_OBJECTS =

lalloc.exe: CMakeFiles/lalloc.dir/main.cpp.obj
lalloc.exe: CMakeFiles/lalloc.dir/LASAalloc.cpp.obj
lalloc.exe: CMakeFiles/lalloc.dir/build.make
lalloc.exe: CMakeFiles/lalloc.dir/linklibs.rsp
lalloc.exe: CMakeFiles/lalloc.dir/objects1.rsp
lalloc.exe: CMakeFiles/lalloc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\barre\Desktop\Github\advcs-labs\lalloc\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable lalloc.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lalloc.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lalloc.dir/build: lalloc.exe

.PHONY : CMakeFiles/lalloc.dir/build

CMakeFiles/lalloc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lalloc.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lalloc.dir/clean

CMakeFiles/lalloc.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\barre\Desktop\Github\advcs-labs\lalloc C:\Users\barre\Desktop\Github\advcs-labs\lalloc C:\Users\barre\Desktop\Github\advcs-labs\lalloc\cmake-build-debug C:\Users\barre\Desktop\Github\advcs-labs\lalloc\cmake-build-debug C:\Users\barre\Desktop\Github\advcs-labs\lalloc\cmake-build-debug\CMakeFiles\lalloc.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lalloc.dir/depend
