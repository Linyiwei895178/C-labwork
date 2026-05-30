//
// Created by LYW on 2026/4/9.
//

#ifndef LAB5CODE_CLIENT_H
#define LAB5CODE_CLIENT_H

#pragma once
#include <string>
using namespace std;

class Client
{
private:
    string id;
    string name;
public:
    Client(string id, string name);
    void showInfo();
};

#endif //LAB5CODE_CLIENT_H