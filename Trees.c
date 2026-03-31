#include <stdio.h>
#include <stdlib.h>

typedef struct binarySearchTree
{
    struct binarySearchTree *left;
    int data;
    struct binarySearchTree *right;
} bst;

void create(bst **root, int val)
{
    (*root) = malloc(sizeof(bst));
    if ((*root) = NULL)
    {
        (*root)->data = val;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return;
    }
    else if (((*root)->data) > val)
    {
        create(((*root)->left), val);
    }
    else if (((*root)->data) < val)
    {
        create(((*root)->right), val);
    }
    else
    {
        return;
    }
}

void preorder(bst *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

main()
{
    bst *root = NULL;
    int ch, val;

    printf("1. Create \n2. Display \nEnter : ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
    printf("Enter Data : ");
        scanf("%d", &val);
        create(&(*root), val);
        break;
    case 2:
        preorder(root);
        break;

    default:
        break;
    }
    while (ch < 4);
}