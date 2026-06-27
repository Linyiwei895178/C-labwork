#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

double area(double a, double b, double c) throw (invalid_argument) {
    if (a <= 0 || b <= 0 || c <= 0)
        throw invalid_argument("the side length should be positive");
    if (a + b <= c || b + c <= a || c + a <= b)
        throw invalid_argument("the side length should fit the triangle inequation");
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
};

int main()
{
    double a, b, c;
    cout << "Please input the side lengths of a triangle: ";
    cin >> a >> b >> c;
    try {
        double s = area(a, b, c);
        cout << "Area: " << s << endl;
    } catch (exception &e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}