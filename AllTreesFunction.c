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
        printf("\n\t1. Insert\n\t2. Preorder Display\n\t3. Inorder Display\n\t4. Postorder Display\n\t5. Search\n\t6. Delete\n\t7. Count Nodes\n\t8. Height\n\t9. Exit\n\n\tEnter your choice : ");
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

        case 6:
            if (root == NULL)
            {
                printf("\n\ttree is empty");
                getch();
            }
            else
            {
                printf("\n\tenter node data to delete : ");
                scanf("%d", &a);
                del(&root, a);
            }
            break;

        case 7:

            while (1)
            {
                printf("\n\n\tcount nodes with following criteria");
                printf("\n  \t-----------------------------------");
                printf("\n\t1. All nodes\n\t2. leaf nodes\n\t3. node having left child obly\n\t4. node having right child only\n\t5. node with both child\n\t6. back\n\n\tenter choice : ");
                scanf("%d", &ch1);
                f = 0;
                switch (ch1)
                {
                case 1:
                    cnt = 0;
                    all(root, &cnt);
                    printf("\n\ttotal nodes are : %d", cnt);
                    getch();
                    break;
                case 2:
                    cnt = 0;
                    leafch(root, &cnt);
                    printf("\n\ttotal leaf ndoes are : %d", cnt);
                    getch();
                    break;

                case 3:
                    cnt = 0;
                    leftch(root, &cnt);
                    printf("\n\tndoes with only left child : %d", cnt);
                    getch();
                    break;

                case 4:
                    cnt = 0;
                    rightch(root, &cnt);
                    printf("\n\tndoes with only right child : %d", cnt);
                    getch();
                    break;

                case 5:
                    cnt = 0;
                    bothch(root, &cnt);
                    printf("\n\tndoes with both childs : %d", cnt);
                    getch();
                    break;

                case 6:
                    f = 5;
                    break;

                default:
                    printf("\n\twrong choics");
                    getch();
                    break;
                }
                if (f == 5)
                {
                    break;
                }
            }

            break;

        case 8:
            h = height(root);
            printf("\n\theight of binary search tree : %d", h);
            getch();
            break;
        case 9:
            exit(0);

        default:
            printf("\n\n\tinvalid choice");
            getch();
            break;
        }
    }
}

insert(node **r, int n) /// Recursive insrtion
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

/*
insert(node **r,int n)      ///  Non recursive insertion
{
    node *t,*z;
    t=malloc(sizeof(node));
    t->data=n;
    t->lc=t->rc=NULL;

    if(*r==NULL)
    {
        *r=t;
        return;
    }
    p=z=*r;
    while(z!=NULL)
    {
            if(z->data==n)
            {
                return;
            }
            if(n > z->data)
            {
                p=z;
                z=p->rc;
            }
            else
            {
                p=z;
                z=p->lc;
            }
    }

    if(n > p->data)
    {
        p->rc=t;
    }
    else
    {
        p->lc=t;
    }
}

*/

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

del(node **r, int n)
{
    node *d, *ios;
    d = search(r, n);
    if (d == NULL)
    {
        printf("\n\tdata not found");
        getch();
        return;
    }

    if (d->lc == NULL && d->rc == NULL) // case 1: if node to be deleted is leaf
    {
        if (d == p->lc)
        {
            p->lc = NULL;
        }
        else
        {
            p->rc = NULL;
        }
        free(d);
        return;
    }

    if (d->lc != NULL && d->rc == NULL) // case 1: if node to be deleted has only left child
    {
        if (d == p->lc)
        {
            p->lc = d->lc;
        }
        else
        {
            p->rc = d->lc;
        }
        d->lc = NULL;
        free(d);
        return;
    }

    if (d->lc == NULL && d->rc != NULL) // case 1: if node to be deleted has only right child
    {
        if (d == p->lc)
        {
            p->lc = d->rc;
        }
        else
        {
            p->rc = d->rc;
        }
        d->rc = NULL;
        free(d);
        return;
    }

    if (d->lc != NULL && d->rc != NULL) // case 1: if node to be deleted has both child
    {
        p = d;
        ios = p->rc;
        while (ios->lc != NULL)
        {
            p = ios;
            ios = p->lc;
        }

        d->data = ios->data;

        if (ios->rc == NULL)
        {
            if (ios == p->lc)
            {
                p->lc = NULL;
            }
            else
            {
                p->rc = NULL;
            }
        }
        else
        {
            if (ios == p->lc)
            {
                p->lc = ios->rc;
            }
            else
            {
                p->rc = ios->rc;
            }
            ios->rc = NULL;
        }
        free(ios);
        return;
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

void leafch(node *r, int *p)
{
    if (r != NULL)
    {
        if (r->lc == NULL && r->rc == NULL)
        {
            (*p)++;
        }
        leafch(r->lc, p);
        leafch(r->rc, p);
    }
}

void leftch(node *r, int *p)
{
    if (r != NULL)
    {
        if (r->lc != NULL && r->rc == NULL)
        {
            (*p)++;
        }
        leftch(r->lc, p);
        leftch(r->rc, p);
    }
}

void rightch(node *r, int *p)
{
    if (r != NULL)
    {
        if (r->lc == NULL && r->rc != NULL)
        {
            (*p)++;
        }
        rightch(r->lc, p);
        rightch(r->rc, p);
    }
}

void bothch(node *r, int *p)
{
    if (r != NULL)
    {
        if (r->lc != NULL && r->rc != NULL)
        {
            (*p)++;
        }
        bothch(r->lc, p);
        bothch(r->rc, p);
    }
}

int height(node *r)
{
    int lh, rh;
    if (r == NULL)
    {
        return (0);
    }
    else
    {
        lh = height(r->lc);
        rh = height(r->rc);

        if (lh > rh)
        {
            return (lh + 1);
        }
        else
        {
            return (rh + 1);
        }
    }
}
