#include <algorithm> //You may ONLY use copy from this library
#include <cassert>
#include "darray.h"
#include <iostream>
using namespace std;
namespace DS {

//Copy Constructor (does a deep copy)
    darray::darray(const darray& source) {
        //TO DO
        numberOfItems = source.numberOfItems;  //CHANGES VALUE TO THE NUMBER OF ITEMS IN THE ARRAY PASSED BY REF.
        data = new value_type[source.numberOfItems];  //ALLOCATES NEW BLOCK OF MEMORY ON THE HEAP
        copy(source.data, source.data + source.numberOfItems, data);  //COPIES SOURCE.DATA OVER TO DATA
    }

//Assignment (does a deep copy, watch for self assignment)
    darray& darray::operator=(const darray &source) {
        //TO DO
        value_type *newData;  //DECLARES A POINTER TO AN ARRAY

       if (this != &source) {
           numberOfItems = source.numberOfItems;  //CHANGES VALUE TO THE NUMBER OF ITEMS IN THE ARRAY PASSED BY REF.
           newData = new value_type[numberOfItems];  //ALLOCATES NEW BLOCK OF MEMORY ON THE HEAP
           copy(source.data, source.data + numberOfItems, newData);  //COPIES SOURCE.DATA OVER TO DATA
           delete [] data;  //DEALLOCATES MEMORY ON THE HEAP BY DELETING OLD ARRAY
           data = newData;  //SETTING DATA EQUAL TO NEW DATA;
       }
        return *this;  //DE-REFERENCES POINTER TO RETURN VALUES IN THE ARRAY
    }

//Precondition: None
//Postcondition: Physical arrays size is increased by one.
//  the entry is is added to the array in the position that maintains increasing order.
//  No memory leaks.
//  Linear search may be used.
    void darray::insert(value_type entry) {
        //To do
        auto *temp = new value_type[numberOfItems];  //INITIALIZES NEW POINTER TO AN ARRAY
        copy(data, data + numberOfItems, temp);  //COPIES DATA OVER TO TEMP
        delete[] data;  //DEALLOCATES MEMORY BY DELETING OLD ARRAY
        data = temp;

        int index = 0;
        for (int i = 0; i < numberOfItems; i++) {  //FINDS INDEX WHERE THE NUMBER IS TO BE INSERTED
            if (data[i] < entry) {
                index++;
            }
        }

        for (int i = numberOfItems; i >= index; i--) {   //NUMBERS AFTER INDEX ARE SHIFTED FORWARD ONE POSITION
            data[i] = data[i - 1];
        }

        data[index] = entry;  //DATA AT INDEX IS EQUAL TO ENTRY
        numberOfItems++;
    }

//Precondition: Array is at least size index+1
//Postcondition: Array size is reduced by one with no memory leaks and claiming the least amount of memory.
//  The new array has the same sequence as before minus the entry at index.
//  The value of the item removed is returned.
    darray::value_type darray::remove(size_t index) {
        //To do
        assert(size() >= index + 1);

        auto *temp = new value_type[numberOfItems];  //CREATES TEMP POINTER TO ALLOCATE BLOCK OF MEMORY
        copy(data, data + numberOfItems, temp);  //COPIES NEW ARRAY ELEMENTS INTO TEMP POINTER
        delete [] data;  //DEALLOCATES
        data = temp;

        value_type numRemoved = data[index];
        for (size_t i = index + 1; i < numberOfItems; i++) {  //NUMBERS AFTER INDEX ARE SHIFTED BACK ONE POSITION
            data[i - 1] = data[i];
        }

        numberOfItems--;
        return numRemoved;
    }

//Precondition: param is new size, which is one more than current size OR one less than current size
//Postcondition: array is resized without any memory leaks
    void darray::resize(size_t param) {
        //TO DO (OPTIONAL helper function)
        if (param == 1) {
            numberOfItems++;
            value_type *newArr = new value_type[numberOfItems];
            copy(data, data + numberOfItems, newArr);
            delete [] data;
            data = newArr;
            data[numberOfItems - 1] = 0;
        }
        else {
            numberOfItems--;
            value_type *newArr = new value_type[numberOfItems];
            copy(data, data + numberOfItems, newArr);
            delete [] data;
            data = newArr;
        }
    }

    darray::value_type darray::deleteFirstElement() {
        value_type *temp = new value_type[numberOfItems];
        copy(data, data + numberOfItems, temp);
        delete [] data;
        data = temp;

        for (int i = 1; i < numberOfItems; i++) {
            data[i - 1] = data[i];
        }
        numberOfItems--;
    }

    darray::value_type darray::deleteLastElement() {
        value_type *temp = new value_type[numberOfItems];
        copy(data, data + numberOfItems, temp);
        delete [] data;
        data = temp;

        numberOfItems--;
        for (int i = numberOfItems; i < 1; i--) {
            data[i - 1] = data[i];
        }
    }

   size_t darray::reduceEven() {
        size_t newSize = 0;
        for (int i = 0; i < numberOfItems; i++) {
            if (i % 2 == 0) {
                cout << data[i] << " ";
                newSize++;
            }
        }
        value_type *n = new value_type[newSize];
       int j = 0;
        for(int i = 0; i < numberOfItems; i++) {
            if ( i % 2 == 0) {
                n[j] = data[i];
                j++;
            }
        }
        delete [] data;
        data = n;
        cout << endl;
        for (int i = 0; i < newSize; i++) {
            cout << n[i] << " ";
        }
    }

    size_t darray::removeOdds() {
        size_t numberofOdds = 0;
        size_t newSize = 0;
        for (int i = 0; i < numberOfItems; i++) {
            if (data[i] % 2 != 0) {
                cout << data[i] << " ";
                numberofOdds++;
            }
        }
        cout << endl;
        cout << numberofOdds << " " << endl;
        newSize = numberOfItems - numberofOdds;

        value_type *n = new value_type[newSize];
        int j = 0;
        for (int i = 0; i < numberOfItems; i++) {
            if (data[i] % 2 == 0) {
                n[j] = data[i];
                j++;
            }
        }
        delete [] data;
        data = n;
        for (int i = 0; i < newSize; i++) {
            cout << n[i] << " ";
        }
    }

    int darray::removeMore(value_type target) {
        size_t newSize = 0;
        size_t numsRemoved = 0;
        for(size_t i = 0; i < size(); i++) {
            if (data[i] > target) {
                numsRemoved++;
            }
        }
        newSize = size() - numsRemoved;

        value_type *temp = new value_type[newSize];
        size_t j = 0;
        for (size_t i = 0; i < numberOfItems; i++) {
            if (data[i] < target) {
                temp[j] = data[i];
                j++;
            }
        }
        numberOfItems = newSize;
        delete [] data;
        data = temp;

        for(int i = 0; i < numberOfItems; i++) {
            cout << data[i] << " ";
        }
    }

} /* namespace DS */