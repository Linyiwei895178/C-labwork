//
// Created by LYW on 2026/4/9.
//

#include "client.h"
#include <iostream>
using namespace std;

Client::Client(string id, string name)
{
    this->id = id;
    this->name = name;
}

void Client::showInfo()
{
    cout << "the number of client: " << id << endl;
    cout << "the name of client: " << name << endl;
}