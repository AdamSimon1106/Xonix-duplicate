cmake_minimum_required (VERSION 3.26)

project (oop2_ex04)
set (MY_AUTHORS "Adam_Simonov-Benny_Beer")

include (cmake/CompilerSettings.cmake)

add_executable (${CMAKE_PROJECT_NAME}
        src/main.cpp
        src/Board.cpp
        include/Board.h
        src/FileParser.cpp
        include/FileParser.h
        src/GameController.cpp
        include/GameController.h
        src/Player.cpp
        include/Player.h
        src/Enemy.cpp
        include/Enemy.h
        src/Hud.cpp
        include/Hud.h
        include/Tile.h
        src/Tile.cpp)

        # Copy the entire resources/ folder into the build directory
file(COPY resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:DEBUG>:-fsanitize=address>)
if (NOT MSVC)
    target_link_options(${CMAKE_PROJECT_NAME} PRIVATE $<$<CONFIG:DEBUG>:-fsanitize=address>)
endif()

add_subdirectory (include)
add_subdirectory (src)
add_subdirectory (resources)

include (cmake/Zip.cmake)
if(APPLE)
    set (SFML_LOCATION "/opt/homebrew/Cellar/sfml@2/2.6.2_1")
    set (SFML_DIR "${SFML_LOCATION}/lib/cmake/SFML")
endif ()
if(WIN32)
    set (SFML_LOCATION "C:/SFML/SFML-2.6.1")
    set (SFML_DIR "${SFML_LOCATION}/lib/cmake/SFML")
endif ()
find_package (SFML 2.6 COMPONENTS graphics REQUIRED)

#set_target_properties (sfml-main sfml-system sfml-window sfml-graphics sfml-audio sfml-network PROPERTIES MAP_IMPORTED_CONFIG_RELWITHDEBINFO RELEASE)
target_link_libraries (${CMAKE_PROJECT_NAME} sfml-graphics)
#target_link_libraries (${CMAKE_PROJECT_NAME} sfml-graphics sfml-main)

include (cmake/SFML.cmake)

