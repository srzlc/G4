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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.14.5/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.14.5/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sharong/Desktop/G4/S1.2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sharong/Desktop/G4/S1.2/build

# Include any dependencies generated for this target.
include CMakeFiles/S1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/S1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/S1.dir/flags.make

CMakeFiles/S1.dir/S1.cc.o: CMakeFiles/S1.dir/flags.make
CMakeFiles/S1.dir/S1.cc.o: ../S1.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sharong/Desktop/G4/S1.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/S1.dir/S1.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/S1.dir/S1.cc.o -c /Users/sharong/Desktop/G4/S1.2/S1.cc

CMakeFiles/S1.dir/S1.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/S1.dir/S1.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sharong/Desktop/G4/S1.2/S1.cc > CMakeFiles/S1.dir/S1.cc.i

CMakeFiles/S1.dir/S1.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/S1.dir/S1.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sharong/Desktop/G4/S1.2/S1.cc -o CMakeFiles/S1.dir/S1.cc.s

CMakeFiles/S1.dir/src/S1ActionInitialization.cc.o: CMakeFiles/S1.dir/flags.make
CMakeFiles/S1.dir/src/S1ActionInitialization.cc.o: ../src/S1ActionInitialization.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sharong/Desktop/G4/S1.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/S1.dir/src/S1ActionInitialization.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/S1.dir/src/S1ActionInitialization.cc.o -c /Users/sharong/Desktop/G4/S1.2/src/S1ActionInitialization.cc

CMakeFiles/S1.dir/src/S1ActionInitialization.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/S1.dir/src/S1ActionInitialization.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sharong/Desktop/G4/S1.2/src/S1ActionInitialization.cc > CMakeFiles/S1.dir/src/S1ActionInitialization.cc.i

CMakeFiles/S1.dir/src/S1ActionInitialization.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/S1.dir/src/S1ActionInitialization.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sharong/Desktop/G4/S1.2/src/S1ActionInitialization.cc -o CMakeFiles/S1.dir/src/S1ActionInitialization.cc.s

CMakeFiles/S1.dir/src/S1DetectorConstruction.cc.o: CMakeFiles/S1.dir/flags.make
CMakeFiles/S1.dir/src/S1DetectorConstruction.cc.o: ../src/S1DetectorConstruction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sharong/Desktop/G4/S1.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/S1.dir/src/S1DetectorConstruction.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/S1.dir/src/S1DetectorConstruction.cc.o -c /Users/sharong/Desktop/G4/S1.2/src/S1DetectorConstruction.cc

CMakeFiles/S1.dir/src/S1DetectorConstruction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/S1.dir/src/S1DetectorConstruction.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sharong/Desktop/G4/S1.2/src/S1DetectorConstruction.cc > CMakeFiles/S1.dir/src/S1DetectorConstruction.cc.i

CMakeFiles/S1.dir/src/S1DetectorConstruction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/S1.dir/src/S1DetectorConstruction.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sharong/Desktop/G4/S1.2/src/S1DetectorConstruction.cc -o CMakeFiles/S1.dir/src/S1DetectorConstruction.cc.s

CMakeFiles/S1.dir/src/S1EventAction.cc.o: CMakeFiles/S1.dir/flags.make
CMakeFiles/S1.dir/src/S1EventAction.cc.o: ../src/S1EventAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sharong/Desktop/G4/S1.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/S1.dir/src/S1EventAction.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/S1.dir/src/S1EventAction.cc.o -c /Users/sharong/Desktop/G4/S1.2/src/S1EventAction.cc

CMakeFiles/S1.dir/src/S1EventAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/S1.dir/src/S1EventAction.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sharong/Desktop/G4/S1.2/src/S1EventAction.cc > CMakeFiles/S1.dir/src/S1EventAction.cc.i

CMakeFiles/S1.dir/src/S1EventAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/S1.dir/src/S1EventAction.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sharong/Desktop/G4/S1.2/src/S1EventAction.cc -o CMakeFiles/S1.dir/src/S1EventAction.cc.s

CMakeFiles/S1.dir/src/S1PrimaryGeneratorAction.cc.o: CMakeFiles/S1.dir/flags.make
CMakeFiles/S1.dir/src/S1PrimaryGeneratorAction.cc.o: ../src/S1PrimaryGeneratorAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sharong/Desktop/G4/S1.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/S1.dir/src/S1PrimaryGeneratorAction.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/S1.dir/src/S1PrimaryGeneratorAction.cc.o -c /Users/sharong/Desktop/G4/S1.2/src/S1PrimaryGeneratorAction.cc

