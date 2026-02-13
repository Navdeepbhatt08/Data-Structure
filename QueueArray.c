#include<stdio.h>
#define max 5

int Enque(int [],int);
int Deque(int [],int);
int Display(int [],int,int);

int main()
{
int ch;
int front=0,rear=-1, queue[max];
do
    {
        printf("\n1.Push \n2.Pop \n3.Display \n4.Peek \nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            top = push(stack, top);
            break;
        case 2:
            top = pop(stack, top);
            break;
        case 3:
            display(stack, top);
            break;
        case 4:
            peek(stack, top);
            break;

        default:
            break;
        }
    } while (ch != 10);

}