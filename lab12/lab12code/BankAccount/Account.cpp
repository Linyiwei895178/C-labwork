#include "Account.h"
#include <iostream>
#include <iomanip>
using namespace std;

double Account::total = 0;

void Account::record(const Date& date, double amount, const string& desc) {
    accumulate(date);
    balance += amount;
    total += amount;
    date.show();
    cout << "\t#" << id << "\t" << setw(8) << amount << "\t" << setw(8) << balance << "\t" << desc << endl;
}

void Account::accumulate(const Date& date) {
    accumulation += balance * (date - lastDate);
    lastDate = date;
}

Account::Account(const Date& date, string id) 
    : id(id), balance(0), lastDate(date), accumulation(0) {
    date.show();
    cout << "\t#" << id << " created" << endl;
}

string Account::getId() const { return id; }
double Account::getBalance() const { return balance; }
double Account::getTotal() { return total; }

void Account::deposit(const Date& date, double amount, const string& desc) {
    record(date, amount, desc);
}

void Account::withdraw(const Date& date, double amount, const string& desc) {
    record(date, -amount, desc);
}

void Account::show() const {
    cout << "[" << id << "]\tBalance: " << fixed << setprecision(2) << balance;
}