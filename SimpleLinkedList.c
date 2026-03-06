#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} list;

list *push(list *);
list *pop(list *);
void display(list *);

main()
{
    list *top = NULL;
    int ch;
    do
    {
        printf("1.Push\n2.Pop\n3.Display\nEnter your choice : ");
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
            display(top);
            break;

        default:
            break;
        }
    } while (ch <= 3);
}

list *push(list *top)
{
    int x;
    list *p = NULL;
    p = (list *)malloc(sizeof(list));
    if (p != NULL)
    {
        printf("Enter value to be Insert \n");
        ;
        scanf("%d", &x);

        p->data = x;
        p->next = top;
        top = p;
    }
    return (top);
}

list *pop(list *top)
{
    list *p = NULL;
    if (top == NULL)
    {
        printf("Empty \n");
    }
    else
    {

        printf("value Poped %d \n ", top->data);
        p = top;
        top = top->next;
        free(p);
    }
    return (top);
}

void display(list *top)
{
    if (top == NULL)
    {
        printf("Empty \n");
    }
    else
    {
        while (top != NULL)
        {
            printf("%d\n\n", top->data);
            top = top->next;
        }
    }
}