//struct for values in queue
struct Node {
    int value; 
    struct Node *next;
};

class Queue{
    private:
        Node *head;
        Node *end;

    public:
        //inserting value into queue
        void enQueue(int value);
        //deleting front/head value in queue and moving next value to the head
        void deQueue();
        //display queue
        void peekQueue();
};