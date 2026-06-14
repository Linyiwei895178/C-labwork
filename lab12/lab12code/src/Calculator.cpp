#include "Stack.h"
#include <string>
#include <sstream>
#include <cmath>
#include <iostream>
using namespace std;

class Calculator 
{
private:
    Stack<double> s;
    void enter(double num);
    bool getTwoOperands(double &opnd1, double &opnd2);
    void compute(char op);
public:
    void run();
    void clear();
};

inline double stringToDouble(const string &str)
{
    istringstream stream(str);
    double result;
    stream >> result;
    return result;
}

void Calculator::enter(double num) { s.push(num); }

bool Calculator::getTwoOperands(double &opnd1, double &opnd2)
{
    if (s.isEmpty()) { cerr << "Missing right operand!" << endl; return false; }
    opnd1 = s.pop();
    if (s.isEmpty()) { cerr << "Missing left operand!" << endl; return false; }
    opnd2 = s.pop();
    return true;
}

void Calculator::compute(char op) 
{
    double a, b;
    if (!getTwoOperands(a, b)) { s.clear(); return; }
    switch(op) 
    {
        case '+': s.push(b + a); break;
        case '-': s.push(b - a); break;
        case '*': s.push(b * a); break;
        case '/': 
        {
            if (a == 0) { cerr << "Divided by 0!" << endl; s.clear(); }
            else s.push(b / a);
            break;
        }
        case '^': s.push(pow(b, a)); break;
        default: cerr << "Unrecognized operator!" << endl;
    }
    cout << "= " << s.peek() << " ";
}

void Calculator::run() {
    string str;
    while (cin >> str, str != "q") {
        switch (str[0]) {
            case 'c': s.clear(); break;
            case '-': 
            {
                if (str.size() > 1) enter(stringToDouble(str));
                else compute(str[0]);
                break;
            }
            case '+': case '*': case '/': case '^':
                compute(str[0]); break;
            default: enter(stringToDouble(str));
        }
    }
}

void Calculator::clear() { s.clear(); }

int main()
{
    Calculator c;
    cout << "enter the postfix expression: (space to split, q is quit, c is clear): " << endl;
    c.run();
    return 0;
}