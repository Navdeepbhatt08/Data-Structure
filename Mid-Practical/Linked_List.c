#include<stdio.h>
#include<stdlib.h>

typedef struct slist
{
    int data;
    struct slist*next;
} slist;

slist *insert(slist *ptr)
{
    int x ;
    slist *p = NULL;
    
    p = (slist*)malloc(sizeof(slist));
    if(p==NULL)
    {
        printf("MEmory Allocation failed ");
        return ptr;
    }
    printf("Enter  Data : " );
    scanf("%d",&x);
    p ->data = x;
    p->next = ptr ;
    ptr = p;

    return ptr;
}