#include <iostream>
#include "queue.hpp"

using std::cout;
using std::endl;


void Queue::enQueue(int new_value){
    Node* newNode = new Node();
    newNode->value = new_value;
    newNode->next = nullptr;
    
    //conditionals if queue empty
    if (head == nullptr) {
        head = end = newNode;
    } else {
        //link new node and update the end of the queue
        end->next = newNode;
        end = newNode;
    }
}

void Queue::deQueue(){
    if (head == nullptr){
        cout << "Queue is empty." << endl;
        return;
    }
    Node *temp = head;//establishing head value that will be deleted from head of queue
    head = head->next;
    delete temp;
    if (head == nullptr){
        end = nullptr;
    }
}

void Queue::peekQueue(){
    if (head==nullptr){
        cout << "Queue is empty." << endl;
        return;
    }
    //display queue
    cout << "Queue: ";
    Node *current = head;
    while (current != nullptr){
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}
