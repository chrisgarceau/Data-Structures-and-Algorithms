// Program Name: Project 1
// Programmer Name: YOUR NAME HERE
// Attempt Number: Your first Blackboard attempt is "1" for each assignment
// Purpose: Tests every permutation of every function of statistician class (left to student to do)
// Purpose for Update: n/a

#include <iostream>
#include "stats.h"

using namespace std;

//Allow the access of all items in the DS namespace as if it was in global namespace
using namespace DS;

int main() {

    //create empty object
    statistician s;
    statistician x;
    statistician u;

    //Add the first value

cout << s << endl;
x.add(1);
x.add(5);
x.add(3);
cout << x << endl;
u = x + s;
cout << u << endl;

    //The other values this object should have is sum of 5, mean of 1.66666, min of -10, and max of 10

    //The following will not work until most accessors exist
    //Once you do that, this will be a simple way to output all the data of each object
    //std::cout << s << std::endl;

    return EXIT_SUCCESS;
}
