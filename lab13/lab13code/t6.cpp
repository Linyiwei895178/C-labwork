#include <iostream>
#include <fstream>
using namespace std;

struct SalaryInfo {
    unsigned id;
    double salary;
};

int main()
{
    SalaryInfo emps[] = {
        {600001, 8000},
        {600002, 9500},
        {600003,7200}
    };

    ofstream os("payroll.dat", ios::out | ios::binary);
    os.write(reinterpret_cast<char*>(emps), sizeof(emps));
    os.close();

    ifstream is("payroll.dat", ios::in | ios::binary);
    if (is) {
        is.seekg(1 * sizeof(SalaryInfo));
        streampos pos = is.tellg();
        cout << "the current reading postion: " << pos << " Byte" << endl;

        SalaryInfo emp;
        is.read(reinterpret_cast<char*>(&emp), sizeof(emp));
        cout << "the second record: ID = " << emp.id << ", Salary = " << emp.salary << endl;
        is.close();
    }

    return 0;
}