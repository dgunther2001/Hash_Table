#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;


typedef uint64_t hashfunction (const string);

#define FNV_PRIME 0x100000001b3
#define FNV_OFFSET 0xcbf29ce48422325UL // most optimal offset for collision managment and getting a hash value of 0
uint64_t hash_fnv1_default(string data) {
    uint64_t hashValue = FNV_OFFSET;
    int length = data.size();
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
    //Node<Object>** entries;
    hashfunction* hash_function;
    int size;

public:
    Node<Object>** entries; // MAKE THIS PRIVATE AGAIN

    Hash_Table(hashfunction* hf, int s) {
        entries = new Node<Object>*[s];
        hash_function = hf;
        size = s;
    }

    Hash_Table(hashfunction* hf) {
        entries = new Node<Object>*[20];
        hash_function = hf;
        size = 20;
    }

    Hash_Table(int s) {
        entries = new Node<Object>*[s];
        hash_function = hash_fnv1_default;
        size = s;
    }

    Hash_Table() {
        entries = new Node<Object>*[20];
        hash_function = hash_fnv1_default;
        size = 20;
    }

    ~Hash_Table() {

    }

    hashfunction* getHashFunction() {
        return hash_function;
    }

    int getSize() {
        return size;
    }

    bool hash_insert(string key, Object object) {
        int index = hash_function(key) % getSize();

        if (entries[index] == NULL) {
            Node<Object>* newNode = new Node<Object>(object, key);
            entries[index] = newNode;

            return true;
        } 

        // TODO => implement chaining
        else {
            return false;
        }

    }




    Object* hash_delete(const string key);
    Node<Object>* hash_get_entry(string key, int index);


    void printTable() { // IMPLEMENT CHAINED PRINTING
    
        
        for (int i = 0; i < getSize(); i++) {

            cout << i << ":\t -- \t";
            if (entries[i] != NULL) {
                /* TODO => IMPLEMENT PRINTING OF CONSECUTIVE CHAINING
                while(entries[i]->getNext() != NULL) {

                }
                */




                cout << entries[i]->getKey();
            } 
            cout << endl;
        }
        

    
        

    }


};

//#include "../../src/hash_table.cpp"

#endif