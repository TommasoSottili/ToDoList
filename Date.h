//
// Created by sotti on 10/02/2026.
//

#ifndef TODOLIST_DATE_H
#define TODOLIST_DATE_H


class Date {

private:
    int day;
    int month;
    int year;

bool is_leap_year(int year);

public:
    Date(int day, int month, int year);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);
};


#endif //TODOLIST_DATE_H