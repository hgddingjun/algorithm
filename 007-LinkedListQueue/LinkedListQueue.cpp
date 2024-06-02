#include "LinkedListQueue.h"

int main(void) {
	CLinkedListQueue<int> llq;
	cout << "test Linked List Queue" << endl;
	llq.EnQueue(10);
	llq.EnQueue(20);
	llq.EnQueue(30);
	llq.EnQueue(40);
	llq.EnQueue(50);
	llq.EnQueue(60);
	
	cout << llq.GetQueueHead() << endl;
	
	cout << llq.GetQueueTail() << endl;
	return 0;
}
