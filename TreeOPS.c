#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} bst;

// Insert node
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

// Traversals
void inorder(bst *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(bst *root)
{
    if (root)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(bst *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Count total nodes
int countTotal(bst *root)
{
    if (!root) return 0;
    return 1 + countTotal(root->left) + countTotal(root->right);
}

// Count leaf nodes
int countLeaf(bst *root)
{
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}

// Count nodes with both children
int countBothChild(bst *root)
{
    if (!root) return 0;
    int count = 0;
    if (root->left && root->right)
        count = 1;
    return count + countBothChild(root->left) + countBothChild(root->right);
}

// Count nodes with only left child
int countLeftOnly(bst *root)
{
    if (!root) return 0;
    int count = 0;
    if (root->left && !root->right)
        count = 1;
    return count + countLeftOnly(root->left) + countLeftOnly(root->right);
}

// Count nodes in left subtree
int countLeftSubtree(bst *root)
{
    if (!root || !root->left) return 0;
    return countTotal(root->left);
}

// Count nodes in right subtree
int countRightSubtree(bst *root)
{
    if (!root || !root->right) return 0;
    return countTotal(root->right);
}

// Find minimum
bst* findMin(bst *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

// Find maximum
bst* findMax(bst *root)
{
    while (root && root->right)
        root = root->right;
    return root;
}

// Delete leaf node
bst* deleteLeaf(bst *root, int key)
{
    if (!root) return NULL;

    if (key < root->data)
        root->left = deleteLeaf(root->left, key);
    else if (key > root->data)
        root->right = deleteLeaf(root->right, key);
    else
    {
        // Node found
        if (!root->left && !root->right)
        {
            free(root);
            return NULL;
        }
        else
        {
            printf("Not a leaf node, cannot delete\n");
        }
    }
    return root;
}

// Main
int main()
{
    bst *root = NULL;
    int ch, val;

    while (1)
    {
        printf("\n1.Insert\n2.Inorder\n3.Preorder\n4.Postorder");
        printf("\n5.Total Nodes\n6.Left Subtree Nodes\n7.Right Subtree Nodes");
        printf("\n8.Leaf Nodes\n9.Nodes with both child\n10.Left child only");
        printf("\n11.Minimum\n12.Maximum\n13.Delete Leaf\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            insert(&root, val);
            break;

        case 2:
            inorder(root);
            break;

        case 3:
            preorder(root);
            break;

        case 4:
            postorder(root);
            break;

        case 5:
            printf("Total nodes: %d\n", countTotal(root));
            break;

        case 6:
            printf("Left subtree nodes: %d\n", countLeftSubtree(root));
            break;

        case 7:
            printf("Right subtree nodes: %d\n", countRightSubtree(root));
            break;

        case 8:
            printf("Leaf nodes: %d\n", countLeaf(root));
            break;

        case 9:
            printf("Nodes with both child: %d\n", countBothChild(root));
            break;

        case 10:
            printf("Nodes with only left child: %d\n", countLeftOnly(root));
            break;

        case 11:
        {
            bst *min = findMin(root);
            if (min)
                printf("Minimum: %d\n", min->data);
            break;
        }

        case 12:
        {
            bst *max = findMax(root);
            if (max)
                printf("Maximum: %d\n", max->data);
            break;
        }

        case 13:
            printf("Enter leaf node to delete: ");
            scanf("%d", &val);
            root = deleteLeaf(root, val);
            break;

        default:
            exit(0);
        }
    }
}