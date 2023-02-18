#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

#define MINRAND 10
#define MAXRAND 99
#define INITIALHEAP 15
#include "treeHeap.h"

using namespace std;
using namespace DS;

int main() {

    treeHeap<int> th;
    srand(time(NULL));

    for ( int i=0 ; i < INITIALHEAP ; ++i )
        th.push( rand() % (MAXRAND-MINRAND+1) + MINRAND );

    cout << "BEFORE" << endl;
    th.printTree();

    cout << "After pop #1" << endl;
    th.pop();
    th.printTree();

    cout << "After pop #2" << endl;
    th.pop();
    th.printTree();

    cout << "After pop #3" << endl;
    th.pop();
    th.printTree();

    cout << "done" << endl;
    return 0;
}