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
CMAKE_SOURCE_DIR = /home/student-4/robtic_project_2024/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/student-4/robtic_project_2024/build

# Include any dependencies generated for this target.
include welcome_robot/CMakeFiles/localization_welcome_robot_node.dir/depend.make

# Include the progress variables for this target.
include welcome_robot/CMakeFiles/localization_welcome_robot_node.dir/progress.make

# Include the compile flags for this target's objects.
include welcome_robot/CMakeFiles/localization_welcome_robot_node.dir/flags.make

welcome_robot/CMakeFiles/localization_welcome_robot_node.dir/src/localization_node.cpp.o: welcome_robot/CMakeFiles/localization_welcome_robot_node.dir/flags.make
welcome_robot/CMakeFiles/localization_welcome_robot_node.dir/src/localization_node.cpp.o: /home/student-4/robtic_project_2024/src/welcome_robot/src/localization_node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student-4/robtic_project_2024/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object welcome_robot/CMakeFiles/localization_welcome_robot_node.dir/src/localization_node.cpp.o"
	cd /home/student-4/robtic_project_2024/build/welcome_robot && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/localization_welcome_robot_node.dir/src/localization_node.cpp.o -c /home/student-4/robtic_project_2024/src/welcome_robot/src/localization_node.cpp

welcome_robot/CMakeFiles/localization_welcome_robot_node.dir/src/localization_node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/localization_welcome_robot_node.dir/src/localization_node.cpp.i"
	cd /home/student-4/robtic_project_2024/build/welcome_robot && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student-4/robtic_project_2024/src/welcome_robot/src/localization_node.cpp > CMakeFiles/localization_welcome_robot_node.dir/src/localization_node.cpp.i

welcome_robot/CMakeFiles/localization_welcome_robot_node.dir/src/localization_node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/localization_welcome_robot_node.dir/src/localization_node.cpp.s"
	cd /home/student-4/robtic_project_2024/build/welcome_robot && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student-4/robtic_project_2024/src/welcome_robot/src/localization_node.cpp -o CMakeFiles/localization_welcome_robot_node.dir/src/localization_node.cpp.s

welcome_robot/CMakeFiles/localization_welcome_robot_node.dir/src/localization.cpp.o: welcome_robot/CMakeFiles/localization_welcome_robot_node.dir/flags.make
welcome_robot/CMakeFiles/localization_welcome_robot_node.dir/src/localization.cpp.o: /home/student-4/robtic_project_2024/src/welcome_robot/src/localization.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student-4/robtic_project_2024/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object welcome_robot/CMakeFiles/localization_welcome_robot_node.dir/src/localization.cpp.o"
	cd /home/student-4/robtic_project_2024/build/welcome_robot && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/localization_welcome_robot_node.dir/src/localization.cpp.o -c /home/student-4/robtic_project_2024/src/welcome_robot/src/localization.cpp

welcome_robot/CMakeFiles/localization_welcome_robot_node.dir/src/localization.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/localization_welcome_robot_node.dir/src/localization.cpp.i"
	cd /home/student-4/robtic_project_2024/build/welcome_robot && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student-4/robtic_project_2024/src/welcome_robot/src/localization.cpp > CMakeFiles/localization_welcome_robot_node.dir/src/localization.cpp.i

welcome_robot/CMakeFiles/localization_welcome_robot_node.dir/src/localization.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/localization_welcome_robot_node.dir/src/localization.cpp.s"
	cd /home/student-4/robtic_project_2024/build/welcome_robot && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student-4/robtic_project_2024/src/welcome_robot/src/localization.cpp -o CMakeFiles/localization_welcome_robot_node.dir/src/localization.cpp.s

# Object files for target localization_welcome_robot_node
localization_welcome_robot_node_OBJECTS = \
"CMakeFiles/localization_welcome_robot_node.dir/src/localization_node.cpp.o" \
"CMakeFiles/localization_welcome_robot_node.dir/src/localization.cpp.o"

# External object files for target localization_welcome_robot_node
localization_welcome_robot_node_EXTERNAL_OBJECTS =

