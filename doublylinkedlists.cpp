#include <stdio.h>
#include <stdlib.h>

class List {
private:
    struct Node {
        int data;
        struct Node* next;
        struct Node* prev;
    };
    struct Node* head;
public:
    List() {
        head = nullptr;
    }
    struct Node* CreateNode();
    void DeleteNode(struct Node*);
    int IsEmpty();
    int Insert_Beg_Node(int);
    int Append_Node(int);
    int Insert_Pos_Node(int, int);
    int Delete_Beg_Node();
    int Delete_End_Node();
    int Delete_Pos_Node(int);
    int SearchNode(int);
    void Display();
};

struct List::Node* List::CreateNode() {
    return (struct Node*)malloc(sizeof(struct Node));
}

void List::DeleteNode(struct Node* del) {
    free(del);
}

int List::IsEmpty() {
    return head == nullptr;
}

int List::Insert_Beg_Node(int val) {
    struct Node* NewNode = CreateNode();
    if (NewNode == nullptr) {
        return 0;
    }
    NewNode->data = val;
    NewNode->next = head;
    NewNode->prev = nullptr;
    if (head != nullptr) {
        head->prev = NewNode;
    }
    head = NewNode;
    return 1;
}

int List::Append_Node(int val) {
    struct Node* NewNode = CreateNode();
    if (NewNode == nullptr) {
        return 0;
    }
    NewNode->data = val;
    NewNode->next = nullptr;

    if (head == nullptr) {
        NewNode->prev = nullptr;
        head = NewNode;
        return 1;
    }

    struct Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = NewNode;
    NewNode->prev = temp;
    return 1;
}

int List::Insert_Pos_Node(int val, int pos) {
    if (pos < 1) {
        return 0;
    }
    if (pos == 1 || head == nullptr) {
        return Insert_Beg_Node(val);
    }
    struct Node* NewNode = CreateNode();
    if (NewNode == nullptr) {
        return 0;
    }
    NewNode->data = val;

    struct Node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp == nullptr) {
            return 0;
        }
        temp = temp->next;
    }

    if (temp == nullptr) {
        return 0;
    }

    NewNode->next = temp->next;
    NewNode->prev = temp;
    if (temp->next != nullptr) {
        temp->next->prev = NewNode;
    }
    temp->next = NewNode;
    return 1;
}

int List::Delete_Beg_Node() {
    if (head == nullptr) {
        return 0;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    DeleteNode(temp);
    return 1;
}

int List::Delete_End_Node() {
    if (head == nullptr) {
        return 0;
    }
    struct Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    if (temp->prev != nullptr) {
        temp->prev->next = nullptr;
    }
    else {
        head = nullptr;
    }
    DeleteNode(temp);
    return 1;
}

int List::Delete_Pos_Node(int pos) {
    if (pos < 1 || head == nullptr) {
        return 0;
    }
    if (pos == 1) {
        return Delete_Beg_Node();
    }
    struct Node* temp = head;
    for (int i = 1; i < pos && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        return 0;
    }
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    temp->prev->next = temp->next;
    DeleteNode(temp);
    return 1;
}

int List::SearchNode(int val) {
    if (head == nullptr) {
        return 0;
    }
    struct Node* temp = head;
    int pos = 1;
    while (temp != nullptr && temp->data != val) {
        temp = temp->next;
        pos++;
    }
    if (temp == nullptr) {
        return 0;
    }
    return pos;
}

void List::Display() {
    if (head == nullptr) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp != nullptr) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    List NewList;
    int opt, var, pos, variable;
    while (true) {
        system("cls");
        printf("\n-------------------------------------------------\nOptions : \n\t0-Exit\n\t1-Insert At Beginning\n\t2-Appending\n\t3-Insertion\n\t4-Delete beginning\n\t5-Delete end\n\t6-Deletetion\n\t7-Search\n\t8-Display\n>>> ");
        scanf("%d", &opt);
        system("cls");
        switch (opt) {
        case 0:
            return 0;
        case 1:
            printf("\nValue : ");
            scanf("%d", &var);
            if (NewList.Insert_Beg_Node(var) == 1) {
                printf("\nInserted Successfully");
            }
            else {
                printf("\nList is Full : ");
            }
            break;
        case 2:
            printf("Value to append :  ");
            scanf("%d", &var);
            if (NewList.Append_Node(var) == 1) {
                printf("\nInserted Successfully");
            }
            else {
                printf("\nList is Full :(");
            }
            break;
        case 3:
            printf("Value to Insert :  ");
            scanf("%d", &var);
            printf("Position to Insert :  ");
            scanf("%d", &pos);
            variable = NewList.Insert_Pos_Node(var, pos);
            if (variable == 1) {
                printf("\nInserted Successfully");
            }
            else if (variable == 0) {
                printf("\nList is Full :(");
            }
            else {
                printf("Invalid Position");
            }
            break;
        case 4:
            if (NewList.Delete_Beg_Node() == 1) {
                printf("\nDeleted Successfully");
            }
            else {
                printf("\nList is Empty :(");
            }
            break;
        case 5:
            if (NewList.Delete_End_Node() == 1) {
                printf("\nDeleted Successfully");
            }
            else {
                printf("\nList is Empty :(");
            }
            break;
        case 6:
            printf("Position to Remove :  ");
            scanf("%d", &pos);
            if (NewList.Delete_Pos_Node(pos) == 1) {
                printf("\nDeleted Successfully");
            }
            else {
                printf("\nList is Empty :(");
            }
            break;
        case 7:
            printf("Element to search :  ");
            scanf("%d", &var);
            pos = NewList.SearchNode(var);
            if (pos != 0) {
                printf("\nFound Element In index :%d", pos);
            }
            else {
                printf("\nElement Not Found in List");
            }
            break;
        case 8:
            printf("Values in List : ");
            NewList.Display();
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
        printf("\n\n(Press ENTER key to continue)");
        getchar();
        getchar();
    }
    return 0;
}

