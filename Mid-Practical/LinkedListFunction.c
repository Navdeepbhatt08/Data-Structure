#include <stdio.h>
#include <stdlib.h>

typedef struct slist
{
    int data;
    struct slist *next;
} slist;

slist *insert(slist *ptr)
{
    int x;
    slist *p = NULL;

    p = (slist *)malloc(sizeof(slist));
    if (p == NULL)
    {
        printf("Memory Allocation failed ");
        return ptr;
    }
    printf("Enter  Data : ");
    scanf("%d", &x);
    p->data = x;
    p->next = ptr;
    ptr = p;
    return ptr;
}
void display(slist *node)
{
    if (node == NULL)
    {
        printf("List is Empty \n");
        return;
    }
    while (node != NULL)
    {
        printf("%d->", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void dispCicular(slist *head)
{
    slist *ptr;

    ptr = head;
    while (ptr->next != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("%d->", ptr->data);
    printf("Back To First");
}

void DispSingly(slist *head)
{
    slist *ptr;
    ptr = head;
     while(ptr->next!=head)
     {
        printf("%d->",ptr->data);
        ptr = ptr ->next;
     }
     printf("%d->",ptr->data);
    printf("NULL");
}

slist *BubbleSort(slist *ptr)
{
    int temp;
    slist *i, *j;
    for (i = ptr; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("Sorted List : ");
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("Null");
}


slist *deleteMiddle(slist *ptr)
{
    slist *slow = ptr;
    slist *fast = ptr;
    slist *prev = NULL;
    while(fast!=NULL && fast->next!=NULL )
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    prev->next = slow->next;
    free(slow);

printf("Middle Deleted");
slist *temp = ptr;

while(temp!=NULL)
{
    printf("%d->",temp->data);
    temp = temp->next;
}
    return ptr;

}
main()
{
    int ch;
    slist *head = NULL;
    do
    {
        printf("\nEnter choice : ");
        printf("\n1. Insert At Left");
        printf("\n2. Display");
        printf("\n3. Display Circular");
        printf("\n4. Sort");
        printf("\n5. Delete Middle");
        printf("\n6. Disp Singly");

        printf("\nChoice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            head = insert(head);
            break;

        case 2:
            display(head);
            break;
        case 3:
            dispCicular(head);
            break;
        case 4:
            BubbleSort(head);
            break;
        case 5:
            head = deleteMiddle(head);
            break;
        case 6:
           DispSingly(head);
            break;
        }

    } while (ch < 100);
}