#include "hash_table/hash_table.h"



// HASH TABLE GET AND SET METHODS




// HASH TABLE OPERATIONS
template <class Object>
hashfunction* Hash_Table<Object>::getHashFunction() {
    return this->hash_function;
}

template <class Object> // TODO
bool Hash_Table<Object>::hash_insert(const string key, Object* object) {
    int index = hash_function(key, key.size()); // calculates the absolute hash value
    index = index % size; // mods with the size of the able to force it to fit

    return true;
}

template <class Object> // TODO
Object* Hash_Table<Object>::hash_delete(const string key) {

}

template <class Object> // TODO
Node<Object>* Hash_Table<Object>::hash_get_entry(const string key, int index) {

}

template <class Object> // TODO
void Hash_Table<Object>::printTable() {

}



