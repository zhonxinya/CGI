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
CMAKE_SOURCE_DIR = /home/zxy/learn/CC/CGI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zxy/learn/CC/CGI/build

# Include any dependencies generated for this target.
include src/module/CMakeFiles/module.dir/depend.make

# Include the progress variables for this target.
include src/module/CMakeFiles/module.dir/progress.make

# Include the compile flags for this target's objects.
include src/module/CMakeFiles/module.dir/flags.make

src/module/CMakeFiles/module.dir/TaskManager/taskmanger.c.o: src/module/CMakeFiles/module.dir/flags.make
src/module/CMakeFiles/module.dir/TaskManager/taskmanger.c.o: ../src/module/TaskManager/taskmanger.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxy/learn/CC/CGI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/module/CMakeFiles/module.dir/TaskManager/taskmanger.c.o"
	cd /home/zxy/learn/CC/CGI/build/src/module && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/module.dir/TaskManager/taskmanger.c.o   -c /home/zxy/learn/CC/CGI/src/module/TaskManager/taskmanger.c

src/module/CMakeFiles/module.dir/TaskManager/taskmanger.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/module.dir/TaskManager/taskmanger.c.i"
	cd /home/zxy/learn/CC/CGI/build/src/module && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zxy/learn/CC/CGI/src/module/TaskManager/taskmanger.c > CMakeFiles/module.dir/TaskManager/taskmanger.c.i

src/module/CMakeFiles/module.dir/TaskManager/taskmanger.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/module.dir/TaskManager/taskmanger.c.s"
	cd /home/zxy/learn/CC/CGI/build/src/module && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zxy/learn/CC/CGI/src/module/TaskManager/taskmanger.c -o CMakeFiles/module.dir/TaskManager/taskmanger.c.s

src/module/CMakeFiles/module.dir/SData/cJSON.c.o: src/module/CMakeFiles/module.dir/flags.make
src/module/CMakeFiles/module.dir/SData/cJSON.c.o: ../src/module/SData/cJSON.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxy/learn/CC/CGI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/module/CMakeFiles/module.dir/SData/cJSON.c.o"
	cd /home/zxy/learn/CC/CGI/build/src/module && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/module.dir/SData/cJSON.c.o   -c /home/zxy/learn/CC/CGI/src/module/SData/cJSON.c

src/module/CMakeFiles/module.dir/SData/cJSON.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/module.dir/SData/cJSON.c.i"
	cd /home/zxy/learn/CC/CGI/build/src/module && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zxy/learn/CC/CGI/src/module/SData/cJSON.c > CMakeFiles/module.dir/SData/cJSON.c.i

src/module/CMakeFiles/module.dir/SData/cJSON.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/module.dir/SData/cJSON.c.s"
	cd /home/zxy/learn/CC/CGI/build/src/module && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zxy/learn/CC/CGI/src/module/SData/cJSON.c -o CMakeFiles/module.dir/SData/cJSON.c.s

src/module/CMakeFiles/module.dir/SocketDao/html_lib.c.o: src/module/CMakeFiles/module.dir/flags.make
src/module/CMakeFiles/module.dir/SocketDao/html_lib.c.o: ../src/module/SocketDao/html_lib.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxy/learn/CC/CGI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/module/CMakeFiles/module.dir/SocketDao/html_lib.c.o"
	cd /home/zxy/learn/CC/CGI/build/src/module && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/module.dir/SocketDao/html_lib.c.o   -c /home/zxy/learn/CC/CGI/src/module/SocketDao/html_lib.c

src/module/CMakeFiles/module.dir/SocketDao/html_lib.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/module.dir/SocketDao/html_lib.c.i"
	cd /home/zxy/learn/CC/CGI/build/src/module && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zxy/learn/CC/CGI/src/module/SocketDao/html_lib.c > CMakeFiles/module.dir/SocketDao/html_lib.c.i

