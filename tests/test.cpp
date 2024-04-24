#include <hash_table/hash_table.h>

using namespace std;


int main() {

    /*
    Node<int> newNode(75, "hello");
    string l = newNode.getKey();
    int m = newNode.getObject();
    cout << l << endl;
    cout << m << endl;
    */



    Hash_Table<int> myTable;

    myTable.hash_insert("Hannah", 22);
    myTable.hash_insert("Daniel", 23);
    //

    //cout << myTable.entries[16]->getKey() << endl;
    //cout << myTable.entries[9]->getKey() << endl;

    myTable.printTable();

    //cout << correct << endl;

    
    //hashfunction* myhash = myTable.getHashFunction();

    //cout << myhash("hi") % 20 << endl;
    //cout << myhash("Daniel") % 20 << endl;
    //cout << myhash("JJ") % 20 << endl;

    

    return 0;
}