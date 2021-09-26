cmake_minimum_required(VERSION 3.13)
project(note-warrior)

set(CMAKE_CXX_STANDARD 14)

find_package(raylib CONFIG REQUIRED)

add_executable(note-warrior src/main.cpp src/Octagon/Octagon.cpp src/Octagon/Octagon.h src/Functions/Functions.cpp src/Functions/Functions.h src/Octagon/Note/Note.cpp src/Octagon/Note/Note.h src/Game/Game.cpp src/Game/Game.h src/MainMenu/MainMenu.cpp src/MainMenu/MainMenu.h src/ControlsController/ControlsController.cpp src/ControlsController/ControlsController.h src/main.h)

target_include_directories(note-warrior PRIVATE ${RAYLIB_INCLUDE_DIRS})
target_link_libraries(note-warrior PRIVATE ${RAYLIB_LIBRARIES})