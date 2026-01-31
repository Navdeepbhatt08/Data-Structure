#include <stdio.h>
#define SIZE 5

struct Queue {
    int s1[SIZE];
    int s2[SIZE];
    int top1;
    int top2;
};

// Insertion
struct Queue enqueue(struct Queue q, int item) {
    if (q.top1 == SIZE - 1) {
        printf("Queue Overflow\n");
        return q;
    }
    q.top1++;
    q.s1[q.top1] = item;
    printf("Inserted %d\n", item);
    return q;
}

/* Dequeue operation */
struct Queue dequeue(struct Queue q) {
    int i;

    if (q.top1 == -1 && q.top2 == -1) {
        printf("Queue Underflow\n");
        return q;
    }

    if (q.top2 == -1) {
        while (q.top1 != -1) {
            q.top2++;
            q.s2[q.top2] = q.s1[q.top1];
            q.top1--;
        }
    }

    printf("Deleted %d\n", q.s2[q.top2]);
    q.top2--;
    return q;
}

/* Display operation */
void display(struct Queue q) {
    int i;

    if (q.top1 == -1 && q.top2 == -1) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements: ");

    for (i = q.top2; i >= 0; i--) {
        printf("%d ", q.s2[i]);
    }

    for (i = 0; i <= q.top1; i++) {
        printf("%d ", q.s1[i]);
    }

    printf("\n");
}

int main() {
    struct Queue q;
    int choice, item;

    q.top1 = -1;
    q.top2 = -1;

    do {
        printf("\n--- Queue using Two Stacks ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &item);
                q = enqueue(q, item);
                break;

            case 2:
                q = dequeue(q);
                break;

            case 3:
                display(q);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
