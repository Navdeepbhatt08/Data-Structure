#include <stdio.h>
#define SIZE 3

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

int main()
{
    int queue[SIZE], rear = -1, front = 0, item;

    for (int i = 0; i < 4; i++)   
    {
        printf("Enter element to insert: ");
        scanf("%d", &item);
        rear = enqueue(queue, rear, item);
    }

    return 0;
}
