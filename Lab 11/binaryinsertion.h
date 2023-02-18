/*
 * binaryinsertion.h
 *
 *  Created on: Nov 28, 2015
 *      Author: S Miller
 */

#ifndef BINARYINSERTION_H_
#define BINARYINSERTION_H_

#include <algorithm>
#include "arraypprint.h"

//Binary Insertion
template <typename T, typename S>
size_t binarySearch(T data[], T item, S low, S high)
{
	arraypprints(data+low,high-low+1,"bs s"," target="+numtostr(item));

    if (high <= low)
        return (item > data[low]) ? (low + 1): low;

    S mid = (low + high)/2;

    if(item <= data[mid])
        return mid+1;

    if(item > data[mid])
        return binarySearch(data, item, mid+1, high);
    return binarySearch(data, item, low, mid-1);
}

// Function to sort an array a[] of size 'n'
template <typename T, typename S>
void binaryInsertionSort(T data[], S n)
{
	T selected;
    S i=0, loc, j;

    array2pprints(data,i+1,data+i+1,n-i-1);

    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = data[i];

        // find location where selected should be inserted
        loc = binarySearch(data, selected, static_cast<S>(0), j);
        array2pprints(data,i+1,data+i+1,n-i-1,"bis loc"," loc="+numtostr(loc));

        // Move all elements after location to create space
        if ( j >= loc ) {
#ifdef _MSC_VER
        		//copy_backward causes issues in Visual Studio, not sure if this is still needed in current versions
        		for(j = i ; j > loc ; --j ) {
        	        data[j] = data[j-1];
        		}
#else
        		std::copy_backward(data + loc,data + i,data+i+1);
#endif

        }
        data[loc] = selected;

        array2pprints(data,i+1,data+i+1,n-i-1);
    }
}


#endif /* BINARYINSERTION_H_ */
