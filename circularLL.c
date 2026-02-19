#include <stdio.h>
#include <stdlib.h>

typedef struct circularLL
{
    int data;
    struct circularLL *next;
} cl;

void insert(cl **f, cl **r)
{
    int x;
    cl *p = NULL;
    p = (cl *)malloc(sizeof(cl));

    if (p != NULL)
    {
        printf("Enter Data  : ");
        scanf("%d", &x);
        p->data = x;
        if (*f == NULL && *r == NULL)
        {
            *f = *r = p;
            p->next = p;
        }
        else
        {
            (*r)->next = p;
            *r = p;
            (*r)->next = *f;
        }

        (*r)->next = *f;
    }
}

void display(cl **f, cl **r)
{
    if (*f == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    cl *temp = *f;
    printf("Circular Linked List: ");
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != *f);

    printf("(Back to First Node)\n");
}

main()
{
    cl *f = NULL, *r = NULL;
    int ch;
    do
    {
        printf("1.Insert Element \n2.Display\n Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert(&f, &r);
            break;

        case 2:
            display(&f, &r);
            break;

        default:
            break;
        }
    } while (ch < 3);
}