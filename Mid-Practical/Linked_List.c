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

slist *insertEnd(slist *ptr)
{
    int x;
    slist *p = NULL, *temp = NULL;

    p = (slist *)malloc(sizeof(slist));
    if (p == NULL)
    {
        printf("Memory Allocation failed");
        return ptr;
    }

    printf("Enter Data: ");
    scanf("%d", &x);

    p->data = x;
    p->next = NULL;

    if (ptr == NULL) // If list is empty
    {
        ptr = p;
    }
    else
    {
        temp = ptr;
        while (temp->next != NULL) // Traverse to last node
        {
            temp = temp->next;
        }
        temp->next = p; // Insert at end
    }

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

void findMax(slist *node)
{
    int max;
    if (node == NULL)
    {
        printf("List is Empty \n");
        return;
    }
    max = node->data;
    while (node != NULL)
    {
        if (node->data > max)
        {
            max = node->data;
        }
        node = node->next;
    }
    printf("max element is %d ", max);
}

main()
{
    int ch;
    slist *head = NULL;
    do
    {
        printf("\nEnter choice : ");
        printf("\n1. Insert At Left");
        printf("\n2. Insert At Right");
        printf("\n3. Display");
        printf("\n4. Find Max Element");
        printf("\n5. Exit");
        printf("\nChoice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            head = insert(head);
            break;

        case 2:
            head = insertEnd(head);
            break;
        case 3:
            display(head);
            break;
        case 4:
            findMax(head);
            break;

        default:
            break;
        }

    } while (ch < 4);
}