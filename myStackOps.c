#include <stdio.h>
#define max 5

int push(int top, int stack[]);
int pop(int top, int stack[]);
void disp(int top, int stack[]);

main()
{
    int stack[max], top = -1, ch;
    do
    {
        printf("1. Push \n2. POP \n3. Display \n Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            top = push(top, stack);
            break;

        case 2:
            top = pop(top, stack);
            break;

        case 3:
            disp( top,stack);
            break;
        }

    } while (ch <= 4);
}

 int push(int top ,int stack[])
 {
    int x;
    if(top == max-1)
    {
        printf("Stack is Overflow\n");
    }
    else
    {
        printf("Enter value to insert : ");
        scanf("%d",&x);
        top ++;
        stack[top]=x;
    }
    return(top);
 }

 int pop(int top ,int stack[])
 {
    int x;
    if(top == -1)
    {
        printf("Stack is Underflow\n");
    }
    else
    {
    x = stack[top];
   printf("Value poped %d \n",x);
   top--;
}
    return(top);
 }


 void disp(int top ,int stack[])
 {

    if (top == -1)
    {
        printf("Empty Stack\n");
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