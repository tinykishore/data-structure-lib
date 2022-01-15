#include <iostream>

typedef struct template_queue {
    int data;
    struct template_queue *link;
} Queue;

bool isEmpty(Queue **queue) {
    if (*queue == nullptr) return true;
    else return false;
}

void enqueue(Queue **queue, int data) {
    auto *temp = new Stack();
    temp->data = data;
    temp->link = *stack;
    *stack = temp;
}

int dequeue(Queue **queue) {
    int val;
    if (isEmpty(stack)) {
        // "Stack Empty"
        return -1;
    } else {
        Stack *temp = *stack;
        *stack = (*stack)->link;
        val = temp->data;
        delete temp;
        return val;
    }
}

int next(Queue **queue) {
    if (isEmpty(queue)) return -1;
    return (*stack)->data;
}

Queue *initializeQueue() {
    return nullptr;
}

Queue *reverse(Queue **queue) {

}

void displayStack(Queue **queue) {
    Queue *temp = *queue;
    while (temp != nullptr) {
        if (temp->link != nullptr) std::cout << temp->data << " -> ";
        else std::cout << temp->data << std::endl;
        temp = temp->link;
    }
    delete temp;
}