src/module/CMakeFiles/module.dir/SocketDao/html_lib.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/module.dir/SocketDao/html_lib.c.s"
	cd /home/zxy/learn/CC/CGI/build/src/module && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zxy/learn/CC/CGI/src/module/SocketDao/html_lib.c -o CMakeFiles/module.dir/SocketDao/html_lib.c.s

src/module/CMakeFiles/module.dir/SocketDao/socketdao.c.o: src/module/CMakeFiles/module.dir/flags.make
src/module/CMakeFiles/module.dir/SocketDao/socketdao.c.o: ../src/module/SocketDao/socketdao.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxy/learn/CC/CGI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/module/CMakeFiles/module.dir/SocketDao/socketdao.c.o"
	cd /home/zxy/learn/CC/CGI/build/src/module && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/module.dir/SocketDao/socketdao.c.o   -c /home/zxy/learn/CC/CGI/src/module/SocketDao/socketdao.c

src/module/CMakeFiles/module.dir/SocketDao/socketdao.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/module.dir/SocketDao/socketdao.c.i"
	cd /home/zxy/learn/CC/CGI/build/src/module && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zxy/learn/CC/CGI/src/module/SocketDao/socketdao.c > CMakeFiles/module.dir/SocketDao/socketdao.c.i

src/module/CMakeFiles/module.dir/SocketDao/socketdao.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/module.dir/SocketDao/socketdao.c.s"
	cd /home/zxy/learn/CC/CGI/build/src/module && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zxy/learn/CC/CGI/src/module/SocketDao/socketdao.c -o CMakeFiles/module.dir/SocketDao/socketdao.c.s

src/module/CMakeFiles/module.dir/Log/log.c.o: src/module/CMakeFiles/module.dir/flags.make
src/module/CMakeFiles/module.dir/Log/log.c.o: ../src/module/Log/log.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxy/learn/CC/CGI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object src/module/CMakeFiles/module.dir/Log/log.c.o"
	cd /home/zxy/learn/CC/CGI/build/src/module && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/module.dir/Log/log.c.o   -c /home/zxy/learn/CC/CGI/src/module/Log/log.c

src/module/CMakeFiles/module.dir/Log/log.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/module.dir/Log/log.c.i"
	cd /home/zxy/learn/CC/CGI/build/src/module && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zxy/learn/CC/CGI/src/module/Log/log.c > CMakeFiles/module.dir/Log/log.c.i

src/module/CMakeFiles/module.dir/Log/log.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/module.dir/Log/log.c.s"
	cd /home/zxy/learn/CC/CGI/build/src/module && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zxy/learn/CC/CGI/src/module/Log/log.c -o CMakeFiles/module.dir/Log/log.c.s

src/module/CMakeFiles/module.dir/Pro/jsonrpc-c.c.o: src/module/CMakeFiles/module.dir/flags.make
src/module/CMakeFiles/module.dir/Pro/jsonrpc-c.c.o: ../src/module/Pro/jsonrpc-c.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxy/learn/CC/CGI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object src/module/CMakeFiles/module.dir/Pro/jsonrpc-c.c.o"
	cd /home/zxy/learn/CC/CGI/build/src/module && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/module.dir/Pro/jsonrpc-c.c.o   -c /home/zxy/learn/CC/CGI/src/module/Pro/jsonrpc-c.c

src/module/CMakeFiles/module.dir/Pro/jsonrpc-c.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/module.dir/Pro/jsonrpc-c.c.i"
	cd /home/zxy/learn/CC/CGI/build/src/module && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zxy/learn/CC/CGI/src/module/Pro/jsonrpc-c.c > CMakeFiles/module.dir/Pro/jsonrpc-c.c.i

src/module/CMakeFiles/module.dir/Pro/jsonrpc-c.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/module.dir/Pro/jsonrpc-c.c.s"
	cd /home/zxy/learn/CC/CGI/build/src/module && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zxy/learn/CC/CGI/src/module/Pro/jsonrpc-c.c -o CMakeFiles/module.dir/Pro/jsonrpc-c.c.s