CMakeFiles/S1.dir/src/S1PrimaryGeneratorAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/S1.dir/src/S1PrimaryGeneratorAction.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sharong/Desktop/G4/S1.2/src/S1PrimaryGeneratorAction.cc > CMakeFiles/S1.dir/src/S1PrimaryGeneratorAction.cc.i

CMakeFiles/S1.dir/src/S1PrimaryGeneratorAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/S1.dir/src/S1PrimaryGeneratorAction.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sharong/Desktop/G4/S1.2/src/S1PrimaryGeneratorAction.cc -o CMakeFiles/S1.dir/src/S1PrimaryGeneratorAction.cc.s

CMakeFiles/S1.dir/src/S1RunAction.cc.o: CMakeFiles/S1.dir/flags.make
CMakeFiles/S1.dir/src/S1RunAction.cc.o: ../src/S1RunAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sharong/Desktop/G4/S1.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/S1.dir/src/S1RunAction.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/S1.dir/src/S1RunAction.cc.o -c /Users/sharong/Desktop/G4/S1.2/src/S1RunAction.cc

CMakeFiles/S1.dir/src/S1RunAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/S1.dir/src/S1RunAction.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sharong/Desktop/G4/S1.2/src/S1RunAction.cc > CMakeFiles/S1.dir/src/S1RunAction.cc.i

CMakeFiles/S1.dir/src/S1RunAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/S1.dir/src/S1RunAction.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sharong/Desktop/G4/S1.2/src/S1RunAction.cc -o CMakeFiles/S1.dir/src/S1RunAction.cc.s

CMakeFiles/S1.dir/src/S1SteppingAction.cc.o: CMakeFiles/S1.dir/flags.make
CMakeFiles/S1.dir/src/S1SteppingAction.cc.o: ../src/S1SteppingAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sharong/Desktop/G4/S1.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/S1.dir/src/S1SteppingAction.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/S1.dir/src/S1SteppingAction.cc.o -c /Users/sharong/Desktop/G4/S1.2/src/S1SteppingAction.cc

CMakeFiles/S1.dir/src/S1SteppingAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/S1.dir/src/S1SteppingAction.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sharong/Desktop/G4/S1.2/src/S1SteppingAction.cc > CMakeFiles/S1.dir/src/S1SteppingAction.cc.i

CMakeFiles/S1.dir/src/S1SteppingAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/S1.dir/src/S1SteppingAction.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sharong/Desktop/G4/S1.2/src/S1SteppingAction.cc -o CMakeFiles/S1.dir/src/S1SteppingAction.cc.s

CMakeFiles/S1.dir/src/analysis.cc.o: CMakeFiles/S1.dir/flags.make
CMakeFiles/S1.dir/src/analysis.cc.o: ../src/analysis.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sharong/Desktop/G4/S1.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/S1.dir/src/analysis.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/S1.dir/src/analysis.cc.o -c /Users/sharong/Desktop/G4/S1.2/src/analysis.cc

CMakeFiles/S1.dir/src/analysis.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/S1.dir/src/analysis.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sharong/Desktop/G4/S1.2/src/analysis.cc > CMakeFiles/S1.dir/src/analysis.cc.i

CMakeFiles/S1.dir/src/analysis.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/S1.dir/src/analysis.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sharong/Desktop/G4/S1.2/src/analysis.cc -o CMakeFiles/S1.dir/src/analysis.cc.s

# Object files for target S1
S1_OBJECTS = \
"CMakeFiles/S1.dir/S1.cc.o" \
"CMakeFiles/S1.dir/src/S1ActionInitialization.cc.o" \
"CMakeFiles/S1.dir/src/S1DetectorConstruction.cc.o" \
"CMakeFiles/S1.dir/src/S1EventAction.cc.o" \
"CMakeFiles/S1.dir/src/S1PrimaryGeneratorAction.cc.o" \
"CMakeFiles/S1.dir/src/S1RunAction.cc.o" \
"CMakeFiles/S1.dir/src/S1SteppingAction.cc.o" \
"CMakeFiles/S1.dir/src/analysis.cc.o"

# External object files for target S1
S1_EXTERNAL_OBJECTS =

