#include "DoubleLinkedList.h"
const int NodeNum = 8;
int main(void) {
    CNode<int> *n[NodeNum];
    CDoubleLinkedList<int> dl;

    for(int i=0; i<NodeNum; i++) {
        n[i] = new CNode<int>();
        n[i]->element = i*10;
        dl.InsertNode(dl.head, n[i]);
        dl.TraveralDLinkedListNext(dl.head);
    }
    cout << "insert Double Linked List successfully!" << endl;

    cout <<endl << "====================================================" << endl;
    dl.TraveralDLinkedListNext(dl.head);
    dl.TraveralDLinkedListPrev(dl.head);
    cout << "====================================================" << endl <<endl;

    cout << "delete Double Linked List successfully!" << endl;
    for(int i=0; i<NodeNum; i++) {
        dl.DeleteNode(dl.head, n[i]);
        dl.TraveralDLinkedListNext(dl.head);
    }

    return 0;
}
