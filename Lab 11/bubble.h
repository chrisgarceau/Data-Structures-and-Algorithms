/*
 * bubble.h
 *
 *  Created on: Dec 2, 2015
 *      Author: steve
 */

#ifndef BUBBLE_H_
#define BUBBLE_H_

#include <algorithm>  // Provides swap
#include "arraypprint.h"

//void bubblesort(Item data[ ], size_t n);
// Precondition: data is an array with at least n components.
// Postcondition: The elements are rearranged so that
// data[0] <= data[1] <= ... <= data[n-1].
template <typename T, typename S>
void bubblesort(T data[ ], S n)
// Library facilities used: algorithm, cstdlib
{

	bool swapped = true; //Set to true to enter loop at least once

	for(S i = 0; i < n && swapped; ++i) //Iterate n times OR until we complete a pass requiring NO swaps
	{
		swapped = false;

		for(S j = 1; j < n; j++)   // Iterate over entire array
		{
			if ( data[j] < data[j-1] ) {
				//Value to the LEFT is GREATER then RIGHT value, therefore, swap them
				std::swap(data[j],data[j-1]);
				swapped = true;
				arraypprints(data,n,"swap","loop " + numtostr(i) );
			}
		}

	}

}


#endif /* BUBBLE_H_ */
