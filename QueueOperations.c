#include <stdio.h>
#define SIZE 5

int enqueue(int[],int,int);

int enqueue(int queue[], int rear, int item) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow\n");
    } else {
        rear++;
        queue[rear] = item;
        printf("Inserted %d\n", item);
    }
    return rear;   // returning updated rear (call by value)
}

int dequeue(int queue[], int front, int rear) {
    if (front > rear) {
        printf("Queue Underflow\n");
    } else {
        printf("Deleted %d\n", queue[front]);
        front++;
    }
    return front;  // returning updated front (call by value)
}

void display(int queue[], int front, int rear) {
    int i;
    if (front > rear) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue elements: ");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int queue[SIZE];
    int front = 0, rear = -1;
    int choice, item;

    do {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &item);
            rear = enqueue(queue, rear, item);
            break;

        case 2:
            front = dequeue(queue, front, rear);
            break;

        case 3:
            display(queue, front, rear);
            break;

        case 4:
            printf("Exiting program\n");
            break;

        default:
            printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
