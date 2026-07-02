#include <exception>
#include<iostream> 
#include "account.h"
#include "date.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;

struct deleter {
    template <class T>
    void operator()(T* p) { delete p; }
};

class Controller {
private:
    Date date;
    vector<Account *> accounts;
    bool end;
public:
    Controller(const Date &date) : date(date), end(false) {}
    ~Controller();
    const Date &getDate() const { return date; }
    bool isEnd() const { return end; }
    bool runCommand(const string &cmdLine);

};
Controller::~Controller() {
    for_each(accounts.begin(), accounts.end(), deleter());
}

bool Controller::runCommand(const string &cmdLine) {
    istringstream str(cmdLine);
    char cmd, type;
    int index, day;
    double amount, credit, rate, fee;
    string id, desc;
    Account *account;
    Date date1, date2;
    str >> cmd;

    switch (cmd) {
    case 'a':
        str >> type >> id;
        if (type == 's') {
            str >> rate;
            account = new SavingsAccount(date, id, rate);
        } else {
            str >> credit >> rate >> fee;
            account = new CreditAccount(date, id, credit, rate, fee);
        }
        accounts.push_back(account);
        break;
    case 'd':
        str >> index >> amount;
        getline(str, desc);
        accounts[index]->deposit(date, amount, desc);
        break;
    case 'w':
        str >> index >> amount;
        getline(str, desc);
        accounts[index]->withdraw(date, amount, desc);
        break;
    case 's':
        for (size_t i = 0; i < accounts.size(); i++) {
            cout << "[" << i << "]";
            accounts[i]->show(cout);
            cout << endl;
        }
        break;
    case 'c':
        str >> day;
        if (day < date.getDay())
            cout << "You cannot specify a previous day";
        else if (day > date.getMaxDay())
            cout << "invalid day";
        else  
            date = Date(date.getYear(), date.getMonth(), day);
        break;
    case 'n':
        if (date.getMonth() == 12)
            date = Date(date.getYear() + 1, 1, 1);
        else
            date = Date(date.getYear(), date.getMonth() + 1, 1);
        for (vector<Account*>::iterator iter = accounts.begin(); iter != accounts.end(); ++iter)
            (*iter)->settle(date);
        break;
    case 'q':
        date1 = Date::read();
        date2 = Date::read();
        Account::query(date1, date2);
        break;
    case 'e':
        end = true;
        return true;
    default:
        cout << "Invalid command: " << cmdLine << endl;
        return false;
    }
    return false;
}

int main() {
    Date date(2008, 11, 1);
    Controller controller(date);
    string cmdLine;
    const char* FILE_NAME = "commands.txt";
    ifstream fileIn(FILE_NAME);
    if (fileIn) {
        while (getline(fileIn, cmdLine)) {
            try {
                controller.runCommand(cmdLine);
            } catch (exception &e) {
                cout << "Bad line in " << FILE_NAME << ": " << cmdLine << endl;
                cout << "Error: " << e.what() << endl;
                return 1;
            }
        }
        fileIn.close();
    }
    ofstream fileOut(FILE_NAME, ios_base::app);
    cout << "(a)add account, (d) deposit (w)withdraw (s)show (c)change day (n)next month (q)query (e)exit" << endl;

    while (!controller.isEnd()) {
        cout << controller.getDate() << "\tTotal: " << Account::getTotal() << "\tcommand>";
        string cmdLine;
        getline(cin, cmdLine);
        try { 
            if (controller.runCommand(cmdLine))
            fileOut << cmdLine << endl;
        } catch (AccountException &e) {
            cout << "Error(#" << e.getAccount()->getId() << "): " << e.what() << endl;
        } catch (exception &e) {
            cout << "Error: " << e.what() << endl;
        }
    }
    return 0;
}