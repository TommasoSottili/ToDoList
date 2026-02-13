//
// Created by sotti on 13/02/2026.
//

#ifndef TODOLIST_TODOLIST_H
#define TODOLIST_TODOLIST_H
#include "ToDo.h"
#include <list>
#include <stdexcept>
#include <fstream>

class ToDoList {
private:
    std::string name;
    std::list<ToDo> activities_list;
    std::list<ToDo>::iterator findActivity(const std::string& description);
public:
    explicit ToDoList(std::string name);//explicit per imperdire che il compilatore tratti una stringa come se fosse una ToDoList
    ToDoList() = default;

    void addToDo(const ToDo& activity);
    void removeToDo(const std::string& description);
    void removeAllToDo();

    void ToDoCompleted(const std::string& description);
    void modify(const std::string& o, const std::string& n);

    std::string getName() const;

    int totalToDoCount() const;
    int uncompletedToDoCount() const;

    const std::list<ToDo>& getToDoList() const;
    std::list<ToDo> getUncompletedTodo() const;

    void saveToFile(const std::string& filename) const;
};


#endif //TODOLIST_TODOLIST_H