/*
Program Name: Lab x
Programmer Name: Prof. Miller
Date Submitted: Not submitted
File Purpose: doubly linked node
Date Updated: n/a
Purpose for Update: n/a
Global Variable List: n/a (avoid these)
*/

#ifndef NODE_DLL_H_
#define NODE_DLL_H_

namespace DSDLL {

    template <typename T>
    class node
    {
    public:
        typedef T value_type;
        node(value_type d = value_type(), node * n = nullptr, node * p = nullptr) : data_field(d), next_ptr(n), prev_ptr(p) {}

        //Assessor/Getters
        const value_type& getData () const { return data_field; }
        node const * getPrev () const { return prev_ptr; }
        node const * getNext () const { return next_ptr; }
        //Shorter versions of the above two
        node const * prev () const { return prev_ptr; }
        node const * next () const { return next_ptr; }

        //Mutators/Setters
        void setData (const value_type& d) { data_field = d; }
        void setPrev (node * new_link) { prev_ptr = new_link; }
        void setNext (node * new_link) { next_ptr = new_link; }

        //Other
        value_type& data() { return data_field; }
        const value_type& data() const { return data_field; }
        node*& prev () { return prev_ptr; }
        node*& next () { return next_ptr; }

    private:
        value_type data_field;
        node* next_ptr;
        node* prev_ptr;
    };

} /* namespace DSDLL */

#endif /* NODE_DLL_H_ */