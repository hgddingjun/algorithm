#include "LinkedListStack.h"

int main(void) {
	cout << "test Linked List Stack:" << endl;
	CLinkedListStack<char> lls;
	lls.Push('a');
	cout << "[1] current stack top element is: " << lls.Top() << endl;
	lls.Push('b');
	cout << "[2] current stack top element is: " << lls.Top() << endl;
	lls.Push('c');
	cout << "[3] current stack top element is: " << lls.Top() << endl;
	lls.Push('d');
	cout << "[4] current stack top element is: " << lls.Top() << endl;
	lls.Push('e');
	cout << "[5] current stack top element is: " << lls.Top() << endl;
	lls.Push('f');
	cout << "[6] current stack top element is: " << lls.Top() << endl;

	cout<<"============================================="<<endl;

	cout << "[1] current stack top element is: " << lls.Top() << endl;
	lls.Pop();
	cout << "[2] current stack top element is: " << lls.Top() << endl;
	lls.Pop();
	cout << "[3] current stack top element is: " << lls.Top() << endl;
	lls.Pop();
	cout << "[4] current stack top element is: " << lls.Top() << endl;
	lls.Pop();
	cout << "[5] current stack top element is: " << lls.Top() << endl;
	lls.Pop();
	cout << "[6] current stack top element is: " << lls.Top() << endl;
	lls.Pop();
	return 0;
}
