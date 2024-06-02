#ifndef __LINK_LIST_H
#define __LINK_LIST_H

#include <iostream>
using namespace std;

template <typename T> class CLinkList;  //decareation
template <typename T> class CLinkIterator;

template <typename T>
class CNode {
    friend class CLinkList<T>; 
public:
    CNode(T);

private:
    T element;
    CNode* next;
};

template <typename T>
CNode<T>::CNode(T data) {
    element = data;
    next = nullptr;
}


template <typename T>
class CLinkList {
public:
    CLinkList() { first = nullptr; }
    void InsertFront(T key);
    void DeleteNode(T key);
    void InvertLinkList(void);
    void ConcatenateLinkList(CLinkList<T> b);
    void TraversalLinkList(void);

private:
    CNode<T>* first;
};

template <typename T>
void CLinkList<T>::InsertFront(T key) {
    CNode<T>* node = new CNode<T>(key);
    node->next = first;
    first = node;
}

template <typename T>
void CLinkList<T>::DeleteNode(T key) {
    if (first == nullptr) { return ; }
    CNode<T>* cur = first;
    CNode<T>* prv = nullptr;
    for(; cur && cur->element != key; prv=cur, cur=cur->next) {
    }

    if(cur) {
        if( prv ) { //find delete node.
            prv->next = cur->next;
        } else { //if delete node is head node
            first = first->next;
        }
        delete cur;
    }
}

template <typename T>
void CLinkList<T>::InvertLinkList(void) {
    CNode<T>* p = first;
    CNode<T>* q = nullptr;

    if (first == nullptr) { return ;}

    while( p != nullptr ) {
         CNode<T>* r = q;
         q = p;
         p = p->next;
         q->next = r;
    }
    first = q;
}

template <typename T>
void CLinkList<T>::ConcatenateLinkList(CLinkList<T> b) {
    CNode<T>* p;
    if( !first ) {
        first = b.first;
        return;
    }

    if( b.first ) {
        p = first;
        while(p->next) {
            p = p->next;
        }
        p->next = b.first;
    }
}

template <typename T>
void CLinkList<T>::TraversalLinkList(void) {
    CNode<T>* p = first;
    while(p) {
        if(p->next != nullptr) {
            cout << p->element << " -> ";
        } else {
            cout << p->element;
        }        
        p = p->next;
    }
    cout << endl;
}


#endif
