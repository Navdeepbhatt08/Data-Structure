#include <stdio.h>
#define SIZE 5

int enqueue(int queue[], int rear, int item);
int dequeue(int queue[], int rear, int front);
void display(int queue[], int front, int rear);
void peek(int queue[], int front, int rear);

int main()
{
    int queue[SIZE];
    int rear = -1, front = 0;
    int item, ch;
    do
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &item);
            rear = enqueue(queue, rear, item);
            break;
        case 2:
            front = dequeue(queue, rear, front);
            break;
        case 3:
            peek(queue, front, rear);
            break;
        case 4:
            display(queue, front, rear);
            break;
        case 5:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice\n");
        }
    } while (ch != 5);

    return 0;
}

int enqueue(int queue[], int rear, int item)
{
    if (rear == SIZE - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        rear++;
        queue[rear] = item;
        printf("Inserted %d\n", item);
    }
    return rear;
}
int dequeue(int queue[], int rear, int front)
{
    if (front > rear)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("Deleted %d\n", queue[front]);
        front++;
    }
    return front;
}

void peek(int queue[], int front, int rear)
{
    if (front > rear)
        printf("Queue is empty\n");
    else
        printf("Front element: %d\n", queue[front]);
}

void display(int queue[], int front, int rear)
{
    if (front > rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}
