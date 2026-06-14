#include <iostream>
#include "DNode.h"
using namespace std;

template <class T>
void printList(DNode<T>* head)
{
    if (!head) return;
    DNode<T>* p = head;
    do {
        cout << p->data << " ";
        p = p->nextNodeRight();
    } while (p != head);
    cout << endl;
}

int main()
{
    DNode<int>* head = new DNode<int>(1);
    cout << "the inited list: ";
    printList(head);

    //insert from the right
    DNode<int>* n2 = new DNode<int>(2);
    DNode<int>* n3 = new DNode<int>(3);
    head->insertRight(n2);
    n2->insertRight(n3);
    cout << "insert right 2, 3: ";
    printList(head);

    //insert from the left
    DNode<int>* n0 = new DNode<int>(0);
    head->insertLeft(n0);
    cout << "insert - from the right: ";
    printList(head);

    //delete the node
    n2->deleteNode();
    delete n2;
    cout << "delete node2: ";
    printList(head);

    //free the memory
    DNode<int>* p = head->nextNodeRight();
    while (p != head) 
    {
        DNode<int>* temp = p;
        p = p->nextNodeRight();
        delete temp;
    }
    delete head;
    return 0;
}

