

namespace DS {

    template<typename T>
    mystack<T>::~mystack<T>() {
        node_count = 0;
        pTop = nullptr;
    }

    template<typename T>
    void mystack<T>::push(const value_type &entry) {
        node *newNode = new node;
        newNode->setData(entry);
        newNode->setNext(pTop);
        pTop = newNode;

        node_count++;
    }

    template<typename T>
    void mystack<T>::pop() {
        assert(!empty( ));
        node *removePtr;
        removePtr = pTop;
        pTop = pTop->next();
        free(removePtr);
        node_count--;
    }

}