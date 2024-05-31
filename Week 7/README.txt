==========================================================================================
==========================================================================================

DESIGN:

Initialization - 
	Create an array with a specific, limited size and each element in the bucket like a linked list.

Hash funct - 
	Define hash function: hash(key) = sum of ASCII values of characters in key % size of table.

Insert(key, value):
	Insert pairs for keys and values into the bucket at a specific index/position.

Search(key):
	Get the position from the hash funct
	Search the bucket at the element's position for the key and return the value.
	If conditionals will be used to determine whether or not the element is in the bucket.

Delete(key):
	Search the bucket at the position, remove from bucket if found.
	If conditionals used to if it's there or not.


TESTING:

Search:

    Input: search("key1") (after insert("key1", "value1"))
    Output: Returns "value1"

Delete:

    Input: delete("key1") (after insert("key1", "value1"))
    Output: search("key1") returns None

Collision Handling:

    Input: insert("key1", "value1"), insert("key2", "value2") (assuming both keys hash to the same position which will require more testing)
    Output: search("key1") returns "value1", search("key2") returns "value2"

==========================================================================================
==========================================================================================

Simple Hash

hash funct:

int HashTable::hash(string value) {
    int result = 0;
    for (char c : value) {
        result += (int)c;
    }
    return result % capacity;
}

add funct


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


contains funct

bool HashTable::search(string value) {
    int bucket = hash(value);
    return storage[bucket] == value;
}


remove funct

bool HashTable::remove(string value) {
    int bucket = hash(value);
    if (storage[bucket] == value) {
        storage[bucket] = "";
        --size;
        return true;
    }
    return false;
}

==========================================================================================
==========================================================================================

Smarter Hashtable:

hash funct:

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

add funct:

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

contains funct: 

bool HashTableChaining::search(std::string value) {
    int bucket = hash(value);
    std::list<std::string>& chain = storage[bucket];
    
    return std::find(chain.begin(), chain.end(), value) != chain.end();
}


remove funct:

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

==========================================================================================
==========================================================================================

Comparison:

In a simple hash table, when collisions happen, it just overwrites the existing data, which can lead to data loss and slower performance as collisions pile up. On the other hand, a chaining hash table takes a smarter approach to collisions by storing multiple values in linked lists. This way, it keeps running smoothly even when there are more collisions. Tests show that chaining keeps insert and search operations efficient, while the simple hash table slows down a lot as collisions increase. So, chaining is definitely the better option for managing collisions without losing any data.

==========================================================================================
==========================================================================================

Inputs/Outputs:

Inputs:

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


Outputs:

Running tests for Simple Hash Table...
Initial size: 0 (expected: 0)
Initial collision count: 0 (expected: 0)
After adding 'Joseph': size: 1 (expected: 1)
Collision count: 0 (expected: 0)
After adding 'Josepi': size: 2 (expected: 2)
Collision count: 0 (expected: 0)
After adding 'cats': size: 3 (expected: 3)
Collision count: 1 (expected: 1)
Search 'Joseph': 0 (expected: 1)
Search 'nonexistent': 0 (expected: 0)
After removing 'cats': size: 2 (expected: 2)
Search 'cats': 0 (expected: 0)
Running tests for Chaining Hash Table...
Initial size: 0 (expected: 0)
Initial collision count: 0 (expected: 0)
After adding 'Joseph': size: 1 (expected: 1)
Collision count: 0 (expected: 0)
After adding 'Josepi': size: 2 (expected: 2)
Collision count: 0 (expected: 0)
After adding 'cats': size: 3 (expected: 3)
Collision count: 1 (expected: 0)
After adding 'cat': size: 4 (expected: 4)
Collision count: 1 (expected: 1)
Search 'Joseph': 1 (expected: 1)
Search 'nonexistent': 0 (expected: 0)
After removing 'cats': size: 3 (expected: 3)
Search 'cats': 0 (expected: 0)