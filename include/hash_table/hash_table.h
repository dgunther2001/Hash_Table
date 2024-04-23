#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;


typedef uint64_t hashfunction (const string, size_t length);

#define FNV_PRIME 0x100000001b3
#define FNV_OFFSET 0xcbf29ce48422325UL // most optimal offset for collision managment and getting a hash value of 0
uint64_t hash_fnv1_default(string data, size_t length) {
    uint64_t hashValue = FNV_OFFSET;
    for (int i = 0; i < length; i++) {
        hashValue = hashValue * FNV_PRIME; // multiply the intial hashvalue by a prime number
        hashValue = hashValue ^ data[i]; // then xor the hashvalue with the ascii code (in binary) of the "i'th" character in the text being hashed
    }
    return hashValue;
}

template <class Object>
class Node {
private:
    Object object; // a generic object type
    Node* next; // allows us to chain entries of the hash table for collisions (glorified linked list)
    string key; // specify the key (key should be some attribute of the object)

public:
    Object getObject(void) {
        return object;
    }
    Node* getNext(void) {
        return next;
    }
    string getKey(void) {
        return key;
    }

    void setObject(Object obj) {
        object = obj;
    }
    void setNext(Node* n) {
        next = n;
    }
    void setKey(string k) {
        key = k;
    }

    Node(Object obj, string k) {
        object = obj;
        key = k;
        next = NULL;
    }
    ~Node() {

    }
};

template <class Object>
class Hash_Table {
private:
    Node<Object>** entries;
    hashfunction* hash_function;
    int size;

public:
    Hash_Table(hashfunction* hash_function, int size) {
        entries = new Node<Object>*[size];
        hash_function = hash_function;
        size = size;
    }

    Hash_Table(hashfunction* hash_function) {
        entries = new Node<Object>*[20];
        hash_function = hash_function;
        size = 20;
    }

    Hash_Table(int size) {
        entries = new Node<Object>*[size];
        hash_function = hash_fnv1_default;
        size = size;
    }

    Hash_Table() {
        entries = new Node<Object>*[20];
        hash_function = hash_fnv1_default;
        size = 20;
    }

    ~Hash_Table() {

    }

    hashfunction* getHashFunction();

    bool hash_insert(const string key, Object* object);
    Object* hash_delete(const string key);
    Node<Object>* hash_get_entry(const string key, int index);
    void printTable();
    


};

//#include "../../src/hash_table.cpp"

#endif