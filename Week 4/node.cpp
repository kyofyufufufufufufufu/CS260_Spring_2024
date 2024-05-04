#include "node.hpp"

Node::Node() {
    this->id = 0;
    this->value = 0;
    this->next = nullptr;
}

string Node::to_string() {
    string result = "id: " + std::to_string(this->id) + 
        ", value: " + std::to_string(this->value) + ", next " 
        + std::to_string((long long)this->next);
    return result;
}
