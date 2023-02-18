/*
 * bstree.h

Binary Tree


Precondition: None
Precondition: Inserts newDataItem into the binary search tree.  Calls bst_insert in all cases except for empty tree.
void insert( const Item&);

Precondition: bst_height is implemented and works
Precondition: Returns the height of the binary tree pointed to by root_ptr by calling the private recursive
	function called bst_height.  Recall that an empty tree is said to have height = -1.
long height( ) const { return (root_ptr == NULL) ? -1 : bst_height(root_ptr);  };

Precondition: None
Postcondition: Calls the book authors binary_tree_node print helper function to output the tree to stdout
void prettyprint() const;

Precondition: None
Postcondition: The book authors binary_tree_node inorder/preorder/postorder functions are called in order to output the ordered collapsed tree
void preorderprint() const;
void inorderprint() const;
void postorderprint() const;

Precondition: Tree has at least one node
Postcondition: Height of the tree is returned recursively, recall that a tree with one node is height of 0
long bst_height(const  binary_tree_node<Item>*) const;

Precondition: Tree has at least one node, ie height >= 0
Precondition: Inserts newDataItem into the binary search tree in the correct spot.
void bst_insert( const Item& newDataItem,binary_tree_node<Item>*);

 */

#ifndef BSTREE_H_
#define BSTREE_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream> //Very cool way to join strings with numbers and other types
#include "node_btree.h"

namespace DS {

/*
Precondition: None
Postcondition:  Outputs data prepended by the -> string.  This function gets called by the (pre/in/post)print functions
*/
    template <typename T>
    void print_node(const T data) { std::cout <<  "->" << data; };

    template <typename T>
    class bst_tree {
    public:
        typedef T value_type;
        typedef DSBTREE::node<value_type> node;

        bst_tree() { root_ptr = nullptr;	}
        ~bst_tree() { clear(root_ptr); };
        void clear() { clear(root_ptr); root_ptr=nullptr; };

        void insert( const T& newDataItem);
        long height( ) const { return (root_ptr == NULL) ? -1 : bst_height(root_ptr);  };

        void printTree() const;
        std::string toString() const;

        bool in_bst(const T& target) { return in_bst(target,root_ptr); }

        bool bst_remove(const T& target) { return bst_remove(target,root_ptr); }

        void bst_remove_max(node*&, T&);


    private:
        void bst_insert( const T&, node*);
        void clear(node* root);

        bool bst_remove(const T&, node*&);
        bool in_bst(const T&, node*);

        long bst_height(const node*) const;
        void printTree(const node*, size_t= 0) const;
        void buildStringStream(const node*, std::ostringstream&, bool& firstOutputted) const;

        node* root_ptr;
    };

    template <typename T>
    void bst_tree<T>::clear(node* root) {
        if (root != nullptr)
        {
            clear( root->left() );
            clear( root->right() );
            delete root;
        }
    }

    template <typename T>
    void bst_tree<T>::insert( const T& newDataItem) {
        if ( root_ptr == nullptr )
            root_ptr = new node(newDataItem);
        else bst_insert(newDataItem, root_ptr);
    }

    template <typename T>
    void bst_tree<T>::printTree() const {
        if ( root_ptr == nullptr )
            std::cout << "Empty tree" << std::endl;
        else
        {
            std::cout << std::endl;
            printTree(root_ptr, 0);
            std::cout << std::endl;
        }
    }

    template <typename T>
    void bst_tree<T>::printTree(const node* node_ptr, size_t depth) const
// Library facilities used: iomanip, iostream, stdlib
    {
        //To output a binary tree in pretty ASCII we do INORDER
        //However, we go RIGHT first instead of LEFT
        if (node_ptr != nullptr)
        {
            printTree(node_ptr->right(), depth + 1);
            std::cout << std::setw(4*depth) << ""; // Indent 4*depth spaces.
            std::cout << node_ptr->data( ) << std::endl;
            printTree(node_ptr->left(), depth + 1);
        }
    }

    template <typename T>
    std::string bst_tree<T>::toString() const {
        std::ostringstream s;
        bool firstNumberOutputted = false;
        buildStringStream(root_ptr, s, firstNumberOutputted);
        return s.str();
    }

} //End Namespace DS

#include "bst_tree.hpp"
#endif /* BSTREE_H_ */