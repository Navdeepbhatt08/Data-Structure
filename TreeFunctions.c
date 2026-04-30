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

int count(bst *root)
{
    if (root == NULL)
        return 0;

    return 1 + count(root->left) + count(root->right);
}

int leafNode(bst *root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return leafNode(root->left) + leafNode(root->right);
}

int LeftChildOnly(bst *root)
{

    if (root == NULL)
        return 0;

    int count = 0;
    if (root->left != NULL && root->right == NULL)
    {
        count = 1;
    }
    return count + LeftChildOnly(root->left) + LeftChildOnly(root->right);
}

int main()
{
    int v, ch;
    bst *root = NULL;

    while (1)
    {
        printf("\n1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Count Nodes\n6.Count Leaf Node \n7.Having Left Child Only\n");
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
            printf("Total nodes = %d\n", count(root));
            break;

        case 6:
            printf("Leaf Node = %d", leafNode(root));

            break;
        case 7:
            printf("Left Child Only Node = %d", LeftChildOnly(root));

            break;

        case 8:
            exit(0);
        }
    }
}