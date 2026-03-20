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

void findDuplicate(slist *head)
{
    slist *ptr1, *ptr2;

    for (ptr1 = head; ptr1->next != NULL; ptr1 = ptr1->next)
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next)
        {
            if (ptr1->data == ptr2->data)
            {
                printf("%d -> ", ptr1->data);
                break;
            }
        }
}

slist *deleteAlter(slist *ptr)
{
    slist *temp;
    slist *head = ptr;

    while (ptr != NULL && ptr->next != NULL)
    {
        temp = ptr->next;
        ptr->next = temp->next;
        free(temp);
        ptr = ptr->next;
    }
    ptr = head;

    while (ptr != NULL)
    {
        printf("%d ->", ptr->data);
        ptr = ptr->next;
    }
    return head;
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

slist *reverseList(slist *ptr)
{
    slist *prev = NULL;
    slist *curr = ptr;
    slist *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    printf("Reversed List \n");
    while (prev != NULL)
    {
        printf("%d->", prev->data);
        prev = prev->next;
    }
    printf("NULL\n");
}

slist * 

main()
{
    int ch;
    slist *head = NULL;
    do
    {
        printf("\nEnter choice : ");
        printf("\n1. Insert At Left");
        printf("\n2. Insert At Right");
        printf("\n3. Display the List");
        printf("\n4. Find Max Element");
        printf("\n5. Find Min Element");
        printf("\n6. Find Alternate");
        printf("\n7. delete Alternate");
        printf("\n8. delete First ");
        printf("\n9. delete Last");
        printf("\n10. Search ");
        printf("\n11. Reverse Linked List ");
        printf("\n12. Delete Alternate");
        printf("\n13. Find Duplicate");

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
        case 11:
            reverseList(head);
            break;
        case 12:
            deleteAlter(head);
            break;
        case 13:
            findDuplicate(head);
            break;

        default:
            break;
        }

    } while (ch < 100);
}