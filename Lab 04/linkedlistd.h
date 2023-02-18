/*
Program Name: Lab 4
Programmer Name: Prof. Miller
Date Submitted: Not submitted
File Purpose: ListNode and linkedList header
Date Updated: n/a
Purpose for Update: n/a
Global Variable List: n/a (avoid these)
*/

#ifndef LINKEDDLIST_H
#define LINKEDDLIST_H
#include <cstdlib>
#include <iostream>
#include "node_dll.h"

namespace DS {

    class linkedList
    {
    public:
        typedef int value_type;
        typedef DSDLL::node<value_type> node;

        //The following are implemented in linkedlistd.cpp
        linkedList ();
        virtual ~linkedList ();
        void insertItem (value_type);
        void makeList (const value_type [],const size_t& count);
        void deleteList ();

        //The following two functions are implemented by student in lab04.cpp
        node* appendAt (const value_type&, node* );
        node* insertAt (const value_type&, node* = nullptr);

        //The following two assessors are for testing purpose and implemented inline
        //Therefore, you do not need to implement in the cpp file
        node* getHead() { return head; };
        node* getTail() { return tail; };

        //The following friend function is implemented in lablinklist.cpp
        friend std::ostream& operator<<(std::ostream&, const linkedList&);
        friend std::ostream& operator>>(std::ostream&, const linkedList&);
    private:
        node* head;
        node* tail;
    };

} //end namespace

#endif /* linkedList_H_ */