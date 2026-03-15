#include <stdio.h>
#include <stdlib.h>

typedef struct singlelist
{
    int data;
    struct slist *next;
} slist;

slist *insertLeft(slist *ptr)
{
    int x;
    slist *p = NULL;
    p = (slist *)malloc(sizeof(slist));

    printf("Enter Data To Insert : ");
    scanf("%d", &x);
    p->data = x;
    p->next = ptr;
    ptr = p;
    return ptr;
}

slist *insertRight(slist *ptr)
{
    int x;
    slist *p = NULL, *temp = NULL;
    p = (slist *)malloc(sizeof(slist));

    printf("Enter Data To Insert : ");
    scanf("%d", &x);
    p->data = x;
    p->next = NULL;

    if (ptr == NULL)
    {
        ptr = p;
    }
    else
    {
        temp = ptr;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
    }

    return ptr;
}
