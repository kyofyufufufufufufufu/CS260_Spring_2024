Testing in test_autosort.cpp

int main() {
    test_autosort_list_constructor();
    test_autosort_list_insert_first_node();
    test_autosort_list_insert_second_node();
    test_autosort_list_insert_node_after_end();
    test_autosort_list_insert_node_with_same_value_as_head();
    test_autosort_list_insert_node_before_head();
    test_autosort_list_insert_node_in_middle_of_list();
    test_autosort_list_search();
    test_autosort_list_remove_head();
    test_autosort_list_remove_middle_node();
    test_autosort_list_remove_nonexistent_node();

    cout << "All tests passed!" << endl;

    return 0;
}

Testing results:

INPUT:
g++ .\test_autosort.cpp .\autosort_list.cpp -o testing.exe
OUTPUT:
All tests passed!

Insert function:

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

Search Function:

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

Remove Function:

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

INPUT:
int main() {
    list my_list;

    my_list.insert(3);
    my_list.insert(1);
    my_list.insert(2);

    std::cout << my_list.to_string() << std::endl;

    if (my_list.search(2)) {
        std::cout << "Found 2 in the list." << std::endl;
    } else {
        std::cout << "2 is not in the list." << std::endl;
    }

    my_list.remove(2);
    std::cout << my_list.to_string() << std::endl;

    return 0;
}

OUTPUT:
[1, 2, 3]
Found 2 in the list.
[1, 3]


CHART:

Operation	Array-Based List	Linked List
Insert	              O(n)	           O(n)
Search	      O(log n) truthy/falsy        O(n)
Remove	              O(n)	           O(n)