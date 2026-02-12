//
// Created by sotti on 12/02/2026.
//

#ifndef TODOLIST_TODO_H
#define TODOLIST_TODO_H
#include <string>
#include "Date.h"

class ToDo {
private:
    Date date;
    bool completed;
    std::string description;
public:
    ToDo(const Date &date, const std::string& description);

    void setDescription(const std::string& description);
    void setCompleted(bool completed);
    std::string getDescription() const;
};


#endif //TODOLIST_TODO_H