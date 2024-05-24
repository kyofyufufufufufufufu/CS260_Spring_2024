Design (transcribed from notes from a physical notebook):

			-Binary Search Tree-
			 Node Class: Value
			/		  \
		     left		  right

	Binary Search Tree (class)
	  -pointer to the 'head' node
	
	Insert Funct
	  -adding value to tree
		    |
		    v
	  -find correct position and insert
	*if empty conditionals

	Remove Funct
	 -Removes value from tree
		    |
		    v
	 -Node has more than 1 in the branch?
		    |
		    v
	 -Replaces 'head' node with second node in order and reorders any other children nodes

	In-Order Traverse Funct
	 -Is what makes it determine left and right order


Tests:

void test_add() {
    BST tree;
    tree.add(5);
    tree.add(3);
    tree.add(7);

    std::vector<int> expected = {3, 5, 7};
    assert(tree.inOrderTraversal() == expected);
}

void test_remove() {
    BST tree;
    tree.add(5);
    tree.add(3);
    tree.add(7);
    tree.remove(3);

    std::vector<int> expected = {5, 7};
    assert(tree.inOrderTraversal() == expected);
}

void test_search() {
    BST tree;
    tree.add(5);
    tree.add(3);
    tree.add(7);

    assert(tree.search(3) == true);
    assert(tree.search(10) == false);
}

void test_inOrderTraversal() {
    BST tree;
    tree.add(5);
    tree.add(3);
    tree.add(7);
    tree.add(2);
    tree.add(4);
    tree.add(6);
    tree.add(8);

    std::vector<int> expected = {2, 3, 4, 5, 6, 7, 8};
    assert(tree.inOrderTraversal() == expected);
}


node with in-line constructor

#pragma once

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

add function and helper that reorders other values:

void BST::add(int data) {
    if (root == nullptr) {
        root = new Node(data);
    } else {
        addHelper(root, data);
    }
}

void BST::addHelper(Node *node, int data) {
    if (data <= node->data) {
        if (node->left == nullptr) {
            node->left = new Node(data);
        } else {
            addHelper(node->left, data);
        }
    } else {
        if (node->right == nullptr) {
            node->right = new Node(data);
        } else {
            addHelper(node->right, data);
        }
    }
}

remove function and helper

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

In-Order Traversal

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

=========================================================================================
=========================================================================================

Analysis:

 In a well-organized binary search tree, adding or finding items is usually quick, averaging a much smaller scale of steps, but if the tree becomes unbalanced, it can become as slow as in an unordered binary tree, where it may take many more steps in comparison to insert or search for an item. So a small BST would be faster than a small unorder BST. But a large BST may take the same amount of time as an unordered BST.

=========================================================================================
=========================================================================================



Input for testing:

int main() {
    test_add();
    test_remove();
    test_search();
    test_inOrderTraversal();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}


Output for testing:

PS C:\Users\catbr\OneDrive\Documents\CS 260\Week 6> .\main  
All tests passed!


Input for main:

int main() {
    BST tree;
    tree.add(5);
    tree.add(3);
    tree.add(7);
    tree.add(2);
    tree.add(4);
    tree.add(6);
    tree.add(8);

    std::vector<int> traversal = tree.inOrderTraversal();
    for (int value : traversal) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    tree.remove(3);
    traversal = tree.inOrderTraversal();
    for (int value : traversal) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}



Output for main:

2 3 4 5 6 7 8 
2 4 5 6 7 8
		