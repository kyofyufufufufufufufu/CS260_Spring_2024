#include <iostream>
#include "hash.hpp"
#include "hash_chaining.hpp"

using std::cout;
using std::endl;

void runSimpleHashTableTests() {
    HashTable ht(10);
    cout << "Running tests for Simple Hash Table..." << endl;

    cout << "Initial size: " << ht.getSize() << " (expected: 0)" << endl;
    cout << "Initial collision count: " << ht.getCollisionCount() << " (expected: 0)" << endl;

    //add
    ht.add("Joseph");
    cout << "After adding 'Joseph': size: " << ht.getSize() << " (expected: 1)" << endl;
    cout << "Collision count: " << ht.getCollisionCount() << " (expected: 0)" << endl;

    ht.add("Josepi");
    cout << "After adding 'Josepi': size: " << ht.getSize() << " (expected: 2)" << endl;
    cout << "Collision count: " << ht.getCollisionCount() << " (expected: 0)" << endl;

    ht.add("cats");
    cout << "After adding 'cats': size: " << ht.getSize() << " (expected: 3)" << endl;
    cout << "Collision count: " << ht.getCollisionCount() << " (expected: 1)" << endl;

    //search
    cout << "Search 'Joseph': " << ht.search("Joseph") << " (expected: 1)" << endl;
    cout << "Search 'nonexistent': " << ht.search("nonexistent") << " (expected: 0)" << endl;

    //remove
    ht.remove("cats");
    cout << "After removing 'cats': size: " << ht.getSize() << " (expected: 2)" << endl;
    cout << "Search 'cats': " << ht.search("cats") << " (expected: 0)" << endl;
}

void runChainingHashTableTests() {
    HashTableChaining ht(10);
    cout << "Running tests for Chaining Hash Table..." << endl;

    cout << "Initial size: " << ht.getSize() << " (expected: 0)" << endl;
    cout << "Initial collision count: " << ht.getCollisionCount() << " (expected: 0)" << endl;

    //add
    ht.add("Joseph");
    cout << "After adding 'Joseph': size: " << ht.getSize() << " (expected: 1)" << endl;
    cout << "Collision count: " << ht.getCollisionCount() << " (expected: 0)" << endl;

    ht.add("Josepi");
    cout << "After adding 'Josepi': size: " << ht.getSize() << " (expected: 2)" << endl;
    cout << "Collision count: " << ht.getCollisionCount() << " (expected: 0)" << endl;

    ht.add("cats");
    cout << "After adding 'cats': size: " << ht.getSize() << " (expected: 3)" << endl;
    cout << "Collision count: " << ht.getCollisionCount() << " (expected: 0)" << endl;

    //adding value to cause ocllision
    ht.add("cat");
    cout << "After adding 'cat': size: " << ht.getSize() << " (expected: 4)" << endl;
    cout << "Collision count: " << ht.getCollisionCount() << " (expected: 1)" << endl;

    //search
    cout << "Search 'Joseph': " << ht.search("Joseph") << " (expected: 1)" << endl;
    cout << "Search 'nonexistent': " << ht.search("nonexistent") << " (expected: 0)" << endl;

    //remove
    ht.remove("cats");
    cout << "After removing 'cats': size: " << ht.getSize() << " (expected: 3)" << endl;
    cout << "Search 'cats': " << ht.search("cats") << " (expected: 0)" << endl;
}

int main() {
    runSimpleHashTableTests();
    runChainingHashTableTests();
    return 0;
}
