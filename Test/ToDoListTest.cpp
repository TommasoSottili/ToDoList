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

TEST_F(ToDoListTest, CountsCorrect) {
    EXPECT_EQ(list.totalToDoCount(),3);
    list.ToDoCompleted("Compito A");
    EXPECT_EQ(list.uncompletedToDoCount(),2);
    list.ToDoCompleted("Compito A");
}

TEST_F(ToDoListTest, ListRetrieval) {
    EXPECT_EQ(list.getToDoList().size(),3);
    list.ToDoCompleted("Compito A");
    std::list<ToDo> uncompletedToDoList = list.getUncompletedTodo();
    EXPECT_EQ(uncompletedToDoList.size(),2);
    EXPECT_EQ(uncompletedToDoList.front().getDescription(), "Compito B");
}

TEST_F(ToDoListTest, RemoveAllTodos) {
    list.removeAllToDo();
    EXPECT_EQ(list.totalToDoCount(),0);
    EXPECT_EQ(list.uncompletedToDoCount(),0);
    EXPECT_TRUE(list.getToDoList().empty());
}

TEST_F(ToDoListTest, ChangeCompleted) {
    list.ToDoCompleted("Compito A");
    list.ToDoCompleted("Compito B");
    EXPECT_EQ(list.uncompletedToDoCount(),1);
    bool fad = false;
    for (const auto& item : list.getToDoList()) {
        if (item.getDescription() == "Compito A" &&  item.isCompleted()) {
            fad = true;
        }
    }
    EXPECT_TRUE(fad);
}

