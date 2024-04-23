#include <iostream>
#include "queue.hpp"

using std::cout;
using std::endl;

int main() {
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

    return 0;

}