#define max 10
#include <stdio.h>

int push(int, int[]);
int pop(int, int[]);
void display(int, int[]);

main()
{

    int stack[max], top = -1, ch;
    printf("1.Push \n2.Pop \n3.Display \nEnter your choice : ");
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

    default:
        break;
    }
}

int push(int top, int stack[])
{
    int x;
    if (top == max - 1)
    {
        printf("Stack Is Full 🤨");
    }
    else
    {
        printf("Enter a value to be pushed : ");
        scanf("%d",&x);
         top++;
         stack[top]=x;
    }
    return (top);
}

int pop(int top, int stack[])
{
    int x;
    if (top ==  -1)
    {
        printf("Emp🤨");
    }
    else
    {
        printf("Enter a value to be pushed : ");
        scanf("%d",&x);
         top++;
         stack[top]=x;
    }
    return (top);
}