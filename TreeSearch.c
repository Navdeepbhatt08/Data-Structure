#include<stdio.h>
#include<stdlib.h>

typedef struct  node
{
    int data;
    struct node *lc,*rc;
} node;


node *p = NULL;
