#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    double values[] = { 1.23, 35.36, 653.7, 124358.24 };
    string names[] = { "Zoot", "Jimmy", "AI", "Stan" };

    cout << "------1. setprecision--------" << endl;
    for (int i = 0; i < 4; i++) {
        cout << setiosflags(ios_base::left)
            << setw(6) << names[i]
            << resetiosflags(ios_base::left)
            << setw(12) << setprecision(7) << values[i] << endl;
    }

    cout << "\n----2. remove setprecision(default accuracy)---" << endl;
    for (int i = 0; i < 4; i++) {
        cout << setiosflags(ios_base::left)
            << setw(6) << names[i]
            << resetiosflags(ios_base::left)
            << setw(12) << values[i] << endl;
    }

    return 0;
}
