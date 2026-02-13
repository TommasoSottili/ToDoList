//
// Created by sotti on 13/02/2026.
//

#include "gtest/gtest.h"
#include "../ToDoList.h"

class ToDoListTest : public ::testing::Test {
protected:
    ToDoList list;

    void SetUp() override {
        list = ToDoList("Lista Test");

        list.addToDo(ToDo(Date(1,1,2024), "Compito A"));
        list.addToDo(ToDo(Date(2,1,2024), "Compito B"));
        list.addToDo(ToDo(Date(3,1,2024), "Compito C"));
    }
};

