#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new webpage after the current webpage
struct Node* newWebpage(struct Node* current, int data) {
    struct Node* newNode = newNode(data);
    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;
    return newNode;
}

// Function to move to the front webpage
struct Node* front(struct Node* current) {
    if (current->next != NULL) {
        return current->next;
    }
    return current;
}

// Function to move to the back webpage
struct Node* back(struct Node* current) {
    if (current->prev != NULL) {
        return current->prev;
    }
    return current;
}

// Function to free the memory allocated to the doubly linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = newNode(0); // Dummy node
    struct Node* current = head;

    int choice, webpage;
    do {
        printf("\n1. New Webpage\n2. Front\n3. Back\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter webpage number: ");
                scanf("%d", &webpage);
                current = newWebpage(current, webpage);
                break;
            case 2:
                current = front(current);
                break;
            case 3:
                current = back(current);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    // Free allocated memory before exiting
    freeList(head);
    
    return 0;
}
