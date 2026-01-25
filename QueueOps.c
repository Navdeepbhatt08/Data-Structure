#include <stdio.h>
#define size 5

int enqueue(int[], int, int);
int dequeue(int[], int, int);
int display(int[], int, int);

main()
{

int queue[size],front = 0,rear = -1 ,ch;
do
{
    printf("\n 1. Enqueue \n 2. DeQueue \n 3. Display \n Enter your choice : ");
    scanf("%d",&ch);

    switch(ch)
    {
            case 1: 
            rear = enqueue(queue,rear,front);
            break;

            case 2: 
            front = dequeue(queue,rear,front);
            break;
    }

} while (ch<4);


}