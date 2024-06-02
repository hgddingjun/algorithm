#ifndef __LINKITERATOR_H
#define __LINKITERATOR_H

#include <iostream>
using namespace std;

template <typename T> class CNode;
template <typename T> class CLinkList;  //decareation
template <typename T> class CLinkIterator;


template <typename T>
class CNode {
    friend class CLinkList<T>; 
    friend class CLinkIterator<T>;
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
    friend class CLinkIterator<T>;
public:
    CLinkList() { firstNode = nullptr; }
    void InsertFront(T key);
    void DeleteNode(T key);
    void InvertLinkList(void);
    void ConcatenateLinkList(CLinkList<T> b);
    void TraversalLinkList(void);

private:
    CNode<T>* firstNode;
};


template <typename T> 
class CLinkIterator {
public:
    CLinkIterator(const CLinkList<T>& LL): linkList(LL), currentNode(LL.firstNode) {}
    bool isNotNull() ;
    bool isNextNotNull() ;
    T* First();
    T* Next();

private:
    const CLinkList<T>& linkList;
    CNode<T>* currentNode;
};

template <typename T>
bool CLinkIterator<T>::isNotNull()  {
    if( currentNode ) 
        return true;
    else 
        return false;
}

template <typename T>
bool CLinkIterator<T>::isNextNotNull()  {
    if( currentNode && currentNode->next )
        return true;
    else
        return false;
}

template <typename T>
T* CLinkIterator<T>::First() {
    if( linkList.firstNode )
        return &linkList.firstNode->element;
    else
        return nullptr;
}

template <typename T>
T* CLinkIterator<T>::Next() {
    if( currentNode) {
        currentNode = currentNode->next;
        return &currentNode->element;
    }
    else
        return nullptr;
}

template <typename T>
void CLinkList<T>::InsertFront(T key) {
    CNode<T>* node = new CNode<T>(key);
    node->next = firstNode;
    firstNode = node;
}

template <typename T>
void CLinkList<T>::DeleteNode(T key) {
    if (firstNode == nullptr) { return ; }
    CNode<T>* cur = firstNode;
    CNode<T>* prv = nullptr;
    for(; cur && cur->element != key; prv=cur, cur=cur->next) {
    }

    if(cur) {
        if( prv ) { //find delete node.
            prv->next = cur->next;
        } else { //if delete node is head node
            firstNode = firstNode->next;
        }
        delete cur;
    }
}

template <typename T>
void CLinkList<T>::InvertLinkList(void) {
    CNode<T>* p = firstNode;
    CNode<T>* q = nullptr;

    if (firstNode == nullptr) { return ;}

    while( p != nullptr ) {
         CNode<T>* r = q;
         q = p;
         p = p->next;
         q->next = r;
    }
    firstNode = q;
}

template <typename T>
void CLinkList<T>::ConcatenateLinkList(CLinkList<T> b) {
    CNode<T>* p;
    if( !firstNode ) {
        firstNode = b.firstNode;
        return;
    }

    if( b.firstNode ) {
        p = firstNode;
        while(p->next) {
            p = p->next;
        }
        p->next = b.firstNode;
    }
}

template <typename T>
void CLinkList<T>::TraversalLinkList(void) {
    CNode<T>* p = firstNode;
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
