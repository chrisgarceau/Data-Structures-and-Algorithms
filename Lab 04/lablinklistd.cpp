/*
Program Name: Lab 4
Programmer Name: Prof. Miller
Date Submitted: Not submitted
File Purpose: Driver code
Date Updated: n/a
Purpose for Update: n/a
Global Variable List: n/a (avoid these)
*/

#include <iostream>
#include "linkedlistd.h"

using namespace std;
using namespace DS;


int main() {

    linkedList list1;
    linkedList::node *tn1,*tn2;

    //Test of adding items out of order
    list1.insertItem(5);
    list1.insertItem(20);
    list1.insertItem(10);
    cout << list1 << endl;
    cout >> list1 << endl;

    //Test of deleting entire list
    list1.deleteList();
    cout << list1 << endl;

    //Add items again using insertAt and appendAt
    list1.insertAt(5);
    tn1 = list1.appendAt(10,list1.getHead());
    tn2 = list1.appendAt(7,list1.getTail());
    list1.appendAt(20,tn1);
    list1.insertAt(30,list1.getHead());
    list1.appendAt(2,tn2);
    //Output forwards
    cout << list1 << endl;
    //Output reverse
    cout >> list1 << endl;

    //Now replace list with a new one in a specific order
    int pow2[] = {1,2,4,8,16,32,16,8,4,2,1};
    list1.makeList(pow2,sizeof(pow2)/sizeof(int));
    cout << list1 << endl;
    cout >> list1 << endl;

    //Returning a non-zero number, if not 3, then we know it seg-faulted
    return 3;
}

namespace DS {

/*

The following is provided so that everybody can easily get the same exact output

*/
    std::ostream& operator<<(std::ostream& os, const linkedList &srcList) {

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
        std::cout << "--X" << std::endl;

        return os;
    }

    std::ostream& operator>>(std::ostream& os, const linkedList &srcList) {

        //Set a current-pointer to the "head".
        const linkedList::node* cursor = srcList.tail;
        if ( cursor == nullptr )
            return os;

        //Print out a start symbol
        os << "X--[" << cursor->getData() << "]";
        cursor = cursor->getPrev();

        //While current-pointer is not NULL
        while ( cursor != nullptr )
        {
            //Print the data member ("datum") of the current node
            os << "<-[" << cursor->getData() << "]";
            //Set the current-pointer to the "next" node in the list.
            cursor = cursor->getPrev();
        }
        //Print out a basic termination symbol
        std::cout << "<-" << std::endl;

        return os;
    }
}