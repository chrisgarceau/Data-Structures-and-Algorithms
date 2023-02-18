#include <ostream>
#include <cassert>
#include "linkedlistd.h"
using namespace std;
namespace DS {

//     Precondition: cursor is not NULL
//     Postcondition: A new node is created with the datum of newdatum.
//      The new node next points to cursor->next
//      The new node prev points to cursor
//      The cursor->next prev points to the new node
//      The cursor next points to the new node
//      Returns a pointer to the new node
    linkedList::node* linkedList::appendAt (const value_type& newdatum, node* cursor) {
        assert(cursor != nullptr);
        if (head == nullptr) {
            return nullptr;
        }
        node *newNode = new node(newdatum, cursor->next(), cursor);
        cursor->next() = newNode;

        if (newNode->next() != nullptr) {
            newNode->next()->prev() = newNode;
        }
        if (newNode->next() == nullptr) {
            tail = newNode;
        }
        return newNode;
    }

//     Precondition: none
//     Postcondition: A new node is created with the datum of newdatum.
//      The new node next points to cursor
//      The new node prev points to cursor->prev
//      The cursor->prev next points to the new node
//      The cursor prev points to the new node
//      Returns a pointer to the new node
    linkedList::node* linkedList::insertAt (const value_type& newdatum, node* cursor) {
        if (cursor == nullptr) {
            node *newNode = new node;
            newNode->setData(newdatum);
            head = newNode;
            return head;
        }
        else {
            node *newNode = new node();
            newNode->setData(newdatum);
            newNode->next() = cursor->next();
            newNode->prev() = cursor->prev();
            cursor->prev() = newNode;
            cursor->prev()->setNext(newNode);

        if (newNode->prev() != nullptr) {
            head = newNode;
        }

            return newNode;
        }
    }
} // end namespace