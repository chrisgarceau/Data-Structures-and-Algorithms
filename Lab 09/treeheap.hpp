#include "treeheap.h"
namespace DS {

    //Precondition: p points to a complete binary tree which is also a valid
    //  MAX HEAP except for the root node
    //Postcondition: The tree pointed to by p is a valid MAX HEAP
    template <typename T>
    void treeHeap<T>::heapify_downward(node* p) {
        //TODO: Student implements
        if(p == nullptr) {
            return;
        }
        heapify_downward(p->left());
        heapify_downward(p->right());
        node* largest = p;
        if(p->left() && p->left()->data() > p->data()) {
            largest = p->left();
        }
        if(p->right() && p->right()->data() > p->data()) {
            largest = p->right();
        }
        if(largest->data() != p->data()) {
            std::swap(p->data(), largest->data());
            heapify_downward(p);
        }
    }


} /* end namespace DS */