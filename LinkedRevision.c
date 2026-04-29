#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *insert(node *ptr)
{
    int x;
    node *p = NULL;
    p = (node *)malloc(sizeof(node));
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

void display(node *ptr)
{

    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("Null");
}

void sum(node *ptr)
{
    int sum = 0;

    while (ptr != NULL)
    {
        sum = sum + ptr->data;
        ptr = ptr->next;
    }
    printf("Sum is : %d  ", sum);
}
void targetSum(node *ptr)
{
    int target;
    printf("Enter target : ");
    scanf("%d", &target);

    while (ptr != NULL)
    {
        if (ptr->data * ptr->next->data < target)
        {
            printf("Node Found : %d & %d ", ptr->data, ptr->next->data);
        }
        ptr = ptr->next;
    }
}

// Delete Duplicate Element
node *deleteDup(node *head)
{
    node *current = head;
    node *temp, *prev;

    while (current != NULL)
    {
        prev = current;
        temp = current->next;

        while (temp != NULL)
        {
            if (current->data == temp->data)
            {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        current = current->next;
    }

    return head;
}

main()
{
    int ch;
    node *head = NULL;
    do
    {
        printf("\nEnter choice : ");
        printf("\n1. Insert At Left");
        printf("\n2. Display ");
        printf("\n3. Sum ");
        printf("\n4. Target Sum ");
        printf("\n5. Delete Duplicate ");
        printf("\nEnter your choice : ");
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
            sum(head);
            break;
        case 4:
            targetSum(head);
            break;
        case 5:
            head = deleteDup(head);
            break;
        default:
            break;
        }
    } while (ch != 10);
}