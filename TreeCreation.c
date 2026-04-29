#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *lc, *rc;
} typedef node;

void insert(node **r, int n)
{
    node *t;
    t = malloc(sizeof(node));
    t->data = n;
    t->lc = t->rc = NULL;

    if (*r == NULL)
    {
        *r = t;
        return;
    }

    if (n > (*r)->data)
    {
        insert(&((*r)->rc), n);
    }

    else
    {
        insert(&((*r)->lc), n);
    }
}

void Inorder(node **r)
{
    if (*r != NULL)
    {
        Inorder(&((*r)->lc));
        printf("%d ", (*r)->data);
        Inorder(&((*r)->rc));
    }
}
void all(node *r, int *p)
{
    if (r != NULL)
    {
        (*p)++;
        all(r->lc, p);
        all(r->rc, p);
    }
}

void leftCount(node *r, int *p)
{
    if (r != NULL)
    {
        (*p)++;
        leftCount(r->lc, p);
    }
}
void rightCount(node *r, int *p)
{
    if (r != NULL)
    {
        (*p)++;
        rightCount(r->rc, p);
    }
}

void findMax(node *r)
{
    while (r->rc != NULL)
    {
        r = r->rc;
    }
    printf("Max Data Node is %d", r->data);
}

int leafCount(node *r)
{
    if (r == NULL)
    {
        return 0;
    }
    if (r->rc == NULL && r->lc == NULL)
    {
        return 1;
    }

    return leafCount(r->rc) + leafCount(r->lc);
}

int countFullNodes(node *r)
{
    if (r == NULL)
        return 0;

    if (r->lc != NULL && r->rc != NULL)
        return 1 + countFullNodes(r->lc) + countFullNodes(r->rc);

    return countFullNodes(r->lc) + countFullNodes(r->rc);
}

int main()
{
    node *root = NULL;
    int choice, value;
    int count;

    while (1)
    {
        printf("\n--- BST MENU ---\n");
        printf("1. Insert Node\n");
        printf("2. Display Inorder\n");
        printf("3. Count Total Nodes\n");
        printf("4. Count Total Left Child\n");
        printf("5. Count Total Right Child\n");
        printf("6. Find Max Data Node\n");
        printf("7. Count Total Leaf Nodes\n");
        printf("8. Count Nodes Having Both Childeren\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insert(&root, value);
            break;
        case 2:
            Inorder(&root);
            break;
        case 3:
            count = 0;
            all(root, &count);
            printf("Total nodes = %d\n", count);
            break;
        case 4:
            count = 0;
            leftCount(root, &count);
            printf("Total Left Child = %d\n", count);
            break;
        case 5:
            count = 0;
            rightCount(root, &count);
            printf("Total Right Child = %d\n", count);
            break;
        case 6:
            findMax(root);
            break;

        case 7:
            leafCount(root);
            count = leafCount(root);
            printf("Total leaf nodes = %d\n", count);
            break;
        case 8:
            countFullNodes(root);
            count = countFullNodes(root);
            printf("Total nodes Having Both child = %d\n", count);
            break;

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}