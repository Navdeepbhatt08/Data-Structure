#include<stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
} sl;

sl* createNode(int value) {
    sl* newNode = (sl*)malloc(sizeof(sl));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
sl* insertAtBeginning(sl* head, int value) {
    sl* newNode = createNode(value);
    newNode->next = head;
    return newNode;
}
void displayList(sl* head) {
    sl* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int main() {
    sl* head = NULL;

    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);

    displayList(head);

    return 0;
}
