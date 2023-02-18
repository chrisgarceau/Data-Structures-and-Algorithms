//============================================================================
// Name        : sort_driver.cpp
// Author      :  S.Miller
//============================================================================

//Uncomment only one of the following
//To show lots of debug information enable the 2nd one
//Warning, make sure the array size is small if you want the debugging output to make sense
#define HIDEOUTPUT 0 //NO OUTPUT
//#define HIDEOUTPUT 1 //YES OUTOUT

//#define STATIC_ARRAY 1 //1 if static array
#define STATIC_ARRAY 0 //0 if dynamic array

#include <iostream>
#include <random>
#include "sort_helpers.h"

int main() {
    //To allow BIG random numbers
    std::random_device rd;     //Get a random seed from the OS entropy device, or whatever
    std::mt19937_64 eng(rd()); //Use the 64-bit Mersenne Twister 19937 generator and seed it with entropy.

    //The following lines are to test best case, average case, and worst case
    //* LAB ************************
    //How many items should the array contain?
    size_t itemCount = 10000;
    //* LAB ***********************

#if STATIC_ARRAY
	//Only uncomment the following few lines if you want to generate test cases used in class
	//int items[] = {22,40,30,20,11,21,31,41}; //ideal for quicksort example
	//int items[] = {70,31,42,13,54,25,86,47}; //ideal for most
	//int items[] = {62,83,18,53,07,17,95,86,47,69,25,28};
    //int items[] = {62,83,18,53,07,17,95,86,47,69,25,28};
    itemCount = sizeof(items)/sizeof(items[0]);
#else
    auto *items = new long long[itemCount];

    // *  [LAB]  **************************************
    // ** Uncomment only one of the following at a time **
    // *  [LAB]  **************************************
//    populateBestArray(items, itemCount);
//    populateAvgArray(items, itemCount, eng);
    populateWorstArray(items, itemCount);
    //*  [LAB]  **************************************
#endif

    //LAB
	//Uncomment only one sort method at a time, otherwise second sort will always be best case
//	sortVia(items, itemCount, BUBBLESORT);
//	sortVia(items, itemCount, SELECTIONSORT);
//	sortVia(items, itemCount, INSERTIONSORT);
//	sortVia(items, itemCount, SHELLSORT);
//	sortVia(items, itemCount, BINARYINSERTIONSORT);
//	sortVia(items, itemCount, HEAPSORT);
//	sortVia(items, itemCount, MERGESORT);
	sortVia(items, itemCount, QUICKSORT);
//    sortVia(items, itemCount, RADIXSORT);
    //LAB

#if !STATIC_ARRAY
	delete [] items;
#endif
    std::cout << "\ndone\n" << std::endl;
	return 0;
}

