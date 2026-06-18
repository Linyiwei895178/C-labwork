// getline version
// #include <iostream>
// #include <string>
// using namespace std;

// int main()
// {
//     // string line;
//     // cout << "Please enter a line with spaces (ended with 't'): " << endl;
//     // getline(cin, line, 't');
//     // cout << "the result of reading: " << line << endl;

//     string line;
//     char ch;
//     cout << "Please enter a line with spaces (ended with 't')" << endl;
//     while (cin.get(ch)) {
//         if (ch == 't') break;
//         line += ch;
//     }

//     cout << "the result of reading is: " << line << endl;
//     return 0;
// }

//file add and read the output
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    const char* filename = "test.txt";
    ofstream fout(filename, ios::app);
    if (fout) {
        fout << "Hello C++ File IO" << endl;
        fout << "This is a new line." << endl;
        fout.close();
        cout << "the output has completed!" << endl; 
    }

    ifstream fin(filename);
    if (fin) {
        string line;
        cout << "\nthe content of the file: " << endl;
        while (getline(fin, line)) {
            cout << line << endl;
        }
        fin.close();
    } else {
        cout << "fail to open the file!" << endl;
    }

    return 0;
}