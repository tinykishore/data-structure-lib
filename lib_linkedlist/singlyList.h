// Fully Working, more tests needed

#include <iostream>

typedef struct template_singlyList {
    int data;
    struct template_singlyList *next;
} sNode;

void display(sNode **head) {
    sNode *temp = *head;
    while (temp != nullptr) {
        if (temp->next == nullptr) std::cout << temp->data;
        else std::cout << temp->data << " -> ";
        temp = temp->next;
    }
}

int listSize(sNode **head) {
    if (*head == nullptr) return 0;
    else {
        int count = 0;
        sNode *temp = *head;
        while (temp != nullptr) {
            ++count;
            temp = temp->next;
        }
        return count;
    }
}

void insertData(sNode **head, int data) {
    auto *newNode = new sNode();
    newNode->data = data;
    newNode->next = nullptr;
    if (*head == nullptr) {
        *head = newNode;
    } else {
        sNode *temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertDataPosition(sNode **head, int data, int position) {
    int size = listSize(head);
    if (position < 1 || position > size + 1)
        return;
    else {
        while (position--) {
            if (position == 0) {
                auto *temp = new sNode();
                temp->data = data;
                temp->next = *head;
                *head = temp;
            } else head = &(*head)->next;
        }
        size++;
    }
}

void insertDataSorted(sNode **head, int data) {
    sNode *temp = new sNode();
    temp->data = data;
    temp->next = nullptr;
    sNode *current;

    if (*head == nullptr || (*head)->data >= temp->data) {
        temp->next = *head;
        *head = temp;
    }
    else {
        current = *head;
        while (current->next != nullptr && current->next->data < temp->data) {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
    }
}
void deleteData(sNode **head, int data) {
    sNode *current = *head;
    sNode *previous = nullptr;
    while (current->data != data && current->next != nullptr) {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    delete current;
}

void reverse(sNode **head) {
    sNode *prev = nullptr;
    sNode *next = nullptr;

    sNode *current = *head;
    while (current != NULL) {
        // Store next
        next = current->next;
        // Reverse current node's pointer
        current->next = prev;
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *head = prev;
}

void sort(sNode **head) {
    sNode *temp = *head;
    // Traverse the List
    while (temp) {
        sNode *minimum = temp;
        sNode *nextNode = temp->next;

        // Traverse the unsorted sublist
        while (nextNode) {
            if (minimum->data > nextNode->data) {
                minimum = nextNode;
            }
            nextNode = nextNode->next;
        }

        // Swap Data
        int x = temp->data;
        temp->data = minimum->data;
        minimum->data = x;
        temp = temp->next;
    }
}

