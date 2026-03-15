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

slist *insertEnd(slist *ptr)
{
    int x;
    slist *p = NULL, *temp = NULL;

    p = (slist *)malloc(sizeof(slist));
    if (p == NULL)
    {
        printf("Memory Allocation failed");
        return ptr;
    }

    printf("Enter Data: ");
    scanf("%d", &x);

    p->data = x;
    p->next = NULL;

    if (ptr == NULL)
    {
        ptr = p;
    }
    else
    {
        temp = ptr;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
    }

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

void findMax(slist *node)
{
    int max;
    if (node == NULL)
    {
        printf("List is Empty \n");
        return;
    }
    max = node->data;
    while (node != NULL)
    {
        if (node->data > max)
        {
            max = node->data;
        }
        node = node->next;
    }
    printf("max element is %d ", max);
}

void findMin(slist *node)
{
    int min;
    if (node == NULL)
    {
        printf("Empty");
    }
    min = node->data;
    while (node != NULL)
    {
        if (node->data < min)
        {
            min = node->data;
        }
        node = node->next;
    }
    printf("Min Element is %d ", min);
}

void findAlternate(slist *node)
{
    if (node == NULL)
    {
        printf("Empty");
    }
    while (node != NULL)
    {
        printf("%d-> ", node->data);
        node = node->next->next;
    }
}

slist *deleteAlternate(slist *node)
{
    slist *temp;

    if (node == NULL)
    {
        printf("Empty");
    }
    while (node != NULL && node->next != NULL)

    {
        temp = node->next;
        node->next = temp->next;
        free(temp);
        node = node->next;
    }
    printf("Alternate Deleted");
    return node;
}
slist *deleteFirst(slist *ptr)
{
    slist *temp;

    if (ptr == NULL)
    {
        printf("List is Empty");
        return NULL;
    }

    temp = ptr;
    ptr = ptr->next;
    free(temp);

    printf("First Element Deleted\n");
    return ptr;
}

slist *deleteLast(slist *ptr)
{
    slist *p = ptr;
    slist *q = NULL;

    if (ptr == NULL)
        return NULL;

    if (ptr->next == NULL)
    {
        free(ptr);
        return NULL;
    }

    while (p->next != NULL)
    {
        q = p;
        p = p->next;
    }

    q->next = NULL;
    free(p);
    printf("Last Element Deleted");
    return ptr;
}

void search(slist *ptr)
{
    int key;
    printf("Enter the element you want to search: ");
    scanf("%d", &key);

    while (ptr != NULL)
    {
        if (ptr->data == key)
        {
            printf("Element Found\n");
            return;
        }
        ptr = ptr->next;
    }

    printf("Element Not Found\n");
}

main()
{
    int ch;
    slist *head = NULL;
    do
    {
        printf("\nEnter choice : ");
        printf("\n1. Insert At Left");
        printf("\n2. Insert At Right");
        printf("\n3. Display");
        printf("\n4. Find Max Element");
        printf("\n5. Find Min Element");
        printf("\n6. Find Alternate");
        printf("\n7. delete Alternate");
        printf("\n8. delete First ");
        printf("\n9. delete Last");
        printf("\n10. Search ");
        printf("\n11. Exit");
        printf("\nChoice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            head = insert(head);
            break;

        case 2:
            head = insertEnd(head);
            break;
        case 3:
            display(head);
            break;
        case 4:
            findMax(head);
            break;
        case 5:
            findMin(head);
            break;
        case 6:
            findAlternate(head);
            break;
        case 7:
            deleteAlternate(head);
            break;
        case 8:
            head = deleteFirst(head);
            break;
        case 9:
            head = deleteLast(head);
            break;
        case 10:
            search(head);
            break;

        default:
            break;
        }

    } while (ch < 100);
}