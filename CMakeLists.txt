cmake_minimum_required(VERSION 4.1)
project(ToDoList)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(Test)
set(SOURCE_FILES
        Date.cpp
        Date.h
        ToDo.h
        ToDo.cpp
        ToDoList.h
        ToDoList.cpp)
add_executable(ToDoList main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(ToDoList core)