#include <iostream>
#include "link.h"
using namespace std;

template<class T>
class LinkQueue
{
private:
    LinkedList<T> list;
public:
    void enQueue(const T& val) { list.insertAfter(val); }
    T deQueue() { return list.deleteFront(); }
    T getFront() { list.reset(0); return list.data(); }
    bool isEmpty() { return list.isEmpty(); }
    int getSize() { return list.getSize(); }

    void show() 
    {
        cout << "Queue: ";
        list.reset();
        while (!list.endOfList()) 
        {
            cout << list.data() << " ";
            list.next();
        }
        cout << endl;
    }
};

int main()
{
    LinkQueue<int> q;
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    cout << "out of queue: " << q.deQueue() << endl;
    q.show();
    cout << "the head of queue: " << q.getFront() << endl;
    return 0;
}