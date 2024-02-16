#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* head, int pos, int data) {
    struct Node* newNode = createNode(data);
    
    if (pos < 1) {
        printf("Invalid position\n");
        return head;
    }

    if (head == NULL && pos != 1) {
        printf("Invalid position\n");
        return head;
    }

    if (pos == 1) {
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        return newNode;
    }

    struct Node* current = head;
    int index = 1;

    while (current->next != NULL && index < pos - 1) {
        current = current->next;
        index++;
    }

    if (index == pos - 1) {
        newNode->next = current->next;
        if (current->next != NULL)
            current->next->prev = newNode;
        current->next = newNode;
        newNode->prev = current;
    } else {
        printf("Invalid position\n");
    }

    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int position, data;

    do {
        printf("Enter the position to insert (0 to exit): ");
        scanf("%d", &position);

        if (position == 0)
            break;

        printf("Enter the data: ");
        scanf("%d", &data);

        head = insertNode(head, position, data);

        printf("Updated List: ");
        printList(head);
    } while (1);

    freeList(head);

    return 0;
}
