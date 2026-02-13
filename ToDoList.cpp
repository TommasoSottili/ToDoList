//
// Created by sotti on 13/02/2026.
//

#include "ToDoList.h"

ToDoList::ToDoList(std::string name): name(std::move(name)) {};

void ToDoList::removeAllToDo() {
    activities_list.clear();
}

void ToDoList::addToDo(const ToDo& activity) {
    activities_list.push_back(activity);
}

void ToDoList::removeToDo(const std::string& description) {
    activities_list.remove_if([&description](const ToDo& t) {
       return t.getDescription() == description;
   });//implementazione Lambda Expression
}
