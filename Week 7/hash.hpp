#include <string>

using std::string;

class HashTable {
/*
creates a key (hash funct) adds up the ASCII values of the characters in 
the key (add funct) and then takes the modulus (%) and the table's size 
(getSize, get CollisionCount)
*/
public:
    HashTable(int initialCapacity);
    int hash(string key);
    int add(string key);
    bool remove(string key);
    bool search(string key);

    string toString();
    int getSize();
    int getCollisionCount();

private:
    int capacity;
    int size;
    int collisionCount;

    string *storage;
    bool resize();
};