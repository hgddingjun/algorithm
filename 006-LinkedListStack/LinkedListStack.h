#ifndef __LINKED_LIST_STACK
#define __LINKED_LIST_STACK
#include <iostream>
using namespace std;

template <typename T> class CLinkedListStack;

template <typename T>
class CNode {
	friend class CLinkedListStack<T>;
public:
	CNode(const T& e): element(e)  {}
private:
	T element;
	CNode<T>* link;
};


template <typename T>
class CLinkedListStack {
public:
	CLinkedListStack(): stacktop(nullptr) {}
	~CLinkedListStack() { MakeStackEmpty(); }
	bool isEmpty() const;
	T& Top();
	void Push(const T& e);
	void Pop();
	void MakeStackEmpty();
private:
	CNode<T>* stacktop;	//stack top point
};


template <typename T>
bool CLinkedListStack<T>::isEmpty() const {
	return stacktop == nullptr;
}

template <typename T>
void CLinkedListStack<T>::Push(const T& e) {
	CNode<T>* newNode = new CNode<T>(e);
	newNode->link = stacktop;
	stacktop = newNode;
}

template <typename T>
T& CLinkedListStack<T>::Top() {
	return stacktop->element;
}

template <typename T>
void CLinkedListStack<T>::Pop() {
	CNode<T>* curNode = stacktop;
	if(curNode) {
		stacktop = stacktop->link;
		delete curNode;
		curNode = nullptr;
	}
}

template <typename T>
void CLinkedListStack<T>::MakeStackEmpty() {
	while( stacktop ) {
		Pop();
		stacktop=stacktop->link;
	}
}


#endif
