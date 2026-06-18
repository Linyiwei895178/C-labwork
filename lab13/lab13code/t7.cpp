#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// template <class T>
// inline string toString(const T &v) {
//     ostringstream os;
//     os << v;
//     return os.str();
// }

// int main()
// {
//     string s1 = toString(12345);
//     string s2 = toString(3.14159);

//     cout << "Integer to String: " << s1 << endl;
//     cout << "Float to String: " << s2 << endl;

//     return 0;
// }

template <class T>
inline T fromString(const string &str) {
    istringstream is(str);
    T v;
    is >> v;
    return v;
}

int main()
{
    int a = fromString<int>("2024");
    double b = fromString<double>("99.99");
    cout << "String to Integer: " << a << endl;
    cout << "String to Float: " << b << endl;

    return 0;
}


