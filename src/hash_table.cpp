#include "hash_table/hash_table.h"

using namespace std;

// NODE INITIALIZATION
template <class Object>
Node<Object>::Node(Object* object, char* key) {
        object = object;
        key = key;
        next = NULL;
};


// HASH TABLE CONSTRUCTORS
template <class Object>
Hash_Table<Object>::Hash_Table(hashfunction* hash_function, int size) {
    entries = new Node<Object>*[size];
    hash_function = hash_function;
    size = size;
}

template <class Object>
Hash_Table<Object>::Hash_Table(hashfunction* hash_function) {
    entries = new Node<Object>*[20];
    hash_function = hash_function;
    size = 20;
}

template <class Object>
Hash_Table<Object>::Hash_Table(int size) {
    entries = new Node<Object>*[size];
    hash_function = hash_fnv1;
    size = size;
}

template <class Object>
Hash_Table<Object>::Hash_Table() {
    entries = new Node<Object>*[20];
    hash_function = hash_fnv1;
    size = 20;
}


// HASH TABLE OPERATIONS
template <class Object>
bool Hash_Table<Object>::hash_insert(const char* key, Object* object) {

}

template <class Object>
Object* Hash_Table<Object>::hash_delete(const char* key) {

}

template <class Object>
Node<Object>* Hash_Table<Object>::hash_get_entry(const char* key, int index) {

}

template <class Object>
void Hash_Table<Object>::printTable() {

}



