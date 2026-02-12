//
// Created by sotti on 12/02/2026.
//

#include "ToDo.h"
#include <sstream>
#include <vector>

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

void ToDo::changeCompleted() {
    this->completed = !completed;
}

std::string ToDo::getDate() const {
    std::stringstream ss;
    ss << date.getDay() << "/" << date.getMonth() << "/" << date.getYear();
    return ss.str();
}

Date ToDo::getDateString(const std::string& dateString) {
    std::stringstream stream(dateString); //inizializzo lo steram con dati da poterli leggere
    std::string temporary; //stringa temporanea dove salvo i pezzi della data
    std::vector<int> parts;
    //divide la stringa "giorno/mese/anno"
    while (std::getline(stream, temporary, '/'))//legge stream e mette il contenuto in temporary e si ferma ogni volta che trova il carattere /
    {
        parts.push_back(std::stoi(temporary));
    }
    if (parts.size() != 3) {
        throw std::invalid_argument("Data nel file non valida");//verifica se abbiamo esattamente tre numeri
    }
    return Date(parts[0], parts[1], parts[2]);
}

bool ToDo::operator==(const ToDo& todo) const {
    if (this->date == todo.date && this->description == todo.description)
        return true;
    return false;
}
