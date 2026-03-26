#include <stdlib.h>
#include <stdio.h>

typedef struct binarySearchTree
{
    struct binarySearchTree *left;
    int data;
    struct binarySearchTree *right;
} bst;

void createTree(bst **rt, int v)
{
    bst *p = NULL;
    if (*rt == NULL)
    {
        p = (bst *)malloc(sizeof(bst));
        p->data = v;
        p->right = NULL;
        p->left = NULL;
        *rt = p;
    }

    else if ((*rt)->data > v)
    {
        createTree(&((*rt)->left), v);
    }

    else if ((*rt)->data < v)
    {
        createTree(&((*rt)->right), v);
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
        preorder(rt->left);
        printf("%d ", rt->data);
        preorder(rt->right);
    }
}
void postorder(bst *rt)
{
    if (rt != NULL)
    {

        preorder(rt->left);
        preorder(rt->right);
        printf("%d ", rt->data);
    }
}

main()
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
            createTree(&root, v);
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