# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /cygdrive/c/Users/35191/AppData/Local/JetBrains/CLion2021.3/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/35191/AppData/Local/JetBrains/CLion2021.3/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/35191/Documents/Projectos/Optimization_Problems/Hibrido

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/35191/Documents/Projectos/Optimization_Problems/Hibrido/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Evolutivo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Evolutivo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Evolutivo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Evolutivo.dir/flags.make

CMakeFiles/Evolutivo.dir/main.c.o: CMakeFiles/Evolutivo.dir/flags.make
CMakeFiles/Evolutivo.dir/main.c.o: ../main.c
CMakeFiles/Evolutivo.dir/main.c.o: CMakeFiles/Evolutivo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/35191/Documents/Projectos/Optimization_Problems/Hibrido/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Evolutivo.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Evolutivo.dir/main.c.o -MF CMakeFiles/Evolutivo.dir/main.c.o.d -o CMakeFiles/Evolutivo.dir/main.c.o -c /cygdrive/c/Users/35191/Documents/Projectos/Optimization_Problems/Hibrido/main.c

CMakeFiles/Evolutivo.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Evolutivo.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/35191/Documents/Projectos/Optimization_Problems/Hibrido/main.c > CMakeFiles/Evolutivo.dir/main.c.i

CMakeFiles/Evolutivo.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Evolutivo.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/35191/Documents/Projectos/Optimization_Problems/Hibrido/main.c -o CMakeFiles/Evolutivo.dir/main.c.s

CMakeFiles/Evolutivo.dir/algoritmo.c.o: CMakeFiles/Evolutivo.dir/flags.make
CMakeFiles/Evolutivo.dir/algoritmo.c.o: ../algoritmo.c
CMakeFiles/Evolutivo.dir/algoritmo.c.o: CMakeFiles/Evolutivo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/35191/Documents/Projectos/Optimization_Problems/Hibrido/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Evolutivo.dir/algoritmo.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Evolutivo.dir/algoritmo.c.o -MF CMakeFiles/Evolutivo.dir/algoritmo.c.o.d -o CMakeFiles/Evolutivo.dir/algoritmo.c.o -c /cygdrive/c/Users/35191/Documents/Projectos/Optimization_Problems/Hibrido/algoritmo.c

CMakeFiles/Evolutivo.dir/algoritmo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Evolutivo.dir/algoritmo.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/35191/Documents/Projectos/Optimization_Problems/Hibrido/algoritmo.c > CMakeFiles/Evolutivo.dir/algoritmo.c.i

CMakeFiles/Evolutivo.dir/algoritmo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Evolutivo.dir/algoritmo.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/35191/Documents/Projectos/Optimization_Problems/Hibrido/algoritmo.c -o CMakeFiles/Evolutivo.dir/algoritmo.c.s

CMakeFiles/Evolutivo.dir/utils.c.o: CMakeFiles/Evolutivo.dir/flags.make
CMakeFiles/Evolutivo.dir/utils.c.o: ../utils.c
CMakeFiles/Evolutivo.dir/utils.c.o: CMakeFiles/Evolutivo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/35191/Documents/Projectos/Optimization_Problems/Hibrido/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Evolutivo.dir/utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Evolutivo.dir/utils.c.o -MF CMakeFiles/Evolutivo.dir/utils.c.o.d -o CMakeFiles/Evolutivo.dir/utils.c.o -c /cygdrive/c/Users/35191/Documents/Projectos/Optimization_Problems/Hibrido/utils.c

CMakeFiles/Evolutivo.dir/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Evolutivo.dir/utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/35191/Documents/Projectos/Optimization_Problems/Hibrido/utils.c > CMakeFiles/Evolutivo.dir/utils.c.i

CMakeFiles/Evolutivo.dir/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Evolutivo.dir/utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/35191/Documents/Projectos/Optimization_Problems/Hibrido/utils.c -o CMakeFiles/Evolutivo.dir/utils.c.s

CMakeFiles/Evolutivo.dir/funcao.c.o: CMakeFiles/Evolutivo.dir/flags.make
CMakeFiles/Evolutivo.dir/funcao.c.o: ../funcao.c
CMakeFiles/Evolutivo.dir/funcao.c.o: CMakeFiles/Evolutivo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/35191/Documents/Projectos/Optimization_Problems/Hibrido/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Evolutivo.dir/funcao.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Evolutivo.dir/funcao.c.o -MF CMakeFiles/Evolutivo.dir/funcao.c.o.d -o CMakeFiles/Evolutivo.dir/funcao.c.o -c /cygdrive/c/Users/35191/Documents/Projectos/Optimization_Problems/Hibrido/funcao.c

CMakeFiles/Evolutivo.dir/funcao.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Evolutivo.dir/funcao.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/35191/Documents/Projectos/Optimization_Problems/Hibrido/funcao.c > CMakeFiles/Evolutivo.dir/funcao.c.i

CMakeFiles/Evolutivo.dir/funcao.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Evolutivo.dir/funcao.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/35191/Documents/Projectos/Optimization_Problems/Hibrido/funcao.c -o CMakeFiles/Evolutivo.dir/funcao.c.s

# Object files for target Evolutivo
Evolutivo_OBJECTS = \
"CMakeFiles/Evolutivo.dir/main.c.o" \
"CMakeFiles/Evolutivo.dir/algoritmo.c.o" \
"CMakeFiles/Evolutivo.dir/utils.c.o" \
"CMakeFiles/Evolutivo.dir/funcao.c.o"

# External object files for target Evolutivo
Evolutivo_EXTERNAL_OBJECTS =

Evolutivo.exe: CMakeFiles/Evolutivo.dir/main.c.o
Evolutivo.exe: CMakeFiles/Evolutivo.dir/algoritmo.c.o
Evolutivo.exe: CMakeFiles/Evolutivo.dir/utils.c.o
Evolutivo.exe: CMakeFiles/Evolutivo.dir/funcao.c.o
Evolutivo.exe: CMakeFiles/Evolutivo.dir/build.make
Evolutivo.exe: CMakeFiles/Evolutivo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/35191/Documents/Projectos/Optimization_Problems/Hibrido/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable Evolutivo.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Evolutivo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Evolutivo.dir/build: Evolutivo.exe
.PHONY : CMakeFiles/Evolutivo.dir/build

CMakeFiles/Evolutivo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Evolutivo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Evolutivo.dir/clean

CMakeFiles/Evolutivo.dir/depend:
	cd /cygdrive/c/Users/35191/Documents/Projectos/Optimization_Problems/Hibrido/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/35191/Documents/Projectos/Optimization_Problems/Hibrido /cygdrive/c/Users/35191/Documents/Projectos/Optimization_Problems/Hibrido /cygdrive/c/Users/35191/Documents/Projectos/Optimization_Problems/Hibrido/cmake-build-debug /cygdrive/c/Users/35191/Documents/Projectos/Optimization_Problems/Hibrido/cmake-build-debug /cygdrive/c/Users/35191/Documents/Projectos/Optimization_Problems/Hibrido/cmake-build-debug/CMakeFiles/Evolutivo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Evolutivo.dir/depend

