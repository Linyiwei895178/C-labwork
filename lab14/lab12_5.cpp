#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

template <class T>
class Array {
public:
    Array(int size) : size(size) {
        data = new T[size];
    }
    ~Array() {
        delete[] data;
    }

    T& operator[](int index) throw (out_of_range) {
        if (index < 0 || index >= size) {
            throw out_of_range("Array index out of range: index=" + to_string(index) + ", size=" + to_string(size));
        }
        return data[index];
    }

    int getSize() const { return size; }

private:
    T* data;
    int size;
};

int main() {
    try {
        Array<int> arr(5);
        for (int i = 0; i < 5; i++) {
            arr[i] = i * 10;
            cout << "arr[" << i << "] = " << arr[i] << endl;
        }
        
        cout << "\nTrying to access arr[10]..." << endl;
        arr[10] = 100;
    }
    catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "\nProgram continues after exception handling." << endl;
    return 0;
}
