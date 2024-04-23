#include "hash_table.h"

using namespace std;

template <typename Object>
class Node {
    
    Node(Object* object, char* key) {
        this.object = object;
        this.key = key;
        this.next = NULL;
    };
};

template <typename Object>
class Hash_Table {

    Hash_Table(hashfunction* hash_function, int size) {
        this.entries = new Node*[size];
        this.hash_function = hash_function;
        this.size = size;
    }

    Hash_Table(hashfunction* hash_function) {
        this.entries = new Node*[20];
        this.hash_function = hash_function;
        this.size = 20;
    }

    Hash_Table(int size) {
        this.entries = new Node*[size];
        this.hash_function = hash_fnv1;
        this.size = size;
    }

    Hash_Table() {
        this.entries = new Node*[20];
        this.hash_function = hash_fnv1;
        this.size = 20;
    }


    bool hash_insert(const char* key, Object* object) {

    }

    Object* hash_delete(const char* key) {

    }

    Node<Object>* hash_get_entry(const char* key, int index) {

    }
};


