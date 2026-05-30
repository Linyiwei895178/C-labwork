//
// Created by LYW on 2026/4/9.
//

#include "client.h"
#include <iostream>

int main()
{
    cout << "=== 1. 创建第一个客户 ===" << endl;
    Client c1("C001", "张三");
    c1.showInfo();

    cout << "=== 2. 创建第二个 ===" << endl;
    Client c2("C002", "李四");
    c2.showInfo();
    c1.showInfo();

    cout << "== 3. 修改服务器名称 ===" << endl;
    Client::ChangeServerName("Campus_Server_01");

    cout << "=== 4.修改后两个客户的服务器名同步更新 ===" << endl;
    c1.showInfo();
    c2.showInfo();

    cout << "=== 5. 直接获取总客户数 ===" << endl;
    cout << "当前总客户数： " << Client::getTotalClient() << endl;

    return 0;
}