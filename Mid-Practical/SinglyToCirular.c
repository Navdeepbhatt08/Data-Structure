#include <stdio.h>
#include <stdlib.h>

typedef struct slist
{
    int data;
    struct slist *next;
} node;

node *insert(node *ptr);
void display(node *ptr);
void displayCircular(node *head);
node *convertCircular(node *head);

int main()
{
    int ch;
    node *head = NULL;

    do
    {
        printf("\n1. Insert At Left");
        printf("\n2. Display Simple List");
        printf("\n3. Convert into Circular");
        printf("\n4. Display Circular List");
        printf("\n5. Exit");
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
            head = convertCircular(head);
            break;

        case 4:
            displayCircular(head);
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice\n");
        }

    } while (1);
}

node *insert(node *ptr)
{
    int x;
    node *p;

    p = (node *)malloc(sizeof(node));

    printf("Enter element: ");
    scanf("%d", &x);

    p->data = x;
    p->next = ptr;
    ptr = p;

    return ptr;
}

void display(node *ptr)
{
    if (ptr == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }

    printf("NULL\n");
}

node *convertCircular(node *head)
{
    node *ptr = head;

    if (head == NULL)
    {
        printf("List Empty\n");
        return head;
    }

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = head;

    printf("Converted to Circular Linked List\n");

    return head;
}

void displayCircular(node *head)
{
    node *ptr;

    if (head == NULL)
    {
        printf("List Empty\n");
        return;
    }

    ptr = head;

    while (ptr->next != head)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }

    
printf("%d -> ", ptr->data);   
printf("(Back to Head)\n");
}