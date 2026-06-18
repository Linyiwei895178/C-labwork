#include "account.h"
#include <iomanip>
#include <cassert>

using namespace std;

double Account::total = 0.0;
vector<AccountRecord> Account::records;

// ============= the record of the Account============
void AccountRecord::show() const {
    cout << date << "\t#" << account->getId() << "\t"
        << fixed <<  setprecision(2) << amount << "\t"
        << balance << "\t" << desc << endl;
}

//=================the base of the Class Account==============
Account::Account(const Date& date, const string&id)
    : id(id), balance(0.0)
{
    cout << date << "\t#" << id << "created" << endl;
}

void Account::record(const Date& date, double amount, const string& desc) {
    balance += amount;
    total += amount;
    records.push_back({date, this, amount, balance, desc});
    cout << date << "\t#" << id << "\t"
        << fixed << setprecision(2) << amount << "\t"
        << balance << "\t" << desc << endl;
}

void Account::show(ostream& out) const {
    out << id << "\tBalance: " << fixed << setprecision(2) << balance;
}

ostream& operator<<(ostream& out, const Account& account) {
    account.show(out);
    return out;
}

void Account::query(const Date& date1, const Date& date2) {
    for (const auto& rec : records) {
        if (rec.date - date1 >= 0 && date2 - rec.date >= 0) {
            rec.show();
        }
    }
}

//================Savings Account========================
SavingsAccount::SavingsAccount(const Date& date, const string& id, double annualRate) 
    : Account(date, id), acc(date, 0.0), annualRate(annualRate) {}

void SavingsAccount::deposit(const Date& date, double amount, const string& desc) {
    record(date, amount, desc);
    acc.change(date, getBalance());
}

void SavingsAccount::withdraw(const Date& date, double amount, const string& desc) {
    assert(amount <= getBalance() && "Insufficient balance");
    record(date, -amount, desc);
    acc.change(date, getBalance());
}

void SavingsAccount::settle(const Date& date) {
    if (date.getMonth() == 1 && date.getDay() == 1) {
        double interest = acc.reset(date) * annualRate / 365.0;
        if (interest != 0) {
            record(date, interest, "interest");
            acc.change(date, getBalance());
        }
    }
}

void SavingsAccount::show(ostream& out) const {
    Account::show(out);
    out << "\tAnnual rate: " << annualRate;
}

///============================Credit Saving Account====================
CreditAccount::CreditAccount(const Date& date, const string& id, double creditLimit, 
                            double dailyRate, double annualFee)
                            : Account(date, id), creditLimit(creditLimit),
                            dailyRate(dailyRate), annualFee(annualFee), acc(date, 0.0) {}

void CreditAccount::deposit(const Date& date, double amount, const string& desc) {
    record(date, amount, desc);
    acc.change(date, getBalance());
}

void CreditAccount::withdraw(const Date& date, double amount, const string& desc) {
    assert(getAvailableCredit() >= amount && "Exceed credit limit");
    record(date, -amount, desc);
    acc.change(date, getBalance());
}

void CreditAccount::settle(const Date& date) {
    if (date.getDay() == 1) {
        double interest = acc.reset(date) * dailyRate;
        if (interest != 0) {
            record(date, interest, "interest");
            acc.change(date, getBalance());
        }
    }

    if (date.getMonth() == 1 && date.getDay() == 1 ) {
        record(date, -annualFee, "annual fee");
        acc.change(date, getBalance());
    }
}

void CreditAccount::show(ostream& out) const {
    Account::show(out);
    out << "\tAvailable credit: " << fixed << setprecision(2) << getAvailableCredit();
}

