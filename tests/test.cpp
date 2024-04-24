#include <hash_table/hash_table.h>
#include <iostream>
#include <string>

using namespace std;

class students {
private: 
    std::string name;
    int age;

public:
    students(std::string n, int a) {
        name = n;
        age = a;
    }

    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    
    
    bool operator==(const students& otherStudent) const {
        return (name == otherStudent.name && age == otherStudent.age);
    }
    
    

    bool operator!=(const students& otherStudent) const {
        return (name != otherStudent.name || age != otherStudent.age);
    }

    
    friend ostream& operator<< (ostream& os, const students& s)
    {
        os << s.name << ": " << s.age;
        return os;
    }
    
    
    

};


int main() {
    
    Hash_Table<students> myTable1;

    students* student1 = new students("Daniel", 23);
    students* student2 = new students("Hannah", 22);
    students* student3 = new students("Zach", 23);

    myTable1.hash_insert(student1->getName(), student1);
    myTable1.hash_insert(student2->getName(), student2);
    myTable1.hash_insert(student3->getName(), student3);
    
    students* test = myTable1.hash_get_entry("Daniel")->getObject();

    /*
    Node<int> newNode(75, "hello");
    string l = newNode.getKey();
    int m = newNode.getObject();
    cout << l << endl;
    cout << m << endl;
    */

    myTable1.printTable();

    cout << "\n";

    myTable1.hash_delete("Daniel");

    myTable1.printTable();

    cout << "\n";

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

    myTable.printTable();

    myTable.hash_delete("Paul");

    cout << "\n";
    
    myTable.printTable();

    int textval = myTable.hash_get_entry("Connor")->getObject();

    cout << "\n";

    cout << test->getName() << "\n";
    cout << textval << "\n";

    cout << "\n";

    cout << myTable1.hashContains("Hannah") << "\n";
    cout << myTable1.hashContains("George") << "\n";
    cout << myTable.hashContains("Janie") << "\n";
    cout << myTable1.hashContains("Johnny") << "\n";
    




    //

    //cout << myTable.entries[2]->getKey() << endl;
    //cout << myTable.entries[9]->getKey() << endl;
    /*
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
    */
    

    //cout << correct << endl;

    
    //hashfunction* myhash = myTable.getHashFunction();

    //cout << myhash("hi") % 20 << endl;
    //cout << myhash("Daniel") % 20 << endl;
    //cout << myhash("JJ") % 20 << endl;

    

    return 0;
}