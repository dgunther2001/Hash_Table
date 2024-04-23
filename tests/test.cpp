#include <hash_table/hash_table.h>

using namespace std;


int main() {

    Node<int> newNode(75, "hello");
    string l = newNode.getKey();
    int m = newNode.getObject();
    cout << l << endl;
    cout << m << endl;



    //Hash_Table<int> myTable;

    //hashfunction* myhash = myTable.getHashFunction();


    return 0;
}