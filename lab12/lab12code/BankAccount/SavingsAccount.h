#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H
#include "Account.h"

class SavingsAccount : public Account {
private:
    double rate; // 年利率
public:
    SavingsAccount(const Date& date, string id, double rate);
    void settle(const Date& date) override;
    void show() const override;
};
#endif