#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <cstdlib>
#include <string>
#include <iostream>
#include <optional>

typedef uint64_t hashfunction (const std::string);

#define FNV_PRIME 0x100000001b3
#define FNV_OFFSET 0xcbf29ce48422325UL // most optimal offset for collision managment and getting a hash value of 0
uint64_t hash_fnv1_default(std::string data) {
    uint64_t hashValue = FNV_OFFSET;
    int length = data.size();
    for (int i = 0; i < length; i++) {
        hashValue = hashValue * FNV_PRIME; // multiply the intial hashvalue by a prime number
        hashValue = hashValue ^ data[i]; // then xor the hashvalue with the ascii code (in binary) of the "i'th" character in the text being hashed
    }
    return hashValue;
}

template <typename Object>
class Node {
private:
    Object object; // a generic object type
    Node* next; // allows us to chain entries of the hash table for collisions (glorified linked list)
    std::string key; // specify the key (key should be some attribute of the object)

public:
    Object getObject(void) {
        return object;
    }
    Node* getNext(void) {
        return next;
    }
    std::string getKey(void) {
        return key;
    }

    void setObject(Object obj) {
        object = obj;
    }
    void setNext(Node* n) {
        next = n;
    }
    void setKey(std::string k) {
        key = k;
    }

    Node(Object obj, std::string k) {
        object = obj;
        key = k;
        next = NULL;
    }
    ~Node() {

    }
};

template <typename Object>
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

    bool hash_insert(std::string key, Object object) {
        int index = hash_function(key) % getSize();

        if (entries[index] == NULL) {
            Node<Object>* newNode = new Node<Object>(object, key);
            entries[index] = newNode;

            return true;
        } 

        else {
            Node<Object>* newNode = new Node<Object>(object, key);
            Node<Object>* nextNode = entries[index];

            newNode->setNext(nextNode);
            entries[index] = newNode;

            return true;
        }

    }

    Object hash_delete(std::string key) {
        int index = hash_function(key) % getSize();

        Node<Object>* currentNode = entries[index];
        Node<Object>* previousNode = NULL;

        if (currentNode == NULL) {
            return Object();
        }

        while (currentNode != NULL && currentNode->getKey() != key) {
            previousNode = currentNode;
            currentNode = currentNode->getNext();
        }


        if (currentNode == NULL) {
            return Object();
        }

        if (previousNode == NULL) { // IF WE ARE AT THE HEAD OF THE LIST
            if (currentNode->getNext() != NULL) {
                Node<Object>* nextNode = currentNode->getNext();
                entries[index] = nextNode;
                return currentNode->getObject();
            } else {
                entries[index] = NULL;
                return currentNode->getObject();
            }
        } else { // OTHERISE, PREVIOUS NDOE EXISTS
            if (currentNode->getNext() == NULL) { // IF THE CURRENT NODE IS THE LAST ELEMENT OF THE LINKED LIST
                previousNode->setNext(NULL);
                return currentNode->getObject();
            }
            else { // IF THE CURRENT NODE IS IN THE MIDDLE OF THE LINKED LIST
                Node<Object>* nextNode = currentNode->getNext();
                previousNode->setNext(nextNode);
                return currentNode->getObject();
            }
        }



    } 


    void printTable() { 
    
        Node<Object>* newNode;
        for (int i = 0; i < getSize(); i++) {
            newNode = entries[i];

            std::cout << i << "\t|\t";
            if (newNode != NULL) {
                while(newNode != NULL) {
                    std::cout << newNode->getKey();

                    if (newNode->getNext() != NULL) {
                        std::cout << "\t -- \t";
                    }
                    newNode = newNode->getNext();
                }
            } 
            std::cout << "\n";
        }

    }

    Node<Object>* hash_get_entry(std::string key) {
        int index = hash_function(key) % getSize();
        Node<Object>* currentNode = entries[index];
        Node<Object>* previousNode = NULL;

        while (currentNode != NULL && currentNode->getKey() != key) {
            previousNode = currentNode;
            currentNode = currentNode->getNext();
        }

        if (currentNode == NULL) {
            return NULL;
        } else {
            return currentNode;
        }
    }
    

};

#endif