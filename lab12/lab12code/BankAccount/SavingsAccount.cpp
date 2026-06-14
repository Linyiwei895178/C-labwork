#include "SavingsAccount.h"
#include <iostream>
using namespace std;

SavingsAccount::SavingsAccount(const Date& date, string id, double r)
    : Account(date, id), rate(r) {}

void SavingsAccount::settle(const Date& date) {
    accumulate(date);
    double interest = accumulation * rate / 365;
    if (interest != 0) {
        record(date, interest, "interest");
    }
    accumulation = 0;
}

void SavingsAccount::show() const {
    Account::show();
    cout << "\tType: Savings" << endl;
}