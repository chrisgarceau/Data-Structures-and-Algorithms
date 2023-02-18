//============================================================================
// Name        : lablinklist.cpp
// Author      : S. Miller
// Version     : 1.2
// Copyright   : WCC
// Description : Linked List Lab Test Program
//============================================================================

#include <iostream>
#include "linkedlist.h"

using namespace std;
using namespace DS;


int main() {

    linkedList list1;

    //Replace list with a new one in a specific order
    int pow2[] = {1,2,4,8,16,32,16,8,4,2,1};
    list1.makeList(pow2,sizeof(pow2)/sizeof(int));
    list1.add(90);
    list1.add(34);
    cout << list1 << endl;

    //Test of deleting entire list
    list1.deleteList();

    //Test of adding items out of order
    list1.insertItem(5);
    list1.insertItem(20);
    list1.insertItem(10);
    list1.add(303);
    cout << list1 << endl;

    //Add items again in same order as before
    list1.insertItem(5);
    list1.insertItem(20);
    list1.insertItem(10);
    cout << list1 << endl;

    //Returning a non-zero number, if not 3, then we know it seg-faulted
    return 3;
}

namespace DS {

/*
The following is provided so that everybody can easily get the same exact output
*/
    std::ostream& operator<<(std::ostream& os, const linkedList& srcList) {

        //Set a current-pointer to the "head".
        const linkedList::node* cursor = srcList.head;

        //While current-pointer is not NULL
        while ( cursor != nullptr )
        {
            //Print the data member ("datum") of the current node
            os << "->[" << cursor->getData() << "]";
            //Set the current-pointer to the "next" node in the list.
            cursor = cursor->getNext();
        }
        //Print out a basic termination symbol
        os << "--X" << std::endl;

        return os;
    }
}