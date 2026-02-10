cmake_minimum_required(VERSION 4.1)
project(ToDoList)

set(CMAKE_CXX_STANDARD 20)

add_executable(ToDoList main.cpp
        Date.cpp
        Date.h)
