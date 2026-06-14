#include "CreditAccount.h"
#include <iostream>
#include <iomanip>
using namespace std;

CreditAccount::CreditAccount(const Date& date, string id, double c, double r, double f)
    : Account(date, id), credit(c), rate(r), fee(f) {}

double CreditAccount::getDebt() const {
    return balance < 0 ? -balance : 0;
}

double CreditAccount::getAvailableCredit() const {
    return credit + balance; // balance为负表示欠款
}

void CreditAccount::settle(const Date& date) {
    accumulate(date);
    // 按月结算利息
    double interest = getDebt() * rate;
    if (interest != 0) {
        record(date, -interest, "interest");
    }
    // 每年1月1日扣年费
    if (date.getMonth() == 1 && date.getDay() == 1) {
        record(date, -fee, "annual fee");
    }
    accumulation = 0;
}

void CreditAccount::show() const {
    Account::show();
    cout << "\tAvailable credit: " << fixed << setprecision(2) << getAvailableCredit();
    cout << "\tType: Credit" << endl;
}