#include <iostream>
#include <sstream>
#include <string>
#include "autosort_list.h"
#include "node.h"

using std::cout;
using std::endl;
using std::string;

list::list() {
    head = nullptr;
}

void list::insert(int data) {
    node *new_node = new node;
    new_node->data = data;
    new_node->next = nullptr;

    if (head == nullptr || data < head->data) {
        new_node->next = head;
        head = new_node;
    } else {
        node *current = head;
        while (current->next != nullptr && current->next->data < data) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

bool list::search(int data) {
    node *current = head;
    while (current != nullptr) {
        if (current->data == data) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void list::remove(int data) {
    if (head == nullptr) {
        return;
    }

    //reordering head to next value and deleting temp
    if (head->data == data) {
        node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    node *current = head;
    while (current->next != nullptr && current->next->data != data) {
        current = current->next;
    }

    if (current->next == nullptr) {
        return;
    }

    //reordering list when deleting temp 
    node *temp = current->next;
    current->next = current->next->next;
    delete temp;
}

string list::to_string() {
    std::stringstream result_string_stream;
    if (head == nullptr) {
        result_string_stream << "[empty list]";
    } else {
        node *current = head;
        result_string_stream << "[";
        while (current != nullptr) {
            result_string_stream << current->data;
            if (current->next != nullptr) {
                result_string_stream << ", ";
            }
            current = current->next;
        }
        result_string_stream << "]";
    }

    return result_string_stream.str();
}
