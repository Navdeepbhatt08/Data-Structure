#include<stdio.h>
#define max 5

int Enque(int [],int);
int Deque(int [],int);
void Display(int [],int,int);

int main()
{
int ch;
int front=-1,rear=-1, queue[max];
do
    {
        printf("\n1.Enque \n2.Deque \n3.Display\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            rear = Enque(queue,rear);
            break;
        case 2:
            front = Deque(queue,front);
            break;
        case 3:
            Display(queue,front,rear);
            break;

        default:
            break;
        }
    } while (ch != 0);
}

int Enque(int queue[],int rear)
{
    int x;
    if(rear=max-1)
    {
        printf("Queue Is Full");
    }
    else
    {
        printf("Enter a value to insert : ");
        scanf("%d",&x);
        rear++;
        queue[rear]=x;
    }
    return(rear);
}
int Deque(int queue[],int front)
{
    int x;
    if(front==0)
    {
      printf("Empty Cannot Delete : \n");
    }
    else{
        x = queue[front];
        printf("Value Deleted : %x",x);
        front++;
    }
    return(front);
}

void Display(int queue[],int front,int rear)
{
    if(rear<front)
    {
        printf("Empty : \n");
    }
    else
    {
        while(front<=rear)
        {
            printf("%d ",queue[front]);
        }
    }
}