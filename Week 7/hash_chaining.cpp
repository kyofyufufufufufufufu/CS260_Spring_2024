#include "hash_chaining.hpp"
#include <algorithm>

HashTableChaining::HashTableChaining(int initialCapacity) {
    capacity = initialCapacity;
    storage = new std::list<std::string>[capacity];
}

int HashTableChaining::hash(std::string value) {
    int result = 0;
    for (char c : value) {
        result += (int)c;
    }
    return result % capacity;
}

void HashTableChaining::add(std::string value) {
    int bucket = hash(value);
    std::list<std::string>& chain = storage[bucket];
    
    //checking for collision and increment conditional
    if (!chain.empty() && std::find(chain.begin(), chain.end(), value) == chain.end()) {
        ++collisionCount;
    }
    
    //adding value to bucket chain
    if (std::find(chain.begin(), chain.end(), value) == chain.end()) {
        chain.push_back(value);
        ++size;
    }
}

bool HashTableChaining::remove(std::string value) {
    int bucket = hash(value);
    std::list<std::string>& chain = storage[bucket];
    
    auto it = std::find(chain.begin(), chain.end(), value);
    if (it != chain.end()) {
        chain.erase(it);
        --size;
        return true;
    }
    return false;
}

bool HashTableChaining::search(std::string value) {
    int bucket = hash(value);
    std::list<std::string>& chain = storage[bucket];
    
    return std::find(chain.begin(), chain.end(), value) != chain.end();
}

std::string HashTableChaining::toString() {
    std::stringstream result;
    for (int i = 0; i < capacity; ++i) {
        result << "[" << i << "]: ";
        for (const auto& str : storage[i]) {
            result << str << " -> ";
        }
        result << "NULL\n";
    }
    return result.str();
}

int HashTableChaining::getSize() {
    return size;
}

int HashTableChaining::getCollisionCount() {
    return collisionCount;
}
