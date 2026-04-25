#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char name[50];
    int roll_no;
    struct node *next;
} node;

node *insert(node *head)
{
    node *p = (node *)malloc(sizeof(node));

    printf("Enter Name    : ");
    scanf(" %[^\n]", p->name);
    printf("Enter Roll No : ");
    scanf("%d", &p->roll_no);
    p->next = NULL;

    if (head == NULL)
        return p;

    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = p;

    return head;
}
void display(node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("\n%-5s %-20s %s\n", "S.No", "Name", "Roll No");

    int i = 1;
    node *temp = head;
    while (temp != NULL)
    {
        printf("%-5d %-20s %d\n", i++, temp->name, temp->roll_no);
        temp = temp->next;
    }
}

node *delete_duplicates(node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return head;
    }

    int deleted = 0;
    node *outer = head;

    while (outer != NULL)
    {
        node *prev = outer;
        node *inner = outer->next;

        while (inner != NULL)
        {

            if (strcasecmp(outer->name, inner->name) == 0)
            {
                printf("Duplicate found  → Name: %-20s Roll No: %d  [DELETED]\n",
                       inner->name, inner->roll_no);

                prev->next = inner->next;
                free(inner);
                inner = prev->next;
                deleted++;
            }
            else
            {
                prev = inner;
                inner = inner->next;
            }
        }

        outer = outer->next;
    }

    if (deleted == 0)
        printf("No duplicate names found.\n");
    else
        printf("\nTotal duplicates deleted: %d\n", deleted);

    return head;
}

node *delete_all(node *head)
{
    node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("All nodes deleted.\n");
    return NULL;
}

int main()
{
    node *head = NULL;
    int ch;

    while (1)
    {
        printf("1. Insert Student\n");
        printf("2. Display List\n");
        printf("3. Delete Duplicate Names\n");
        printf("4. Clear List\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            head = insert(head);
            printf("Student inserted successfully.\n");
            break;

        case 2:
            display(head);
            break;

        case 3:
            printf("\nDeleting Duplicate Names\n");
            head = delete_duplicates(head);
            break;

        case 4:
            head = delete_all(head);
            break;

        case 5:
            head = delete_all(head);
            exit(0);

        default:
            printf("Invalid choice. Try again.\n");
        }
    }
}