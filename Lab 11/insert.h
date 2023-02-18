/*
 * insert.h
 *
 *  Created on: Nov 29, 2014
 *      Author: S Miller
 */

#ifndef INSERT_H_
#define INSERT_H_

#include <algorithm>  // Provides swap
#include "arraypprint.h"

//void insertionsort(T data[ ], S n);
// Precondition: data is an array with at least n components.
// Postcondition: The elements are rearranged so that
// data[0] <= data[1] <= ... <= data[n-1].
template <typename T, typename S>
void insertionsort(T data[ ], S n)
// Library facilities used: algorithm, cstdlib
{
	S i=0,k;

	array2pprints(data,i+1,data+i+1,n-i-1);

	for(i = 1; i < n; ++i)    // Start with 1 (not 0)
	{

		for(k = i; k > 0 && data[k] < data[k-1]; --k)   // Larger values move up
		{
			array2pprints(data,i+1,data+i+1,n-i-1,"","Larger values move up") ;
			std::swap(data[k],data[k-1]);
		}

		array2pprints(data,i+1,data+i+1,n-i-1);
	}

}

#endif /* INSERT_H_ */
