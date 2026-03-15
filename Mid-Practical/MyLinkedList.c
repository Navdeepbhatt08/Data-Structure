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
