#include <string>
#include <list>
#include "myrecursion.h"

/*
Write a recursive method that takes a string as a parameter.
It returns a string composed of itself, and a mirror image of itself(reversed), separated by a hyphen.
Complete this function without the aid of a helper function and without the usage of the
string classes reverse method.
*/
std::string mirrorString(std::string s) {
    if (s.empty()) {  //IF STRING IS EMPTY RETURN THE EMPTY STRING
        return s;
    }
    else {
        //LOCAL VARIABLE M STORES THE STRING PARAMETER FORWARDS AND BACKWARDS WITH A - SEPARATING THEM.
        std::string m = s.at(0) + mirrorString(s.substr(1)) + s.at(0);
        if (m.length() == 2) {
            m.at(1) = '-';
            m += s.at(0);
        }
        return m;
    }
}

/*
Write a recursive function to RETURN the nth term from the following SERIES
{ 0, 0.5, 1.5, 3, 5, 7.5 }
That is, the 0th term is 0, the 1st term is 0.5.
HINT: Only the 0th term is required to handle the base case.  The difference between each term depends on the previous
RULE EXCEPTION: You may use multiplication operator on the recursive step for this one
*/
double myseries( unsigned long n  ) {
    if (n <= 0) {
        return 0;
    }
    else {
        return (n * 0.5) + myseries(n - 1);
    }
}

/*
Given a non-negative long n, return the count of the occurrences of 7 as a digit, so for example 717 yields 2. (no loops).
Note that mod (%) by 10 yields the rightmost digit (126 % 10 is 6), while divide (/) by 10 removes the rightmost digit (126 / 10 is 12).
count7(717) = 2
count7(7) = 1
count7(123) = 0
*/
unsigned long count7( unsigned long n ) {
    if (n == 0) {
        return 0;
    }
    int digit =  n % 10;
    if (digit == 7) {
        return 1 + count7(n / 10);
    }
    return count7(n / 10);
}

/*
Given an array of ints, is it possible to divide the ints into two groups, so
that the sum of the two groups is the same, with these constraints: all the
values that are multiple of 13 must be in one group, and all the values that
are a multiple of 3 (and not a multiple of 13) must be in the other. (No loops
needed.)
*/
bool split13_3(const long nums[], const size_t count) {
    return split13_3_helper(nums, count, 0, 0, 0);
}
//split13_3 helper function implementation
bool split13_3_helper(const long nums[], const size_t count, int begin, int leftSum, int rightSum) {
    if (begin == count) {
        return leftSum == rightSum;
    }
    if (nums[begin] % 13 == 0) {
        rightSum += nums[begin];
    }
    else if (nums[begin] % 3 == 0) {
        rightSum += nums[begin];
    }
    else {
        return split13_3_helper(nums, count, begin + 1, leftSum + nums[begin], rightSum) ||
        split13_3_helper(nums, count, begin + 1, leftSum, rightSum + nums[begin]);
    }
    return split13_3_helper(nums, count, begin + 1, leftSum, rightSum);
}

/*
Write a recursive method that takes as parameters a String s and an integer i and returns a String that has s repeated i times.
For example, if the given string is "Go bears! " and the integer is 3 then the return value would be "Go bears! Go bears! Go bears! ".
(Note that if the integer is 0, then the empty string "" should be returned.)
*/
std::string repeat(std::string s, unsigned int i) {
    if (s.empty()) {
        return "";
    }
    if (i == 1) {
        return s;
    }

    return s + repeat(s, i - 1);
}

/*
Write and test a method mult with the following specification without using the multiplication operator.
Write a recursive method that performs the multiplication by repeated addition. Make your method work for both positive and
negative integers, as well as zero.
Start by calling a separate helper method that assumes both parameters are non-negative. Then, in the calling method,
make an adjustment afterwards for the case when the signs of the two original numbers were different.
PARAMETERS:   integers j and k
RETURN VALUE: the product j*k
*/
long mult(long j, long k) {
    //IF EITHER J OR K EQUAL ZERO, RETURN 0.
    if( j == 0 || k == 0) {
        return 0;
    }
    //IF EITHER J OR K EQUAL 1, RETURN THE NUMBER THAT IS NOT 1.
    if (k == 1 || j == 1) {
        if (k == 1) {
            return j;
        }
        else {
            return k;
        }
    }
    //IF J AND K ARE POSITIVE
    else if (j > 1 && k > 1){
        return j + mult(j, k - 1);
    }
    //IF J IS NEGATIVE AND K IS POSITIVE
    else if (j < 1 && k > 1) {
        return -1 * (j * -1 + mult(j * -1, k - 1));
    }
    //IF J IS POSITIVE AND K IS NEGATIVE
    else if (j > 1 && k < 1) {
        return -1 * (j + mult(j, (k * -1) - 1));
    }
    //IF BOTH J AND K ARE NEGATIVE
    else if (j < 1 && k < 1) {
        return -1 * j + mult(j * -1, (k * -1) - 1);
    }
}

//Precondition: n is the length of the string, i is the start index, typically 0 when called by user, the
//  passed string list is empty. Assume no letters are duplicated in the source string or that an external process will remove duplicate permutations.
//Postcondition: A list of all possible string permutations is added to the passed list, no console output. The order of the strings does not matter.
//  is generated by this function
void string_permutations(std::string str, size_t n, std::list<std::string>& list_of_permutations, size_t i) {
    if (n - 1 > 0) {
        n--;
        std::swap(str.at(i), str.at(i + 1));
        list_of_permutations.push_back(str);
        std::swap(str.at(i), str.at(i));

        std::swap(str.at(i), str.at(str.length() - 1));
        list_of_permutations.push_back(str);
        std::swap(str.at(i), str.at(str.length() - 1));

        std::swap(str.at(i + 1), str.at(str.length() - 1));
        list_of_permutations.push_back(str);
        std::swap(str.at(i + 1), str.at(str.length() - 1));

        string_permutations(str, n, list_of_permutations, i);
    }
}

