#include "bst_tree.h"
namespace DS {

    //Precondition: root_ptr points to a binary tree with at least one node.
    //Post-condition: returns the total number of nodes within the BST.
    template <typename T>
    int bst_tree<T>::nodeCount(node *root) const {
        if (root == nullptr) {
            return 0;
        }
        return 1 + nodeCount(root->left()) + nodeCount(root->right());
    }

    //Precondition: root_ptr points to a binary tree with at least one node.
    //Post-condition: returns the frequency of a specific node within the BST.
    template <typename T>
    int bst_tree<T>::wordFreq(const T &target, node *root) {
        if (root == nullptr) {
            return 0;
        }
        return (root->data() == target ? 1 : 0) + wordFreq(target, root->left()) + wordFreq(target, root->right());
    }

    //Precondition: root_ptr is a non-empty binary tree.
    //Post-condition: All nodes in the BST are removed.
    template <typename T>
    void bst_tree<T>::clear(node* root) {
        if (root != nullptr) {
            clear(root->left());
            clear(root->right());
            delete root;
        }
    }

    //Precondition: N/A
    //Post-condition: newDataItem is inserted into the BST in the correct position, including duplicates.
    //Note: This function is a dependent of the bst_insertAll function.
    template <typename T>
    void bst_tree<T>::insertAll(const T& newDataItem) {
        if (root_ptr == nullptr)
            root_ptr = new node(newDataItem);
        else bst_insertAll(newDataItem, root_ptr);
    }

    //Precondition: N/A
    //Post-condition: Only one copy of newDataItem is inserted into the BST in the correct position.
    //Note: This function is a dependent of the bst_insertAll function.
    template <typename T>
    void bst_tree<T>::insertOne( const T& newDataItem) {
        if ( root_ptr == nullptr )
            root_ptr = new node(newDataItem);
        else bst_insertOne(newDataItem, root_ptr);
    }

    //Precondition: root_ptr points to a binary tree with at least one node.
    //Post-condition: Tree is output to std::cout.
    template <typename T>
    void bst_tree<T>::printTree() const {
        if (root_ptr == nullptr) {
            std::cout << "Empty tree" << std::endl;
        }
        else {
            std::cout << std::endl;
            printTree(root_ptr, 0);
            std::cout << std::endl;
        }
    }

    //Precondition: Tree contains at least one node.
    //Post-condition: Tree is output to std::cout.
    //Note: This function is a dependancy of printTree().
    template <typename T>
    void bst_tree<T>::printTree(const node* node_ptr, size_t depth) const
// Library facilities used: iomanip, iostream, stdlib
    {
        //To output a binary tree in pretty ASCII we do INORDER
        //However, we go RIGHT first instead of LEFT
        if (node_ptr != nullptr) {
            printTree(node_ptr->right(), depth + 1);
            std::cout << std::setw(4*depth) << ""; // Indent 4*depth spaces.
            std::cout << node_ptr->data( ) << std::endl;
            printTree(node_ptr->left(), depth + 1);
        }
    }

    //Precondition: N/A
    //Post-condition: String stream is created containing the alphabetical order of all the nodes,
    // along with the frequency of each node, separated by a comma.
    // Ex. (a,2), (about,1), ... (world,1).
    template <typename T>
    std::string bst_tree<T>::toStringAlpha(bst_tree<T> &tree) const {
        std::ostringstream s;
        bool firstNumberOutputted = false;
        buildStringStreamAlpha(root_ptr, s, firstNumberOutputted, tree);
        return s.str();
    }

    //Precondition: N/A
    //Post-condition: String stream is created based on node frequency (lowest to highest), from 1 to the highest
    // node frequency that exists. Node frequency and node data are printed, separated by a comma, for every node in
    // the binary tree.
    // Ex. (1,world), (1, work), ... (i,6).
    template <typename T>
    std::string bst_tree<T>::toStringLH(bst_tree<T> &tree, int freq) const {
        std::ostringstream s;
        bool firstNumberOutputted = false;
        buildStringStreamLH(root_ptr, s, firstNumberOutputted, tree, freq);
        return s.str();
    }

