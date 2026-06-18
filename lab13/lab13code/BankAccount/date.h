#pragma once

#include <iostream>

class Date {
private:
    int year;
    int month;
    int day;
    int totalDays;

    void updateTotalDays();
    static int getMonthDays(int year, int month);
    static bool isLeapYear(int year);
public:
    Date(int year, int month, int day);

    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }
    int getTotalDays() const { return totalDays; }

    Date& operator++();

    int operator-(const Date& other) const;

    friend std::istream& operator>>(std::istream& in, Date& date);
    friend std::ostream& operator<<(std::ostream& out, const Date& date);
};