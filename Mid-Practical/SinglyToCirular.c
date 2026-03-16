#include <stdio.h>
#include <stdlib.h>

typedef struct slist
{
    int data;
    struct slist *next;
} node;

node *insert(node *ptr)
{
    int x;
    node *p = NULL;
    p = (node *)malloc(sizeof(node));

    printf("Enter x : ");
    scanf("%d", &x);
    p->data = x;
    p->next = ptr;
    ptr = p;
    return ptr;
}

void display(node *ptr)
{
    if (ptr == NULL)
    {
        printf("List is Empty \n");
        return;
    }
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

node *convertCircular(node *head)
{
    node *ptr = head;

    if (head == NULL)
    {
        printf("List is Empty\n");
        return head;
    }

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = head; // last node pointing to first node
    printf("List converted to Circular Linked List\n");

    return head;
}

main()
{
    int ch;
    node *head = NULL;
    do
    {
        printf("\nEnter choice : ");
        printf("\n1. Insert At Left");
        printf("\n2. Display");
        printf("\n3. Convert into Circular");
        printf("\nChoice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            head = insert(head);
            break;

        case 2:
            display(head);
            break;
        case 3:
            head = convertCircular(head);
            break;

        default:
            break;
        }

    } while (ch < 100);
}