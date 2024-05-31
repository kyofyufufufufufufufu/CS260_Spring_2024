#ifndef HASH_CHAINING_HPP
#define HASH_CHAINING_HPP

#include <string>
#include <list>
#include <sstream>

class HashTableChaining {
public:
    HashTableChaining(int initialCapacity);
    int hash(std::string key);
    void add(std::string key);
    bool remove(std::string key);
    bool search(std::string key);

    std::string toString();
    int getSize();
    int getCollisionCount();

private:
    int capacity = 10;
    int size = 0;
    int collisionCount = 0;

    std::list<std::string>* storage = nullptr;
};

#endif // HASH_CHAINING_HPP
