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



    Hash_Table<int> myTable(10);

    myTable.hash_insert("Hannah", 22);
    myTable.hash_insert("Daniel", 23);
    myTable.hash_insert("Josh", 24);
    myTable.hash_insert("Zach", 25);
    myTable.hash_insert("Deb", 37);
    myTable.hash_insert("Lew", 66);
    myTable.hash_insert("Joey", 33);
    myTable.hash_insert("Lars", 25);
    myTable.hash_insert("Donna", 11);
    myTable.hash_insert("Heather", 2345);
    myTable.hash_insert("Bill", 22345);
    myTable.hash_insert("Elon", 2675);
    myTable.hash_insert("Janie", 28655);
    myTable.hash_insert("Connor", 2546);
    myTable.hash_insert("Conner", 2345653);
    myTable.hash_insert("Michael", 978574);
    myTable.hash_insert("Charlie", 76654567);
    myTable.hash_insert("Paul", 6547355);

    //

    //cout << myTable.entries[16]->getKey() << endl;
    //cout << myTable.entries[9]->getKey() << endl;

    myTable.printTable();

    cout << "\n";

    myTable.hash_delete("Michael");
    myTable.hash_delete("Joey");
    myTable.hash_delete("Lew");
    myTable.hash_delete("Hannah");
    myTable.hash_delete("Janie");
    int i = myTable.hash_delete("Josh");
    myTable.hash_delete("Jimmy");

    //cout << i << endl;


    myTable.printTable();


    cout << endl;

    Node<int>* myNode = myTable.hash_get_entry("Paul");
    cout << myNode->getKey() << ": " <<  myNode->getObject() << endl;

    //cout << correct << endl;

    
    //hashfunction* myhash = myTable.getHashFunction();

    //cout << myhash("hi") % 20 << endl;
    //cout << myhash("Daniel") % 20 << endl;
    //cout << myhash("JJ") % 20 << endl;

    

    return 0;
}