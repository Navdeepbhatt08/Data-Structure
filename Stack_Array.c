#define max 5
#include <stdio.h>

int push(int[], int);
int pop(int[], int);
void display(int[], int);
void peek(int[], int);

main()
{

    int stack[max], top = -1, ch;
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

int push(int stack[], int top)
{
    int x;
    if (top == max - 1)
    {
        printf("Stack Is Full 🤨\n");
    }
    else
    {
        printf("Enter a value to be pushed : ");
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
        printf("Empty hai yrrr🤨");
    }
    else
    {
        x = stack[top];
        printf("Value Poped : %d\n", x);
        top--;
    }
    return (top);
}
void display(int stack[], int top)
{
    int i, x;
    if (top == -1)
    {
        printf("Empty Stack");
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

void peek(int stack[], int top)
{
    int i, x;
    if (top == -1)
    {
        printf("Empty Stack");
    }
    else
    {
        printf("Top Most Peek Element : %d\n", stack[top]);
    }
}