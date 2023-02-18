//File is included by mystack.h
//Implements the hardest two functions, copy constuctor and assignment as well as the trivial top
namespace DS {

    template<typename T>
    typename mystack<T>::value_type mystack<T>::top( ) const
    {
        assert(!empty( ));
        return pTop->getData();
    }

    template<typename T>
    mystack<T>::mystack(const mystack &source) {
        if (source.pTop == nullptr) {
            //Source list is empty, initialize member data
            pTop = nullptr;
        } else {
            node *tail;
            //Special case, add a new head node
            pTop = tail = new node(source.pTop->getData());
            //Loop until no more nodes to add
            for (node *p = source.pTop->getNext(); p != nullptr; p = p->getNext()) {
                tail->setNext(new node(source.pTop->getData()));
                tail = tail->getNext();
            }
        }
        node_count = source.node_count;
    }

    template<typename T>
    void mystack<T>::operator=(const mystack &source) {
        if (this == &source) // Handle self-assignment
            return;

        //Delete old
        node *temp;
        while (pTop != nullptr) {
            temp = pTop;
            pTop = pTop->getNext();
            delete temp;
        }

        if (source.pTop == nullptr) {
            //Source list is empty, initialize member data
            pTop = nullptr;
        } else {
            node *tail;
            //Special case, add a new head node
            pTop = tail = new node(source.pTop->getData());
            //Loop until no more nodes to add
            for (node *p = source.pTop->getNext(); p != nullptr; p = p->getNext()) {
                tail->setNext(new node(source.pTop->getData()));
                tail = tail->getNext();
            }
        }
        node_count = source.node_count;

    }

}