# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.28
cmake_policy(SET CMP0009 NEW)

# MY_HEADER_FILES at include/CMakeLists.txt:2 (file)
file(GLOB NEW_GLOB LIST_DIRECTORIES false RELATIVE "/Users/adamsimonov/לימודים/OOP2/oop2-ex04/include" "/Users/adamsimonov/לימודים/OOP2/oop2-ex04/include/*.h")
set(OLD_GLOB
  "Board.h"
  "Enemy.h"
  "FileParser.h"
  "FloodFill.h"
  "GameController.h"
  "Hud.h"
  "Player.h"
  "WindowManager.h"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/Users/adamsimonov/לימודים/OOP2/oop2-ex04/cmake-build-debug/CMakeFiles/cmake.verify_globs")
endif()

# MY_SOURCE_FILES at src/CMakeLists.txt:1 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false RELATIVE "/Users/adamsimonov/לימודים/OOP2/oop2-ex04/src" "/Users/adamsimonov/לימודים/OOP2/oop2-ex04/src/*.cpp")
set(OLD_GLOB
  "Board.cpp"
  "Enemy.cpp"
  "FileParser.cpp"
  "FloodFill.cpp"
  "GameController.cpp"
  "Hud.cpp"
  "Player.cpp"
  "WindowManager.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/Users/adamsimonov/לימודים/OOP2/oop2-ex04/cmake-build-debug/CMakeFiles/cmake.verify_globs")
endif()
