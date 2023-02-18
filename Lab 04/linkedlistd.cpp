/*
Program Name: Lab 4
Programmer Name:
Date Submitted:
File Purpose: linkedList Class Implementation
Date Updated: n/a
Purpose for Update: n/a
Global Variable List: n/a (avoid these)
*/

#include <ostream>
#include <cassert>
#include "linkedlistd.h"

namespace DS {

    linkedList::linkedList () {
        head = tail = nullptr;
    }

    linkedList::~linkedList () {
        deleteList();
    }

    void linkedList::insertItem (value_type newdatum) {

        node* ccursor = head;
        node* pcursor = nullptr;

        if ( head == NULL ) {
            insertAt(newdatum,ccursor);
        } else {
            while ( ccursor != NULL && newdatum > ccursor->getData() ) {
                pcursor = ccursor;
                ccursor = ccursor->next();
            }

            appendAt(newdatum,pcursor);
        }

    }

    void linkedList::makeList (const value_type items[], const size_t& count) {

        deleteList ();

        if ( count == 0 ) return;

        insertAt(items[0]);

        node* ccursor = head;

        for ( size_t i=1 ; i < count ; ++i ) {
            ccursor = appendAt(items[i],ccursor);
        }

    }

    void linkedList::deleteList () {

        node* dcursor;

        while ( head != nullptr ) {
            dcursor = head;
            head = head->next();
            delete dcursor;
        }
        head = tail = nullptr;

    }

} //end of DS namespace