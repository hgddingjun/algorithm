#include "LinkList.h"

int main(void) {
    CLinkList<char> linkList;
     CLinkList<char> linkList2;

    linkList.InsertFront('p');
    linkList.InsertFront('q');
    linkList.InsertFront('w');
    linkList.InsertFront('e');
    linkList.InsertFront('x');
    linkList.InsertFront('T');

    linkList2.InsertFront('a');
    linkList2.InsertFront('b');
    linkList2.InsertFront('c');
    linkList2.InsertFront('d');
    linkList2.InsertFront('e');
    linkList2.InsertFront('f');
    linkList2.InsertFront('g');
    linkList2.InsertFront('h');
    linkList2.InsertFront('z');

    linkList.TraversalLinkList();
    linkList.InvertLinkList();
    linkList.TraversalLinkList();

    linkList2.InvertLinkList();
    linkList.ConcatenateLinkList(linkList2);
    linkList.TraversalLinkList();

    return 0;
}
