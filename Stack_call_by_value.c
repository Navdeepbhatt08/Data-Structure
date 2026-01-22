#include <stdio.h>
#define max 7

int push(int[], int);
int pop(int[], int);
void peek(int[], int);
// void disp(int[], int);

main()
{
    int stack[max], top = -1, ch;

    do
    {
        printf("\n 1.Push \n 2.Pop \n 3.Peek \n 4.Display \n Enter your choice : ");
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

            // case 4:
            //     disp(stack, top);
            //     break;
        }

    } while (ch <= 4);
}

int push(int stack[], int top)
{
    int x;
    if (top == max - 1)
    {
        printf("Stack Full , Cannot Push !!");
    }
    else
    {

        printf("Enter a value to push : ");
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
        printf("Stack underflow , Cannot Pop !!");
    }
    else
    {
        x = stack[top];
        printf("value Poped : %d ", x);
        top--;
    }
    return (top);
}
void peek(int stack[], int top)
{

    if (top == -1)
    {
        printf(" Cannot Peek !!");
    }
    else
    {
        printf("Value Peeked %d ", stack[top]);
    }
}