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
CMAKE_SOURCE_DIR = /home/george/C_Programs/DoubleLinkedList

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/george/C_Programs/DoubleLinkedList/build

# Include any dependencies generated for this target.
include CMakeFiles/Test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Test.dir/flags.make

CMakeFiles/Test.dir/src/DoubleLinkedList.c.o: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/src/DoubleLinkedList.c.o: ../src/DoubleLinkedList.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/george/C_Programs/DoubleLinkedList/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Test.dir/src/DoubleLinkedList.c.o"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Test.dir/src/DoubleLinkedList.c.o   -c /home/george/C_Programs/DoubleLinkedList/src/DoubleLinkedList.c

CMakeFiles/Test.dir/src/DoubleLinkedList.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Test.dir/src/DoubleLinkedList.c.i"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/george/C_Programs/DoubleLinkedList/src/DoubleLinkedList.c > CMakeFiles/Test.dir/src/DoubleLinkedList.c.i

CMakeFiles/Test.dir/src/DoubleLinkedList.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Test.dir/src/DoubleLinkedList.c.s"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/george/C_Programs/DoubleLinkedList/src/DoubleLinkedList.c -o CMakeFiles/Test.dir/src/DoubleLinkedList.c.s

CMakeFiles/Test.dir/src/IOData.c.o: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/src/IOData.c.o: ../src/IOData.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/george/C_Programs/DoubleLinkedList/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Test.dir/src/IOData.c.o"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Test.dir/src/IOData.c.o   -c /home/george/C_Programs/DoubleLinkedList/src/IOData.c

CMakeFiles/Test.dir/src/IOData.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Test.dir/src/IOData.c.i"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/george/C_Programs/DoubleLinkedList/src/IOData.c > CMakeFiles/Test.dir/src/IOData.c.i

CMakeFiles/Test.dir/src/IOData.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Test.dir/src/IOData.c.s"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/george/C_Programs/DoubleLinkedList/src/IOData.c -o CMakeFiles/Test.dir/src/IOData.c.s

CMakeFiles/Test.dir/ListTest.c.o: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/ListTest.c.o: ../ListTest.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/george/C_Programs/DoubleLinkedList/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Test.dir/ListTest.c.o"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Test.dir/ListTest.c.o   -c /home/george/C_Programs/DoubleLinkedList/ListTest.c

CMakeFiles/Test.dir/ListTest.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Test.dir/ListTest.c.i"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/george/C_Programs/DoubleLinkedList/ListTest.c > CMakeFiles/Test.dir/ListTest.c.i

CMakeFiles/Test.dir/ListTest.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Test.dir/ListTest.c.s"
	/bin/x86_64-linux-gnu-gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/george/C_Programs/DoubleLinkedList/ListTest.c -o CMakeFiles/Test.dir/ListTest.c.s

# Object files for target Test
Test_OBJECTS = \
"CMakeFiles/Test.dir/src/DoubleLinkedList.c.o" \
"CMakeFiles/Test.dir/src/IOData.c.o" \
"CMakeFiles/Test.dir/ListTest.c.o"

# External object files for target Test
Test_EXTERNAL_OBJECTS =

Test: CMakeFiles/Test.dir/src/DoubleLinkedList.c.o
Test: CMakeFiles/Test.dir/src/IOData.c.o
Test: CMakeFiles/Test.dir/ListTest.c.o
Test: CMakeFiles/Test.dir/build.make
Test: CMakeFiles/Test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/george/C_Programs/DoubleLinkedList/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable Test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Test.dir/build: Test

.PHONY : CMakeFiles/Test.dir/build

CMakeFiles/Test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Test.dir/clean

CMakeFiles/Test.dir/depend:
	cd /home/george/C_Programs/DoubleLinkedList/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/george/C_Programs/DoubleLinkedList /home/george/C_Programs/DoubleLinkedList /home/george/C_Programs/DoubleLinkedList/build /home/george/C_Programs/DoubleLinkedList/build /home/george/C_Programs/DoubleLinkedList/build/CMakeFiles/Test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Test.dir/depend

