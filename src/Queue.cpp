#include "../include/Queue.hpp"

#include <iostream>

using std::cout;

queue::queue(int size) {
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

queue::~queue() {
    delete[] arr;
}

void queue::dequeue_all() {
    if (isEmpty()) {
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < capacity; i++) {
        front = (front + 1) % capacity;
    }
    count = 0;
}

void queue::enqueue(int item) {
    if (isFull()) {
        exit(EXIT_FAILURE);
    }

    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}

int queue::peek() {
    if (isEmpty()) {
        exit(EXIT_FAILURE);
    }
    return arr[front];
}

int queue::size() {
    return count;
}

bool queue::isEmpty() {
    return (size() == 0);
}

bool queue::isFull() {
    return (size() == capacity);
}
