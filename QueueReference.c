#include <stdio.h>
#define size 5

void enqueue(int queue[], int *rear, int item);
void dequeue(int queue[], int *front, int rear);
void display(int queue[], int front, int rear);

int main()
{
    int queue[size];
    int front = 0, rear = -1;
    int ch, item;
    do
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &item);
            enqueue(queue, &rear, item);
            break;

        case 2:
            dequeue(queue, &front, rear);
            break;

        case 3:
            display(queue, front, rear);
            break;

        case 4:
            printf("Program Ended\n");
            break;

        default:
            printf("Invalid choice\n");
        }
    } while (ch != 4);

    return 0;
}
void enqueue(int queue[], int *rear, int item)
{
    if (*rear == size - 1)
    {
        printf(" X X X X X  Queue Overflow");
    }
    else
    {
        (*rear)++;
        queue[*rear] = item;
        printf("Inserted Element : %d ", item);
    }
}

void dequeue(int queue[], int *front, int rear)
{
    if (*front > rear)
    {
        printf("Queue Undeflow");
    }
    else
    {
        printf("Element Deleted  : %d ", queue[*front]);
        (*front)++;
    }
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