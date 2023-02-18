// Program Name: Project 2
// Programmer Name: YOUR NAME HERE
// Attempt Number: Your first Blackboard attempt is "1" for each assignment
// Purpose: Tests every permutation of every function of statistician class (left to student to do)
// Purpose for Update: n/a

#include <iostream>
#include "stats.h"

//Allow the access of all items in the DS namespace as if it was in global namespace
using namespace DS;
using namespace std;

int main() {

    //create empty object
    statistician s;
    cout << s << endl;
    statistician x;
    cout << x << endl;
    //Add the first value
    s.add(600);
    s.add(470);
    s.add(170);
    s.add(430);
    s.add(300);
    //Add two more values
    cout << s << endl;
    cout << "Copy Constructor" << endl;
    statistician y = s;
    cout << "Y: " << y << endl;
    cout << endl;
    cout << "Assignment Operator" << endl;
    statistician b;
    b = y;
    cout << b << endl;
    x = b;
    cout << "X: " << x << endl;
    cout << endl;

    //Should output 3
    std::cout << s.length() << std::endl;
    cout << endl;
//    //The other values this object should have is sum of 5, mean of 1.66666, min of -10, and max of 10
//    //The following will not work until most accessors exist
//    //Once you do that, this will be a simple way to output all the data of each object
    std::cout << "Object s: " << endl;
    cout << s << endl;
    cout << "Mean: " << s.mean() << endl;
    cout << "Median: " << s.median() << endl;
    cout << "Stand. Dev.: " << s.standardDeviation() << endl;
    s.remove(600);
    cout << "Removed number." << endl;
    cout << s << endl;
    s.add(650);
    cout << s << endl;
    cout << "== operator" << endl;
    cout << boolalpha << (y == x) << endl;
    cout << "!= operator" << endl;
    cout << boolalpha << (y != x) << endl;
    cout << "Non-member *operator" << endl;
    cout << -5 * y << endl;

    cout << "Member *= operator" << endl;
    y.operator*=(-5);
    cout << y << endl;

    cout << "Reset" << endl;
    y.reset();
    cout << y << endl;
    y.add(30);
    y.add(87);
    y.add(90);
    y.add(56);
    cout << y << endl;
    cout << "Mean: " << y.mean() << endl;
    y.remove(30);
    cout << y << endl;



    return EXIT_SUCCESS;
}