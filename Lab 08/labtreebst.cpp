#include <iostream>
#include "bst_tree.h"
using namespace std;
using namespace DS;

int main() {

    bst_tree<int> bst;

    bst.insert(5);
    bst.insert(15);
    bst.insert(25);
    bst.insert(22);
    bst.insert(-29);
    bst.insert(29);
    bst.insert(2);
    bst.insert(19);
    bst.insert(30);
    bst.insert(40);
    bst.insert(4);
    bst.insert(-34);


    bst.printTree();

    cout << "Height:" << bst.height() << endl;
    cout << "Inorder:" << bst.toString() << endl;

    cout << (bst.in_bst(15) ? "Yes" : "No") << endl;
    cout << (bst.in_bst(30) ? "Yes" : "No") << endl;

    bst.printTree();
    cout << "==================" << endl;
    bst.bst_remove(25);
    bst.printTree();
    cout << "==================" << endl;
    bst.bst_remove(29);
    bst.printTree();
    cout << "==================" << endl;
    bst.bst_remove(5);
    bst.printTree();
    cout << "==================" << endl;

    return 0;
}