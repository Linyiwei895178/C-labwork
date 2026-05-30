//
// Created by LYW on 2026/4/16.
//

#ifndef BANKACCOUNT_DATE_H
#define BANKACCOUNT_DATE_H

#include <iostream>
#include <iomanip>

class Date
{
private:
    int year, month, day;
    bool isLeapYear(int y) const;
    int getMaxDay() const;

public:
    Date(int y = 0, int m = 0, int d = 0);
    void show() const;
    int operator-(const Date &d) const;
    int getYear() const;
    int getMonth() const;
    int getDay() const;
};

#endif //BANKACCOUNT_DATE_H