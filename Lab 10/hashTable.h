//
// Created by steve on 11/9/20.
//

#ifndef LABHASH_HASHTABLE_H
#define LABHASH_HASHTABLE_H

#include <cstddef>
#include <algorithm>

namespace DS {

    enum flags {
        WAS_USED, FREE, INUSE
    };

    template<typename K, typename V>
    struct hash_entry {
        K key;
        V value;
        flags flag = flags::FREE;
    };

    template<typename K>
    size_t integer_hash(const K &key, size_t max) {
        return key % max;
    }

    template<typename K, typename V>
    class hashTable {
    public:
        typedef K key_type;
        typedef V value_type;
        typedef hash_entry<key_type, value_type> entry_type;

        hashTable(size_t capacity=811);
        explicit hashTable(size_t capacity, size_t (*hash)(const key_type &, size_t));
        hashTable(const hashTable&);

        virtual ~hashTable();
        hashTable& operator=(const hashTable&);


        bool insert(const key_type &key, const value_type &val);

        size_t max_size() const { return capacity; };
        size_t size() const { return used; };
        bool empty() const { return used==0; }

        //Removes item with passed key from the collection
        //This effectively reduces the container size by one and returns true
        //Returns false if the key was unable to be found
        bool erase(const key_type& k);

        //Searches the container for an element with a key equivalent to k and returns a reference to it,
        //Returns nullptr if not found
        value_type* find (const key_type& k);

        //Searches the container for elements with a key equivalent to k and returns the number of matches.
        size_t count (const key_type& k) const;

        size_t getCollisions() const { return collisions; }; //Lower is better
        double getUtilization() const { return static_cast<double>(used)/capacity*100; }; //Higher is better

    private:
        size_t capacity;

        size_t (*hash)(const key_type &, size_t);

        entry_type* data;
        size_t used;
        size_t collisions;
    };

    template<typename K, typename V>
    hashTable<K, V>::hashTable(size_t capacity) : capacity(capacity), collisions(0), used(0) {
        hash = &integer_hash;
        data = new entry_type[capacity];
    }

    template<typename K, typename V>
    hashTable<K, V>::hashTable(size_t capacity, size_t (*hash)(const key_type &, size_t)) : capacity(capacity), collisions(0), used(0)  {
        this->hash = hash;
        data = new entry_type[capacity];
    }

    template<typename K, typename T>
    bool hashTable<K, T>::insert(const key_type &key, const value_type &val) {
        size_t h = hash(key, capacity);

        if (used == capacity)
            return false;

        while (data[h].flag == flags::INUSE) {
            h = (h + 1) % capacity; //Wrap around when required
            ++collisions;
        }

        data[h].key = key;
        data[h].flag = flags::INUSE;
        data[h].value = val;
        ++used;
        return true;
    }

    template<typename K, typename V>
    hashTable<K, V>::~hashTable() {
        delete [] data;
    }

    template<typename K, typename V>
    hashTable<K, V>::hashTable(const hashTable & src) {
        capacity = src.capacity;
        used = src.used;
        data = new entry_type[capacity];
        hash = src.hash;
        collisions = src.collisions;
        std::copy(src.data, src.data + src.used, data);
    }

    template<typename K, typename V>
    typename hashTable<K, V>::hashTable& hashTable<K, V>::operator=(const hashTable & src) {
        if ( this == &src)
            return *this;

        delete [] data;

        capacity = src.capacity;
        used = src.used;
        data = new entry_type[capacity];
        hash = src.hash;
        collisions = src.collisions;
        std::copy(src.data, src.data + src.used, data);

        return *this;
    }

    template<typename K, typename T>
    std::ostream& operator<<(std::ostream &out, const hash_entry<K, T>& item) {
        switch ( item.flag ) {
            case flags::INUSE:
                out << item.key << ":" << item.value;
                break;
            case flags::FREE:
                out << "F";
                break;
            case flags::WAS_USED:
                out << "X";
                break;
            default:
                out << "ERROR";
        }
        return out;
    }

}

#include "hashTable.hpp"

#endif //LABHASH_HASHTABLE_H