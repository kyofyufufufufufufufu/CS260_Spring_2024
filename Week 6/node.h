#pragma once

//constructor-node definition
struct Node {
    int data;
    Node *left; //shortcut keys ctrl+shift+leftarrow
    Node *right; //shortcut keys end+shift+home keys
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};