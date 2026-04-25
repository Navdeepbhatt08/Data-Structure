#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *insert(node *head)
{
    int data;
    node *p = (node *)malloc(sizeof(node));

    printf("Enter data: ");
    scanf("%d", &data);

    p->data = data;
    p->next = head;
    head = p;

    return head;
}

void display(node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int checkMultiplication(node *head, int target)
{
    node *p, *q;

    for (p = head; p != NULL; p = p->next)
    {
        for (q = p->next; q != NULL; q = q->next)
        {
            if ((p->data * q->data) < target)
            {
                printf("Nodes found: %d and %d\n", p->data, q->data);
                return 1;
            }
        }
    }

    return 0;
}
int main()
{
    node *head = NULL;
    int ch;

    while (1)
    {
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Check mult\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
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
        {
            int target;
            printf("Enter target: ");
            scanf("%d", &target);

            if (checkMultiplication(head, target))
                printf("Yes, such nodes exist\n");
            else
                printf("No such nodes exist\n");

            break;
        }

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}