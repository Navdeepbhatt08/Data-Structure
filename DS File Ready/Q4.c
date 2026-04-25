#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} tree;

tree *create(int data)
{
    tree *newNode = (tree *)malloc(sizeof(tree));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

tree *insert(tree *root, int data)
{
    if (root == NULL)
        return create(data);
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

int secondLargest(tree *root)
{
    tree *parent = NULL;
    while (root->right != NULL)
    {
        parent = root;
        root = root->right;
    }
    if (root->left != NULL)
    {
        root = root->left;
        while (root->right != NULL)
            root = root->right;

        return root->data;
    }
    return parent->data;
}

tree* minNode(struct node* root)
{
    while(root->left != NULL)
        root = root->left;
    return root;
}

/* Delete node */
tree* deleteNode(struct node* root, int key)
{
    if(root == NULL)
        return NULL;

    if(key < root->data)
        root->left = deleteNode(root->left, key);

    else if(key > root->data)
        root->right = deleteNode(root->right, key);

    else
    {
        if(root->left == NULL)
        {
            tree* temp = root->right;
            free(root);
            return temp;
        }

        else if(root->right == NULL)
        {
            tree* temp = root->left;
            free(root);
            return temp;
        }

        tree* temp = minNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

/* Count nodes having common parent */
int countCommonParent(tree* root)
{
    if(root == NULL)
        return 0;

    int count = 0;

    if(root->left && root->right)
        count += 2;

    count += countCommonParent(root->left);
    count += countCommonParent(root->right);

    return count;
}

// Find height of BST 
int height(tree* root)
{
    if(root == NULL)
        return -1;

    int left = height(root->left);
    int right = height(root->right);

    return (left > right ? left : right) + 1;
}

int countLeft(tree* root)
{
    if(root == NULL)
        return 0;

    return 1 + countLeft(root->left) + countLeft(root->right);
}


void inorder(tree* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    tree* root = NULL;
    int choice, value;

    while(1)
    {
        printf("\n1.Insert\n2.Second Largest\n3.Delete Node\n4.Count Nodes with Common Parent\n5.Height\n6.Nodes on Left Side\n7.Display\n8.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&value);
                root = insert(root,value);
                break;

            case 2:
                printf("Second Largest = %d\n", secondLargest(root));
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d",&value);
                root = deleteNode(root,value);
                break;

            case 4:
                printf("Nodes having common parent = %d\n", countCommonParent(root));
                break;

            case 5:
                printf("Height of tree = %d\n", height(root));
                break;

            case 6:
                if(root->left == NULL)
                    printf("No left subtree\n");
                else
                    printf("Nodes in left subtree = %d\n", countLeft(root->left));
                break;

            case 7:
                inorder(root);
                break;

            case 8:
                exit(0);
        }
    }
}