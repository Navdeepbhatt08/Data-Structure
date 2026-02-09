#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;

/* Create new node */
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/* Insert at beginning */
void insertAtBeginning() {
    int value;
    printf("Enter value: ");
    scanf("%d", &value);

    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

/* Insert at end */
void insertAtEnd() {
    int value;
    printf("Enter value: ");
    scanf("%d", &value);

    Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

/* Insert at specific position */
void insertAtPosition() {
    int value, pos, i = 1;
    printf("Enter value and position: ");
    scanf("%d %d", &value, &pos);

    if (pos == 1) {
        insertAtBeginning();
        return;
    }

    Node* temp = head;
    while (temp != NULL && i < pos - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    Node* newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

/* Display list */
void display(Node* node) {
    if (node == NULL) {
        printf("List is empty\n");
        return;
    }

    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Insert at Beginning");
        printf("\n2. Insert at End");
        printf("\n3. Insert at Position");
        printf("\n4. Display List");
        printf("\n5. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertAtBeginning(); break;
            case 2: insertAtEnd(); break;
            case 3: insertAtPosition(); break;
            case 4: display(head); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
