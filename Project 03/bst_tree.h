// Program Name: Project 3
// Programmer Name: Christopher Garceau
// Attempt Number: 2
// Purpose: Class interface to construct and keep statistics on a BST. Also can calculate statistics of
// specific nodes within the BST.
// Purpose for Update: Updating all class documentation
//
//CLASS PROVIDED: bst_tree
//  (a class to construct and keep statistics on a BST. Also can calculate statistics of
//  specific nodes within the BST.)
//   This class is part of the namespace DS.
//
//CONSTRUCTOR for the bst_tree class:
//  bst_tree( );
//      Precondition: N/A
//      Post-condition: The object has been initialized, and is ready to accept
//          value types to be inserted into a BST. Various actions and statistics will be performed
//          and calculated from data in the BST. Memory allocation is performed.
//
//DESTRUCTOR W/ HELPER METHOD
//  ~bst_tree();
//      Precondition: N/A
//      Post-condition: Calls clear() helper method and returns all heap storage back to the OS.
//
//  void clear();
//      Precondition: BST must have at least one node.
//      Post-condition: The BST is cleared and all of it's memory is returned the heap storage. root_ptr
//          points to nullptr.
//      Note: This function is a dependency of the private member function, clear().
//
//PUBLIC MODIFICATION MEMBER FUNCTIONS
//  void insertAll(const T &newDataItem);
//      Precondition: N/A
//      Post-condition: newDataItem is inserted into the BST in the correct position, including duplicates.
//      Note: This function is a dependency of the bst_insertAll function.
//
//  void insertOne(const T &newDataItem);
//      Precondition: N/A
//      Post-condition: Only one copy of newDataItem is inserted into the BST in the correct position.
//      Note: This function is a dependency of the bst_insertOne function.
//
//PUBLIC CONSTANT MEMBER FUNCTIONS
//  int wordFreq(const T &target);
//     Precondition: BST must have duplicates and has at least one node.
//     Post-condition: The frequency of a specific node is returned as an integer value.
//
//  bool in_bst(const T &target);
//    Precondition: BST must have at least one node.
//    Post-condition: If the target exists within the BST, boolean value returned is true. Else, false is returned.
//
//  std::string toStringAlpha(bst_tree<T> &tree) const;
//     Precondition: BST must have at least one node.
//     Post-condition: A string stream is generated and returned using the buildStringStreamAlpha function.
//
//  std::string toStringLH(bst_tree<T> &tree, int freq) const;
//     Precondition: BST must have at least one node.
//     Post-condition: A string stream is generated and returned using the buildStringStreamLH function.
//
//  void printLH(bst_tree<T> &treeAll, bst_tree<T> &treeOne) const;
//      Precondition: BST references must have at least one node.
//      Post-condition: Utilizes toStringLH, as well as buildStringStreamLH, to output a string that is formatted
//          properly.
//
//  void printTree() const;
//      Precondition: root_ptr points to a BST with at least one node.
//      Post-condition: BST is output to std::cout.
//
//PRIVATE CONSTANT MEMBER FUNCTIONS
//  void bst_insertAll(const T&, node*);
//      Precondition: N/A
//      Post-condition: newDataItem is inserted into the BST in the correct position, including duplicates.
//
//  void bst_insertOne(const T&, node*);
//      Precondition: N/A
//      Post-condition: newDataItem is inserted into the BST into the BST int the correct position. No duplicates allowed.
//
//  long bst_height(const node*) const;
//     Precondition: root_ptr points to a binary tree with at least one node.
//     Post-condition: Height of the tree is returned recursively, recall that a tree
//         with one node is height of 0 and an empty tree has a height of -1.
//
//  int nodeCount(node *root) const;
//      Precondition: root_ptr points to a binary tree with at least one node.
//      Post-condition: returns the total number of nodes within the BST.
//
//  int wordFreq(const T&, node*);
//      Precondition: root_ptr points to a binary tree with at least one node.
//      Post-condition: returns the frequency of a specific node within the BST.
//
//  bool in_bst(const T&, node*);
//      Precondition: root_ptr is a root pointer of a binary search tree.
//      Post-condition: Returns true if target is in the BST, false otherwise.
//
//  void buildStringStreamAlpha(const node*, std::ostringstream&, bool& firstOutputted, bst_tree<T> &tree) const;
//      Precondition: node pointer is a root pointer of a binary search tree,
//          ostringstream is a output stream, most likely empty, but this is not required. the bool value is set to false
//      Post-condition: Build a list of strings in the BST in order as a ostringsteam. After adding the first value, change the bool to true.
//          Comma and spaces are added between each value in the list
//      Note: This function is a dependency of toStringAlpha()
//
//  void buildStringStreamLH(const node*, std::ostringstream&, bool& firstOutputted, bst_tree<T> &tree, int freq) const;
//      Precondition: node pointer is a root pointer of a binary search tree,
//          ostringstream is a output stream, most likely empty, but this is not required. the bool value is set to false.
//      Post-condition: Build a list of strings in the BST in order as a ostringsteam. After adding the first value, change the bool to true.
//          Comma and spaces are added between each value in the list
//      Note: This function is a dependency of toStringLH()
//
//  void printTree(const node*, size_t = 0) const;
//      Precondition: Tree contains at least one node.
//      Post-condition: Tree is output to std::cout.
//      Note: This function is a dependency of printTree().
//
//
// VALUE SEMANTICS:
//  BST objects and the nodes that are part of those objects can be mutated and accessed using public memeber methods,
//  most via private member methods.
//
//INVARIANT DECLARATION
/* This templated class is part of the namespace DS and has the ability to construct binary trees of different types,
 insert new nodes (since the mutator functions are dependents of the node class), and access specific data about
 the binary tree as a whole or a specific node. As for the two mutator functions, insertAll has the ability to insert
 duplicate nodes into a binary tree, while insertOne disregards duplicates and only inserts one copy of each node.
 Most of the private member functions are called by their counterpart accessor public member functions to make sure
 data is not misused. The height function calculates the height of the binary tree, the nodeCount function calculates
 how many nodes are present in the binary tree, the wordFreq function calculates how many copies of a specific node are
 within a binary tree that was created using the insertAll function, and the in_bst function indicates whether or not
 a specific node is present in the binary tree by returning a boolean value. There are multiple public and private member
 methods that work together to output the data in the proper order (alphabetical or lowest to highest frequency) and
 format. Both buildStringStream functions recursively traverse the tree and then create a string using the data of each
 node, including proper formatting such as spaces, commas, brackets, etc. Both toString functions are dependents of
 their respective buildStringStream functions and return the string that the buildStringStream functions created.
 Once the tree is not of use anymore, the data of the binary tree can be deleted using the clear method.
*/

