#include "LinkIterator.h"

int main(void) {
    CLinkList<int> list;
    list.InsertFront(11);
    list.InsertFront(77);
    list.InsertFront(33);
    list.InsertFront(55);
    list.InsertFront(66);
    list.InsertFront(99);
    list.InsertFront(22);
    
    CLinkIterator<int> listIterator( list );
    if( listIterator.isNotNull() ) {
        cout << *listIterator.First();
        do {
            cout << " -> " <<  *listIterator.Next();
        }while( listIterator.isNextNotNull() );
        cout << endl;
    }    
    return 0;
}
