// FILE: quicksort.h

#include <algorithm>  // Provides swap
#include <cstdlib>    // Provides EXIT_SUCCESS, size_t
#include "arraypprint.h"

template <typename T, typename S>
void partition(T data[ ], S n, S& pivot_index);
// Precondition: n > 1, and data is an array (or subarray)
// with at least n elements.
// Postcondition: The function has selected some "pivot value"
// that occurs in data[0]..data[n-1]. The elements of data
// have then been rearranged, and the pivot index set so that:
//   -- data[pivot_index] is equal to the pivot;
//   -- Each item before data[pivot_index] is <= the pivot;
//   -- Each item after data[pivot_index] is >= the pivot.


//void quicksort(Item data[ ], size_t n);
// Precondition: data is an array with at least n components.
// Postcondition: The elements of data have been rearranged so
// that data[0] <= data[1] <= ... <= data[n-1].
template <typename T, typename S>
void quicksort(T data[ ], S n)
// Library facilities used: cstdlib
{
    S pivot_index; // Array index for the pivot element
    S n1;          // Number of elements before the pivot element
    S n2;          // Number of elements after the pivot element

    arraypprints(data,n,"qs start");

    if (n > 1)
    {
        // Partition the array, and set the pivot index.
        partition(data, n, pivot_index);

        // Compute the sizes of the subarrays.
        n1 = pivot_index;
        n2 = n - n1 - 1;

        arraypprints(data,n,"qq","pivot_index="+numtostr(pivot_index) + ", pivot="+numtostr(data[pivot_index]));
        array2pprints(data,n1,(data + pivot_index + 1), n2,"Q pi="+numtostr(n1));

        // Recursive calls will now sort the subarrays.
        quicksort(data, n1);
        quicksort((data + pivot_index + 1), n2);
    }
    arraypprints(data,n,"qs end");
}

template <typename T, typename S>
void partition(T data[ ], S n, S& pivot_index)
// Library facilities used: stdlib.h
//
// NOTES FROM THE IMPLEMENTOR:
// How the partition works on small arrays:
//
// Notice that n=0 is not permitted by the precondition.
//
// If n=1, then too_big_index is initialized as 1, and too_small_index is
// initialized as 0. Therefore, the body of the loop is never executed,
// and after the loop pivot_index is set to zero.
//
// If n=2, then both too_big_index and too_small_index are initialized as 1.
// The loop is entered, and there are two cases to consider:
// -- if data[1] <= pivot, then too_big_index increases to 2, and
//    too_small_index stays at 1. The if-statement at the bottom of the loop
//    is then skipped, and after the loop we copy data[1] down to data[0],
//    and copy the pivot into data[0]. Thus, the smaller element is in
//    data[0], and the larger element (the pivot) is in data[1].
// -- if data[1] > pivot, then too_big_index stays at 1, and too_small_index
//    decreases to 0. The if-statement at the bottom of the loop is then
//    skipped, and after the loop we end up copying the pivot onto data[0]
//    (leaving data[1] alone). Thus, the smaller element (the pivot) remains
//    at data[0], leaving the larger element at data[1].
{

    T pivot = data[0];
    S too_big_index = 1;     // Index of first item after pivot
    S too_small_index = n-1; // Index of last item

    arraypprints(data,n,"P Begin","tsi=" + numtostr(too_small_index)+", tbi=" + numtostr(too_big_index) + ", pivot=" + numtostr(pivot));

    // Partition the array, using pivot as the pivot element
    while (too_big_index <= too_small_index)
    {
        while ((too_big_index < n) && (data[too_big_index] <= pivot))
            too_big_index++;
        while (data[too_small_index] > pivot)
            too_small_index--;
        if (too_big_index < too_small_index)
        	std::swap(data[too_small_index], data[too_big_index]);

        arraypprints(data,n,"P Loop","tsi=" + numtostr(too_small_index)+", tbi=" + numtostr(too_big_index) + " while (tbi <= tsi)");


    }

    // Move the pivot element to its correct position
    pivot_index = too_small_index;
    data[0] = data[pivot_index];
    data[pivot_index] = pivot;
    arraypprints(data,n,"P End","tsi=" + numtostr(too_small_index)+", tbi=" + numtostr(too_big_index) + ", pivot=" + numtostr(pivot));
}
