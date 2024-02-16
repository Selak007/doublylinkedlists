#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void insert_odd_even(struct Node* head, int data, int position, int choice) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    struct Node* current = head;
    int count = 0;
    
    while (current != NULL && count != position) {
        if ((choice == 1 && current->data % 2 != 0) || (choice == 2 && current->data % 2 == 0)) {
            count++;
        }
        if (count != position) {
            current = current->next;
        }
    }
    
    if (current == NULL) {
        printf("Position exceeds the length of the list.\n");
        return;
    }
    
    struct Node* temp = current->next;
    current->next = new_node;
    new_node->prev = current;
    new_node->next = temp;
    if (temp != NULL) {
        temp->prev = new_node;
    }
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, position, data;
    
    printf("Enter 1 for odd or 2 for even: ");
    scanf("%d", &choice);
    
    printf("Enter position to insert: ");
    scanf("%d", &position);
    
    printf("Enter data to insert: ");
    scanf("%d", &data);
    
    insert_odd_even(head, data, position, choice);
    display(head);

    return 0;
}
