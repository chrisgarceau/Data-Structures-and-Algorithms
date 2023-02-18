//============================================================================
// Name        : sorthelpders.h
// Author      :  S.Miller
//============================================================================

#ifndef SORTING_SORT_HELPERS_H
#define SORTING_SORT_HELPERS_H

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <random>
#include <iomanip>
#include "select.h"
#include "insert.h"
#include "binaryinsertion.h"
#include "shellsort.h"
#include "merge.h"
#include "bubble.h"
#include "radix.h"
#include "arraypprint.h"
#include "heapsort.h"
#include "quicksort.h"
#include "walltimer.h"

#define BUBBLESORT 1
#define SELECTIONSORT 2
#define INSERTIONSORT 3
#define MERGESORT 4
#define QUICKSORT 5
#define HEAPSORT 6
#define SHELLSORT 7
#define BINARYINSERTIONSORT 8
#define RADIXSORT 9

template <typename T, typename S>
void sortVia(T in[], S max, int SORTMETHOD, bool doCopy = false) {

    T *items;

    if ( doCopy ) {
        items = new T[max];
        //Do not modify original
        std::copy(in,in+max,items);
    } else
        items = in;
    WallTimer timer;
    std::cout << std::endl;

    //SortSORTMETHOD
    switch (SORTMETHOD)
    {
        case BUBBLESORT: //bubble
            std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl << "Bubble Sort" << std::endl;
            arraypprints(items,max,"Before");
            timer.start();
            bubblesort(items, max);
            timer.stop();
            break;
        case SELECTIONSORT: //selection
            std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl << "Selection Sort" << std::endl;
            arraypprints(items,max,"Before");
            timer.start();
            selectionsort(items, max);
            timer.stop();
            break;
        case INSERTIONSORT: //insertion
            std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl << "Insertion Sort" << std::endl;
            arraypprints(items,max,"Before");
            timer.start();
            insertionsort(items, max);
            timer.stop();
            break;
        case MERGESORT: //mergesort
            std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl << "Merge Sort" << std::endl;
            arraypprints(items,max,"Before");
            timer.start();
            mergesort(items, max);
            timer.stop();
            break;
        case QUICKSORT: //quicksort
            std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl << "Quick Sort" << std::endl;
            arraypprints(items,max,"Before");
            timer.start();
            quicksort(items, max);
            timer.stop();
            break;
        case HEAPSORT: //heapsort
            std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl << "Heap Sort" << std::endl;
            arraypprints(items,max,"Before");
            timer.start();
            heapsort(items, max);
            timer.stop();
            break;
        case SHELLSORT: //shellsort
            std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl << "Shell Sort" << std::endl;
            arraypprints(items,max,"Before");
            timer.start();
            shellsort(items, max);
            timer.stop();
            break;
        case BINARYINSERTIONSORT: //binary Insertion Sort
            std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl << "Binary Insertion Sort" << std::endl;
            arraypprints(items,max,"Before");
            timer.start();
            binaryInsertionSort(items, max);
            timer.stop();
            break;
        case RADIXSORT: //Radix Sort
            std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << std::endl << "Radix Sort" << std::endl;
            arraypprints(items,max,"Before");
            timer.start();
            radix_sort(items, max);
            timer.stop();
            break;
        default:
            std::cerr << "Unknown sort";
    }

    arraypprints(items,max,"After");

    if ( doCopy )
        delete [] items;

    std::cout << "Elapsed Time: "
              << timer.get_minutes()
              << " minute(s) and "
              << timer.get_seconds()
              << " second(s)." << std::endl;
}

template <typename T, typename S>
void populateBestArray(T in[], S asize) {
    for ( S i = 0 ; i < asize ; ++i ) {
        in[i] = i;
    }
}

template <typename T, typename S, typename G>
void populateAvgArray(T in[], S asize, G generator) {
    if( asize > LONG_MAX ) {
        std::uniform_int_distribution<T> distribution;
        for ( size_t i = 0 ; i < asize ; ++i ) {
            in[i] = distribution(generator);
        }

    } else if ( asize > INT_MAX ) {
        std::uniform_int_distribution<long> distribution;
        for ( size_t i = 0 ; i < asize ; ++i ) {
            in[i] = distribution(generator);
        }
    } else if ( asize > SHRT_MAX ) {
        std::uniform_int_distribution<int> distribution;
        for ( size_t i = 0 ; i < asize ; ++i ) {
            in[i] = distribution(generator);
        }
    } else if ( asize < 100 ){
        std::uniform_int_distribution<short> distribution(1, 200);
        for ( size_t i = 0 ; i < asize ; ++i ) {
            in[i] = distribution(generator);
        }
    } else {
        std::uniform_int_distribution<short> distribution;
        for ( size_t i = 0 ; i < asize ; ++i ) {
            in[i] = distribution(generator);
        }
    }
}

template <typename T, typename S>
void populateWorstArray(T in[], S asize) {

    for ( S i = 0, v = asize ; i < asize ; ++i ,--v) {
        in[i] = v;
    }

}

#endif //SORTING_SORT_HELPERS_H
