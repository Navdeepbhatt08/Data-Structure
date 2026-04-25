#include <stdio.h>

struct node
{
    int data;
    struct node *lc, *rc;
} typedef node;

node *p = NULL;

main()
{
    int ch, a, ch1, f = 0, cnt, h;
    ;
    node *root = NULL, *ser;
    while (1)
    {
        system("cls");
        printf("\n\t1. Insert\n\t2. Preorder Display\n\t3. Inorder Display\n\t4. Postorder Display\n\t5. Search\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n\tenter data to insert : ");
            scanf("%d", &a);
            insert(&root, a);
            break;

        case 2:
            if (root == NULL)
            {
                printf("\n\ttree is empty");
            }
            else
            {
                printf("\n\t");
                preorder(&root);
            }
            getch();
            break;

        case 3:
            if (root == NULL)
            {

                printf("\n\ttree is empty");
            }
            else
            {
                printf("\n\t");
                inorder(&root);
            }
            getch();
            break;

        case 4:
            if (root == NULL)
            {
                printf("\n\ttree is empty");
            }
            else
            {
                printf("\n\t");
                postorder(&root);
            }
            getch();
            break;

        case 5:
            if (root == NULL)
            {
                printf("\n\ttree is empty");
            }
            else
            {
                printf("\n\tenter data to search : ");
                scanf("%d", &a);
                ser = search(&root, a);
                if (ser == NULL)
                {
                    printf("\n\tdata not found");
                }
                else
                {
                    printf("\n\tdata found : %d", ser->data);
                    if (ser->data > p->data)
                    {
                        printf("\n\t%d is right child of %d", ser->data, p->data);
                    }
                    else if (ser->data < p->data)
                    {
                        printf("\n\t%d is left child of %d", ser->data, p->data);
                    }
                    else
                    {
                        printf("\n\t%d is root node", ser->data);
                    }
                }
            }
            getch();
            break;

        default:
            printf("\n\n\tinvalid choice");
            getch();
            break;
        }
    }
}

insert(node **r, int n)
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

preorder(node **r)
{
    if (*r != NULL)
    {
        printf("%d ", (*r)->data);
        preorder(&((*r)->lc));
        preorder(&((*r)->rc));
    }
}

inorder(node **r)
{
    if (*r != NULL)
    {
        inorder(&((*r)->lc));
        printf("%d ", (*r)->data);
        inorder(&((*r)->rc));
    }
}

postorder(node **r)
{
    if (*r != NULL)
    {
        postorder(&((*r)->lc));
        postorder(&((*r)->rc));
        printf("%d ", (*r)->data);
    }
}

search(node **r, int n)
{
    node *z;
    p = z = *r;
    while (z != NULL)
    {
        if (z->data == n)
        {
            return (z);
        }
        else if (z->data > n)
        {
            p = z;
            z = z->lc;
        }
        else
        {
            p = z;
            z = z->rc;
        }
    }
    return (z);
}