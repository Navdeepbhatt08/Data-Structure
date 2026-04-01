#include <stdio.h>
#include <stdlib.h>

typedef struct TreeOperations
{
    struct TreeOperations *left, *right;
    int data;
} bst;

void create(bst **root, int v)
{
    (*root) = malloc(sizeof(bst));
    if ((*root) = NULL)
    {
        (*root)->data = v;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return;
    }
    else if (((*root)->data) > v)
    {
        create(((*root)->left), v);
    }
    else if (((*root)->data) < v)
    {
        create(((*root)->right), v);
    }
    else
    {
        return;
    }
}
