//
// Created by LYW on 2026/4/16.
//

#include "Account.h"
#include <iostream>
#include <iomanip>
#include <cmath>

// 静态成员初始化
double Account::rate = 0.035;
double Account::total = 0.0;

// 记录交易
void Account::record(const Date& date, double amount, const std::string& desc) {
    accumulation = accumulate(date);
    lastDate = date;
    amount = floor(amount * 100 + 0.5) / 100;
    balance += amount;
    total += amount;
    date.show();
    std::cout << "\t#" << id << "\t" << std::setw(10) << amount
              << "\t" << std::setw(10) << balance << "\t" << desc << std::endl;
}

// 累计积数
double Account::accumulate(const Date& date) const {
    return accumulation + balance * (date - lastDate);
}

// 构造函数
Account::Account(const Date& date, const std::string& _id)
    : id(_id), balance(0), accumulation(0), lastDate(date) {}

// 存款
void Account::deposit(const Date& date, double amount, const std::string& desc) {
    record(date, amount, desc);
}

// 取款
void Account::withdraw(const Date& date, double amount, const std::string& desc) {
    if (amount > balance) {
        std::cout << "Error: 余额不足！" << std::endl;
        return;
    }
    record(date, -amount, desc);
}

// 结算利息
void Account::settle(const Date& date) {
    double interest = accumulate(date) * rate / 365;
    if (interest > 0)
        record(date, interest, "利息");
    accumulation = 0;
}

// 显示账户信息
void Account::show() const {
    std::cout << "账户：" << id << "\t余额："
              << std::fixed << std::setprecision(2) << balance << std::endl;
}

// Getter & 静态方法
std::string Account::getId() const { return id; }
double Account::getBalance() const { return balance; }
double Account::getTotal() { return total; }
void Account::setRate(double r) { rate = r; }