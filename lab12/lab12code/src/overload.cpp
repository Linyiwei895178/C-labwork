// #include <iostream>
// #include <cstring>
// using namespace std;

// template <class T>
// T myMax(T a, T b)
// {
//     return (a > b) ? a : b;
// }

// const char* myMax(const char* a,  const char* b)
// {
//     return strcmp(a, b) > 0 ? a : b;
// }

// int main()
// {
//     cout << myMax(3, 5) << endl;
//     cout << myMax("apple", "banana") << endl;
//     return 0;
// }

#pragma once
// #include <iostream>
#include <cassert>
using namespace std;

template <class T, int SIZE = 50>
class Stack
{
private:
    T list[SIZE];
    int top;
public:
    Stack() : top(-1) {}
    void push(const T & item);
    T pop();
    void clear();
    const T &peek() const;
    bool isEmpty() const;
    bool isFull() const;
};

template <class T, int SIZE>
void Stack<T, SIZE>::push(const T &item) {
    assert(!isEmpty());
    return list[top];
}

template <class T, int SIZE>
bool Stack<T, SIZE>::isEmpty() const { return top == -1; }

template <class T, int SIZE>
bool Stack<T, SIZE>::isFull() const { return top == SIZE - 1; }

template <class T, int SIZE>
void Stack<T, SIZE>::clear() { top = -1; }

template<int SIZE>
class Stack<bool, SIZE> {
private:
	enum {
		UNIT_BITS = sizeof(unsigned) * 8,  // 每个unsigned的位数
		ARRAY_SIZE = (SIZE - 1) / UNIT_BITS + 1
	};
	unsigned bits[ARRAY_SIZE];  // 位存储数组
	int top;
public:
	Stack() : top(-1) {}
	void push(bool item);
	bool pop();
	bool peek() const;
	bool isEmpty() const;
	bool isFull() const;
	void clear() { top = -1; }
};

template<int SIZE>
void Stack<bool, SIZE>::push(bool item) {
	assert(!isFull());
	top++;
	int idx = top / UNIT_BITS;
	int bit = top % UNIT_BITS;
	if (item)
		bits[idx] |= (1 << bit);
	else
		bits[idx] &= ~(1 << bit);
}

template<int SIZE>
bool Stack<bool, SIZE>::pop() {
	assert(!isEmpty());
	int idx = top / UNIT_BITS;
	int bit = top % UNIT_BITS;
	bool res = (bits[idx] >> bit) & 1;
	top--;
	return res;
}

template<int SIZE>
bool Stack<bool, SIZE>::peek() const {
	assert(!isEmpty());
	int idx = top / UNIT_BITS;
	int bit = top % UNIT_BITS;
	return (bits[idx] >> bit) & 1;
}

template<int SIZE>
bool Stack<bool, SIZE>::isEmpty() const { return top == -1; }

template<int SIZE>
bool Stack<bool, SIZE>::isFull() const { return top == SIZE - 1; }
