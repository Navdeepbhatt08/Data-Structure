#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;


Node* push(Node* top, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return top;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d pushed into stack\n", value);
    return top;
}


Node* pop(Node* top) {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return top;
    }

    Node* temp = top;
    printf("%d popped from stack\n", top->data);

    top = top->next;
    free(temp);

    return top;
}



void display(Node* top) {
    Node* temp = top;

    if (temp == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    Node* top = NULL;
    int choice, value;

    while (1) {
        printf("\n----- STACK MENU -----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                top = push(top, value);
                break;

            case 2:
                top = pop(top);
                break;

            case 3:
                peek(top);
                break;

            case 4:
                display(top);
                break;

            case 5:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
