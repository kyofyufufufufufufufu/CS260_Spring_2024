#include <iostream>
#include <cassert>
#include "BST.h"

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

int main() {
    test_add();
    test_remove();
    test_search();
    test_inOrderTraversal();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
