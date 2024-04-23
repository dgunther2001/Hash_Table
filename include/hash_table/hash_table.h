#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <cstdlib>

typedef uint64_t hashfunction (const char*, size_t length);

#define FNV_PRIME 0x100000001b3
#define FNV_OFFSET 0xcbf29ce48422325UL // most optimal offset for collision managment and getting a hash value of 0
uint64_t hash_fnv1(const char* data, size_t length) {
    uint64_t hashValue = FNV_OFFSET;
    for (int i = 0; i < length; i++) {
        hashValue = hashValue * FNV_PRIME; // multiply the intial hashvalue by a prime number
        hashValue = hashValue ^ data[i]; // then xor the hashvalue with the ascii code (in binary) of the "i'th" character in the text being hashed
    }
    return hashValue;
}

template <class Object>
class Node {
    Object* object; // a generic object type
    Node* next; // allows us to chain entries of the hash table for collisions (glorified linked list)
    char* key; // specify the key (key should be some attribute of the object)

    Node(Object* object, char* key);
};

template <class Object>
class Hash_Table {

    Node<Object>** entries;
    hashfunction* hash_function;
    int size;

    Hash_Table(hashfunction* hash_function, int size);
    Hash_Table(hashfunction* hash_function);
    Hash_Table(int size);
    Hash_Table();

    bool hash_insert(const char* key, Object* object);
    Object* hash_delete(const char* key);
    Node<Object>* hash_get_entry(const char* key, int index);
    void printTable();


};


#endif