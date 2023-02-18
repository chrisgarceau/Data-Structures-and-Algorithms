/*
 * treeHeap.h
 *
 *  Created on: Apr 16, 2016
 *  Updated on: Nov 9, 2020
 *  Author: S. Miller
 */

#ifndef TREEHEAP_H_
#define TREEHEAP_H_

#include "node_btree.h"
#include <cmath>
#include <iomanip>
#include <cassert>

#ifdef _MSC_VER
//Microsoft does not include logn in math.h, therefore, implement for MS visual ONLY
double log2( double n )
{
	return log( n ) / log( 2 );
}
#endif

namespace DS {

    template <typename T>
    class treeHeap {
    public:
        typedef T value_type;
        typedef DSBTREE::node<value_type> node;

        treeHeap() { root_ptr = nullptr; numNodes = 0; }
        ~treeHeap() { clear(root_ptr); }

        //Delete entire tree
        void clear(node* root=nullptr);

        //Output the tree with the head node printing LEFT JUSTIFIED and each height displaying indented
        void printTree() const { printTree(root_ptr, 0); };
        void printTree(const node* node_ptr, size_t depth) const;

        /*
        Precondition: the HEAP is not empty
        Postcondition: The MAX value in the HEAP is REMOVED and RETURNED.  The tree is still a valid HEAP
         */
        value_type pop();

        /*
            Precondition: None
            Postcondition: The tree is still a valid MAX HEAP with the new ITEM added
         */
        void push(const value_type&);

    private:
        node* root_ptr;
        size_t numNodes;

        /*
            Precondition: Arg1 points to a complete binary tree which is also a valid MAX HEAP except for the root node
            Postcondition: The tree pointed to by p is a valid MAX HEAP
         */
        void heapify_downward(node*);

        /*
            Precondition: Arg1 points to a complete binary tree which is NOT empty.  Arg2is initially set to the number of nodes-1.
            Postcondition: A pointer is returned pointing to the parent node of the LAST node in the complete tree
         */
        node* getLastParent(node*,const size_t);

        /*
        Precondition: Arg1 points to a valid MAX HEAP which is NOT empty, Arg2 is initially set to the current number of nodes.
        Postcondition: New item is added to the tree, the tree will still be a complete tree, the tree will be reheapified as a MAX HEAP.
            The return value is not important to the user of this function, internally it is used as a flag to exit the heapification.
         */
        bool completeInsert(node*,const T&,const size_t);

    };


    template <typename T>
    void treeHeap<T>::printTree(const node* node_ptr, size_t depth) const {
        if (node_ptr != nullptr)
        {
            printTree(node_ptr->right(), depth + 1);
            std::cout << std::setw(4*depth) // Indent 4*depth spaces.
                      << node_ptr->data( ) << std::endl;
            printTree(node_ptr->left(), depth + 1);
        }
    }

    template <typename T>
    T treeHeap<T>::pop() {
        assert (numNodes > 0 );
        T poppedItem;

        //Pop
        poppedItem = root_ptr->data();

        if ( numNodes == 1 ) {
            clear(root_ptr);
            numNodes = 0;
        }
        else {

            node* pParent = getLastParent(root_ptr, numNodes - 1);
            if ( pParent->right() == nullptr ) {
                root_ptr->setData( pParent->left()->data());
                delete pParent->left();
                pParent->setLeft(nullptr);
            } else {
                root_ptr->setData( pParent->right()->data());
                delete pParent->right();
                pParent->setRight(nullptr);
            }
            --numNodes;

            heapify_downward(root_ptr);

        }
        return poppedItem;
    }

    template <typename T>
    void treeHeap<T>::push(const T& item) {
        if ( root_ptr == nullptr ) {
            root_ptr = new node(item);
            numNodes = 1;
        }
        else {
            completeInsert(root_ptr, item, numNodes);
        }
    }

    template <typename T>
    bool treeHeap<T>::completeInsert(node* p, const T& item, const size_t targetleaf) {
        //Number of possible nodes at highest depth
        size_t height = (size_t)log2(targetleaf+1);
        size_t nodesLast = (size_t)std::pow(2,height); //#Max # of leaves at this height
        bool reheapify = true; //By default we willl reheapify
        node* visitNode = nullptr;

        if ( height == 1 && p->left() == nullptr ) {
            visitNode = new node(item);
            p->setLeft(visitNode);
            ++numNodes;
        } else if ( height == 1 ) {
            visitNode = new node(item);
            p->setRight(visitNode);
            ++numNodes;
        } else {
            if ( targetleaf - (size_t)std::pow(2,height) + 1 < nodesLast/2 ) {
                //Go Left
                visitNode = p->left();
                reheapify = completeInsert(visitNode,item,targetleaf-std::pow(2,height-1));
            } else {
                visitNode = p->right();
                reheapify = completeInsert(visitNode,item,targetleaf-std::pow(2,height));
            }
        }

        //Reheapify Upwards
        if ( reheapify) {
            if ( visitNode->data() > p->data() ) {
                std::swap( visitNode->data(), p->data() );
                return true;
            }
        }
        return false;
    }

    template <typename T>
    typename treeHeap<T>::node* treeHeap<T>::getLastParent(node* p, const size_t targetleaf) {
        //Number of possible nodes at highest depth
        size_t height = (size_t)log2(targetleaf+1);
        size_t nodesLast = pow(2,height); //#Max # of leaves at this height

        if ( height == 1 ) {
            return p;
        } else {
            if ( targetleaf - pow(2,height) + 1 < nodesLast/2 ) {

                return getLastParent(p->left(),targetleaf-pow(2,height-1));
            } else {
                return getLastParent(p->right(),targetleaf-pow(2,height));
            }
        }
    }

    template <typename T>
    void treeHeap<T>::clear(node* root) {
        if (root != nullptr)
        {
            clear( root->left() );
            clear( root->right() );
            delete root;
        }
    }

} /* namespace DS */

//Student implementation is contained in
#include "treeheap.hpp"

#endif /* TREEHEAP_H_ */