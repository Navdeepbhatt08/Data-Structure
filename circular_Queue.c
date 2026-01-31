#include <stdio.h>
#define max 5

int Cenqueue(int[], int, int);
int Cdequeue(int[],int,int);
void display(int[], int, int);

main()
{
    int cq[max], rear = -1, front = -1, ch;
    do
    {
        printf("\n 1. insert queue \n 2. Delete Element \n 3. Display \n 4. peek \n Enter your choice \n ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            rear = Cenqueue(cq, front, rear);
            if (front == -1)
            {
                front = 0;
            }
            break;

        case 2:
            front = Cdequeue(cq, front, rear);
            break;
        }
    } while (ch != 3);
}

//Funtion Declaration

int Cenqueue(int cq[], int rear, int front)
{
    int x;
    if ((rear + 1) % max == front)
    {
        printf("Queue is Full, Cannot insert ");
    }
    else
    {
        printf("Enter Element to insert : ");
        scanf("%d", &x);

        rear = (rear + 1) % max;
        cq[rear] = x;
        printf("Element inserted %d ", x);
    }
    return (rear);
}

int Cdequeue(int cq[], int rear, int front)
{
    int x;
    if (front == -1)
    {
        printf("Queue is Empty , Cannot Delete.... ");
    }
    else
    {
    printf("Element Deleted %d ",cq[front]);

    front ++;
        cq[front] = x;
    }
    return (front);
}

void display(int cq[], int front, int rear)
{
    if (front == -1 && rear == -1)
    {
        printf("Queue Is Empty");
    }
    else
    {
        while (front != rear)
        {
            printf("%d ", cq[front]);
            front = (front + 1) % max;
        }
    }
}