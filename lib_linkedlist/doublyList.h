#include <iostream>

typedef struct template_doublyList {
    int data;
    struct template_doublyList *previous;
    struct template_doublyList *next;
} dNode;

void display(dNode **head) {
    dNode *temp = *head;
    while (temp != nullptr) {
        if (temp->previous == nullptr) std::cout << temp->data << " -> ";
        else if (temp->next == nullptr) std::cout << " <- " << temp->data;
        else std::cout << " <- " << temp->data << " -> ";
        temp = temp->next;
    }
}

int listSize(dNode **head) {
    if (*head == nullptr) return 0;
    else {
        int count = 0;
        dNode *temp = *head;
        while (temp != nullptr) {
            ++count;
            temp = temp->next;
        }
        return count;
    }
}

void insertData(dNode **head, int data) {
    dNode *newNode = new dNode();
    newNode->data = data;
    newNode->next = nullptr;

    if (*head == nullptr) {
        newNode->previous = nullptr;
        *head = newNode;
    } else {
        dNode *temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->previous = temp;
    }
}

//void deleteData(dNode **head, int data) {
//
//}
