#pragma once

#include <vector>
#include "node.h"

class BST {
    private:
        Node *root;
        //helper functions that move values in the tree and reorder
        void addHelper(Node *node, int data);
        Node *removeHelper(Node *node, int data);
        int minValue(Node *node);
        bool searchHelper(Node *node, int data);
        void inOrderHelper(Node *node, std::vector<int>& result);

    public:
        BST(); //dconstructor
        void add(int data);
        void remove(int data);
        bool search(int data);
        std::vector<int> inOrderTraversal();
};
