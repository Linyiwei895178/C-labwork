//
// Created by LYW on 2026/4/16.
//

#ifndef BANKACCOUNT_ACCOUNT_H
#define BANKACCOUNT_ACCOUNT_H

#include <string>
#include <iostream>
#include "Date.h"
class Account
{
private:
    std::string id;
    double balance;
    double accumulation;
    Date lastDate;
    static double rate;
    static double total;

    void record(const Date& date, double amount, const std::string& desc);
    double accumulate(const Date& date) const;

public:
    Account(const Date& date, const std::string& _id);
    void deposit(const Date& date, double amount, const std::string& desc);
    void withdraw(const Date& date, double amount, const std::string& desc);
    void settle(const Date &date);
    void show() const;
    std::string getId() const;
    double getBalance() const;
    static double getTotal();
    static void setRate(double r);
};

#endif //BANKACCOUNT_ACCOUNT_H