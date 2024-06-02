#ifndef __DLINKED_LIST
#define __DLINKED_LIST

#include <iostream>
using namespace std;

template <typename T> class CDoubleLinkedList;

template <typename T>
class CNode {
    friend class CDoubleLinkedList<T>;
public:

    T element;
    CNode<T>* pNext;
    CNode<T>* pPrev;
};


template <typename T>
class CDoubleLinkedList {
    friend class CNode<T>;
public:
    CDoubleLinkedList();
    virtual ~CDoubleLinkedList() {}
    void InsertNode( CNode<T>* curNode, CNode<T>* newNode );
    void DeleteNode( CNode<T>* h, CNode<T>* delNode );
    void TraveralDLinkedListNext(CNode<T>* h);
    void TraveralDLinkedListPrev(CNode<T>* h);

    CNode<T>* head;
};

template <typename T>
CDoubleLinkedList<T>::CDoubleLinkedList()
{
    head = new CNode<T>();
    head->pNext = head;
    head->pPrev = head;
}

/*
 *  curNode <-1 newNode <-3 curNode-pNext
 *  curNode ->4 newNode ->2 curNode-pNext
 *  step: 1 -> 2 -> 3 -> 4
 */
template <typename T>
void CDoubleLinkedList<T>::InsertNode( CNode<T>* curNode, CNode<T>* newNode ) {
    newNode->pPrev = curNode;
    newNode->pNext = curNode->pNext;
    curNode->pNext->pPrev = newNode;
    curNode->pNext = newNode;
}

template <typename T>
void CDoubleLinkedList<T>::DeleteNode( CNode<T>* h, CNode<T>* delNode ) {
    CNode<T>* current = h;
    current = current->pNext;
    while(current->pNext != h) {
        if ( current->element == delNode->element ) {
            if( delNode == h ) {
                cout << "Head node not permitted delete!" << endl;
            } else { //find, then delete
                delNode->pPrev->pNext = delNode->pNext;
                delNode->pNext->pPrev = delNode->pPrev;
                delete delNode;
                delNode = nullptr;
            }
            break;
        }
        else current = current->pNext;
    }
}

template <typename T>
void CDoubleLinkedList<T>::TraveralDLinkedListNext(CNode<T>* h) {
    CNode<T>* current = h;
    current = current->pNext;
    while (current->pNext != h) {
        if( current->pNext->element != h->element )
            cout << current->element << "->";
        else
            cout << current->element << endl;
        current = current->pNext;
    }
}

template <typename T>
void CDoubleLinkedList<T>::TraveralDLinkedListPrev(CNode<T>* h) {
    CNode<T>* current = h;
    current = current->pPrev->pPrev;
    while (current != h) {
        if( current->pPrev->element != h->element )
            cout << current->element << "->";
        else
            cout << current->element << endl;
        current = current->pPrev;
    }
}

#endif
