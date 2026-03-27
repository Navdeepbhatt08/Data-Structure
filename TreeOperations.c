#include <stdio.h>
#include <stdlib.h>

typedef struct BinarySearchTree
{
    struct BinarySearchTree *left;
    int data;
    struct BinarySearchTree *right;
} bst;

void create(bst **rt, int v)
{
    if (*rt == NULL)
    {
        bst *p = (bst *)malloc(sizeof(bst));
        p->data = v;
        p->left = NULL;
        p->right = NULL;
        *rt = p;
    }
    else if ((*rt)->data > v)
    {
        create(&((*rt)->left), v);
    }
    else if ((*rt)->data < v)
    {
        create(&((*rt)->right), v);
    }
    else
    {
        printf("Duplicate data not allowed\n");
    }
}

void preorder(bst *rt)
{
    if (rt != NULL)
    {
        printf("%d ", rt->data);
        preorder(rt->left);
        preorder(rt->right);
    }
}

void inorder(bst *rt)
{
    if (rt != NULL)
    {
        inorder(rt->left);
        printf("%d ", rt->data);
        inorder(rt->right);
    }
}

void postorder(bst *rt)
{
    if (rt != NULL)
    {
        postorder(rt->left);
        postorder(rt->right);
        printf("%d ", rt->data);
    }
}

int main()
{
    bst *root = NULL;
    int ch, v;

    while (1)
    {
        printf("\n1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Exit\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &v);
            create(&root, v);
            break;

        case 2:
            printf("Preorder: ");
            preorder(root);
            break;

        case 3:
            printf("Inorder: ");
            inorder(root);
            break;

        case 4:
            printf("Postorder: ");
            postorder(root);
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}