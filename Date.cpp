//
// Created by sotti on 10/02/2026.
//

#include "Date.h"

Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

int Date::getDay() const {
    return this->day;
}

int Date::getMonth() const {
    return this->month;
}

int Date::getYear() const {
    return this->year;
}

void Date::setDay(int d) {
    this->day = d;
}

void Date::setMonth(int m) {
    this->month = m;
}

void Date::setYear(int y) {
    this->year = y;
}
