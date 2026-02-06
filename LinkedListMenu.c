#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* sortedHead = NULL;
struct Node* reversedHead = NULL;

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning() {
    int value;
    printf("Enter value: ");
    scanf("%d", &value);

    struct Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertAtEnd() {
    int value;
    printf("Enter value: ");
    scanf("%d", &value);

    struct Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Insert at specific position
void insertAtPosition() {
    int value, pos, i = 1;
    printf("Enter value and position: ");
    scanf("%d %d", &value, &pos);

    if (pos == 1) {
        insertAtBeginning();
        return;
    }

    struct Node* temp = head;
    while (temp != NULL && i < pos - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    struct Node* newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete node by value
void deleteNode() {
    int value;
    printf("Enter value to delete: ");
    scanf("%d", &value);

    struct Node* temp = head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == value) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Sort linked list (Bubble sort)
void sortList() {
    sortedHead = head;
    struct Node *i, *j;
    int temp;

    for (i = sortedHead; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// Display list
void display(struct Node* node) {
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

// Reverse linked list
void reverseList() {
    struct Node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    reversedHead = prev;
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete Node\n");
        printf("5. Sort Linked List\n");
        printf("6. Display Sorted List\n");
        printf("7. Reverse Linked List\n");
        printf("8. Display Reversed List\n");
        printf("9. Display Original List\n");
        printf("10. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertAtBeginning(); break;
            case 2: insertAtEnd(); break;
            case 3: insertAtPosition(); break;
            case 4: deleteNode(); break;
            case 5: sortList(); printf("List sorted\n"); break;
            case 6: display(sortedHead); break;
            case 7: reverseList(); printf("List reversed\n"); break;
            case 8: display(reversedHead); break;
            case 9: display(head); break;
            case 10: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
