#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Date.h"
#include <string>
using namespace std;

class Account {
protected:
    string id;
    double balance;
    Date lastDate;
    double accumulation; // 日积数，用于计息
    static double total; // 所有账户总余额

    void record(const Date& date, double amount, const string& desc);
    void accumulate(const Date& date);
public:
    Account(const Date& date, string id);
    string getId() const;
    double getBalance() const;
    static double getTotal();

    virtual void deposit(const Date& date, double amount, const string& desc);
    virtual void withdraw(const Date& date, double amount, const string& desc);
    virtual void settle(const Date& date) = 0; // 纯虚函数：结算利息/费用
    virtual void show() const;
};
#endif