#include <stdio.h>
#define max 10

int push(int[], int);
int pop(int[], int);
void peek(int[], int);
void display(int[], int);

main()
{
    int top = -1, stack[max], ch;

    do
    {
        printf("\n1.Push \n2.Pop \n3.Peek \n4.Display \n Enter your choice : ");
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
            peek(stack, top);
            break;
        case 4:
            display(stack, top);
            break;
        }
    } while (ch <= 5);
}

int push(int stack[], int top)
{
    int x;
    if (top == max - 1)
    {
        printf("Stack OverFlow \n");
    }
    else
    {
        printf("Enter value to insert : ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
    return (top);
}

int pop(int stack[], int top)
{
    int x;
    if (top == -1)
    {
        printf("Stack UnderFlow \n");
    }
    else
    {
        printf("Value Poped : %d ", stack[top]);
        top--;
    }
    return (top);
}

void peek(int stack[], int top)
{
    int x;
    if (top == -1)
    {
        printf("Stack UnderFlow \n");
    }
    else
    {
        printf("Value at top : %d ", stack[top]);
    }
}
void display(int stack[], int top)
{
    int i;
    if (top == -1)
    {
        printf("Stack UnderFlow \n");
    }
    else
    {
        while (top >= 0)
        {
            printf("%d\n", stack[top]);
            top--;
        }
    }
}