#ifndef __CIRCLE_LINKED_LIST
#define __CIRCLE_LINKED_LIST
#include <iostream>
using namespace std;

template <typename T> class CCircleLinkedList;

template <typename T>
class CNode {
    friend  class CCircleLinkedList<T>;
public:
    T element;
    CNode<T>* pNext;
};

template <typename T>
class CCircleLinkedList {
    friend  class CNode<T>;
public:
    CCircleLinkedList<T>();
    void InsertNode(CNode<T>* curNode, CNode<T>* newNode);
    void DeleteNode(CNode<T>* h, CNode<T>* delNode);
    void TraveralCircleLinkedList(CNode<T>* h);

    CNode<T>* head;
};

template <typename T>
CCircleLinkedList<T>::CCircleLinkedList() {
    head = new CNode<T>();
    head->pNext = head;
}

/*
 * newNode insert right of curNode:      [current] -> [newNode] -> [current->pNext]
 */
template <typename T>
void CCircleLinkedList<T>::InsertNode(CNode<T>* curNode, CNode<T>* newNode) {
    newNode->pNext = curNode->pNext;
    curNode->pNext =newNode;
    curNode = newNode;
}

template <typename T>
void CCircleLinkedList<T>::DeleteNode(CNode<T>* h, CNode<T>* delNode) {
    CNode<T>* curNode = h;
    curNode = curNode->pNext;
    while(curNode->pNext != h) {
        if(curNode->pNext->element == delNode->element) {
            if(delNode == h){
                cout << "Head node not permitted delete!" << endl;
            } else {
                curNode->pNext = delNode->pNext; /* curNode->pNext->pNext */
                delete delNode;
                delNode = nullptr;
            }
            break;
        }
        else curNode = curNode->pNext;
    }
}

template <typename T>
void CCircleLinkedList<T>::TraveralCircleLinkedList(CNode<T>* h) {
    CNode<T>* curNode = h;
    curNode = curNode->pNext;

    while(curNode != head) {
        if(curNode->pNext != head)
            cout << curNode->element << " -> ";
        else
            cout << curNode->element << endl;
        curNode = curNode->pNext;
    }
}
#endif
