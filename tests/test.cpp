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
    myTable.hash_insert("Josh", 23);
    myTable.hash_insert("Zach", 23);
    myTable.hash_insert("Deb", 23);
    myTable.hash_insert("Lew", 23);
    myTable.hash_insert("Joey", 23);
    myTable.hash_insert("Lars", 23);
    myTable.hash_insert("Donna", 23);
    myTable.hash_insert("Heather", 23);
    myTable.hash_insert("Bill", 23);
    myTable.hash_insert("Elon", 23);
    myTable.hash_insert("Janie", 23);
    myTable.hash_insert("Connor", 23);
    myTable.hash_insert("Conner", 23);
    myTable.hash_insert("Michael", 23);
    myTable.hash_insert("Charlie", 23);
    myTable.hash_insert("Paul", 23);

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

    //cout << correct << endl;

    
    //hashfunction* myhash = myTable.getHashFunction();

    //cout << myhash("hi") % 20 << endl;
    //cout << myhash("Daniel") % 20 << endl;
    //cout << myhash("JJ") % 20 << endl;

    

    return 0;
}