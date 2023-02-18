#include "hashTable.h"

namespace DS {

    //Returns true if and item was removed, false otherwise
    template<typename K, typename V>
    bool hashTable<K, V>::erase(const key_type &key) {
        for (int i = 0; i < capacity; i++) {
            if (data[i].flag == INUSE && data[i].key == key) {
                delete [] data;
                return true;
            }
        }
        return false;
    }

    //Returns a pointer to the data requested, nullptr if not found
    template<typename K, typename V>
    typename hashTable<K, V>::value_type* hashTable<K, V>::find(const key_type &key) {
        for (int i = 0; i < capacity; i++) {
            if (data[i].flag == INUSE && data[i].key == key) {
                return &data[i].value;
            }
        }
        return nullptr;
    }

    //Returns 1 if found, 0 otherwise
    template<typename K, typename V>
    size_t hashTable<K, V>::count(const key_type &key) const {
        if (find(key) != nullptr) {
            return 1;
        }
        return 0;
    }

} //End DS Namespace