/home/student-4/robtic_project_2024/devel/lib/welcome_robot/localization_welcome_robot_node: welcome_robot/CMakeFiles/localization_welcome_robot_node.dir/src/localization_node.cpp.o
/home/student-4/robtic_project_2024/devel/lib/welcome_robot/localization_welcome_robot_node: welcome_robot/CMakeFiles/localization_welcome_robot_node.dir/src/localization.cpp.o
/home/student-4/robtic_project_2024/devel/lib/welcome_robot/localization_welcome_robot_node: welcome_robot/CMakeFiles/localization_welcome_robot_node.dir/build.make
/home/student-4/robtic_project_2024/devel/lib/welcome_robot/localization_welcome_robot_node: /opt/ros/noetic/lib/libtf.so
/home/student-4/robtic_project_2024/devel/lib/welcome_robot/localization_welcome_robot_node: /opt/ros/noetic/lib/libtf2_ros.so
/home/student-4/robtic_project_2024/devel/lib/welcome_robot/localization_welcome_robot_node: /opt/ros/noetic/lib/libactionlib.so
/home/student-4/robtic_project_2024/devel/lib/welcome_robot/localization_welcome_robot_node: /opt/ros/noetic/lib/libmessage_filters.so
/home/student-4/robtic_project_2024/devel/lib/welcome_robot/localization_welcome_robot_node: /opt/ros/noetic/lib/libroscpp.so
/home/student-4/robtic_project_2024/devel/lib/welcome_robot/localization_welcome_robot_node: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/student-4/robtic_project_2024/devel/lib/welcome_robot/localization_welcome_robot_node: /usr/lib/x86_64-linux-gnu/libboost_chrono.so.1.71.0
/home/student-4/robtic_project_2024/devel/lib/welcome_robot/localization_welcome_robot_node: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.71.0
/home/student-4/robtic_project_2024/devel/lib/welcome_robot/localization_welcome_robot_node: /opt/ros/noetic/lib/libxmlrpcpp.so
/home/student-4/robtic_project_2024/devel/lib/welcome_robot/localization_welcome_robot_node: /opt/ros/noetic/lib/libtf2.so
/home/student-4/robtic_project_2024/devel/lib/welcome_robot/localization_welcome_robot_node: /opt/ros/noetic/lib/libroscpp_serialization.so
/home/student-4/robtic_project_2024/devel/lib/welcome_robot/localization_welcome_robot_node: /opt/ros/noetic/lib/librosconsole.so
/home/student-4/robtic_project_2024/devel/lib/welcome_robot/localization_welcome_robot_node: /opt/ros/noetic/lib/librosconsole_log4cxx.so
/home/student-4/robtic_project_2024/devel/lib/welcome_robot/localization_welcome_robot_node: /opt/ros/noetic/lib/librosconsole_backend_interface.so
/home/student-4/robtic_project_2024/devel/lib/welcome_robot/localization_welcome_robot_node: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/student-4/robtic_project_2024/devel/lib/welcome_robot/localization_welcome_robot_node: /usr/lib/x86_64-linux-gnu/libboost_regex.so.1.71.0
/home/student-4/robtic_project_2024/devel/lib/welcome_robot/localization_welcome_robot_node: /opt/ros/noetic/lib/librostime.so
/home/student-4/robtic_project_2024/devel/lib/welcome_robot/localization_welcome_robot_node: /usr/lib/x86_64-linux-gnu/libboost_date_time.so.1.71.0
/home/student-4/robtic_project_2024/devel/lib/welcome_robot/localization_welcome_robot_node: /opt/ros/noetic/lib/libcpp_common.so
/home/student-4/robtic_project_2024/devel/lib/welcome_robot/localization_welcome_robot_node: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.71.0
/home/student-4/robtic_project_2024/devel/lib/welcome_robot/localization_welcome_robot_node: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.71.0
/home/student-4/robtic_project_2024/devel/lib/welcome_robot/localization_welcome_robot_node: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/student-4/robtic_project_2024/devel/lib/welcome_robot/localization_welcome_robot_node: welcome_robot/CMakeFiles/localization_welcome_robot_node.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/student-4/robtic_project_2024/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable /home/student-4/robtic_project_2024/devel/lib/welcome_robot/localization_welcome_robot_node"
	cd /home/student-4/robtic_project_2024/build/welcome_robot && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/localization_welcome_robot_node.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
welcome_robot/CMakeFiles/localization_welcome_robot_node.dir/build: /home/student-4/robtic_project_2024/devel/lib/welcome_robot/localization_welcome_robot_node

.PHONY : welcome_robot/CMakeFiles/localization_welcome_robot_node.dir/build

welcome_robot/CMakeFiles/localization_welcome_robot_node.dir/clean:
	cd /home/student-4/robtic_project_2024/build/welcome_robot && $(CMAKE_COMMAND) -P CMakeFiles/localization_welcome_robot_node.dir/cmake_clean.cmake
.PHONY : welcome_robot/CMakeFiles/localization_welcome_robot_node.dir/clean

welcome_robot/CMakeFiles/localization_welcome_robot_node.dir/depend:
	cd /home/student-4/robtic_project_2024/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/student-4/robtic_project_2024/src /home/student-4/robtic_project_2024/src/welcome_robot /home/student-4/robtic_project_2024/build /home/student-4/robtic_project_2024/build/welcome_robot /home/student-4/robtic_project_2024/build/welcome_robot/CMakeFiles/localization_welcome_robot_node.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : welcome_robot/CMakeFiles/localization_welcome_robot_node.dir/depend

