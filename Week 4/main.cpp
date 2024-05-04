#include "stack.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main() {
    Stack test_stack;

    test_stack.push(1);
    test_stack.push(2);
    test_stack.push(3);
    test_stack.push(4);

    cout << "test_stack: ";
    test_stack.printStack();

    //remove test

    test_stack.remove(3);

    cout << "test_stack: ";
    test_stack.printStack();

    //testing add function

    test_stack.add(2, 1);
    cout << "After adding 2 at position 1: ";
    for (int i = 0; i < test_stack.get_size(); ++i) {
        cout << test_stack.get(i) << " ";
    }
    cout << endl;

    return 0;
}
