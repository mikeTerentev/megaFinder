# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = "/Users/miketerentyev/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/183.4886.39/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/miketerentyev/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/183.4886.39/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/miketerentyev/itmo/2-year/MegaFinder

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/miketerentyev/itmo/2-year/MegaFinder/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Run.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Run.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Run.dir/flags.make

CMakeFiles/Run.dir/main.cpp.o: CMakeFiles/Run.dir/flags.make
CMakeFiles/Run.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/miketerentyev/itmo/2-year/MegaFinder/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Run.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Run.dir/main.cpp.o -c /Users/miketerentyev/itmo/2-year/MegaFinder/main.cpp

CMakeFiles/Run.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Run.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/miketerentyev/itmo/2-year/MegaFinder/main.cpp > CMakeFiles/Run.dir/main.cpp.i

CMakeFiles/Run.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Run.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/miketerentyev/itmo/2-year/MegaFinder/main.cpp -o CMakeFiles/Run.dir/main.cpp.s

CMakeFiles/Run.dir/Run_autogen/mocs_compilation.cpp.o: CMakeFiles/Run.dir/flags.make
CMakeFiles/Run.dir/Run_autogen/mocs_compilation.cpp.o: Run_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/miketerentyev/itmo/2-year/MegaFinder/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Run.dir/Run_autogen/mocs_compilation.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Run.dir/Run_autogen/mocs_compilation.cpp.o -c /Users/miketerentyev/itmo/2-year/MegaFinder/cmake-build-debug/Run_autogen/mocs_compilation.cpp

CMakeFiles/Run.dir/Run_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Run.dir/Run_autogen/mocs_compilation.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/miketerentyev/itmo/2-year/MegaFinder/cmake-build-debug/Run_autogen/mocs_compilation.cpp > CMakeFiles/Run.dir/Run_autogen/mocs_compilation.cpp.i

CMakeFiles/Run.dir/Run_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Run.dir/Run_autogen/mocs_compilation.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/miketerentyev/itmo/2-year/MegaFinder/cmake-build-debug/Run_autogen/mocs_compilation.cpp -o CMakeFiles/Run.dir/Run_autogen/mocs_compilation.cpp.s

# Object files for target Run
Run_OBJECTS = \
"CMakeFiles/Run.dir/main.cpp.o" \
"CMakeFiles/Run.dir/Run_autogen/mocs_compilation.cpp.o"

# External object files for target Run
Run_EXTERNAL_OBJECTS =

Run: CMakeFiles/Run.dir/main.cpp.o
Run: CMakeFiles/Run.dir/Run_autogen/mocs_compilation.cpp.o
Run: CMakeFiles/Run.dir/build.make
Run: libMegaFinder.a
Run: /Users/miketerentyev/Qt/5.11.2/clang_64/lib/QtWidgets.framework/QtWidgets
Run: /Users/miketerentyev/Qt/5.11.2/clang_64/lib/QtQuickControls2.framework/QtQuickControls2
Run: /Users/miketerentyev/Qt/5.11.2/clang_64/lib/QtQuick.framework/QtQuick
Run: /Users/miketerentyev/Qt/5.11.2/clang_64/lib/QtGui.framework/QtGui
Run: /Users/miketerentyev/Qt/5.11.2/clang_64/lib/QtQml.framework/QtQml
Run: /Users/miketerentyev/Qt/5.11.2/clang_64/lib/QtNetwork.framework/QtNetwork
Run: /Users/miketerentyev/Qt/5.11.2/clang_64/lib/QtCore.framework/QtCore
Run: CMakeFiles/Run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/miketerentyev/itmo/2-year/MegaFinder/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Run"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Run.dir/build: Run

.PHONY : CMakeFiles/Run.dir/build

CMakeFiles/Run.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Run.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Run.dir/clean

CMakeFiles/Run.dir/depend:
	cd /Users/miketerentyev/itmo/2-year/MegaFinder/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/miketerentyev/itmo/2-year/MegaFinder /Users/miketerentyev/itmo/2-year/MegaFinder /Users/miketerentyev/itmo/2-year/MegaFinder/cmake-build-debug /Users/miketerentyev/itmo/2-year/MegaFinder/cmake-build-debug /Users/miketerentyev/itmo/2-year/MegaFinder/cmake-build-debug/CMakeFiles/Run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Run.dir/depend

