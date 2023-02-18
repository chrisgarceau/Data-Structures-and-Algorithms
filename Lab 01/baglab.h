/*
Programmer Name: Professor Miller
File Purpose: Stats struct and some global convenience functions
Date Updated: Jan 27th, 2019
Purpose for Update: Lab
Global Variable List: n/a (avoid these)
*/

#ifndef BAGLAB_H_
#define BAGLAB_H_

#include <cstdlib>
#include "bag1.h"

namespace DS
{

//Recall that a struct is very similar to a C++ class, however, ALL member items are public
//This simple struct will keep
    struct stats {
        int min;
        int max;
    };

//Precondition: nums is a bag of integers with 0 or more items.
//	bagStats correctly holds the minimum and maximum values in the bag
//  The bag class does NOT have the member function grab_random available.
//Postcondition: All items in the bag is removed. The number of times the loop iterated is returned.
    size_t emptyBag(bag& nums, const stats& bagStats);
//IMPLEMENTED BY STUDENT

//Precondition: nums is a bag of integers with 0 or more items.
//  The bag class HAS the member function grab_random available.
//Postcondition: All items in the bag is removed. The number of times the loop iterated is returned.
    size_t emptyBag(bag& nums);
//IMPLEMENTED BY STUDENT

//Precondition: Values is an array of integers stored as character C strings,
//	size is equal to the number of items in the values array
//Postcondition: All items in values is inserted into the bag b.
//	Stats are returned with the smallest integer inside the array set to min and largest value set to max;
    stats cStrArray2Bag(bag& b, const char* values[], size_t size);




} //End DS namespace



#endif /* BAGLAB_H_ */