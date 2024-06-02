#include "CircleLinkedList.h"

const int MAXNODENUM = 26;

int main(void) {
    CNode<char>* n[MAXNODENUM];
    CCircleLinkedList<char> cll;

    for(int i=0; i<MAXNODENUM; i++) {
        n[i] = new CNode<char>();
        n[i]->element = 'a' + i;
        cll.InsertNode(cll.head, n[i]);
         cll.TraveralCircleLinkedList(cll.head);
    }

    cout << "delete Circle Linked List!" << endl;
    cll.DeleteNode(cll.head, n[16]);
    cll.TraveralCircleLinkedList(cll.head);

    return 0;
}
