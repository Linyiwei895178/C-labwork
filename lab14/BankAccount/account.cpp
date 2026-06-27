#include "account.h"
#include "date.h"
#include <utility>
using namespace std;

using namespace std::rel_ops;
//The AccountRecord class
AccountRecord::AccountRecord (const Date &date, const Account *account, double amount, double balance, const std::string& desc) : date(date), account(account), amount (amount), balance (balance), desc(desc) {}

void AccountRecord::show() const {
    cout << date << "\t#" << account->getId() << "\t" << amount << "\t" << balance << "\t" << desc << endl;
}

double Account::total = 0;
RecordMap Account::recordMap;

Account::Account(const Date &date, const string &id) 
                : id(id) , balance(0) {
    cout << date <<  "\t#" << id << " created" << endl;
}

void Account::show(ostream &out) const { out << id << "\tBalance: " << balance; }

void Account::error(const string &msg) const {
    cout << "Error(#" << id << "): " << msg << endl;
}

void Account::query(const Date& begin, const Date& end) {
    if (begin <= end) {
        RecordMap::iterator iter1 = recordMap.lower_bound(begin);
        RecordMap::iterator iter2 = recordMap.upper_bound(end);
        for (RecordMap::iterator iter = iter1; iter != iter2; ++iter)
            iter->second.show();
    }
}

//===========The Savings Account============
SavingsAccount::SavingsAccount(const Date &date, const string &id, double rate)
    : Account(date, id), rate(rate), acc(date, 0) {}

void SavingsAccount::deposit (const Date &date, double amount, const string &desc) {
    record(date, amount, desc);
    acc.change(date, getBalance());
}

void SavingsAccount::withdraw(const Date &date, double amount, const string &desc) {
    if (amount > getBalance()) {
        error("not enough money");
    } else {
        record(date, -amount, desc);
        acc.change(date, getBalance());
    }
}

void SavingsAccount::settle(const Date &date) {
    double interest = acc.getSum(date) * rate / date.distance(Date(date.getYear() - 1, 1, 1));
    if (interest != 0) record(date, interest, "interest");
    acc.reset(date, getBalance());
}

//=============The CreditAccount===============
CreditAccount::CreditAccount(const Date& date, const string& id, double credit, double rate, double fee) 
                            : Account(date, id), credit(credit), rate(rate), fee(fee), acc(date, 0) {} 

void CreditAccount::deposit(const Date &date, double amount, const string &desc) {
    if (getBalance() + amount > credit) {
        error("not enough credit");
    } else {
        record(date, amount, desc);
        acc.change(date, getBalance());
    }
}

void CreditAccount::settle(const Date &date) {
    double interest = acc.getSum(date) * rate;
    if (interest != 0) record(date, interest, "interest");
    if (date.getMonth() == 1) record(date, -fee, "annual fee");
    acc.reset(date, getBalance());
}

void CreditAccount::show(ostream &out) const {
    Account::show(out);
    cout << "\tAvailable credit:" << getAvailableCredit();
}

void Account::record(const Date &date, double amount, const string &desc) {
    balance += amount;
    total += amount;
    recordMap.insert(make_pair(date, AccountRecord(date, this, amount, balance, desc)));
}

void CreditAccount::withdraw(const Date &date, double amount, const string &desc) {
    if (getBalance() - amount < -credit) {
        error("not enough credit");
    } else {
        record(date, -amount, desc);
        acc.change(date, getBalance());
    }
}
