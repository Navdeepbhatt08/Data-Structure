#include <stdio.h>
#define MAX 10

int enqueue(int[], int);
int dequeue(int[], int, int);
int display(int[], int, int);

main()
{
    int queue[MAX], front = -1, rear, ch;
    do
    {
        printf("\n 1.Enqueue \n 2. Dequeue \n 3. Display \n Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            front = enqueue(queue, rear);
            break;
        case 2:
            rear = dequeue(queue, front, rear);
            break;
        case 3:
            front = display(queue, front, rear);
            break;
        }
    } while (ch <= 3);
}

int enqueue(int queue[], int rear)
{
    int x;
}