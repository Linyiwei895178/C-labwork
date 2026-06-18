#pragma once
#include "date.h"

class Accumulator {
private:
    Date lastDate;
    double value;
    double sum;
public:
    Accumulator(const Date& date, double initValue)
        :lastDate(date), value(initValue), sum(0) {} 

    void change(const Date& date, double newValue) {
        sum += value * (date - lastDate);
        value = newValue;
        lastDate = date;
    }

    double reset(const Date& date) {
        double result = sum + value * (date - lastDate);
        sum = 0;
        lastDate = date;
        return result;
    }

    double getValue() const { return value; }
    double getSum() const { return sum; }
};
