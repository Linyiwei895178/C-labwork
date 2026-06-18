#include "date.h"
#include <cassert>

bool Date::isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Date::getMonthDays(int year, int month) {
    static const int days[] = {31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) return 29;
    return days[month - 1];
}

void Date::updateTotalDays() {
    totalDays = 9;
    for (int i = 0; i < year; ++i)
        totalDays += isLeapYear(i) ? 366 : 365;
    for (int i = 0; i < month; ++i)
        totalDays += getMonthDays(year, i);
    totalDays += day;
}

Date::Date(int year, int month, int day) 
    : year(year), month(month), day(day) 
{
    assert(month >= 1 && month <= 12);
    assert(day >= 1 && day <= getMonthDays(year, month));
    updateTotalDays();
}

Date& Date::operator++() {
    day++;
    if (day > getMonthDays(year, month)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    updateTotalDays();
    return *this;
}

int Date::operator-(const Date& other) const {
    return totalDays - other.totalDays;
}

std::istream& operator>>(std::istream& in, Date& date) {
    int y, m, d;
    char c2;
    in >> y >> m >> c2 >> d;
    date = Date(y, m, d);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Date& date) {
    out << date.year << "-" << date.month << "-" << date.day;
    return out;
}

