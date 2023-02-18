#include "bst_tree.h"
#include <cassert>
namespace DS {
//Precondition: root_ptr points to a binary tree with at least one node
//Postcondition: Height of the tree is returned recursively, recall that a tree
//  with one node is height of 0 and an empty tree has a height of -1
    template <typename T>
    long bst_tree<T>::bst_height(const node *root) const {
        if (root == nullptr) {
            return -1;
        }
        if (root->right() == nullptr && root->left() == nullptr) {
            return 0;
        }
        else {
            long leftDepth = bst_height(root->left());
            long rightDepth = bst_height(root->right());
            if (leftDepth > rightDepth) {
                return leftDepth + 1;
            }
            else {
                return rightDepth + 1;
            }
        }
    }

//Precondition: Tree has at least one node, ie height >= 0
//Precondition: Inserts newDataItem into the binary search tree in the correct spot.
    template <typename T>
    void bst_tree<T>::bst_insert( const T &newDataItem, node *node_ptr) {
         if (newDataItem == node_ptr->data()) {
              return;
         }

        if (newDataItem < node_ptr->data()) {
            if (node_ptr->left() == nullptr) {
                node_ptr->left() = new node(newDataItem);
            }
            else {
                 this->bst_insert(newDataItem, node_ptr->left());
            }
        }
        else {
            if (node_ptr->right() == nullptr) {
                 node_ptr->right() = new node(newDataItem);
            }
            else {
                this->bst_insert(newDataItem, node_ptr->right());
            }
        }
    }

//Precondition: root_ptr is a root pointer of a binary search tree
//Postcondition: Returns true if target is in the BST, false otherwise
    template <typename T>
    bool bst_tree<T>::in_bst(const T& target, node* root) {
        //IF TREE IS EMPTY
        if (root == nullptr) {
            return false;
        }
        //IF ROOT EQUALS TARGET
        if (root->data() == target) {
            return true;
        }
        //RECURSIVELY SEARCH LEFT SUBTREE
        bool existsLeft = in_bst(target, root->left());
        //RETURNS TRUE IF FOUND
        if (existsLeft) {
            return true;
        }
        //RECURSIVELY SEARCH RIGHT SUBTREE
        bool existsRight = in_bst(target, root->right());
        //RETURNS TRUE IF FOUND
        return existsRight;
    }

//Precondition: pointer is a root pointer of a binary search tree,
//  ostringstream is a output stream, most likely empty,
//    but this is not required.
//  the bool value is set to false
//Postcondition: Build a list of numbers in the BST in order as a ostringsteam.
//  After adding the first value, change the bool to true.
//  Comma and spaces are added between each value in the list
//  Note: This function is a dependancy of toString()
    template <typename T>
    void bst_tree<T>::buildStringStream(const node *p, std::ostringstream &s, bool &firstOutputted) const {
        if (p != nullptr) {
            firstOutputted = true;
            if (p->left()) {
                buildStringStream(p->left(), s, firstOutputted);
                s << ", ";
            }
            s << p->data();
            if (p->right()) {
                s << ", ";
                buildStringStream(p->right(), s, firstOutputted);
            }
        }
   }

//Precondition: root_ptr is a root pointer of a binary search tree or may be
//  NULL for an empty tree).
//Postcondition: If target was in the tree, then one copy of target has been
//  removed, and root_ptr now points to the root of the new
//  (smaller) binary search tree. In this case the function returns true.
//  If target was not in the tree, then the tree is unchanged (and the
//  function returns false).
    template <typename T>
    bool bst_tree<T>::bst_remove(const T &target, node *&node_ptr) {
        assert(node_ptr != nullptr);
        //1. BST COULD BE EMPTY
        if (node_ptr == nullptr) {
            return false;
        }
        //2. BST COULD BE NON-EMPTY, WITH TARGET LESS THAN ROOT DATA
        else if (node_ptr != nullptr && target < node_ptr->data()) {
            bst_remove(target, node_ptr->left());
            return true;
        }
        //3. BST COULD BE NON-EMPTY, WITH TARGET GREATER THAN ROOT DATA
        else if (node_ptr != nullptr && target > node_ptr->data()) {
            bst_remove(target, node_ptr->right());
            return true;
        }
        //4.
        else {
            //4a.
            if (node_ptr->left() == nullptr) {
                node_ptr = node_ptr->right();
                return true;
            }
            //4b.
            else {
                bst_remove_max(node_ptr->left(), node_ptr->data());
                return true;
            }
        }
    }

//1 : tree is emtpy
//2 : Tree not empty, target < than root
//3 : tree not empty, target > than root
//4 target == root node, do not need to check, if not < or >, than it is ==
//4a The root node has no left child
//4bThe root does have a left child, remove the max from the left subtree

//Precondtion: root_ptr is a root pointer of a non-empty binary search tree
//Postcondition: The largest item in the BST bas been removed, and the root_ptr
//  now points to the root of the new (smaller) BST. The reference parameter,
//  removed, has been set to a copy of the removed item.
    template <typename T>
    void bst_tree<T>::bst_remove_max(node *&root, T &removed) {
        //BASE CASE: NO RIGHT CHILD
        assert(root_ptr != nullptr);
        if (root->right() == nullptr) {
            removed = root->data();
            root = root->left();
            delete root;
        }
        //CASE 2
        else if (root->right() != nullptr){
            bst_remove_max(root->right(), removed);
        }

    }

} //End Namespace DS
