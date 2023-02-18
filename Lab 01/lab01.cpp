//Name: Christopher Garceau
//Date: Sept. 26, 2020
//Assignment: Lab 01
//File: lab01.cpp
//Attempt: 2

#include <cassert>  //For assert
#include <cstdlib>  //For rand
#include "bag1.h"
#include "baglab.h"

namespace DS {

    bag::value_type bag::grab_random()
    {
        //Remove a random item in the bag
        assert(size() > 0);
        value_type position = rand() % used; //Randomly selects a position within the array
        value_type numGrabbed = data[position]; //Variable stores value grabbed
        erase_one(numGrabbed);  //Value grabbed is removed
        return numGrabbed;  //Returns value removed
    }

    size_t emptyBag(DS::bag& nums, const DS::stats& bagStats) {
        //Implement assuming grab_random does NOT exist
        //Use stats struct to know the max and min
        //Use cstdlib's rand for random function
       assert(nums.size() > 0);
        size_t size = nums.size();
        size_t counter = 0;

        while (size > 0) {
            if (nums.count(rand() % bagStats.max + bagStats.min) > 0) {
                nums.erase(rand() % bagStats.max + bagStats.min);
                counter++;
                --size;
            }
            else {
                counter++;
            }
        }
        return counter;
    }

    size_t emptyBag(DS::bag& nums) {
        //Implement assuming member grab_random exist
        //Random number in the container is erased each loop
        assert(nums.size() > 0);
        size_t counter = 0;

        while (nums.size() > 0) {
            nums.erase(nums.grab_random());
            counter++;
        }

        return counter;
    }

} //End of DS namespace
