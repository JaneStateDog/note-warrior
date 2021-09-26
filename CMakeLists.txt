cmake_minimum_required(VERSION 3.13)
project(note-warrior)

set(CMAKE_CXX_STANDARD 14)

find_package(raylib CONFIG REQUIRED)

add_executable(note-warrior src/main.cpp src/main.h src/Octagon/Octagon.cpp src/Octagon/Octagon.h src/Functions.cpp src/Functions.h src/Note/Note.cpp src/Note/Note.h)

target_include_directories(note-warrior PRIVATE ${RAYLIB_INCLUDE_DIRS})
target_link_libraries(note-warrior PRIVATE ${RAYLIB_LIBRARIES})