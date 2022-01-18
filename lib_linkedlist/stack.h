// Fully Working, more tests needed

#include <iostream>

typedef struct template_stack {
    int data;
    struct template_stack *link;
} Stack;

bool isEmpty(Stack **stack) {
    if (*stack == nullptr) return true;
    else return false;
}

void push(Stack **stack, int data) {
    auto *temp = new Stack();
    temp->data = data;
    temp->link = *stack;
    *stack = temp;
}

int pop(Stack **stack) {
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

int peek(Stack **stack) {
    if (isEmpty(stack)) return -1;
    return (*stack)->data;
}

Stack *initializeStack() {
    return nullptr;
}

Stack *reverse(Stack **stack) {
    Stack *reversedStack = initializeStack();
    while (stack != nullptr) {
        int val = pop(stack);
        if (val == -1) {
            //delete &stack;
            break;
        } else {
            push(&reversedStack, val);
        }
    }
    return reversedStack;
}

void display(Stack **stack) {
    Stack *temp = *stack;
    while (temp != nullptr) {
        if (temp->link != nullptr) std::cout << temp->data << " <- ";
        else std::cout << temp->data << std::endl;
        temp = temp->link;
    }
    delete temp;
}