// Program Name: Project 1
// Programmer Name: S. Miller
// Attempt Number: Your first Blackboard attempt is "1" for each assignment
// Purpose: Class interface to keep statistics on a collection of doubles
// Purpose for Update: n/a
//
// CLASS PROVIDED: statistician
//  (a class to keep track of statistics on a sequence of real numbers)
//   This class is part of the namespace DS.
//
// CONSTRUCTOR for the statistician class:
//  statistician( );
//      Precondition: n/a
//      Postcondition: The object has been initialized, and is ready to accept
//          a sequence of numbers. Various statistics will be calculated about the
//          sequence.

// VALUE CONSTRUCTOR
//  statistician(size_t count, double sum, double smallest, double largest);
//      Precondition: No processing done, so, assumed invariant is followed
//      Postcondition: The object has been initialized using the passed values
//
// PUBLIC MODIFICATION member functions for the statistician class:
//  void add(double r)
//      Precondition: r is not ERROR_FLAG and object is valid
//      Postcondition: The number r is processed by statistician as the next number in
//          its sequence of numbers.

//  void remove(double r)
//      Precondition: r is not ERROR_FLAG and object is valid
//      Postcondition: The number r is processed by statistician and removed. It is assumed
//          that r was a member of the original sequence that was not already removed. However,
//          if r is the current smallest or largest value, the state of the object will change to invalid.
//          If length is already 0, object becomes invalid as well.
//          Once invalid, only a reset will fix it.

//  void reset( );
//      Precondition: n/a
//      Postcondition: The statistician has been cleared, as if no numbers had
//          yet been given to it. Object is valid.
//
// PUBLIC CONSTANT member functions for the statistician class:
//  int length( ) const
//      Precondition: n/a
//      Postcondition: The return value is the length of the sequence that has
//          been given to the statistician (i.e., the number of times that the
//          add(r) function has been activated). Returns 0 when invalid.

//  double sum( ) const
//      Precondition: length( ) > 0
//      Postcondition: The return value is the sum of all the numbers in the
//          statistician's sequence.
//          Returns ERROR_FLAG when object is invalid

//  double mean( ) const
//      Precondition: n/a
//      Postcondition: The return value is the arithmetic mean (i.e., the
//          average of all the numbers in the statistician's sequence).
//          Returns ERROR_FLAG when invalid, such as when length is 0, or when object is invalid.

//  double minimum( ) const
//      Precondition: n/a
//      Postcondition: The return value is the smallest number in the statistician's sequence.
//          Returns ERROR_FLAG when invalid, such as when length is 0, or when object is invalid.

//  double maximum( ) const
//      Precondition: n/a
//      Postcondition: The return value is the largest number in the statistician's sequence.
//          Returns ERROR_FLAG when invalid, such as when length is 0, or when object is invalid.

//  bool is_valid( ) const
//      Precondition: n/a
//      Postcondition: Returns true when the state of the object is valid, false otherwise
//
// NON-MEMBER functions for the statistician class:
//  statistician operator +(const statistician& s1, const statistician& s2)
//      Precondition: n/a
//      Postcondition: The statistician that is returned contains all the
//          numbers of the sequences of s1 and s2. If either s1 or s2 is invalid the result will be invalid.

//  statistician operator *(double scale, const statistician& s)
//      Precondition: The passed statistician object is valid
//      Postcondition: The statistician that is returned contains the same
//          numbers that s does, but each number has been multiplied by the
//          scale number.

//   bool operator ==(const statistician& s1, const statistician& s2)
//      Precondition: n/a
//      Postcondition: The return value is true if s1 and s2 have the zero
//          length. Also, if the length is greater than zero, then s1 and s2 must
//          have the same length, the same  mean, the same minimum,
//          the same maximum, and the same sum.

//   std::ostream& operator<<(std::ostream& out, const statistician s)
//      Precondition: n/a
//      Postcondition: Convenience function to output the state of the object.
//
//
// VALUE SEMANTICS for the statistician class:
//  Assignments and the copy constructor may be used with statistician objects.
//
// Invariant declaration
//  The class will maintain the count, smallest, and largest fields on all mutator functions
//      so that later calls on other functions will always be valid. If at any time the state of the
//      object is invalid, ....
//******************
//      STUDENT FINISH THIS PART OF INVARIANT OUT AND INCLUDE ENTIRE INVARIANT AS PART OF YOUR stats.cpp FILE.
//      Basically, how did you decide to keep track of the validity of the object.
//******************
//      It is possible that the mean could calculate to ERROR_FLAG naturally when length > 1, however,
//      is_valid would let us know if this can be trusted.

#ifndef STATS_H
#define STATS_H
#include <ostream>

namespace DS
{
    class statistician
    {
    public:
        // CONST values
        constexpr static const double ERROR_FLAG = 42.2020; //Special value to keep track of validity

        // CONSTRUCTOR
        statistician( );

        // Value Constructor
        statistician(size_t, double, double, double);

        // MUTATOR/MODIFICATION MEMBER FUNCTIONS
        void add(double);
        void remove(double);
        void reset( );

        // ACCESSOR/CONSTANT MEMBER FUNCTIONS
        size_t length( ) const;
        double sum( ) const;
        double mean( ) const;
        double minimum( ) const;
        double maximum( ) const;
        bool is_valid( ) const;

    private:
        size_t seqCount;    // How many numbers in the sequence
        double seqSum;      // The sum of all the numbers in the sequence
        double seqSmallest; // The smallest number in the sequence
        double seqLargest;  // The largest number in the sequence
    };

    // NON-MEMBER functions for the statistician class
    bool operator ==(const statistician& , const statistician&);
    statistician operator +(const statistician&, const statistician&);
    statistician operator *(double, const statistician&);

    //Implemented here, you do not want to implement in stats.cpp
    inline std::ostream& operator<<(std::ostream& out, const statistician s) {
        if ( s.is_valid() ) {
            out << "Length: " << s.length()
                << ", Sum: :" << s.sum()
                << ", Min: " << s.minimum()
                << ", Max: " << s.maximum();
        } else {
            out << "Invalid";
        }
        return out;
    }
}

#endif