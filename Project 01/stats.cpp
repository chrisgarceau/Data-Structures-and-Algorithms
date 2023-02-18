// Program Name: Project 1
// Programmer Name: Christopher Garceau
// Attempt Number: 2
// Purpose: Statistician class implementation to keep statistics on a collection of doubles
// Purpose for Update: n/a

#include "stats.h"

// INVARIANT DECLARATION
//  The class will maintain the count, smallest, and largest fields on all mutator functions
//  so that later calls on other functions will always be valid. If at any time the state of the
//  object is invalid, the program will output either "Invalid" or return the value of ERROR_FLAG.
//  When a variable is removed, if it is either the smallest value or the largest value of the sequence,
//  the object becomes invalid. Also, the object becomes invalid when the length is 0.
//  Once an object is invalid, only a reset will fix it.


//Start of namespace
namespace DS {

    //DEFAULT CONSTRUCTOR: INITIALIZES PRIVATE CLASS VARIABLES TO ZER0.
    statistician::statistician() {
        seqCount = 0;
        seqSum = 0;
    }

    //VALUE CONSTRUCTOR
    statistician::statistician(size_t length, double sum, double smallest, double largest) {
        seqCount = length;
        seqSum = sum;
        seqSmallest = smallest;
        seqLargest = largest;
    }

    //ADDS VARIABLES TO THE OBJECT
    void statistician::add(double r) {
        if (r < seqSmallest) {
            seqSmallest = r;
        }
        if (r > seqLargest) {
            seqLargest = r;
        }
        if (seqCount == 0) {
            seqCount = 1;
            seqSum = r;
            seqSmallest = r;
            seqLargest = r;
            return;
        }
        seqCount = seqCount + 1;
        seqSum += r;
    }

    //REMOVES NUMBER FROM THE OBJECT
    void statistician::remove(double r) {
        if (length() == 0) {
            return;
        }

        seqCount--;
        seqSum = seqSum - r;

        if (r == seqLargest) {
            seqLargest = ERROR_FLAG;
            is_valid();
            reset();
        }
        if (r == seqSmallest) {
            seqSmallest = ERROR_FLAG;
            is_valid();
            reset();
        }
        if (length() == 0) {
            r = ERROR_FLAG;
            is_valid();
            reset();
        }
    }

    //RESETS OBJECT MEMBER VARIABLES TO 0
    void statistician::reset() {
        seqCount = 0;
        seqSum = 0;
    }

    //RETURNS THE LENGTH OF THE SEQUENCE
    size_t statistician::length() const {
        return seqCount;
    }

    //RETURNS THE SUM OF THE OBJECT, IF VALID
    double statistician::sum() const {
        if (is_valid()) {
            return seqSum;
        }
        else {
            return ERROR_FLAG;
        }
    }

    //RETURNS THE MEAN OF THE OBJECT, IF VALID
    double statistician::mean() const {
        if (!is_valid()) {
            return ERROR_FLAG;
        }
        double avg = seqSum / seqCount;
        return avg;
    }

    //RETURNS THE MINIMUM VALUE OF THE OBJECT, IF VALID
    double statistician::minimum() const {
        if (!is_valid()) {
            return ERROR_FLAG;
        }
        if (seqSmallest < seqLargest) {
            return seqSmallest;
        }
        else {
            return seqLargest;
        }
    }

    //RETURNS THE MAXIMUM VALUE OF THE OBJECT, IF VALID
    double statistician::maximum() const {
        if (!is_valid()) {
            return ERROR_FLAG;
        }
        if (seqSmallest > seqLargest) {
            return seqSmallest;
        }
        else {
            return seqLargest;
        }
    }

    //CHECKS IF THE OBJECT IS VALID
    bool statistician::is_valid() const {
        if (seqLargest == ERROR_FLAG || seqSmallest == ERROR_FLAG || seqCount == 0) {
            return false;
        }
        else {
            return true;
        }
    }

    //CHECKS IF TWO OBJECTS ARE EQUAL TO EACH OTHER
    bool operator==(const statistician &s1, const statistician &s2) {
        if ((s1.length() == s2.length()) && (s1.mean() == s2.mean()) &&
            (s1.sum() == s2.sum()) && (s1.maximum() == s2.maximum()) &&
            (s1.minimum() == s2.minimum())) {
            return true;
        }
        else {
            return false;
        }
    }

    //ADDS TWO OBJECTS TOGETHER
    statistician operator+(const statistician &s1, const statistician &s2) {
        size_t totalLength = s1.length() + s2.length();
        double totalSum = s1.sum() + s2.sum();
        double min = 0;
        double max = 0;

        if (s1.minimum() > s2.minimum()) {
            min = s2.minimum();
        }
        else {
            min = s1.minimum();
        }

        if (s1.maximum() > s2.maximum()) {
            max = s1.maximum();
        }
        else {
            max = s2.maximum();
        }
        statistician Output(totalLength, totalSum, min, max);
        return Output;
    }

    //MULTIPLIES THE OBJECT BY THE SCALE PARAMETER
    statistician operator*(double scale, const statistician &s) {
        size_t length = s.length();
        double sum = scale * s.sum();
        double min = scale * s.minimum();
        double max = scale * s.maximum();

        statistician Output(length, sum, min, max);
        return Output;
    }

} // End of namespace
