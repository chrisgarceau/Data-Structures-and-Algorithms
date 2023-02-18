/*
 * radix.h
 *
 *  Created on: Nov 25, 2019
 *  Updated: Apr 30, 2020
 *      Author: S Miller
 */


#ifndef SORTING_RADIX_H
#define SORTING_RADIX_H

#include <algorithm>
#include <list>
#include <cmath>
#include <vector>

template <typename T, typename S>
void radix_sort(T arr[], S n, S base=10) {
    T i, j, m, p = 1, index, temp, count = 0;

    std::vector<std::list<T>> pocket(base);      //radix of decimal number is 10

    // Find the maximum number to know number of digits
    const S digits = floor(log(*std::max_element(arr, arr + n))/log(base)+1);

    for(i = 0; i < digits; ++i) {
        m = pow(10, i+1);
        p = pow(10, i);
        for(j = 0; j<n; j++) {
            temp = arr[j]%m;
            index = temp/p;      //find index for pocket array
            pocket[index].push_back(arr[j]);
        }
        count = 0;
        for(j = 0; j<10; j++) {
            //delete from linked lists and store to array
            while(!pocket[j].empty()) {
                arr[count] = *(pocket[j].begin());
                pocket[j].erase(pocket[j].begin());
                count++;
            }
        }
    }
}

#endif //SORTING_RADIX_H
