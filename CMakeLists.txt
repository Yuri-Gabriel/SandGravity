cmake_minimum_required(VERSION 3.25)
project(sandgravity)
add_executable(sandgravity main.cpp)
target_link_libraries(sandgravity -lglut -lglfw -lGLEW -lGL -lGLU)