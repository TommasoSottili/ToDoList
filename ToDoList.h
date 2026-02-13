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
};


#endif //TODOLIST_TODOLIST_H