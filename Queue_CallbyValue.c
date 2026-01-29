#include <stdio.h>
#define SIZE 5

int enqueue(int[], int, int);
int dequeue(int[], int, int);
void display(int[], int);
void peek(int[], int);

int main()
{
    int queue[SIZE], rear = -1, front = 0, item, ch;

    do{
         printf("\n 1. Enqueue \n 2. Dequeue \n 3. Peek \n 4.Display \n Enter your choice : ");
    scanf("%d", &ch);
    switch(ch)
    {
        case 1:
        printf("Enter Element To Insert : ");
        scanf("%d",&item);
        rear = enqueue(queue,rear,front);
        break;

        case 2:
        printf("Enter Element To Insert : ");
        scanf("%d",&item);
        case 3:
        printf("Enter Element To Insert : ");
        scanf("%d",&item);
        case 4:
        printf("Enter Element To Insert : ");
        scanf("%d",&item);
    }


    }
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
int dequeue(int queue[], int rear, int item)
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