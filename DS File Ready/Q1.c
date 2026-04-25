#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void *insert(node *head)
{
    struct node *p, *temp;

    p = (node *)malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d", &p->data);

    p->next = NULL;

    if (head == NULL)
        head = p;
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = p;
    }
    return head;
}

void display(node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void *reverse(node *head)
{
    struct node *prev = NULL, *curr = head, *next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
    return prev;
}

int main()
{
    struct node *head = NULL;
    int ch;

    while (1)
    {
        printf("\n1.Insert\n2.Display\n3.Reverse\n4.Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
           head =  insert(head);
            break;
        case 2:
            display(head);
            break;
        case 3:
           head =  reverse(head);
            break;
        case 4:
            exit(0);
        }
    }
}