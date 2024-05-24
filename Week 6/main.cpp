#include <iostream>
#include "BST.h"

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
