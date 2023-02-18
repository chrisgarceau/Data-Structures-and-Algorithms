// FILE: select.cxx
// An interactive test program for the selectionsort function

#include <algorithm>  // Provides swap
#include "arraypprint.h"

// Precondition: data is an array with at least n components.
// Postcondition: The elements are rearranged so that
// data[0] <= data[1] <= ... <= data[n-1].
template <typename T, typename S>
void selectionsort(T data[ ], S n)
// Library facilities used: algorithm, cstdlib
{
    S i, j, index_of_largest;
    T largest;

    for (i = n-1; i > 0; --i)
    {
        largest = data[0];
        index_of_largest = 0;
        for (j = 1; j <= i; ++j)
        {
            if (data[j] > largest)
            {
                largest = data[j];
                index_of_largest = j;
            }
        }
        std::swap(data[i], data[index_of_largest]);
        arraypprints(data,n,"sloop","Swapped "+numtostr(data[i])+"-"+numtostr(data[index_of_largest]));
    }
}
