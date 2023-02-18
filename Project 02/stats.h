// Program Name: Project 2
// Programmer Name: S. Miller
// Attempt Number: Your first Blackboard attempt is "1" for each assignment
// Purpose: Class interface to keep statistics on a collection of value_types
// Purpose for Update: n/a
//
// CLASS PROVIDED: statistician
//  (a class to keep track of statistics on a sequence of real numbers)
//   This class is part of the namespace DS. All code should work for any value_type that
//   supports, +, -, *, /, ==, and !=
//
// CONSTRUCTOR for the statistician class:
//  statistician( );
//      Precondition: n/a
//      Postcondition: The object has been initialized, and is ready to accept
//          a sequence of numbers. Various statistics will be calculated about the
//          sequence. No array allocation is performed.
// COPY CONSTRUCTOR
//  statistician(const statistician&);
//      Precondition: N/A
//      Postcondition: The object has been initialized using the passed object as reference, new object
//          has its own heap storage.
// DESTRUCTOR
//  ~statistician();
//      Precondition: N/A
//      Postcondition: Returns ALL heap storage back to the OS
//
// PUBLIC MODIFICATION member functions for the statistician class:
//  void add(value_type r)
//      Precondition: N/A
//      Postcondition: The number r is processed by statistician and memory of it is preserved in an array.
//          Storage is required for some of the new statistic functions we will now support. The physical
//          size of the array grows by 2 when required. So the initial physical size will be 1 than 2,
//          than 4, 8, 16, and so on.
//      Notes: Expected worst case runtime of O(n), however, usually O(1)
//  void remove(value_type r)
//      Precondition: N/A
//      Postcondition: If r is in the collection, it is removed. If not found, no action. Physical array is not resized.
//  void reset( );
//      Precondition: n/a
//      Postcondition: The statistician has been cleared, as if no numbers had
//          yet been given to it. Object is valid. Heap storage is returned to the OS.
//  statistician(const statistician&);
//      Precondition: N/A
//      Postcondition: The object has been initialized using the passed object as reference, new object
//          has its own heap storage.
// statistician& operator=(const statistician&)
//      Precondition: N/A
//      Postcondition: Old storage is recovered. The object returned has been initialized using the passed
//       object as reference, new object has its own heap storage.
//
// PUBLIC CONSTANT member functions for the statistician class:
//  int length( ) const
//      Precondition: n/a
//      Postcondition: The number of items in storage
//      Notes: Expected runtime of O(1)
//  value_type sum( ) const
//      Precondition: length( ) > 0
//      Postcondition: The return value is the sum of all the numbers in the
//          statistician's sequence.
//      Notes: Expected runtime of O(1)
//  value_type mean( ) const
//      Precondition: length( ) > 0
//      Postcondition: The return value is the arithmetic mean (i.e., the
//          average of all the numbers in the statistician's sequence).
//      Notes: Expected runtime of O(1)
//  statistician::value_type statistician::median( ) const
//      Precondition: length( ) > 0
//      Postcondition: The return value is the median of the values is returned.
//      Help: https://www.mathsisfun.com/median.html
//      Notes: Expected runtime of O(1)
//  value_type standardDeviation( ) const;
//      Precondition: length( ) > 0
//      Postcondition: The return value is the standard deviation of the values is returned.
//      Help: https://www.mathsisfun.com/data/standard-deviation.html
//      Notes: Expected runtime of O(n)
//  value_type minimum( ) const
//      Precondition: length( ) > 0
//      Postcondition: The return value is the smallest number in the statistician's sequence.
//      Notes: Expected runtime of O(1)
//  value_type maximum( ) const
//      Precondition: length( ) > 0
//      Postcondition: The return value is the largest number in the statistician's sequence.
//      Notes: Expected runtime of O(1)
//  bool operator ==(const statistician&)
//      Precondition: n/a
//      Postcondition: The return value is true if this object and passed object have the same contents.
//          The physical size of the arrays DO NOT have to match.
//  bool operator !=(const statistician&)
//      Precondition: n/a
//      Postcondition: The return value is true if this object and passed object have different contents.
//          The physical size of the arrays DO NOT have to match.
//  statistician operator *=(value_type scale)
//      Precondition: N/A
//      Postcondition: Each value in the statistics object is multiplied by scale;
//
// NON-MEMBER functions for the statistician class:
//  statistician operator *(value_type scale, const statistician& s)
//      Precondition: N/A
//      Postcondition: Returns a new object of s multiplies by scale (see the member version of *=)
//
//   std::ostream& operator<<(std::ostream& out, const statistician s)
//      Precondition: n/a
//      Postcondition: Convenience function to output the state of the object.
//
//
// VALUE SEMANTICS for the statistician class:
//  Assignments and the copy constructor may be used with statistician objects.
//
// Invariant declaration
//  STUDENT TODO

#ifndef STATS_H
#define STATS_H
#include <ostream>

namespace DS
{
    class statistician
    {
    public:
        typedef double value_type; //Type of the numbers
        // CONSTRUCTOR
        statistician( ) { seqSum = seqCount = seqCapacity = 0; data = nullptr; };
        // DESTRUCTOR
        virtual ~statistician( );
        // Copy Constructor
        statistician(const statistician&);
        // Assignment
        statistician& operator=(const statistician&);
        // MUTATOR/MODIFICATION MEMBER FUNCTIONS
        void add(value_type);
        void remove(value_type);
        void reserve(size_t);
        void reset( );

        statistician& operator *=(const statistician::value_type&);
        // ACCESSOR/CONSTANT MEMBER FUNCTIONS
        size_t length( ) const { return seqCount; }
        value_type sum( ) const { return seqSum; }
        value_type mean( ) const;
        value_type median( ) const;
        value_type standardDeviation( ) const;
        value_type minimum( ) const { return data[0]; }
        value_type maximum( ) const { return data[seqCount-1]; }
        bool operator ==(const statistician&);
        bool operator !=(const statistician&);

    private:
        size_t seqCount;        // How many numbers in the sequence
        size_t seqCapacity;     // Physical size of the array
        value_type seqSum;      // The sum of all the numbers in the sequence
        value_type * data;      //Pointer to the storage of numbers
    };

    // NON-MEMBER functions for the statistician class
    statistician operator *(const statistician::value_type&, const statistician&);

    //Implemented here, you do not want to implement in stats.cpp
    inline std::ostream& operator<<(std::ostream& out, const statistician s) {
        out << "Length: " << s.length()
            << ", Sum: :" << s.sum()
            << ", Min: " << s.minimum()
            << ", Max: " << s.maximum();
        return out;
    }
}

#endif