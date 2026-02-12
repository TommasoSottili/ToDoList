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

TEST(ToDoTest, CompletedTest) {
    ToDo todo(Date(9, 9, 2026), "Data Laurea");
    todo.changeCompleted();
    EXPECT_TRUE(todo.isCompleted());
    todo.changeCompleted();
    EXPECT_FALSE(todo.isCompleted());
}

TEST(ToDoTest, EqualityTest) {
    ToDo todo1(Date(9, 9, 2026), "Data Laurea");
    ToDo todo2(Date(9, 9, 2026), "Data Laurea");
    EXPECT_TRUE(todo1 == todo2);
}