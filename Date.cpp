//
// Created by sotti on 10/02/2026.
//

#include "Date.h"
#include <stdexcept>

Date::Date(int day, int month, int year) {
    if (!check_date(day, month, year))
        throw std::out_of_range("Data non valida");
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
    if (!check_date(d, this->month, this->year))
        throw std::out_of_range("Giorno non valido");
    this->day = d;
}

void Date::setMonth(int m) {
    if (!check_date(this->day, m, this->year))
        throw std::out_of_range("Mese non valido");
    this->month = m;
}

void Date::setYear(int y) {
    if (!check_date(this->day, this->month, y))
        throw std::out_of_range("Anno non valido");
    this->year = y;
}

bool Date::is_leap_year(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Date::count_days_in_month(int month, int year) {
    switch (month) {
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            if (is_leap_year(year))
                return 29;
        else
            return 28;
        default:
            return 31;
    }
}

bool Date::check_date(int day, int month, int year) {
    if (year<1900 || year>2100)
        return false;
    if (month<1 || month>12)
        return false;
    if (day<1 || day>count_days_in_month(month,year))
        return false;
    return true;
}




