//
// Created by LYW on 2026/4/9.
//

#ifndef BANKACCOUNT_ACCOUNT_H
#define BANKACCOUNT_ACCOUNT_H

class Account
{
private:
    int id;
    double balance;
    static int total;
    const double rate;
public:
    Account(int id, double balance, double rate);
    void show() const;
    static int getTotal();
};

#endif //BANKACCOUNT_ACCOUNT_H