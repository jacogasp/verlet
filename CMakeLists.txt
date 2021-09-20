cmake_minimum_required(VERSION 3.20)
project(Verlet)

set(CMAKE_CXX_STANDARD 14)
file(GLOB source_files ./src/**.cpp)

find_package(SFML COMPONENTS graphics window system REQUIRED)
add_executable(Verlet main.cpp ${source_files})
include_directories(Verlet ./include/)
target_link_libraries(Verlet sfml-graphics sfml-audio)