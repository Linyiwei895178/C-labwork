//
// Created by LYW on 2026/4/9.
//

#ifndef CLIENT1_CLIENT_H
#define CLIENT1_CLIENT_H
#include <iostream>
#include <string>
using namespace std;

class Client
{
private:
    string clientId;
    string clientName;

    static string ServerName;
    static int ClientNum;

public:
    Client(string id, string name);

    static void ChangeServerName(string newServerName);

    void showInfo() const;

    static int getTotalClient();
};


#endif //CLIENT1_CLIENT_H