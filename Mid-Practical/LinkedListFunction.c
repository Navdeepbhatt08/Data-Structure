#include <stdio.h>
#include <stdlib.h>

typedef struct slist
{
    int data;
    struct slist *next;
} slist;

slist *insert(slist *ptr)
{
    int x;
    slist *p = NULL;

    p = (slist *)malloc(sizeof(slist));
    if (p == NULL)
    {
        printf("Memory Allocation failed ");
        return ptr;
    }
    printf("Enter  Data : ");
    scanf("%d", &x);
    p->data = x;
    p->next = ptr;
    ptr = p;
    return ptr;
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

void dispCicular(slist *head)
{
    slist *ptr;
    
    ptr = head;
    while(ptr->next !=NULL)
    {
        printf("%d->",ptr->data);
        ptr = ptr->next;
    }
    printf("%d->",ptr->data);
    printf("Back To First");
}


main()
{
    int ch;
    slist *head = NULL;
    do
    {
        printf("\nEnter choice : ");
        printf("\n1. Insert At Left");
        printf("\n2. Display");
        printf("\n3. Display Circular");
 
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
            dispCicular(head);
            break;
    
        }

    } while (ch < 100);
}