#ifndef __QUEUE_
#define __QUEUE__

class queue {
    int *arr;
    int capacity;
    int front;
    int rear;
    int count;

   public:
    queue(int size);
    ~queue();

    void dequeue_all();
    void enqueue(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};

#endif
