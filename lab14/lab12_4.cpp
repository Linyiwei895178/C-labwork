#include <cstddef>
#include <iostream>
#include <iterator>
#include <new>
using namespace std;

void* allocateMemory(size_t size) {
    if (size > 1024 * 1024 * 1024) {
        throw "Memory allocation failed: size too large";
    }
    void* ptr = new(nothrow) char[size];
    if (ptr == nullptr) {
        throw "Memory allocation failed: out of memory";
    }
    return ptr;
}

int main()
{
    try {
        cout << "Trying to allocate 2GB memory..." << endl;
        void* p = allocateMemory(2 * 1024 * 1024 * 1024);
        delete[] (char*)p;
    }

    catch (const char* str) {
        cout << "Caught string exception: " << str << endl;
    }

    try {
        cout << "\nTrying to allocate huge memory with new..." << endl;
        size_t hugeSize = ~size_t(0);
        char* p = new char[hugeSize];
        delete[] p;
    }
    catch (const bad_alloc& e) {
        cout << "Caught bad_alloc: " << e.what() << endl;
    }

    cout << "\nProgram finished normally." << endl;
    return 0;
}