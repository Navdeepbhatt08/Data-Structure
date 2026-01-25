#include <stdio.h>
#define size 5

int enqueue(int[], int, int);
int dequeue(int[], int, int);
void display(int[], int, int);

main()
{

    int queue[size], front = 0, rear = -1, ch;
    do
    {
        printf("\n 1. Enqueue \n 2. DeQueue \n 3. Display \n Enter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            rear = enqueue(queue, rear, front);
            break;

        case 2:
            front = dequeue(queue, rear, front);
            break;

        case 3:

            display(queue, front, rear);
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (ch < 4);

    return 0;
}

int enqueue(int queue[], int rear, int x)
{
    if (rear == size - 1)
    {
        printf("Queue is Full Cannot Insert Elemenet ");
    }
    else
    {
        printf("Enter value to insert : ");
        scanf("%d", &x);
        rear++;
        queue[rear] = x;
    }
    return rear;
}

int dequeue(int queue[], int front, int rear)
{
    if (rear == size - 1)
    {
        printf("Queue is Full Cannot Insert Elemenet ");
    }
    else
    {
        printf("Enter value to insert : ");
        scanf("%d", &x);
        rear++;
        queue[rear] = x;
    }
    return rear;
}