#define max 5
#include <stdio.h>

int push(int top, int stack[])
{

    int x;
    if (top == max - 1)
    {
        printf("Stack is full , Cannot Push ");
    }
    else
    {
        printf("Enter value : ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
    return (top);
}

int pop(int top, int stack[])
{
    int x;
    if (top == -1)
    {
        printf("Stack is Underflow , Cannot Pop ");
    }
    else
    {
        x = stack[top];

        printf("Value poped : %d", &x);
        top--;
    }
    return (top);
}
void display(int top, int stack[])
{
    if (top == -1)
    {
        printf("Stack is Underflow , Cannot Display !! ");
    }
    else
    {
    }
}

main()
{
    int top = -1, ch, stack[max];

    do
    {
        printf("1. Push\n2. Pop \n3. Display\nEnter your choice : ", &ch);
        switch (ch)
        {
        case 1:
            top = push(top, stack);
            break;
        case 2:
            top = pop(top, stack);
        case 3:
            display(top, stack);
        }
    } while (ch <= 3);
}
