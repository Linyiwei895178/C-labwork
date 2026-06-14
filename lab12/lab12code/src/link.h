#pragma once
#include "attachment/node.h"
#include <iostream>
using namespace std;
#include "node.h"

template <class T>
class LinkedList 
{
private:
    Node<T> *front, *rear;
    Node<T> *prevPtr, *currPtr;
    int size;
    int position;

    Node<T>* newNode(const T& tiem, Node<T> *ptrNext = NULL);
    void freeNode(Node<T> *p);
    void copy(const LinkedList<T>& L);

public:
    LinkedList();
    LinkedList(const LinkedList<T>& L);
    ~LinkedList();
    LinkedList<T>& operator=(const LinkedList<T>& L);

    int getSize() const;
    bool isEmpty() const;
    void reset(int pos = 0);
    void next();
    bool endOfList() const;
    int currentPosition() const;

    void insertFront(const T& item);
    void insertRear(const T& item);
    void insertAt(const T& item);
    void insertAfter(const T& item);

    T deleteFront();
    void deleteCurrent();

    T& data();
    const T& data() const;
    void clear();
    void show();
};

// the completion of the inner function
template <class T>
Node<T>* LinkedList<T>::newNode(const T& item, Node<T> *ptrNext) {
    Node<T> *n = new Node<T>(item, ptrNext);
    return n;
}

template <class T>
void LinkedList<T>::freeNode(Node<T> *p) {
    delete p;
    size--;
}

template <class T>
void LinkedList<T>::copy(const LinkedList<T>& L) 
{
    Node<T> *src = L.front->next;
    Node<T> *dst = front;
    while (src != L.rear) {
        dst->next = newNode(src->getData());
        dst = dst->next;
        src = src->next;
    }
    dst->next = rear;
    size = L.size;
    position = 0;
    prevPtr = front;
    currPtr = front->next;
}

//construction and destruction and assignment
template <class T>
LinkedList<T>::LinkedList() {
    front = new Node<T> ();
    rear = new Node<T> ();
    front->next = rear;
    currPtr = rear;
    prevPtr = front;
    size = 0;
    position = 0;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& L)
{
    front = new Node<T>();
    rear = new Node<T>();
    front->next = rear;
    copy(L);
}

template <class T>
LinkedList<T>::~LinkedList() 
{
    clear();
    delete front;
    delete rear;
}

template <class T>
LinkedList<T>& LinkedList<T>::operator = (const LinkedList<T>& L)
{
    if (this != &L)
    {
        clear();
        copy(L);
    }
    return *this;
}

//statement and iteration api
template <class T>
int LinkedList<T>::getSize() const 
{
    return size;
}

template <class T>
bool LinkedList<T>::isEmpty() const {
    return size == 0;
}

template <class T>
void LinkedList<T>::reset(int pos) {
    if (pos < 0 || pos > size)
    {
        cout << "cross the bolder" << endl;
        return;
    }
    prevPtr = front;
    currPtr = front->next;
    int i = 0;
    while (i < pos)
    {
        prevPtr = prevPtr->next;
        currPtr = currPtr->next;
        i++;
    }
    position = pos;
}

template <class T>
void LinkedList<T>::next() {
    if (endOfList())
    {
        cout << "has moved to the end of the list, can't move! " << endl;
        return;
    }
    prevPtr = prevPtr->next;
    currPtr = currPtr->next;
    position++;
}

template <class T>
bool LinkedList<T>::endOfList() const 
{
    return currPtr == rear;
}

template <class T>
int LinkedList<T>::currentPosition() const 
{
    return position;
}

// the insert api
template <class T>
void LinkedList<T>::insertFront(const T& item)
{
    Node<T>* n = newNode(item, front->next);
    front->next = n;
    size++;
    if (position == 0)
    {
        currPtr = n;
    }
}

template <class T>
void LinkedList<T>::insertRear(const T& item)
{
    Node<T>* temp = front;
    while (temp->next != rear)
    {
        temp = temp->next;
    }
    Node<T> *n = newNode(item, rear);
    temp->next = n;
    size++;
}

template <class T>
T LinkedList<T>::deleteFront() 
{
    if (isEmpty())
    {
        cout << "the link is empty, can't be deleted! " << endl;
        return T();
    }
    Node<T>* temp = front->next;
    T val = temp->getData();
    front->next = temp->next;
    if (currPtr == temp)
    {
        currPtr = currPtr->next;
    }
    freeNode(temp);
    if (position > 0)
    {
        position--;
    }
    return val;
}

template <class T>
void LinkedList<T>::deleteCurrent() 
{
    if (currPtr == rear || isEmpty())
    {
        cout << "can't delete the sentry node or the empty node! " << endl;
        return;
    }
    Node<T>* temp = currPtr;
    prevPtr->next = currPtr->next;
    currPtr = currPtr->next;
    freeNode(temp);
}

//clear the data and access
template <class T>
T& LinkedList<T>::data() 
{
    return currPtr->getData();
}

template <class T>
const T& LinkedList<T>::data() const 
{
    return currPtr->getData();
}

template <class T>
void LinkedList<T>::clear()
{
    Node<T>* temp;
    while (front->next != rear)
    {
        temp = front->next;
        front->next = temp->next;
        delete temp;
    }

    size = 0;
    position = 0;
    prevPtr = front;
    currPtr = rear;
}

