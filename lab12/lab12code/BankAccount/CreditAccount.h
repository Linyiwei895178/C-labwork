#ifndef CREDIT_ACCOUNT_H
#define CREDIT_ACCOUNT_H
#include "Account.h"

class CreditAccount : public Account {
private:
    double credit;   // 信用额度
    double rate;     // 日利率
    double fee;      // 年费
    double getDebt() const; // 获取欠款
public:
    CreditAccount(const Date& date, string id, double credit, double rate, double fee);
    double getAvailableCredit() const;
    void settle(const Date& date) override;
    void show() const override;
};
#endif