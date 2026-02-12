//
// Created by sotti on 12/02/2026.
//
#include "gtest/gtest.h"
#include "../ToDo.h"

TEST(ToDoTest, ConstructorTest) {
    ToDo todo(Date(9, 9, 2026), "Data Laurea");
    EXPECT_EQ(todo.getDate(), "9/9/2026");
    EXPECT_EQ(todo.getDescription(), "Data Laurea");
    EXPECT_FALSE(todo.isCompleted());
}