#define MAX 10
#include <stdio.h>

int stack[MAX];
int top = -1;

int push(int x)
{
    if (top == MAX - 1)
    {
        printf("The Stack is full");
    }
    else
    {
        top++;
        stack[top] = x;
        printf("%d Pushed Into Stack \n", x);
    }
}
void disp()
{
    int i;
    if (top == -1)
    {
        printf("Stack is Empty");
    }
    else
    {
        printf("The Stack is : ");
        for (i = top; i >= 0; i--)
        {
            printf("%d ,", stack[i]);
        }
    }
}

void peek()
{
    
    int i;
    if (top == -1)
    {
        printf("Stack is Empty");
    }
    else
    { 
        printf("The Top Most Element is : %d",stack[top]);
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    
    disp();
    peek();

    return 0;
}