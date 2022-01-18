// Fully Working, more tests needed

#include <iostream>
#include "stack.h"

typedef struct template_queue{
    int data;
    struct template_queue *link;
} Queue;

bool isEmpty(Queue **queue){
    if(*queue == nullptr) return true;
    else return false;
}

void enqueue(Queue **queue, int data) {
    auto *newNode = new Queue();
    newNode->data = data;
    newNode->link = nullptr;

    if(*queue == nullptr){
        *queue = new Queue();
        (*queue)->data = data;
        (*queue)->link = nullptr;
    } else {
        Queue *temp = *queue;
        while (temp->link != nullptr) {
            temp = (Queue*)temp->link;
        }
        temp->link = newNode;
    }
}

int dequeue(Queue **queue) {
    int val;
    if (isEmpty(queue)) {
        // std::cout << "Queue Empty" << std::endl;
        return -1;
    } else {
        Queue *temp = *queue;
        *queue = (Queue*) (*queue)->link;
        val = temp->data;
        delete temp;
        return val;
    }
}

int next(Queue **queue){
    if(isEmpty(queue)) return -1;
    return (*queue)->data;
}

Queue *initializeQueue() {
    return nullptr;
}

Queue *reverse(Queue **queue) {
    auto *reversedQueue = initializeQueue();
    auto *s = initializeStack();
    while (true) {
        int val = dequeue(queue);
        if (val == -1) break;
        push(&s, val);
    }
    while (true) {
        int val = pop(&s);
        if (val == -1) break;
        enqueue(&reversedQueue, val);
    }
    delete &queue;
    return reversedQueue;
}

void display(Queue **queue) {
    Queue *temp = *queue;
    while (temp != nullptr) {
        if (temp->link != nullptr) std::cout << temp->data << " -> ";
        else std::cout << temp->data << std::endl;
        temp = (Queue*) temp->link;
    }
    delete temp;
}