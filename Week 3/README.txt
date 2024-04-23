Requirements for Week 3 Assignment:

Enqueue:

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


Dequeue:

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


Peek:

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


Testing:

input

    Queue new_queue;

    //checking values through testing

    new_queue.peekQueue();

    new_queue.enQueue(1);
    new_queue.enQueue(2);
    new_queue.enQueue(3);
    new_queue.enQueue(4);

    new_queue.peekQueue();
    new_queue.deQueue();
    new_queue.peekQueue();
    new_queue.deQueue();
    new_queue.peekQueue();
    new_queue.deQueue();
    new_queue.peekQueue();
    new_queue.deQueue();
    new_queue.peekQueue();

output:

Queue is empty.
Queue: 1 2 3 4
Queue: 2 3 4
Queue: 3 4
Queue: 4
Queue is empty.