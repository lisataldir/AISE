# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = "/home/lisa/Documents/M1 CHPS/Semestre 1/AISE_24/projet"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/lisa/Documents/M1 CHPS/Semestre 1/AISE_24/projet/build"

# Include any dependencies generated for this target.
include CMakeFiles/serveur.exe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/serveur.exe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/serveur.exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/serveur.exe.dir/flags.make

CMakeFiles/serveur.exe.dir/serveur.c.o: CMakeFiles/serveur.exe.dir/flags.make
CMakeFiles/serveur.exe.dir/serveur.c.o: ../serveur.c
CMakeFiles/serveur.exe.dir/serveur.c.o: CMakeFiles/serveur.exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/lisa/Documents/M1 CHPS/Semestre 1/AISE_24/projet/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/serveur.exe.dir/serveur.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/serveur.exe.dir/serveur.c.o -MF CMakeFiles/serveur.exe.dir/serveur.c.o.d -o CMakeFiles/serveur.exe.dir/serveur.c.o -c "/home/lisa/Documents/M1 CHPS/Semestre 1/AISE_24/projet/serveur.c"

CMakeFiles/serveur.exe.dir/serveur.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/serveur.exe.dir/serveur.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/lisa/Documents/M1 CHPS/Semestre 1/AISE_24/projet/serveur.c" > CMakeFiles/serveur.exe.dir/serveur.c.i

CMakeFiles/serveur.exe.dir/serveur.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/serveur.exe.dir/serveur.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/lisa/Documents/M1 CHPS/Semestre 1/AISE_24/projet/serveur.c" -o CMakeFiles/serveur.exe.dir/serveur.c.s

CMakeFiles/serveur.exe.dir/hachage.c.o: CMakeFiles/serveur.exe.dir/flags.make
CMakeFiles/serveur.exe.dir/hachage.c.o: ../hachage.c
CMakeFiles/serveur.exe.dir/hachage.c.o: CMakeFiles/serveur.exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/lisa/Documents/M1 CHPS/Semestre 1/AISE_24/projet/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/serveur.exe.dir/hachage.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/serveur.exe.dir/hachage.c.o -MF CMakeFiles/serveur.exe.dir/hachage.c.o.d -o CMakeFiles/serveur.exe.dir/hachage.c.o -c "/home/lisa/Documents/M1 CHPS/Semestre 1/AISE_24/projet/hachage.c"

CMakeFiles/serveur.exe.dir/hachage.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/serveur.exe.dir/hachage.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/lisa/Documents/M1 CHPS/Semestre 1/AISE_24/projet/hachage.c" > CMakeFiles/serveur.exe.dir/hachage.c.i

CMakeFiles/serveur.exe.dir/hachage.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/serveur.exe.dir/hachage.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/lisa/Documents/M1 CHPS/Semestre 1/AISE_24/projet/hachage.c" -o CMakeFiles/serveur.exe.dir/hachage.c.s

CMakeFiles/serveur.exe.dir/prime.c.o: CMakeFiles/serveur.exe.dir/flags.make
CMakeFiles/serveur.exe.dir/prime.c.o: ../prime.c
CMakeFiles/serveur.exe.dir/prime.c.o: CMakeFiles/serveur.exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/lisa/Documents/M1 CHPS/Semestre 1/AISE_24/projet/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/serveur.exe.dir/prime.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/serveur.exe.dir/prime.c.o -MF CMakeFiles/serveur.exe.dir/prime.c.o.d -o CMakeFiles/serveur.exe.dir/prime.c.o -c "/home/lisa/Documents/M1 CHPS/Semestre 1/AISE_24/projet/prime.c"

CMakeFiles/serveur.exe.dir/prime.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/serveur.exe.dir/prime.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/lisa/Documents/M1 CHPS/Semestre 1/AISE_24/projet/prime.c" > CMakeFiles/serveur.exe.dir/prime.c.i

CMakeFiles/serveur.exe.dir/prime.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/serveur.exe.dir/prime.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/lisa/Documents/M1 CHPS/Semestre 1/AISE_24/projet/prime.c" -o CMakeFiles/serveur.exe.dir/prime.c.s

# Object files for target serveur.exe
serveur_exe_OBJECTS = \
"CMakeFiles/serveur.exe.dir/serveur.c.o" \
"CMakeFiles/serveur.exe.dir/hachage.c.o" \
"CMakeFiles/serveur.exe.dir/prime.c.o"

# External object files for target serveur.exe
serveur_exe_EXTERNAL_OBJECTS =

serveur.exe: CMakeFiles/serveur.exe.dir/serveur.c.o
serveur.exe: CMakeFiles/serveur.exe.dir/hachage.c.o
serveur.exe: CMakeFiles/serveur.exe.dir/prime.c.o
serveur.exe: CMakeFiles/serveur.exe.dir/build.make
serveur.exe: CMakeFiles/serveur.exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/lisa/Documents/M1 CHPS/Semestre 1/AISE_24/projet/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable serveur.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/serveur.exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/serveur.exe.dir/build: serveur.exe
.PHONY : CMakeFiles/serveur.exe.dir/build

CMakeFiles/serveur.exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/serveur.exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/serveur.exe.dir/clean

CMakeFiles/serveur.exe.dir/depend:
	cd "/home/lisa/Documents/M1 CHPS/Semestre 1/AISE_24/projet/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/lisa/Documents/M1 CHPS/Semestre 1/AISE_24/projet" "/home/lisa/Documents/M1 CHPS/Semestre 1/AISE_24/projet" "/home/lisa/Documents/M1 CHPS/Semestre 1/AISE_24/projet/build" "/home/lisa/Documents/M1 CHPS/Semestre 1/AISE_24/projet/build" "/home/lisa/Documents/M1 CHPS/Semestre 1/AISE_24/projet/build/CMakeFiles/serveur.exe.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/serveur.exe.dir/depend

