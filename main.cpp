#include "lib/stack.h"

int main(int argc, char **argv) {
    Stack *stack = initializeStack();

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);

    displayStack(&stack);

    stack = reverse(&stack);

    displayStack(&stack);
    return 0;
}