src/module/CMakeFiles/module.dir/FManager/fmanager.c.o: src/module/CMakeFiles/module.dir/flags.make
src/module/CMakeFiles/module.dir/FManager/fmanager.c.o: ../src/module/FManager/fmanager.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zxy/learn/CC/CGI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object src/module/CMakeFiles/module.dir/FManager/fmanager.c.o"
	cd /home/zxy/learn/CC/CGI/build/src/module && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/module.dir/FManager/fmanager.c.o   -c /home/zxy/learn/CC/CGI/src/module/FManager/fmanager.c

src/module/CMakeFiles/module.dir/FManager/fmanager.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/module.dir/FManager/fmanager.c.i"
	cd /home/zxy/learn/CC/CGI/build/src/module && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zxy/learn/CC/CGI/src/module/FManager/fmanager.c > CMakeFiles/module.dir/FManager/fmanager.c.i

src/module/CMakeFiles/module.dir/FManager/fmanager.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/module.dir/FManager/fmanager.c.s"
	cd /home/zxy/learn/CC/CGI/build/src/module && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zxy/learn/CC/CGI/src/module/FManager/fmanager.c -o CMakeFiles/module.dir/FManager/fmanager.c.s

# Object files for target module
module_OBJECTS = \
"CMakeFiles/module.dir/TaskManager/taskmanger.c.o" \
"CMakeFiles/module.dir/SData/cJSON.c.o" \
"CMakeFiles/module.dir/SocketDao/html_lib.c.o" \
"CMakeFiles/module.dir/SocketDao/socketdao.c.o" \
"CMakeFiles/module.dir/Log/log.c.o" \
"CMakeFiles/module.dir/Pro/jsonrpc-c.c.o" \
"CMakeFiles/module.dir/FManager/fmanager.c.o"

# External object files for target module
module_EXTERNAL_OBJECTS =

src/module/libmodule.a: src/module/CMakeFiles/module.dir/TaskManager/taskmanger.c.o
src/module/libmodule.a: src/module/CMakeFiles/module.dir/SData/cJSON.c.o
src/module/libmodule.a: src/module/CMakeFiles/module.dir/SocketDao/html_lib.c.o
src/module/libmodule.a: src/module/CMakeFiles/module.dir/SocketDao/socketdao.c.o
src/module/libmodule.a: src/module/CMakeFiles/module.dir/Log/log.c.o
src/module/libmodule.a: src/module/CMakeFiles/module.dir/Pro/jsonrpc-c.c.o
src/module/libmodule.a: src/module/CMakeFiles/module.dir/FManager/fmanager.c.o
src/module/libmodule.a: src/module/CMakeFiles/module.dir/build.make
src/module/libmodule.a: src/module/CMakeFiles/module.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zxy/learn/CC/CGI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C static library libmodule.a"
	cd /home/zxy/learn/CC/CGI/build/src/module && $(CMAKE_COMMAND) -P CMakeFiles/module.dir/cmake_clean_target.cmake
	cd /home/zxy/learn/CC/CGI/build/src/module && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/module.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/module/CMakeFiles/module.dir/build: src/module/libmodule.a

.PHONY : src/module/CMakeFiles/module.dir/build

src/module/CMakeFiles/module.dir/clean:
	cd /home/zxy/learn/CC/CGI/build/src/module && $(CMAKE_COMMAND) -P CMakeFiles/module.dir/cmake_clean.cmake
.PHONY : src/module/CMakeFiles/module.dir/clean

src/module/CMakeFiles/module.dir/depend:
	cd /home/zxy/learn/CC/CGI/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zxy/learn/CC/CGI /home/zxy/learn/CC/CGI/src/module /home/zxy/learn/CC/CGI/build /home/zxy/learn/CC/CGI/build/src/module /home/zxy/learn/CC/CGI/build/src/module/CMakeFiles/module.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/module/CMakeFiles/module.dir/depend

