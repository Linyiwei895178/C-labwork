#include "client.h"
using namespace std;
int main()
{
    Client c1("C001", "ZhangSan");
    c1.showInfo();

    Client c2("C001", "LiSi");
    c2.showInfo();

    return 0;
}