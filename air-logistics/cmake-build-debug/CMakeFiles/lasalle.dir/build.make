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
CMAKE_SOURCE_DIR = C:\Users\barre\Desktop\Github\advcs-labs\air-logistics

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\barre\Desktop\Github\advcs-labs\air-logistics\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lasalle.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lasalle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lasalle.dir/flags.make

CMakeFiles/lasalle.dir/main.cpp.obj: CMakeFiles/lasalle.dir/flags.make
CMakeFiles/lasalle.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\barre\Desktop\Github\advcs-labs\air-logistics\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lasalle.dir/main.cpp.obj"
	C:\MinGW-w64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\lasalle.dir\main.cpp.obj -c C:\Users\barre\Desktop\Github\advcs-labs\air-logistics\main.cpp

CMakeFiles/lasalle.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lasalle.dir/main.cpp.i"
	C:\MinGW-w64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\barre\Desktop\Github\advcs-labs\air-logistics\main.cpp > CMakeFiles\lasalle.dir\main.cpp.i

CMakeFiles/lasalle.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lasalle.dir/main.cpp.s"
	C:\MinGW-w64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\barre\Desktop\Github\advcs-labs\air-logistics\main.cpp -o CMakeFiles\lasalle.dir\main.cpp.s

CMakeFiles/lasalle.dir/slist.cpp.obj: CMakeFiles/lasalle.dir/flags.make
CMakeFiles/lasalle.dir/slist.cpp.obj: ../slist.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\barre\Desktop\Github\advcs-labs\air-logistics\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lasalle.dir/slist.cpp.obj"
	C:\MinGW-w64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\lasalle.dir\slist.cpp.obj -c C:\Users\barre\Desktop\Github\advcs-labs\air-logistics\slist.cpp

CMakeFiles/lasalle.dir/slist.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lasalle.dir/slist.cpp.i"
	C:\MinGW-w64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\barre\Desktop\Github\advcs-labs\air-logistics\slist.cpp > CMakeFiles\lasalle.dir\slist.cpp.i

CMakeFiles/lasalle.dir/slist.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lasalle.dir/slist.cpp.s"
	C:\MinGW-w64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\barre\Desktop\Github\advcs-labs\air-logistics\slist.cpp -o CMakeFiles\lasalle.dir\slist.cpp.s

# Object files for target lasalle
lasalle_OBJECTS = \
"CMakeFiles/lasalle.dir/main.cpp.obj" \
"CMakeFiles/lasalle.dir/slist.cpp.obj"

# External object files for target lasalle
lasalle_EXTERNAL_OBJECTS =

lasalle.exe: CMakeFiles/lasalle.dir/main.cpp.obj
lasalle.exe: CMakeFiles/lasalle.dir/slist.cpp.obj
lasalle.exe: CMakeFiles/lasalle.dir/build.make
lasalle.exe: CMakeFiles/lasalle.dir/linklibs.rsp
lasalle.exe: CMakeFiles/lasalle.dir/objects1.rsp
lasalle.exe: CMakeFiles/lasalle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\barre\Desktop\Github\advcs-labs\air-logistics\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable lasalle.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lasalle.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lasalle.dir/build: lasalle.exe

.PHONY : CMakeFiles/lasalle.dir/build

CMakeFiles/lasalle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lasalle.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lasalle.dir/clean

CMakeFiles/lasalle.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\barre\Desktop\Github\advcs-labs\air-logistics C:\Users\barre\Desktop\Github\advcs-labs\air-logistics C:\Users\barre\Desktop\Github\advcs-labs\air-logistics\cmake-build-debug C:\Users\barre\Desktop\Github\advcs-labs\air-logistics\cmake-build-debug C:\Users\barre\Desktop\Github\advcs-labs\air-logistics\cmake-build-debug\CMakeFiles\lasalle.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lasalle.dir/depend

