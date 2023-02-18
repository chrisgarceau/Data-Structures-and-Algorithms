//============================================================================
// Name        : labdriver.cpp
// Author      : S. Miller
//============================================================================

#include <cassert>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "darray.h"

using namespace DS;

//Precondition: src is a character array of size integers, dest is a darray object
//Postcondition: All integers in the character array are added to array one item at a time, the resulting array
//	is in numeric order (increasing order).
void createDynamicIntegerArray(const char* src[], size_t size, darray& dest);

int main(int argc, const char* argv[]) {

    darray mydarray;
    size_t arraySize = argc - 1;
    srand(static_cast<unsigned int>(time(0)));

    if ( argc == 1 ) {
        std::cerr << "At least one command line argument expected, see previous lab for instructions on how to add them in your IDE." << std::endl;
        return 1;
    }

    createDynamicIntegerArray(&argv[1], arraySize, mydarray);
    //Confirm size is correct
    assert(mydarray.size() == arraySize);

    std::cout << mydarray << std::endl;

    std::cout << "Removed "
              << mydarray.remove(std::rand() % mydarray.size())
              << std::endl;
    //Confirm size is correct
    assert(mydarray.size() == arraySize - 1);

    std::cout << mydarray << std::endl;

    //I recommend adding tests here to test copy constructor and assignment operator!!
    std::cout << mydarray << std::endl;
    mydarray.removeMore(45);
    return 0;
}

void createDynamicIntegerArray(const char* src[], size_t size, darray &dest) {
    for ( size_t i = 0 ; i < size ; ++i ) {
        dest.insert(std::atoi(src[i]));
    }
}

std::ostream& operator<<(std::ostream& out, const darray& b) {
    out << "[";
    if ( b.size() > 0 ) {
        out << b[0];
        for ( size_t i = 1 ; i < b.size() ; ++i ) {
            out << ", " << b[i];
        }
    }
    out << "]";
    return out;
}