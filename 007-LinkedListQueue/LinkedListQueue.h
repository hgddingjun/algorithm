#ifndef __LINKED_LIST_QUEUE
#define __LINKED_LIST_QUEUE

#include <iostream>
using namespace std;

template <typename T>
class CNode {
public:
	CNode(const T& e, CNode<T>* n=nullptr): element(e), pNext(n) {}
	T element;
	CNode<T>* pNext;
};

template <typename T>
class CLinkedListQueue {
public:
	CLinkedListQueue();
	~CLinkedListQueue();

	bool isHeadEmpty() const;
	bool isTailEmpty() const;
	const T& GetQueueHead() const;
	const T& GetQueueTail() const;
	void EnQueue(const T& e);
	const T DeQueue();
	void FlushQueue();

private:
	CNode<T>* pHead;
	CNode<T>* pTail;
};

template <typename T>
CLinkedListQueue<T>::CLinkedListQueue() {
	pHead = pTail = nullptr;
}

template <typename T>
CLinkedListQueue<T>::~CLinkedListQueue() {
	FlushQueue();
}


template <typename T>
bool CLinkedListQueue<T>::isHeadEmpty() const {
	return pHead == nullptr;
}

template <typename T>
bool CLinkedListQueue<T>::isTailEmpty() const {
	return pTail == nullptr;
}

template <typename T>
const T& CLinkedListQueue<T>::GetQueueHead() const {
	if( isHeadEmpty() ) throw "Queue head is empty!";
	return pHead->element;
}

template <typename T>
const T& CLinkedListQueue<T>::GetQueueTail() const {
	if( isTailEmpty() ) throw "Queue tail is empty!";
	return pTail->element;
}


template <typename T>
void CLinkedListQueue<T>::EnQueue(const T& e) {
	if( isHeadEmpty() ) {
		pTail = pHead = new CNode<T>(e);
	} else {
		pTail->pNext = new CNode<T>(e);
		pTail = pTail->pNext;
	}
}


template <typename T>
const T CLinkedListQueue<T>::DeQueue() {
	T	headelement = GetQueueHead();
	CNode<T>* delHead = pHead;
	pHead = pHead->pNext;
	delete delHead;
	delHead = nullptr;
	return headelement;
}


template <typename T>
void CLinkedListQueue<T>::FlushQueue() {
	while( pHead ) {
		DeQueue();
	}
}

#endif 
