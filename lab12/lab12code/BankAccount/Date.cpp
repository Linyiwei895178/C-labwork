#include "Date.h"
#include <iostream>
using namespace std;

bool Date::isLeapYear(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int Date::getMonthDays(int y, int m) const {
    static int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 2 && isLeapYear(y)) return 29;
    return days[m-1];
}

void Date::calcTotalDays() {
    totalDays = 0;
    for (int i = 1; i < year; i++)
        totalDays += isLeapYear(i) ? 366 : 365;
    for (int i = 1; i < month; i++)
        totalDays += getMonthDays(year, i);
    totalDays += day;
}

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {
    calcTotalDays();
}

int Date::getYear() const { return year; }
int Date::getMonth() const { return month; }
int Date::getDay() const { return day; }

int Date::getMaxDay() const {
    return getMonthDays(year, month);
}

void Date::show() const {
    cout << year << "-" << month << "-" << day;
}

int Date::operator-(const Date& other) const {
    return totalDays - other.totalDays;
}