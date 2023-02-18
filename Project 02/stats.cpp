// Program Name: Project 02
// Programmer Name: Christopher Garceau
// Attempt Number: 2
// Purpose: Statistician class implementation to keep statistics on a collection of value_type
// Purpose for Update: n/a
#include "stats.h"
#include <algorithm>
#include <cmath>

// Invariant declaration
//  STUDENT TODO
//  The class is part of the namespace DS and will maintain the statistics on a sequence of value_types.
//  The sequence length, capacity, and sum private member variables will contain accurate values.
//  Each number in the sequence will be contained within a dynamic array, which is pointed to by
//  the private member variable, *data. These private member variables will store said data so
//  that all mutator, as well as accessor functions, can access and manipulate the object and return new data
//  while maintaining the object's validity. When a value is added to the sequence, the length of the sequence is increased
//  by one, the total sum of the sequence is increased by the value passed as the parameter, and the capacity of the sequence
//  is double that of the length. When a value is removed from the sequence, the length of the sequence is decreased by one,
//  the total sum of the sequence is decreased by the value passed as the parameter, and the capacity of the sequence
//  remains the same. When an object is reset, all private member variables are set to zero and data is equal to nullptr.
//  The object returns back to its original state, that being the state just after it is constructed.

//Start of namespace
using namespace std;
namespace DS {

    //DESTRUCTOR - DEALLOCATES MEMORY
    statistician::~statistician() {
        //TODO: Student implements
        delete [] data;
    }

    //COPY CONSTRUCTOR - SETS OBJECTS PRIVATE MEMBER DATA & VARIABLES TO THAT OF SOURCE'S
    statistician::statistician(const statistician &source) {
        data = new value_type[source.seqCapacity]; //ALLOCATES NEW BLOCK OF MEMORY ON THE HEAP
        seqCapacity = source.seqCapacity;
        seqCount = source.seqCount;
        seqSum = source.seqSum;
        copy(source.data, source.data + source.seqCount, data); //COPIES SOURCE.DATA OVER TO CURRENT OBJECT'S DATA
    }

    //ASSIGNMENT OPERATOR
    statistician& statistician::operator=(const statistician &source) {
        value_type *newData;

        if (this != &source) {
            seqCount = source.seqCount;
            seqCapacity = source.seqCapacity;
            seqSum = source.seqSum;
            newData = new value_type[seqCapacity];  //ALLOCATES NEW BLOCK OF MEMORY ON THE HEAP
            copy(source.data, source.data + seqCount, newData);  //COPIES SOURCE.DATA OVER TO NEWDATA
            delete [] data;  //DEALLOCATES MEMORY ON THE HEAP
            data = newData;  //SETTING DATA EQUAL TO NEWDATA;
        }
        return *this;  //DE-REFERENCES POINTER TO RETURN VALUES IN THE ARRAY
    }

    //PUBLIC MODIFICATION MEMBER FUNCTIONS
    void statistician::add(value_type r) {  //ADDS VALUE TO THE SEQUENCE AN THE CORRECT INDEX (ASCENDING ORDER)
        //TODO: Student implements
        auto *temp = new value_type[seqCapacity]; //INITIALIZES NEW POINTER TO AN ARRAY
        copy(data, data + seqCount, temp);  //COPIES DATA OVER TO TEMP
        delete [] data;  //DEALLOCATES MEMORY
        data = temp;

        int index = 0;
        for (int i = 0; i < seqCount; i++) {  //FINDS INDEX WHERE THE NUMBER IS TO BE ADDED
            if (data[i] < r) {
                index++;
            }
        }

        for (int i = seqCount; i >= index; i--) {  //NUMBERS AFTER INDEX ARE SHIFTED FORWARD ONE POSITION
            data[i] = data[i - 1];
        }
        data[index] = r;  //DATA AT INDEX IS EQUAL TO R

        seqCount++;  //SEQUENCE COUNT IS INCREMENTED
        seqCapacity = seqCount * 2;  //SEQUENCE CAPACITY IS DOUBLED
        seqSum += r;  //R IS ADDED TO THE TOTAL SUM OF THE SEQUENCE
    }

    void statistician::remove(value_type r) {  //REMOVES SPECIFIC PARAMETER VALUE
        auto *temp = new value_type[seqCapacity];  //CREATES TEMP POINTER TO ALLOCATE BLOCK OF MEMORY
        copy(data, data + seqCapacity, temp);  //COPIES NEW ARRAY ELEMENTS INTO TEMP POINTER
        delete[] data;  //DEALLOCATES MEMORY
        data = temp;

        size_t index = 0;
        for (size_t i = 0; i < seqCount; i++) { //FINDS INDEX WHERE THE NUMBER IS TO BE DELETED
            if (r == data[i]) {
                seqCount--;  //SEQUENCE LENGTH IS DECREMENTED
                seqSum = seqSum - r;  //R IS SUBTRACTED FROM TOTAL SEQUENCE SUM
                index = i;  //INDEX EQUALS POSITION OF PARAMETER VALUE WITHIN SEQUENCE
            }
        }

        for (size_t i = index + 1; i < seqCapacity; i++) {  //NUMBERS AFTER INDEX ARE SHIFTED BACK ONE POSITION
            data[i - 1] = data[i];
        }
    }

