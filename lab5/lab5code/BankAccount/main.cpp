#include "Account.h"
#include <iostream>
using namespace std;

int main()
{
    Account accs[3] = {
        Account(1001, 5000, 0.015),
        Account(1002, 8000, 0.015),
        Account(1003, 10000, 0.015),
    };

    for (int i = 0; i < 3; i++)
    {
        accs[i].show();
    }

    cout << "total accounts: " << Account::getTotal() << endl;

    return 0;
}