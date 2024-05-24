#include "BST.h"
#include "node.h"

BST::BST(){
    root=nullptr;
}

void BST::add(int data) {
    if (root == nullptr) {
        root = new Node(data);
    } else {
        addHelper(root, data); //use helper to add node to tree
    }
}

void BST::addHelper(Node *node, int data) {
    if (data <= node->data) {
        if (node->left == nullptr) {
            node->left = new Node(data); //adding node to left
        } else {
            addHelper(node->left, data);
        }
    } else {
        if (node->right == nullptr) {
            node->right = new Node(data); //adding node to right
        } else {
            addHelper(node->right, data);
        }
    }
}

void BST::remove(int data) {
    root = removeHelper(root, data);
}

Node *BST::removeHelper(Node *node, int data) {
    if (node == nullptr) {
        return node;
    }
    if (data < node->data) {
        node->left = removeHelper(node->left, data);
    } else if (data > node->data) {
        node->right = removeHelper(node->right, data);
    } else {
        if (node->left == nullptr) {
            Node *temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node *temp = node->left;
            delete node;
            return temp;
        }
        node->data = minValue(node->right);
        node->right = removeHelper(node->right, node->data);
    }
    return node;
}

int BST::minValue(Node *node) {
    Node *current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current->data;
}

bool BST::search(int data) {
    return searchHelper(root, data);
}

bool BST::searchHelper(Node *node, int data) {
    if (node == nullptr) {
        return false;
    }
    if (node->data == data) {
        return true;
    } else if (data < node->data) {
        return searchHelper(node->left, data);
    } else {
        return searchHelper(node->right, data);
    }
}

std::vector<int> BST::inOrderTraversal() {
    std::vector<int> result;
    inOrderHelper(root, result);
    return result;
}

void BST::inOrderHelper(Node *node, std::vector<int>& result) {
    if (node != nullptr) {
        inOrderHelper(node->left, result);
        result.push_back(node->data);
        inOrderHelper(node->right, result);
    }
}
