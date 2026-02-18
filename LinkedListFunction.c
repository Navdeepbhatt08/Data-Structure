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
        printf("\n2. Display");
        printf("\n3. Exit");
        printf("\nChoice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            head = insertFirst(head);
            break;

        case 2:
            display(head);
            break;

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (ch != 3);

    return 0;
}
