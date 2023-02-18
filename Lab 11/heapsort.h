// FILE: heapsort.cxx
// An interactive test program for the selectionsort function

#include <algorithm>   // Provides swap
#include <cstdlib>     // Provides EXIT_SUCCESS, size_t

#include "arraypprint.h"

// PROTOTYPES of the functions used in this test program:
template <typename T, typename S>
void heapsort(T data[ ], S n);
// Precondition: data is an array with at least n components.
// Postcondition: The elements of data have been rearranged so
// that data[0] <= data[1] <= ... <= data[n-1].

template <typename S>
S parent(S k);
// Precondition: k> 0.
// Postcondition: The function assumes that k is the index of an array element, where the array
// represents a complete binary tree. The return value is the index of the parent of node k, using
// the formula from rule 3 on page 624.

template <typename S>
S left_child(S k);
// Postcondition: The function assumes that k is the index of an array element, where the array
// represents a complete binary tree. The return value is the index of the left child of node k,
// using the formula from rule 2 on page 624.

template <typename S>
S right_child(S k);
// Postcondition: The function assumes that k is the index of an array element, where the array
// represents a complete binary tree. The return value is the index of the right child of node k,
// using the formula from rule 2 on page 624.

template <typename T, typename S>
void make_heap(T data[ ], S n);
// Precondition: data is an array with at least n elements.
// Postcondition: The elements of data have been rearranged so that the
// complete binary tree represented by this array is a heap.

template <typename T, typename S>
void reheapify_down(T data[ ], S n, S i = 0);
// Precondition: n > 0, and data is an array with at least n elements. These elements form a
// heap **except** that data[0] may be in an incorrect location.
// location.
// Postcondition: The data values have been rearranged so that the first n elements of data now
// form a heap.

template <typename T, typename S>
void heapsort(T data[ ], S n)
// Library facilities used: algorithm, cstdlib
{
    make_heap(data, n);

    //n-1 times
    for ( S i = n - 1 ; i >= 1 ; --i )
    {
    	std::swap(data[0],data[i]);
    	array2pprints(data,i,data+i,n-i,"heapsort","After swapping head with last item");
    	reheapify_down(data, i, static_cast<S>(0));
    }
}

template <typename S>
S parent(S k)
// Library facilities used: cstdlib
{
    return (k-1)/2;
}

template <typename S>
S left_child(S k)
// Library facilities used: cstdlib
{
    return 2*k + 1;
}

template <typename S>
S right_child(S k)
// Library facilities used: cstdlib
{
    return 2*k + 2;
}

template <typename T, typename S>
void make_heap(T data[ ], S n)
// Library facilities used: itemtool.h (from page 277), cstdlib
//
{
	arraypprints(data,n,"mkheap s");

	//Start with the first parent node (non-leaf)
	for ( S i = n / 2 ; i > 0 ; i-- )
	{
		reheapify_down(data,n,i-1);
	}
    arraypprints(data,n,"mkheap e");
}

template <typename T, typename S>
void reheapify_down(T data[ ], S n, S i /*=0*/)
{
	S l,r, largest;
	l = left_child(i);
	r = right_child(i);
	if ( l < n && data[l] > data[i] )
		largest = l;
	else
		largest = i;
	if ( r < n && data[r] > data[largest] )
		largest = r;
	if ( largest != i ) {
		std::swap(data[i],data[largest]);
		reheapify_down(data, n, largest);
	}
}
