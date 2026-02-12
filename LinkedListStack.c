#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *push(Node *);
Node *pop(Node *);
void disp(Node *);
void revdisp(Node *);

int main()
{
    Node *top = NULL;
    int choice;

    while (1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Reverse Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            top = push(top);
            break;

        case 2:
            top = pop(top);
            break;

        case 3:
            disp(top);
            break;

        case 4:
            revdisp(top);
            break;

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

Node *push(Node *top)
{
    int x;
    Node *p = NULL;
    p = (Node *)malloc(sizeof(Node));
    if (p != NULL)
    {
        printf("Enter data : ");
        scanf("%d", &x);
        p->data = x;
        p->next = top;
        top = p;
    }
    return (top);
}
Node *pop(Node *top)
{
    int x;
    Node *p = NULL;
    if (top == NULL)
    {
        printf("Empty");
    }
    else
    {
        x = top->data;
        printf("%d poped\n", x);
        p = top;
        top = top->next;
        free(p);
    }
    return (top);
}
void disp(Node *top)
{
    if (top == NULL)
    {
        printf("Whattt......? It's empty brother..");
    }
    else
    {
        while (top != NULL)
        {
            printf("\n%d", top->data);
            top = top->next;
        }
        printf("\n");
    }
}

void revdisp(Node *top)
{
    if (top == NULL)
    {
        printf("Whattt......? It's empty brother..\n");
        return;
    }
    revdisp(top->next);
    printf("\n%d\n", top->data);
}
