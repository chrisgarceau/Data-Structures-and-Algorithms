/*
Program Name: Lab x
Programmer Name: Prof. Miller
Date Submitted: Not submitted
File Purpose: node and linkedList Class Header
Date Updated: n/a
Purpose for Update: n/a
Global Variable List: n/a (avoid these)
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <cstdlib>
#include <ostream>
#include "node_ll_int.h"

namespace DS {

    class linkedList
    {
    public:
        typedef DSLLI::node node;
        linkedList () { head = nullptr; };
        virtual ~linkedList () { deleteList(); };
        void add(node::value_type);
        void insertItem (node::value_type);
        void makeList (const node::value_type [],const size_t& count);
        void deleteList ();

        //The following friend function is implemented in lablinklist.cpp
        friend std::ostream& operator<<(std::ostream&, const linkedList&);
    private:
        node* head; //points to the first node of the linked list
    };

} //end namespace

#endif /* LINKEDLIST_H_ */