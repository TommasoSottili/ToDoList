//
// Created by sotti on 13/02/2026.
//

#include "ToDoList.h"
#include <algorithm>

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

std::list<ToDo>::iterator ToDoList::findActivity(const std::string& description) {
    for (auto it = activities_list.begin(); it != activities_list.end(); ++it)
    {
        if (it->getDescription() == description)
            return it;
    }
    return activities_list.end();
}

void ToDoList::ToDoCompleted(const std::string& description) {
    auto it = findActivity(description);
    if (it != activities_list.end()) {
        it->changeCompleted();
    }
}

void ToDoList::modify(const std::string& o, const std::string& n) {
    auto it = findActivity(o);
    if (it != activities_list.end()) {
        it->setDescription(n);
    }
    else {
        throw std::runtime_error("Attività '" + o + "' non trovata.");
    }
}

std::string ToDoList::getName() const {
    return name;
}

int ToDoList::totalToDoCount() const {
    return activities_list.size();
}

int ToDoList::uncompletedToDoCount() const {
    return std::count_if(activities_list.begin(), activities_list.end(), [](const ToDo& t){
       return !t.isCompleted();
   });
}


