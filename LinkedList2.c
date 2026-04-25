#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *next;
    int data;
} sl;

sl  *insert(sl *ptr )
{
int data;
sl *p;
p = (sl*)malloc(sizeof(sl*));

printf("Insert data : ");
scanf("%d ",&data);
p->data = data;
p->next = ptr ;
ptr = p;

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
