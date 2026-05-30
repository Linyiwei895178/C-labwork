//
// Created by LYW on 2026/4/16.
//

#include "Date.h"
#include <iostream>
bool Date::isLeapYear(int y) const
{
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int Date::getMaxDay() const
{
    if (month == 2)
        return isLeapYear(year) ? 29 : 28;
    int monthDay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return monthDay[month - 1];
}

Date::Date(int y, int m, int d) : year(y), month(m), day(d){}

void Date::show() const
{
    std::cout << std::setw(4) << std::setfill('0') << year << "-"
         << std::setw(2) << std::setfill('0') << month << "-"
         << std::setw(2) << std::setfill('0') << day;
}

int Date::operator-(const Date &d) const
{
    int days = 0;
    Date temp = d;
    while (temp.year < year || temp.month < month || temp.day < day)
    {
        temp.day++;
        if (temp.day > temp.getMaxDay())
        {
            temp.day = 1;
            temp.month++;
            if (temp.month > 12)
            {
                temp.month = 1;
                temp.year++;
            }
        }
        days++;
    }
    return days;
}

int Date::getYear() const {return year;}
int Date::getMonth() const {return month;}
int Date::getDay() const {return day;}
