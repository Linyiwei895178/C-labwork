
// TIP 要<b>Run</b>代码，请按 <shortcut actionId="Run"/> 或点击装订区域中的 <icon src="AllIcons.Actions.Execute"/> 图标。
#include <iostream>
#include <vector>
#include "Date.h"
#include "Account.h"

using namespace std;

int main() {
    cout << "===== 个人银行账户管理程序 =====" << endl;
    Date date(2026, 1, 1);
    vector<Account> accounts;

    // 创建账户
    accounts.emplace_back(date, "1001");
    accounts.emplace_back(date, "1002");
    cout << "已创建账户：1001、1002" << endl << endl;

    // 业务操作
    date = Date(2026, 1, 5);
    accounts[0].deposit(date, 10000.0, "工资");
    accounts[1].deposit(date, 5000.0, "压岁钱");

    date = Date(2026, 2, 1);
    accounts[0].withdraw(date, 2000.0, "消费");

    date = Date(2026, 3, 1);
    for (auto& acc : accounts)
        acc.settle(date);

    // 输出结果
    cout << endl << "===== 账户信息 =====" << endl;
    for (const auto& acc : accounts)
        acc.show();
    cout << "所有账户总金额：" << fixed << setprecision(2) << Account::getTotal() << endl;

    return 0;
}
