#include <stdio.h>
#include <stdlib.h>

typedef struct slist
{
    int data;
    struct slist *next;
} slist;

slist *insertFirst(slist *ptr)
{
    int x;
    slist *p = NULL;

    p = (slist *)malloc(sizeof(slist));
    if (p == NULL)
    {
        printf("Memory allocation failed\n");
        return ptr;
    }

    printf("Enter Data : ");
    scanf("%d", &x);

    p->data = x;    
    p->next = ptr;
    ptr = p;

    return ptr;
}

slist *insertEnd(slist *ptr)
{
    slist *p, *temp;
    int x;

    p = (slist *)malloc(sizeof(slist));
    if (p == NULL)
    {
        printf("Memory Allocation Failed");
        printf("Then This iS Failed");
        return ptr;
    }

    printf("Enter data: ");
    scanf("%d", &x);

    p->data = x;
    p->next = NULL;

    if (ptr == NULL) // if list is empty
        ptr = p;
    else
    {
        temp = ptr;
        while (temp->next != NULL) // go to last node
            temp = temp->next;

        temp->next = p; // attach new node
    }

    return ptr;
}

slist *delete(slist *ptr)
{
    int x;
    slist *p = NULL;
    if (ptr == NULL)
    {
        printf("Empty");
    }
    else
    {
        x = ptr->data;
        printf("%d Deleted ", x);
        p = ptr;
        ptr = ptr->next;
        free(p);
    }
    return (ptr);
}

void display(slist *node)
{
    if (node == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (node != NULL)
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main()
{
    int ch;
    slist *head = NULL;
    do
    {
        printf("\nEnter choice : ");
        printf("\n1. Insert At First");
        printf("\n2. Insert At End");
        printf("\n3. Display");
        printf("\n4. Delete");
        printf("\n5. Exit");
        printf("\nChoice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            head = insertFirst(head);
            break;

        case 2:
            head = insertEnd(head);
            break;
        case 3:
            display(head);
            break;

        case 4:
            head = delete(head);
            break;

        case 5:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (ch != 7);

    return 0;
}
