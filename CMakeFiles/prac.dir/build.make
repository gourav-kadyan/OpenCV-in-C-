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
CMAKE_SOURCE_DIR = /home/kpit/OpenPrac

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kpit/OpenPrac

# Include any dependencies generated for this target.
include CMakeFiles/prac.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/prac.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/prac.dir/flags.make

CMakeFiles/prac.dir/SIFT.cpp.o: CMakeFiles/prac.dir/flags.make
CMakeFiles/prac.dir/SIFT.cpp.o: SIFT.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kpit/OpenPrac/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/prac.dir/SIFT.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/prac.dir/SIFT.cpp.o -c /home/kpit/OpenPrac/SIFT.cpp

CMakeFiles/prac.dir/SIFT.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prac.dir/SIFT.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kpit/OpenPrac/SIFT.cpp > CMakeFiles/prac.dir/SIFT.cpp.i

CMakeFiles/prac.dir/SIFT.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prac.dir/SIFT.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kpit/OpenPrac/SIFT.cpp -o CMakeFiles/prac.dir/SIFT.cpp.s

# Object files for target prac
prac_OBJECTS = \
"CMakeFiles/prac.dir/SIFT.cpp.o"

# External object files for target prac
prac_EXTERNAL_OBJECTS =

prac: CMakeFiles/prac.dir/SIFT.cpp.o
prac: CMakeFiles/prac.dir/build.make
prac: /usr/local/lib/libopencv_gapi.so.4.9.0
prac: /usr/local/lib/libopencv_highgui.so.4.9.0
prac: /usr/local/lib/libopencv_ml.so.4.9.0
prac: /usr/local/lib/libopencv_objdetect.so.4.9.0
prac: /usr/local/lib/libopencv_photo.so.4.9.0
prac: /usr/local/lib/libopencv_stitching.so.4.9.0
prac: /usr/local/lib/libopencv_video.so.4.9.0
prac: /usr/local/lib/libopencv_videoio.so.4.9.0
prac: /usr/local/lib/libopencv_imgcodecs.so.4.9.0
prac: /usr/local/lib/libopencv_dnn.so.4.9.0
prac: /usr/local/lib/libopencv_calib3d.so.4.9.0
prac: /usr/local/lib/libopencv_features2d.so.4.9.0
prac: /usr/local/lib/libopencv_flann.so.4.9.0
prac: /usr/local/lib/libopencv_imgproc.so.4.9.0
prac: /usr/local/lib/libopencv_core.so.4.9.0
prac: CMakeFiles/prac.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kpit/OpenPrac/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable prac"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/prac.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/prac.dir/build: prac

.PHONY : CMakeFiles/prac.dir/build

CMakeFiles/prac.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/prac.dir/cmake_clean.cmake
.PHONY : CMakeFiles/prac.dir/clean

CMakeFiles/prac.dir/depend:
	cd /home/kpit/OpenPrac && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kpit/OpenPrac /home/kpit/OpenPrac /home/kpit/OpenPrac /home/kpit/OpenPrac /home/kpit/OpenPrac/CMakeFiles/prac.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/prac.dir/depend

