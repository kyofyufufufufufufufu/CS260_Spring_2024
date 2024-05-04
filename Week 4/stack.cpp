#include "stack.hpp"
#include <iostream>

Stack::Stack() {
    top = nullptr;
    size = 0;
}

Stack::~Stack() {
    while (top != nullptr) {
        Node *temp = top;
        top = top->next;
        delete temp;
    }
}

Stack::Stack(const Stack& other) {
    top = nullptr;
    size = 0;
    Node *current = other.top;
    while (current != nullptr) {
        push(current->value);
        current = current->next;
    }
}

int Stack::pop() {
    if (top != nullptr) {
        int old_top_value = top->value;
        Node *old_top = top;
        top = top->next;
        size--;
        delete old_top;
        return old_top_value;
    } else {
        throw runtime_error("Empty stack.");
    }
}

void Stack::push(int new_value) {
    Node *new_node = new Node();
    new_node->id = size;
    size++;
    new_node->value = new_value;
    new_node->next = top;
    top = new_node;
}

int Stack::get_size() {
    return size;
}

void Stack::add(int value, int position) {
    if (position < 0 || position > size) {
        throw runtime_error("Invalid position.");
    }
    if (position == 0) {
        Node *new_node = new Node();
        new_node->value = value;
        new_node->next = top;
        top = new_node;
        size++;
        return;
    }
    Node *current = top;
    for (int i = 0; i < position - 1; ++i) {
        current = current->next;
    }
    Node *new_node = new Node();
    new_node->value = value;
    new_node->next = current->next;
    current->next = new_node;
    size++;
}

int Stack::remove(int position) {
    if (position < 0 || position >= size) {
        throw runtime_error("Invalid position.");
    }
    int removed_value;
    if (position == 0) {
        Node *temp = top;
        top = top->next;
        removed_value = temp->value;
        delete temp;
    } else {
        Node *current = top;
        for (int i = 0; i < position - 1; ++i) {
            current = current->next;
        }
        Node *temp = current->next;
        current->next = temp->next;
        removed_value = temp->value;
        delete temp;
    }
    size--;
    return removed_value;
}

int Stack::get(int position) {
    if (position < 0 || position >= size) {
        throw runtime_error("Invalid position.");
    }
    Node *current = top;
    for (int i = 0; i < position; ++i) {
        current = current->next;
    }
    return current->value;
}

void Stack::printStack() const {
    Node* current = top;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}