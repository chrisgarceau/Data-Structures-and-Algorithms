// FILE: merge.cxx
// An interactive test program for the mergesort function

#include <cstdlib>    // Provides EXIT_SUCCESS, size_t
#include "arraypprint.h"

// PROTOTYPES of the functions used in this test program:
template <typename T, typename S>
void mergesort(T data[ ], S n);
// Precondition: data is an array with at least n components.
// Postcondition: The elements of data have been rearranged so
// that data[0] <= data[1] <= ... <= data[n-1].
// NOTE: If there is insufficient dynamic memory, then new_handler is called.

template <typename T, typename S>
void merge(T data[ ], S n1, S n2);
// Precondition: data is an array (or subarray) with at least n1+n2 elements. 
// The first n1 elements (from data[0] to data[n1-1]) are sorted from smallest 
// to largest, and the last n2 (from data[n1] to data[n1+n2-1]) are also 
// sorted from smallest to largest.
// Postcondition: The first n1+n2 elements of data have been
// rearranged to be sorted from smallest to largest.
// NOTE: If there is insufficient dynamic memory, then new_handler is called.

template <typename T, typename S>
void mergesort(T data[ ], S n)
// Precondition: data is an array with at least n components.
// Postcondition: The elements of data have been rearranged so
// that data[0] <= data[1] <= ... <= data[n-1].
// NOTE: If there is insufficient dynamic memory, then bad_alloc is thrown.
// Library facilities used: cstdlib
{
    S n1; // Size of the first subarray
    S n2; // Size of the second subarray

    arraypprints(data,n,"ms begin");

    if (n > 1)
    {
        // Compute sizes of the subarrays.
        n1 = n / 2;
        n2 = n - n1;

        mergesort(data, n1);         // Sort from data[0] through data[n1-1]
        mergesort((data + n1), n2);  // Sort from data[n1] to the end


        // Merge the two sorted halves.
        merge(data, n1, n2);
    }
}

template <typename T, typename S>
void merge(T data[ ], S n1, S n2)
// Precondition: data is an array (or subarray) with at least n1 + n2 elements.
// The first n1 elements (from data[0] to data[n1 - 1]) are sorted from
// smallest to largest, and the last n2 (from data[n1] to data[n1 + n2 - 1])
// also are sorted from smallest to largest.
// Postcondition: The first n1 + n2 elements of data have been rearranged to be
// sorted from smallest to largest.
// NOTE: If there is insufficient dynamic memory, then bad_alloc is thrown.
// Library facilities used: cstdlib
{
    T *temp;          // Points to dynamic array to hold the sorted elements
    S copied  = 0; // Number of elements copied from data to temp
    S copied1 = 0; // Number copied from the first half of data
    S copied2 = 0; // Number copied from the second half of data
    S i;           // Array index to copy from temp back into data

    // Allocate memory for the temporary dynamic array.
    temp = new T[n1+n2];

    array2pprints(data,n1, data+n1, n2,"merge s");

    // Merge elements, copying from two halves of data to the temporary array.
    while ((copied1 < n1) && (copied2 < n2))
    {
        if (data[copied1] < (data + n1)[copied2])
            temp[copied++] = data[copied1++];        // Copy from first half
        else
            temp[copied++] = (data + n1)[copied2++]; // Copy from second half
    }

    // Copy any remaining entries in the left and right subarrays.
    while (copied1 < n1)
        temp[copied++] = data[copied1++];
    while (copied2 < n2)
        temp[copied++] = (data+n1)[copied2++];

    // Copy from temp back to the data array, and release temp's memory.
    for (i = 0; i < n1+n2; i++)
        data[i] = temp[i];
    delete [ ] temp; 

    array2pprints(data,n1, data+n1, n2,"merge e");
}


