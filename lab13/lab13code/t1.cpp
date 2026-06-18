#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    char a[7] = {'a', 'e', 'd', 'c', 'b', 'f', 'g'};
    int n = sizeof(a) / sizeof(a[0]);

    sort(a, a + n);

    cout << "array after sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    char target = 'b';
    char* p = find(a, a + n, target);
    if (p != a + n) {
        int index = p - a;
        cout << "char" << target << " index is : " << index << endl;
    } else {
        cout << "can not find the character! " << endl;
    }

    return 0;
}