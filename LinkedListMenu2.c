#include <stdio.h>

typedef struct node
{
    int info;
    struct node *next;
} list;

main()
{
    list *l, *r;
    l = r = NULL;
    int ch, a;
    while (1)
    {
        system("cls");
        printf("\n\t1. Insetr at begining\n\t2. Insert at end\n\t3. Insert at specific position\n\t4. Delete\n\t5. Display All\n\t6. Sort\n\t7. Reverse Display\n\t8. Exit\n\n\tEntr your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n\tenter data to  insert : ");
            scanf("%d", &a);
            insbeg(&l, &r, a);
            break;

        case 2:
            printf("\n\tenter data tom  insert : ");
            scanf("%d", &a);
            insend(&l, &r, a);
            break;

        case 3:
            printf("\n\tenter node position : ");
            scanf("%d", &a);
            inspos(&l, &r, a);
            break;
            break;

        case 4:
            printf("\n\tenter node data to delete : ");
            scanf("%d", &a);
            del(&l, &r, a);
            break;

        case 5:
            disp(l);
            break;

        case 6:
            sort(&l);
            break;

        case 7:
            printf("\n\n\t");
            revdisp(l, r);
            getch();
            break;

        case 8:
            exit(0);

        default:
            printf("\n\n\tinvalid choice");
            getch();
            break;
        }
    }
}

insbeg(list **L, list **R, int n) // L=&l - > *L==l       R=&r -> *R==r
{
    list *t;
    t = malloc(sizeof(list));
    t->info = n;
    t->next = NULL;

    t->next = *L;
    *L = t;
    if (*R == NULL)
    {
        *R = t; // or R=L;
    }
}

insend(list **L, list **R, int n)
{
    list *t;
    t = malloc(sizeof(list));
    t->info = n;
    t->next = NULL;

    if (*R == NULL)
    {
        *L = *R = t;
        return;
    }
    (*R)->next = t;
    *R = t;
    t->next = NULL;
}

inspos(list **L, list **R, int p)
{
    list *a, *b, *t;
    int c = 0, i;
    a = *L;
    while (a != NULL)
    {
        a = a->next;
        c++;
    }
    if (p > (c + 1) || p < 0)
    {
        printf("\n\n\tposition doesn't exist");
        getch();
        return;
    }

    t = malloc(sizeof(list));
    printf("\n\tenter node data to insert : ");
    scanf("%d", &(t->info));
    t->next = NULL;

    a = b = *L;

    if (p == 1)
    {
        t->next = (*L);
        (*L) = t;
        if (*R == NULL)
        {
            *R = t;
        }
        return;
    }

    for (i = 0; i < p - 1; i++)
    {
        a = b;
        b = a->next;
    }
    a->next = t;
    t->next = b;
    if (b == NULL)
    {
        *R = t;
    }
}

sort(list **L)
{
    list *i, *j;
    int x;
    i = *L;
    while (i->next != NULL)
    {
        j = i->next;
        while (j != NULL)
        {
            if (i->info > j->info)
            {
                x = i->info;
                i->info = j->info;
                j->info = x;
            }
            j = j->next;
        }
        i = i->next;
    }
}

del(list **L, list **R, int n)
{
    list *a, *b;
    if (*L == NULL)
    {
        printf("\n\n\tlinked list is empty");
        getch();
        return;
    }
    a = b = *L;
    if ((*L)->info == n)
    {
        *L = (*L)->next;
        a->next = NULL;
        free(a);
        if (*L == NULL)
        {
            *R = NULL;
        }
        printf("\n\tdata deleted");
        getch();
        return;
    }
    while (b != NULL)
    {
        a = b;
        b = a->next;
        if (b == NULL)
        {
            break;
        }
        if (b->info == n)
        {
            a->next = b->next;
            b->next = NULL;
            if (b == *R) // if node to be deleted is the last node
            {
                (*R) = a;
            }
            free(b);
            printf("\n\tdata deleted");
            getch();
            return;
        }
    }
    printf("\n\n\tdata not found");
    getch();
}

disp(list *L)
{
    list *t;
    if (L == NULL)
    {
        printf("\n\tliked list is empty");
        getch();
        return;
    }
    t = L;
    printf("\n\n\t");
    while (t != NULL)
    {
        printf("%d  ", t->info);
        t = t->next;
    }
    getch();
}

/*
revdisp(list *L,list *R)                // RECURSIVE REVERSE DISPLAY
{
    if(L!=NULL)
    {
        revdisp(L->next);
        printf("%d  ",L->info);

    }
}
*/

revdisp(list *L, list *R) // ITERATIVE REVERSE DISPLAY
{
    list *a, *b;
    b = R;
    while (b != L)
    {
        a = L;
        while (a->next != b)
        {
            a = a->next;
        }

        printf("%d  ", b->info);
        b = a;
    }
    printf("%d", b->info);
}
