//
// Created by sotti on 13/02/2026.
//

#include "ToDoList.h"
#include <algorithm>
#include <utility>
#include <fstream>
#include <sstream>
#include <vector>

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

const std::list<ToDo>& ToDoList::getToDoList() const{
    return activities_list;
}

std::list<ToDo> ToDoList::getUncompletedTodo() const {
    std::list<ToDo> uncompleted;
    for (const auto& it : activities_list)
    {
        if (!it.isCompleted())
            uncompleted.push_back(it);
    }
    return uncompleted;
}

void ToDoList::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Errore nella scrittura sul file");
    for (const auto& it : activities_list) {
        file << it.getDescription() << "|"
             << it.getDate() << "|"
             << it.isCompleted() << "\n";
    }
    file.close();
}

void ToDoList::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open())
        return;
    activities_list.clear();
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string item;
        std::vector<std::string> tokens;
        while (std::getline(ss, item, '|')) {
            tokens.push_back(item);
        }
        if (tokens.size() >= 3) {
            try {
                std::string description = tokens[0];
                std::string dateStr = tokens[1];
                bool completed = (tokens[2] == "1");
                Date date = ToDo::getDateString(dateStr);
                ToDo todo(date,description);
                if (completed) {
                    todo.setCompleted(true);
                }
                activities_list.push_back(todo);
            }
            catch (...) {}
        }
    }
    file.close();
}

