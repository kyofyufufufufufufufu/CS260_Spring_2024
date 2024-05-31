#include <iostream>
#include "hash_chaining.hpp"

using std::cout;
using std::endl;

int main() {
    HashTableChaining ht(10);
    cout << "Create table." << endl;
    cout << "table contents (empty table): " << ht.toString() << endl;
    cout << "size of empty table: " << ht.getSize() << endl;

    ht.add("Joseph");
    cout << "Add Joseph." << endl;
    cout << "table contents (one entry): " << ht.toString() << endl;
    cout << "size of table after 1 add: " << ht.getSize() << endl;
    cout << "collision count: " << ht.getCollisionCount() << endl;

    ht.add("Josepi");
    cout << "Add Josepi." << endl;
    cout << "table contents (non-collision second entry): " << ht.toString() << endl;
    cout << "size of table after 2 add (non-collision): " << ht.getSize() << endl;
    cout << "collision count: " << ht.getCollisionCount() << endl;

    ht.add("cats");
    cout << "Add cats." << endl;
    cout << "table contents (collision third entry): " << ht.toString() << endl;
    cout << "size of table after 3 add (1 collision): " << ht.getSize() << endl;
    cout << "collision count: " << ht.getCollisionCount() << endl;

    ht.remove("cats");
    cout << "Remove cats." << endl;
    cout << "table contents (remove cats): " << ht.toString() << endl;
    cout << "size of table after 3 add and one remove (1 collision): " << ht.getSize() << endl;
    cout << "collision count: " << ht.getCollisionCount() << endl;

    return 0;
}
