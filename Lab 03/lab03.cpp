#include "linkedlist.h"

namespace DS {

    void linkedList::insertItem (node::value_type item) {
    node *curr, *prev;
    prev = nullptr;
    curr = head;

    while (curr != nullptr && item > curr->getData()) {
        prev = curr;
        curr = curr->next();
    }

    node *temp_ptr = new node(item, curr);

        if (prev == nullptr) {
            head = temp_ptr;
        }
        else {
            prev->next() = temp_ptr;
        }

    }

    void linkedList::makeList (const node::value_type items[], const size_t &count) {
        node *new_node = new node(items[count - 1], head);

        for (int i = count - 2; i >= 0; i--) {
            new_node = new node(items[i], new_node);
            head = new_node;
        }
    }

    void linkedList::deleteList () {
        while (head != nullptr) {
            node *temp_ptr = head;
            head = head->next();
            delete temp_ptr;
        }
        head = nullptr;
    }


    void linkedList::add(node::value_type r) {
//        if (r < *min) {  //IF R IS LESS THAN MIN, MIN IS NOW R
//            *min = r;
//        }
//        if (r > *max) {  //IF R IS GREATER THAN MAX, MAX IS NOW R
//            *max = r;
//        }

        node *newNode = new node;  //ALLOCATES NEW NODE
        newNode->setData(r);  //SETS NEW NODES DATA TO r
        newNode->setNext(head);  //SETS NEXT OF NEW NODE AS HEAD
        head = newNode;  //HEAD POINTS TO THE NEW NODE

//        seqSum = seqSum + r;  //SUM IS UPDATED
    }

} //end of namespace