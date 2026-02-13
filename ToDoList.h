//
// Created by sotti on 13/02/2026.
//

#ifndef TODOLIST_TODOLIST_H
#define TODOLIST_TODOLIST_H
#include "ToDo.h"
#include <list>

class ToDoList {
private:
    std::string name;
    std::list<ToDo> activities_list;
public:
    explicit ToDoList(std::string name);//explicit per imperdire che il compilatore tratti una stringa come se fosse una ToDoList
    ToDoList() = default;
};


#endif //TODOLIST_TODOLIST_H