S1: CMakeFiles/S1.dir/S1.cc.o
S1: CMakeFiles/S1.dir/src/S1ActionInitialization.cc.o
S1: CMakeFiles/S1.dir/src/S1DetectorConstruction.cc.o
S1: CMakeFiles/S1.dir/src/S1EventAction.cc.o
S1: CMakeFiles/S1.dir/src/S1PrimaryGeneratorAction.cc.o
S1: CMakeFiles/S1.dir/src/S1RunAction.cc.o
S1: CMakeFiles/S1.dir/src/S1SteppingAction.cc.o
S1: CMakeFiles/S1.dir/src/analysis.cc.o
S1: CMakeFiles/S1.dir/build.make
S1: /Users/sharong/path/to/geant4/G4-install/lib/libG4Tree.dylib
S1: /Users/sharong/path/to/geant4/G4-install/lib/libG4GMocren.dylib
S1: /Users/sharong/path/to/geant4/G4-install/lib/libG4visHepRep.dylib
S1: /Users/sharong/path/to/geant4/G4-install/lib/libG4RayTracer.dylib
S1: /Users/sharong/path/to/geant4/G4-install/lib/libG4VRML.dylib
S1: /Users/sharong/path/to/geant4/G4-install/lib/libG4OpenGL.dylib
S1: /Users/sharong/path/to/geant4/G4-install/lib/libG4gl2ps.dylib
S1: /Users/sharong/path/to/geant4/G4-install/lib/libG4interfaces.dylib
S1: /Users/sharong/path/to/geant4/G4-install/lib/libG4persistency.dylib
S1: /Users/sharong/path/to/geant4/G4-install/lib/libG4error_propagation.dylib
S1: /Users/sharong/path/to/geant4/G4-install/lib/libG4readout.dylib
S1: /Users/sharong/path/to/geant4/G4-install/lib/libG4physicslists.dylib
S1: /Users/sharong/path/to/geant4/G4-install/lib/libG4parmodels.dylib
S1: /Users/sharong/path/to/geant4/G4-install/lib/libG4FR.dylib
S1: /Users/sharong/path/to/geant4/G4-install/lib/libG4vis_management.dylib
S1: /Users/sharong/path/to/geant4/G4-install/lib/libG4modeling.dylib
S1: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.15.sdk/System/Library/Frameworks/OpenGL.framework/OpenGL.tbd
S1: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.15.sdk/System/Library/Frameworks/OpenGL.framework/OpenGL.tbd
S1: /usr/local/opt/qt/lib/QtOpenGL.framework/QtOpenGL
S1: /usr/local/opt/qt/lib/QtPrintSupport.framework/QtPrintSupport
S1: /usr/local/opt/qt/lib/QtWidgets.framework/QtWidgets
S1: /usr/local/opt/qt/lib/QtGui.framework/QtGui
S1: /usr/local/opt/qt/lib/QtCore.framework/QtCore
S1: /Users/sharong/path/to/geant4/G4-install/lib/libG4run.dylib
S1: /Users/sharong/path/to/geant4/G4-install/lib/libG4event.dylib
S1: /Users/sharong/path/to/geant4/G4-install/lib/libG4tracking.dylib
S1: /Users/sharong/path/to/geant4/G4-install/lib/libG4processes.dylib
S1: /Users/sharong/path/to/geant4/G4-install/lib/libG4analysis.dylib
S1: /Users/sharong/path/to/geant4/G4-install/lib/libG4zlib.dylib
S1: /usr/lib/libexpat.dylib
S1: /Users/sharong/path/to/geant4/G4-install/lib/libG4digits_hits.dylib
S1: /Users/sharong/path/to/geant4/G4-install/lib/libG4track.dylib
S1: /Users/sharong/path/to/geant4/G4-install/lib/libG4particles.dylib
S1: /Users/sharong/path/to/geant4/G4-install/lib/libG4geometry.dylib
S1: /Users/sharong/path/to/geant4/G4-install/lib/libG4materials.dylib
S1: /Users/sharong/path/to/geant4/G4-install/lib/libG4graphics_reps.dylib
S1: /Users/sharong/path/to/geant4/G4-install/lib/libG4intercoms.dylib
S1: /Users/sharong/path/to/geant4/G4-install/lib/libG4global.dylib
S1: /Users/sharong/path/to/geant4/G4-install/lib/libG4clhep.dylib
S1: CMakeFiles/S1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sharong/Desktop/G4/S1.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable S1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/S1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/S1.dir/build: S1

.PHONY : CMakeFiles/S1.dir/build

CMakeFiles/S1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/S1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/S1.dir/clean

CMakeFiles/S1.dir/depend:
	cd /Users/sharong/Desktop/G4/S1.2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sharong/Desktop/G4/S1.2 /Users/sharong/Desktop/G4/S1.2 /Users/sharong/Desktop/G4/S1.2/build /Users/sharong/Desktop/G4/S1.2/build /Users/sharong/Desktop/G4/S1.2/build/CMakeFiles/S1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/S1.dir/depend

