//add function

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

//remove function
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

//get and print function

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

//tests

input:

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

output:
test_stack: 4 3 2 1 
test_stack: 4 3 2
After adding 2 at position 1: 4 2 3 2
