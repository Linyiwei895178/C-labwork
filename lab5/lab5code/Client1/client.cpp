//
// Created by LYW on 2026/4/9.
//

#include "client.h"
#include <iostream>
using namespace std;

string Client::ServerName = "Default_Server";
int Client::ClientNum = 0;

Client::Client(string id, string name) : clientId(id), clientName(name)
{
    ClientNum++;
}

void Client::ChangeServerName(string newServerName)
{
    ServerName = newServerName;
}

void Client::showInfo() const
{
    cout << "=======客户信息======="  << endl;
    cout << "客户编号： " << clientId << endl;
    cout << "客户姓名： " << clientName << endl;
    cout << "所属服务器： " << ServerName << endl;
    cout << "当前总客户数： " << ClientNum << endl;
    cout << "=====================" << endl << endl;
}

int Client::getTotalClient()
{
    return ClientNum;
}
