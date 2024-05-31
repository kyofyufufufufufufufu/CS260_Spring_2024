#include <sstream>
#include "hash.hpp"

using std::stringstream;

HashTable::HashTable(int initialCapacity) {
    capacity = initialCapacity;
    size = 0;
    collisionCount = 0;

    storage = new string[capacity];
    for (int i = 0; i < capacity; ++i) {
        storage[i] = "";
    }
}

int HashTable::hash(string value) {
    int result = 0;
    for (char c : value) {
        result += (int)c;
    }
    return result % capacity;
}

int HashTable::add(string value) {
    int bucket = hash(value);

    if (size >= capacity * 0.7) {
        resize();
        bucket = hash(value);
    }
    //for collisions
    if (storage[bucket] != "" && storage[bucket] != value) {
        ++collisionCount;
    }

    //adds value to the appropriate bucket
    storage[bucket] = value;
    ++size;
    return bucket;
}

bool HashTable::remove(string value) {
    int bucket = hash(value);
    if (storage[bucket] == value) {
        storage[bucket] = "";
        --size;
        return true;
    }
    return false;
}

bool HashTable::search(string value) {
    int bucket = hash(value);
    return storage[bucket] == value;
}

bool HashTable::resize() {
    int newCapacity = capacity * 2;

    string* newStorage = new string[newCapacity];
    for (int i = 0; i < newCapacity; ++i) {
        newStorage[i] = "";
    }

    //rehashes all existing elements into the new array
    for (int i = 0; i < capacity; ++i) {
        if (storage[i] != "") {
            int newBucket = hash(storage[i]) % newCapacity;
            newStorage[newBucket] = storage[i];
        }
    }

    //deletes old storage
    delete[] storage;

    //updates with new array and capacity
    storage = newStorage;
    capacity = newCapacity;

    return true;
}

string HashTable::toString() {
    stringstream result;
    for (int i = 0; i < capacity; ++i) {
        result << storage[i] << ", ";
    }
    return result.str();
}

int HashTable::getSize() {
    return size;
}

int HashTable::getCollisionCount() {
    return collisionCount;
}
