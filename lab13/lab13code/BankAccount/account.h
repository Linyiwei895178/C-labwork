#pragma once

#include "date.h"
#include "accumulator.h"
#include <string>
#include <vector>
#include <iostream>

class Account;

struct AccountRecord {
    Date date;
    const Account* account;
    double amount;
    double balance;
    std::string desc;

    void show() const;
};

class Account {
private:
    std::string id;
    double balance;
    static double total;
    static std::vector<AccountRecord> records;
    
protected:
    void record(const Date& date, double amount, const std::string& desc);

public:
    Account(const Date& date, const std::string& id);
    virtual ~Account() = default;

    std::string getId() const { return id; }
    double getBalance() const { return balance; }
    static double getTotal() { return total; }

    virtual void deposit(const Date& date, double amount, const std::string& desc) = 0;
    virtual void withdraw(const Date& date, double amount, const std::string& desc) = 0;
    virtual void settle(const Date& date) = 0;

    virtual void show(std::ostream& out) const;

    static void query(const Date& date1, const Date& date2);
};

std::ostream& operator<<(std::ostream& out, const Account& account);

class SavingsAccount : public Account {
private:
    Accumulator acc;
    double annualRate;
public:
    SavingsAccount(const Date& date, const std::string& id, double annualRate);

    double getAnnualRate() const { return annualRate; }

    void deposit(const Date& date, double amount, const std::string& desc) override;
    void withdraw(const Date& dae, double amount, const std::string& desc) override;
    void settle(const Date& date) override;
    void show(std::ostream& out) const override;
};

class CreditAccount : public Account {
    private:
    double creditLimit;
    double dailyRate;
    double annualFee;
    Accumulator acc;
public:
    CreditAccount(const Date& date, const std::string& id, double creditLimit, double dailyRate, double annualFee);

    double getCreditLimit() const { return creditLimit; }
    double getAvailableCredit() const { return creditLimit + getBalance(); }
    double getDailyRate() const { return dailyRate; }
    double getAnnualFee() const { return annualFee; }

    void deposit(const Date& date, double amount, const std::string& desc) override;
    void withdraw(const Date& date, double amount, const std::string& desc) override;
    void settle(const Date& date) override;
    void show(std::ostream& out) const override;
};
