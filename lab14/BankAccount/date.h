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
public:
    Date(int year = 1, int month = 1, int day = 1);
    static Date read();
    int getYear() const { return year; }
    int getMonth() const { return month; }
    int getDay() const { return day; }
    int getTotalDays() const { return totalDays; }
    int getMaxDay() const;
    bool isLeapYear() const {
        return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    }
    void show() const;
    int distance(const Date& date) const {
        return totalDays - date.totalDays;
    }
    //计算两个日期之间相差多少天
    int operator-(const Date& other) const;

    bool operator<(const Date& date) const {
        return totalDays < date.totalDays;
    }
};

std::istream &operator>>(std::istream &in, Date &date);
std::ostream &operator<<(std::ostream &out, const Date &date);