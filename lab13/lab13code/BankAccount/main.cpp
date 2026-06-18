#include<iostream> 
#include "account.h"
#include "date.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

struct deleter {
    template <class T>
    void operator()(T* p) { delete p; }
};

class Controller {
private:
    Date currentDate;
    vector<Account*> accounts;
    bool endFlag;

    void settleToDate(const Date& targetDate) {
        while (currentDate.getTotalDays() < targetDate.getTotalDays()) {
            ++currentDate;
            for (auto acc : accounts) {
                acc->settle(currentDate);
            }
        }
    }

public:
    Controller(const Date& startDate)
            : currentDate(startDate), endFlag(false) {}

    ~Controller() {
        for_each(accounts.begin(), accounts.end(), deleter());
    }

    const Date& getDate() const { return currentDate; }
    bool isEnd() const { return endFlag; }

    bool runCommand(const string& cmdLine) {
        istringstream iss(cmdLine);
        char cmd;
        iss >> cmd;

        switch (cmd) {
            case 'a': {
                char type;
                string id;
                iss >> type >> id;
                if (type == 's') {
                    double rate;
                    iss >> rate;
                    accounts.push_back(new SavingsAccount(currentDate, id, rate));
                } else if (type == 'c') {
                    double credit, rate, fee;
                    iss >> credit >> rate >> fee;
                    accounts.push_back(new CreditAccount(currentDate, id, credit, rate, fee));
                } else {
                    cout << "Unknown account type: " << type << endl;
                    return false;
                }
                return true;
            }
            case 'd': { // deposit: d index amount desciption
                int idx;
                double amount;
                string desc;
                iss >>idx >> amount;
                getline(iss, desc);
                if (!desc.empty() && desc[0] == ' ') desc = desc.substr(1);
                if (idx >= 0 && idx < accounts.size())
                    accounts[idx]->deposit(currentDate, amount, desc);
                else cout << "Invalid index" << endl;
                return true;
            }
            case 'w': {
                int idx;
                double amount;
                string desc;
                iss >> idx >> amount;
                getline(iss, desc);
                if (!desc.empty() && desc[0] == ' ') desc = desc.substr(1);
                if (idx >= 0 && idx < accounts.size())
                    accounts[idx]->withdraw(currentDate, amount, desc);
                else cout << "Invalid index" << endl;
                return true;
            }
            case 's': {
                for (size_t i = 0; i < accounts.size(); ++i)
                    cout << "[" <<  i << "] " << *accounts[i] << endl;
                return false;
            }
            case 'c': {
                int day;
                iss >> day;
                Date target(currentDate.getYear(), currentDate.getMonth(), day);
                if (target - currentDate >= 0) settleToDate(target);
                else cout << "Cannot go backward" << endl;
                return true;
            }
            case 'n': {
                int m = currentDate.getMonth() + 1;
                int y = currentDate.getYear();
                if (m > 12) { m = 1; y++; }
                settleToDate(Date(y, m, 1));
                return true;
            }
            case 'q': {
                Date d1(0, 0, 0), d2(0, 0, 0);
                iss >> d1 >> d2;
                Account::query(d1, d2);
                return false;
            }
            case 'e': 
                endFlag = true;
                return false;
            default:
                cout << "Invalid command: " << cmdLine << endl;
                return false;
        }
    }
};

int main()
{
    const char* CMD_FILE = "commands.txt";
    Controller controller(Date(2008, 11, 1));

    //1. read the history command and recover the state
    ifstream fin(CMD_FILE);
    if (fin) {
        string line;
        while (getline(fin, line))
            if (!line.empty()) controller.runCommand(line);
        fin.close();
    }

    //2. append state and open the file, save new commands
    ofstream fout(CMD_FILE, ios_base::app);

    //3. interaction main loop
    cout << "(a)add (d)deposit (w)withdraw (s)show (c)day (n)next month (q)query (e)exit" << endl;
    while (!controller.isEnd()) {
        cout << controller.getDate()
            << "\tTotal: " << fixed << setprecision(2) << Account::getTotal()
            << "\tcommand> ";

        string line;
        getline(cin, line);
        if (line.empty()) continue;
        if (controller.runCommand(line))
            fout << line << endl;
    }

    fout.close();
    return 0;
}