#ifndef BSTREE_H_
#define BSTREE_H_

#include <iostream>
#include <iomanip>
#include <string>
#include "node_btree.h"

namespace DS {

    template <typename T>
    class bst_tree {

    public:
        //Typedef declarations
        typedef T value_type;
        typedef DSBTREE::node<value_type> node;

        //Default constructor
        bst_tree() { root_ptr = nullptr; }

        //Destructor
        ~bst_tree() { clear(root_ptr); };
        void clear() { clear(root_ptr); root_ptr = nullptr; };

        //Mutator methods
        void insertAll(const T &newDataItem);
        void insertOne(const T &newDataItem);

        //Accessor methods
        int wordFreq(const T &target) { return wordFreq(target, root_ptr); }
        bool in_bst(const T &target) { return in_bst(target,root_ptr); }
        std::string toStringAlpha(bst_tree<T> &tree) const;
        std::string toStringLH(bst_tree<T> &tree, int freq) const;
        void printLH(bst_tree<T> &treeAll, bst_tree<T> &treeOne) const;
        void printTree() const;

    private:
        void clear(node* root);
        void bst_insertAll(const T&, node*);
        void bst_insertOne(const T&, node*);
        long bst_height(const node*) const;
        int nodeCount(node *root) const;
        int wordFreq(const T&, node*);
        bool in_bst(const T&, node*);
        void buildStringStreamAlpha(const node*, std::ostringstream&, bool& firstOutputted, bst_tree<T> &tree) const;
        void buildStringStreamLH(const node*, std::ostringstream&, bool& firstOutputted, bst_tree<T> &tree, int freq) const;
        void printTree(const node*, size_t = 0) const;
        node* root_ptr;
    };

} //End Namespace DS

#include "bst_tree.hpp"
#endif /* BSTREE_H_ */
