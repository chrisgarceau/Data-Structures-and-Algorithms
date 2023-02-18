// FILE: mystack.h
// TEMPLATE CLASS PROVIDED: stack<Item> (a stack of items)
//   The template parameter, Item, is the data type of the items in the stack,
//   also defined as stack<Item>::value_type.
//   It may be any of the C++ built-in types (int, char, etc.), or a class
//   with a default constructor, a copy constructor, and an assignment
//   operator. The definition stack<Item>::size_type is the data type of
//   any variable that keeps track of how many items are in a stack.
//
// CONSTRUCTOR for the stack<Item> template class:
//   stack( )
//     Postcondition: The stack has been initialized as an empty stack.
//
// MODIFICATION MEMBER FUNCTIONS for the stack<Item> class:
//   void push(const Item& entry)
//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been pushed onto the stack.
//
//   void pop( )
//     Precondition: size( ) > 0.
//     Postcondition: The top item of the stack has been removed.
//
// CONSTANT MEMBER FUNCTIONS for the stack<Item> class:
//   bool empty( ) const
//     Postcondition: Return value is true if the stack is empty.
//
//   size_type size( ) const
//     Postcondition: Return value is the total number of items in the stack.
//
//   Item top( ) const
//     Precondition: size( ) > 0.
//     Postcondition: The return value is the top item of the stack (but the
//     stack is unchanged. This differs slightly from the STL stack (where
//     the top function returns a reference to the item on top of the stack).
//
// VALUE SEMANTICS for the stack<Item> class:
//   Assignments and the copy constructor may be used with stack<Item>
//   objects.
//
// DYNAMIC MEMORY USAGE by the stack<Item> template class:
//   If there is insufficient dynamic memory, then the following functions
//   throw bad_alloc:
//   the copy constructor, push, and the assignment operator.

#ifndef MYSTACK_H
#define MYSTACK_H
#include <cstdlib>   // Provides size_t
#include "node_ll.h"

namespace DS
{
    template<typename T>
    class mystack
    {
    public:
        // TYPEDEFS
        typedef std::size_t size_type;
        typedef T value_type;
        typedef DSLL::node<value_type> node;
        // CONSTRUCTORS and DESTRUCTOR
        mystack( ){ pTop = nullptr;  node_count = 0;  }
        mystack(const mystack& source);
        virtual ~mystack( );
        // MODIFICATION MEMBER FUNCTIONS
        void push(const value_type& entry);
        void pop( );
        void operator =(const mystack& source);
        // CONSTANT MEMBER FUNCTIONS
        size_type size( ) const { return node_count; }
        bool empty( ) const { return pTop == nullptr; }
        value_type top( ) const;
    private:
        size_t node_count;
        node *pTop;  // Points to top of stack
    };
}

#include "mystack-starter.hpp"
#include "mystack-student.hpp"

#endif
