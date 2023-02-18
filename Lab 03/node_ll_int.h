/*
Programmer Name: Prof. Miller
Date Submitted: Not submitted
File Purpose: single linked node
Date Updated: n/a
Purpose for Update: n/a
Global Variable List: n/a (avoid these)

Stores one data item and has ability to point to another node like itself

Value Semantics declaration:
	Is it safe to use the copy constructor and the assignment operator

Dynamic Memory Usage declaration:
	None explicitly, however, objects of this type are usually on the heap

Static & Global variable list:
	none

Invariant declaration:
	data_field: points to a data item, this class does not check the invariant
		of this data

	next_ptr: should be a valid pointer to a like object or nullptr, however,
		this class does not validate this

*/

#ifndef NODE_LL_I_H_
#define NODE_LL_I_H_

namespace DSLLI {

    class node
    {
    public:
        typedef int value_type;

        //Constructor
        node(value_type d = value_type(), node * n = nullptr) : data_field(d), next_ptr(n) {}

        //Assessor/Getters
        const value_type& getData() const { return data_field; }
        node const * getNext() const { return next_ptr; }

        //Mutators/Setters
        void setData(const value_type& new_data) { data_field = new_data; }
        void setNext(node * new_link) { next_ptr = new_link; }

        //Other
        value_type& data() { return data_field; }
        node*& next() { return next_ptr; }

    private:
        value_type data_field;
        node* next_ptr;
    };

} /* namespace DSLLI */

#endif /* NODE_LL_I_H_ */