    void statistician::reserve(size_t) {}

    void statistician::reset() {  //ALL PRIVATE MEMBER DATA & VARIABLES ARE SET TO ORIGINAL STATE
        seqCount = 0;
        seqSum = 0;
        seqCapacity = 0;
        delete [] data;
        data = nullptr;
    }

    //ALL VALUES WITHIN THE SEQUENCE AND THE SEQSUM PRIVATE MEMBER VARIABLE ARE MULTIPLIED BY THE SCALE PARAMETER
    statistician& statistician::operator *=(const statistician::value_type &scale) {
        auto *t = new statistician;  //DECLARES NEW STATISTICIAN OBJECT
        auto *temp = new value_type[seqCapacity]; //DECLARES NEW POINTER TO AN ARRAY
        copy(data, data + seqCapacity, temp); //COPIES DATA INTO TEMP DATA
        delete [] data;
        data = temp;

        for (int i = 0; i < seqCount; i++) {  //MULTIPLIES EACH VALUE IN SEQUENCE BY SCALE PARAMETER
            data[i] = data[i] * scale;
        }

        if (scale < 0) {
            int j = 0;
            for (int i = seqCount - 1; i > 0; i--) {
                int temp = data[j];
                data[j] = data[i];
                data[i] = temp;
                j++;
            }
        }

        seqSum = seqSum * scale;  //MULTIPLIES SEQSUM BY SCALE PARAMETER
        t->seqSum = seqSum; //T.SEQSUM POINTS TO NEW SEQSUM
        return *t;
    }

    //Notice here how you need to use the scope for the value_type, only when return is of a typedef defined in a class
    statistician::value_type statistician::mean() const {  //RETURNS AVERAGE OF THE NUMBERS IN THE SEQUENCE
        //TODO: Student implements
        value_type avg = seqSum / seqCount;
        return avg;
    }

    statistician::value_type statistician::median() const {  //RETURNS THE MEDIAN OF THE NUMBERS IN THE SEQUENCE
        value_type med;
        size_t index1 = seqCount / 2;
        size_t index2 = (seqCount / 2) - 1;

        if (seqCount <= 2) {
            return mean();
        }
        if (seqCount > 2 && seqCount % 2 == 0) {  //IF SEQCOUNT IS GREATER THAN TWO AND HAS AN EVEN NUMBER OF VALUES, MEDIAN EQUALS THE AVERAGE OF THE TWO MIDDLE VALUES
            med = (data[index1] + data[index2]) / 2;
        }
        else {  //IF SEQCOUNT HAS AN ODD NUMBER OF VALUES, THE VALUE IN EXACTLY THE MIDDLE IS THE MEDIAN
            med = data[index1];
        }
        return med;
    }

    statistician::value_type statistician::standardDeviation( ) const {  //RETURNS THE STAND. DEV. OF THE NUMBERS IN THE SEQUENCE
        value_type avg = seqSum / seqCount;
        value_type diffFromAvg = 0;
        value_type variance;
        value_type standDev;

        for (int i = 0; i < seqCount; i++) {
            diffFromAvg += ((avg - data[i]) * (avg - data[i]));
        }
        variance = diffFromAvg / seqCount;
        standDev = sqrt(variance);
        return standDev;
    }

    bool statistician::operator==(const statistician &source) { //RETURNS TRUE/FALSE IF THE OBJECT'S VALUES ARE EQUAL OR NOT
        if ((seqCount == source.length()) && (mean() == source.mean()) &&
            (seqSum == source.sum()) && (maximum() == source.maximum()) &&
            (minimum() == source.minimum())) {
            return true;
        }
        else {
            return false;
        }
    }

    bool statistician::operator !=(const statistician &source) {  //RETURNS TRUE/FALSE IF OBJECT'S VALUES ARE NOT EQUAL OR NOT
        if ((seqCount != source.length()) || (mean() != source.mean()) ||
            (seqSum != source.sum()) || (maximum() != source.maximum()) ||
            (minimum() != source.minimum())) {
            return true;
        }
        else {
            return false;
        }
    }

    statistician operator*(const statistician::value_type &scale, const statistician &source) {  //MULTIPLIES EVERY VALUE IN THE SEQUENCE BY THE SCALE
        statistician t = source; //USES COPY CONSTRUCTOR TO CREATE NEW STATISTICIAN OBJECT
        t.operator*=(scale); //USES *= MEMBER OPERATOR FUNCTION
        return t;
    }
} // End of namespace