#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int data;
    struct stack *next;
} stack;

stack *push(stack *);
stack *pop(stack *);
void disp(stack *);

int main()
{
    stack *top = NULL;
    int ch;

    do
    {
        printf("\n1. Push \n2. Pop \n3. Display Stack \n Enter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            top = push(top);
            break;

        case 2:
            top = pop(top);
            break;
        case 3:
            disp(top);
            break;

        default:
            break;
        }
    } while (ch != 4);
    return 0;
}

stack *push(stack *top)
{
    int x;
    stack *p = NULL;
    p =(stack*)malloc(sizeof(stack));

    if(p!=NULL)
    {
        printf("Enter data : ");
        scanf("%d",&x);
        p->data = x;
        p->next = top;
        top = p;
    }
    return(top);
}

stack *pop(stack *top)
{
    int x;
    stack *p = NULL;

    if(top==NULL)
    {
printf("UnderFlow , Don't doo....");
    }
    else
    {
        x = top->data;
        printf("Element Poped : %d ",x);
        p = top;
        top = top->next;
        free(p);
    }

    return(top);
}
void disp(stack *top)
{
    if(top==NULL)
    {
        printf("Nahi hoga bhai Data hi nahi hai...");
    }
    else
    {
        while (top!=NULL)
        {
            printf("%d \n",top->data);
            top= top->next;
        }
        
    }
}