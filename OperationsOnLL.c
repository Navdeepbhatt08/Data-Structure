#include <stdio.h>
#include <stdlib.h>

typedef struct SingleLinkedList
{
    struct SingleLinkedList *next;
    int data;
} slist;

int insertAtbeg(slist *ptr)
{
    int x;
    slist *p = NULL;
    p = (slist *)malloc(sizeof(slist));
    if (p != NULL)
    {
        printf("Enter Data : ");
        scanf("%d", &x);
        p->data = x;
        p->next = ptr;
        ptr = p;
        return ptr;
    }
    else
    {
        printf("Memory Not Assigned ");
    }
}

void display(slist *node)
{
    if (node == NULL)
    {
        printf("List is Empty \n");
        return;
    }

    while (node != NULL)
    {
        printf("%d->", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

main()
{
    int ch;
    slist *head = NULL;
    do
    {
        printf("\nEnter choice : ");
        printf("\n1. Insert At Left");
        printf("\n2. Display List");

        printf("\nChoice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            head = insertAtbeg(head);
            break;

        case 2:
            display(head);
            break;

        default:
            break;
        }

    } while (ch < 100);
}