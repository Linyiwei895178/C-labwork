#include <exception>
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class MathException : public exception {
public:
    MathException(const string& msg) : msg(msg) {}
    virtual const char* what() const throw() {
        return msg.c_str();
    }
protected:
    string msg;
};

class DivideByZeroException : public MathException {
public:
    DivideByZeroException() : MathException("Division by zero error") {}
};

class OverflowException : public MathException {
public:
    OverflowException() : MathException("Numeric overflow error") {}
};

double divide(double x, double y) {
    if (y == 0)
        throw DivideByZeroException();
    return x / y;
}

int main()
{
    try {
        cout << "10 / 2 = " << divide(10, 2) << endl;
        cout << "10 / 2 = " << divide(10, 0) << endl;
    }

    catch (const DivideByZeroException& e) {
        cout << "Specific error: " << e.what() << endl;
    }
    catch (const MathException& e) {
        cout << "Math error: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "General error: " << e.what() << endl;
    }

    cout << "Program continues..." << endl;
    return 0;
}