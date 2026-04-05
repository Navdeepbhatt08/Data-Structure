#include <stdio.h>
#include <stdlib.h>

typedef struct BinarySearchTree
{
    struct BinarySearchTree *left, *right;
    int data;
} bst;

void insert(bst **root, int val)
{
    if (*root == NULL)
    {
        bst *p = (bst *)malloc(sizeof(bst));
        p->data = val;
        p->left = p->right = NULL;
        *root = p;
    }
    else if (val < (*root)->data)
        insert(&(*root)->left, val);
    else if (val > (*root)->data)
        insert(&(*root)->right, val);
    else
        printf("Duplicate not allowed\n");
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

void inorder(bst *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(bst *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    int v, ch;
    bst *root = NULL;

    while (1)
    {
        printf("\n1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &v);
            insert(&root, v);
            break;

        case 2:
            preorder(root);
            break;

        case 3:
            inorder(root);
            break;

        case 4:
            postorder(root);
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
}