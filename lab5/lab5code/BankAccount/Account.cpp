//
// Created by LYW on 2026/4/9.
//

#include "Account.h"
#include <iostream>
using namespace std;

int Account::total =  0;

Account::Account(int id, double balance, double rate) : id(id), balance(balance), rate(rate)
{
    total++;
}

void Account::show() const
{
    cout << "Account: " << id << "balance: " << balance << " rate: " << rate << endl;
}

int Account::getTotal()
{
    return total;
}