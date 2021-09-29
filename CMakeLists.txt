cmake_minimum_required(VERSION 3.18)
project(Verlet)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML COMPONENTS graphics window system REQUIRED)
add_executable(
        Verlet main.cpp
        src/App.cpp
        src/App_Cleanup.cpp
        src/App_Event.cpp
        src/App_Init.cpp
        src/App_Loop.cpp
        src/App_Render.cpp
        src/Particle.cpp
        src/Stick.cpp
        src/VectorMath.cpp
        include/Verlet/QuadTree.h include/Verlet/Bounds.h
        src/QuadTree.cpp)
include_directories(Verlet ./include/)
target_link_libraries(Verlet sfml-graphics sfml-audio)

add_subdirectory(tests)