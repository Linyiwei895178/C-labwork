#include "Account.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"
#include "Array.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    Date date(2008, 11, 1);
    Array<Account*> accounts(0); // 初始大小为0的账户数组

    cout << "(a)add account (d)deposit (w)withdraw (s)show" << endl;
    cout << "(c)change day (n)next month (e)exit" << endl;

    char cmd;
    do {
        date.show();
        cout << "\tTotal: " << Account::getTotal() << "\tcommand> ";
        char type;
        int index, day;
        double amount, credit, rate, fee;
        string id, desc;
        Account* account;
        cin >> cmd;

        switch (cmd) {
        case 'a': // 新增账户
            cin >> type >> id;
            if (type == 's') {
                cin >> rate;
                account = new SavingsAccount(date, id, rate);
            } else {
                cin >> credit >> rate >> fee;
                account = new CreditAccount(date, id, credit, rate, fee);
            }
            accounts.resize(accounts.getSize() + 1);
            accounts[accounts.getSize() - 1] = account;
            break;

        case 'd': // 存款
            cin >> index >> amount;
            getline(cin, desc);
            accounts[index]->deposit(date, amount, desc);
            break;

        case 'w': // 取款
            cin >> index >> amount;
            getline(cin, desc);
            accounts[index]->withdraw(date, amount, desc);
            break;

        case 's': // 显示所有账户
            for (int i = 0; i < accounts.getSize(); i++) {
                cout << "[" << i << "] ";
                accounts[i]->show();
            }
            break;

        case 'c': // 修改日期
            cin >> day;
            if (day < date.getDay())
                cout << "Cannot set to previous day!" << endl;
            else if (day > date.getMaxDay())
                cout << "Invalid day!" << endl;
            else
                date = Date(date.getYear(), date.getMonth(), day);
            break;

        case 'n': // 进入下个月
            if (date.getMonth() == 12)
                date = Date(date.getYear() + 1, 1, 1);
            else
                date = Date(date.getYear(), date.getMonth() + 1, 1);
            for (int i = 0; i < accounts.getSize(); i++)
                accounts[i]->settle(date);
            break;
        }
    } while (cmd != 'e');

    // 释放内存
    for (int i = 0; i < accounts.getSize(); i++)
        delete accounts[i];
    return 0;
}