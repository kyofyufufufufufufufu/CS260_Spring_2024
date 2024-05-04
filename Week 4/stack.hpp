#pragma once

#include "node.hpp"
#include <stdexcept>

using std::runtime_error;

class Stack {
    Node *top;
    int size;

//all public methods used for Stack class
public:
    Stack();
    ~Stack(); //destructor
    Stack(const Stack& other); //copy constructor
    int pop(); //pop element off of stack
    void push(int new_value); //push an element onto the stack
    int get_size(); //get size of stack
    void add(int value, int position); //add element onto stack to a specific position
    int remove(int position); //remove an element at a specific position on the stack
    int get(int position); //gets position inside the stack
    void printStack() const; //prints stack
};
