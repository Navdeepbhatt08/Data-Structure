#include<stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} sl;

main()
{
    sl *p= NULL , *l = NULL;
    int ch,v;
    while (1)
    {
        printf("Enter value to insert : ");
        scanf("%d",&v);
        p=(sl*)malloc(sizeof(sl));
        if(p!=NULL)
        {
            p->data=v;
            p->next = l;
            l=p;
        }
        printf("Continue (0/1) : ");
        scanf("%d",&ch);
        if(ch==0)
        {
            break;
        }
        
    }
    while (p!=NULL)
    {
        printf("%d -> ",p->data);
        p=p->next;
    }
    printf("Null");
    p=l;
    
    
}