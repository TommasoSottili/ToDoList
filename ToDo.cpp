//
// Created by sotti on 12/02/2026.
//

#include "ToDo.h"

ToDo::ToDo(const Date& date, const std::string& description):date(date), description(description),completed(false) {};

std::string ToDo::getDescription() const {
    return description;
}

void ToDo::setDescription(const std::string& description) {
    this->description = description;
}

void ToDo::setCompleted(bool completed) {
    this->completed = completed;
}

bool ToDo::isCompleted() const {
    return completed;
}

void ToDo::changeCompleted(bool completed) {
    this->completed = !completed;
}