    //Precondition: N/A
    //Post-condition: Sequentially, every node with each possible frequency is found and output to std::cout.
    //Note: This function is a dependancy of tostringLH(bst_tree<T> &, int) and
    // buildStringStreamLH(const node*, std::ostringstream&, bool&, bst_tree<T> &)
    template <typename T>
    void bst_tree<T>::printLH(bst_tree<T> &treeAll, bst_tree<T> &treeOne) const {
        for (int i = 1; i < 500; i++) {
            std::cout << treeOne.toStringLH(treeAll, i);
        }
    }

    //Precondition: root_ptr points to a binary tree with at least one node
    //Post-condition: Height of the tree is returned recursively, recall that a tree
    // with one node is height of 0 and an empty tree has a height of -1
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

    //Precondition: Binary tree has at least one node.
    //Post-condition: Inserts newDataItem into the binary search tree in the correct spot, including duplicates.
    template <typename T>
    void bst_tree<T>::bst_insertAll( const T &newDataItem, node *node_ptr) {
        if (newDataItem < node_ptr->data()) {
            if (node_ptr->left() == nullptr) {
                node_ptr->left() = new node(newDataItem);
            }
            else {
                this->bst_insertAll(newDataItem, node_ptr->left());
            }
        }
        else {
            if (node_ptr->right() == nullptr) {
                node_ptr->right() = new node(newDataItem);
            }
            else {
                this->bst_insertAll(newDataItem, node_ptr->right());
            }
        }
    }

    //Precondition: Binary tree has at least one node.
    //Post-condition: Inserts newDataItem into the binary search tree in the correct spot. Only one copy is inserted.
    // Duplicates are not allowed.
    template <typename T>
    void bst_tree<T>::bst_insertOne(const T &newDataItem, node *node_ptr) {
        if (newDataItem == node_ptr->data()) {
            return;
        }
        if (newDataItem < node_ptr->data()) {
            if (node_ptr->left() == nullptr) {
                node_ptr->left() = new node(newDataItem);
            }
            else {
                this->bst_insertOne(newDataItem, node_ptr->left());
            }
        }
        else {
            if (node_ptr->right() == nullptr) {
                node_ptr->right() = new node(newDataItem);
            }
            else {
                this->bst_insertOne(newDataItem, node_ptr->right());
            }
        }
    }

    //Precondition: root_ptr is a root pointer of a binary search tree.
    //Post-condition: Returns true if target is in the BST, false otherwise.
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

    //Precondition: node pointer is a root pointer of a binary search tree,
    //  ostringstream is a output stream, most likely empty,
    //  but this is not required.
    //  the bool value is set to false
    //Post-condition: Build a list of strings in the BST in order as a ostringsteam.
    //  After adding the first value, change the bool to true.
    //  Comma and spaces are added between each value in the list
    //  Note: This function is a dependancy of toStringAlpha()
    template <typename T>
    void bst_tree<T>::buildStringStreamAlpha(const node *p, std::ostringstream &s, bool &firstOutputted, bst_tree<T> &tree) const {
        if (p != nullptr) {
            firstOutputted = true;
            if (p->left()) {
                buildStringStreamAlpha(p->left(), s, firstOutputted, tree);
                s << ", "; // print ", " everytime after you descended to the left
            }
            s << "(" << p->data() << "," << tree.wordFreq(p->data()) << ")";
            if (p->right()) {
                s << ", "; // print ", " everytime before you descend to the right
                buildStringStreamAlpha(p->right(), s, firstOutputted, tree);
            }
        }
    }

    //Precondition: node pointer is a root pointer of a binary search tree,
    //  ostringstream is a output stream, most likely empty,
    //    but this is not required.
    //  the bool value is set to false
    //Post-condition: Build a list of strings in the BST in order as a ostringsteam.
    //  After adding the first value, change the bool to true.
    //  Comma and spaces are added between each value in the list
    //  Note: This function is a dependancy of toStringLH()
    template <typename T>
    void bst_tree<T>::buildStringStreamLH(const node *p, std::ostringstream &s, bool& firstOutputted, bst_tree<T> &tree, int freq) const {
        if (p != nullptr) {
            firstOutputted = true;
            if (p->left()) {
                buildStringStreamLH(p->left(), s, firstOutputted, tree, freq);
            }
            if (tree.wordFreq(p->data()) == freq) {
                s << "(" << tree.wordFreq(p->data()) << "," << p->data() << "), ";
            }
            if (p->right()) {
                buildStringStreamLH(p->right(), s, firstOutputted, tree, freq);
            }
            }
        }

} //End Namespace DS