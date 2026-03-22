#define max 5
#include <stdio.h>
int push(int stack[], int top)
{
    int x;
    printf("Enter the data to push : ");
    scanf("%d", &x);
    top++;
    stack[top] = x;

    return (top);
}
int pop(int stack[], int top)
{
    printf("Value Poped : %d", stack[top]);
    top--;
    return (top);
}

void peek(int stack[], int top)
{
    printf("Top Most value : %d", stack[top]);
}

void display(int stack[], int top)
{
    while (top >= 0)
    {
        printf(" %d\n", stack[top]);
        top--;
    }
}

main()
{

    int top = -1, ch;
    int stack[max];
    do
    {
        printf("\n 1.PUSH\n 2.POP \n 3. PEEK \n 4.DISPLAY");
        printf("\n Enter your choice : ");
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

        default:
            break;
        }
    } while (ch != 5);
}