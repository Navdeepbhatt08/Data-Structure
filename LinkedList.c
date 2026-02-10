#include <stdio.h>
#include <stdlib.h>

typedef struct slist
{
    int data;
    struct slist *next;
} sl;

main()
{
    sl *head = NULL;
    sl *temp = NULL;
    sl *p = NULL;
    int choice = 1;

    while (choice)
    {
        temp = (sl *)malloc(sizeof(sl));
        printf("Enter data: ");
        scanf("%d", &temp->data);
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            p = head;
        }
        else
        {
            p->next = temp;
            p = temp;
        }

        printf("Do you want to continue (0/1)? ");
        scanf("%d", &choice);
    }

    printf("The linked list is:\n");
    p = head;
    while (p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");

    p = head;
    sl *nextNode;
    while (p != NULL)
    {
        nextNode = p->next;
        free(p);
        p = nextNode;
    }

    return 0;
}