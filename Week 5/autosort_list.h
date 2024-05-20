#pragma once

#include <string>
#include "node.h"

class list {
private:
    node *head;

public:
    list();
    void insert(int data); //inserts value into the list
    bool search(int data); //searches list for value
    void remove(int data); //removes value from list
    std::string to_string();
};
