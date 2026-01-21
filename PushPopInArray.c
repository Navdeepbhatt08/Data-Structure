#include <stdio.h>
#define MAX 5

void push(int stack[], int *top);
void pop(int stack[], int *top);
void peek(int stack[], int top);
void display(int stack[], int top);

int main()
{
    int stack[MAX];
    int top = -1;   
    int choice;

    while (1)
    {
        printf("\n--- STACK OPERATIONS ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push(stack, &top);
            break;

        case 2:
            pop(stack, &top);
            break;

        case 3:
            peek(stack, top);
            break;

        case 4:
            display(stack, top);
            break;

        case 5:
            printf("Exiting program.\n");
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}

void push(int stack[], int *top)
{
    int item;
    if (*top == MAX - 1)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        printf("Enter element to push: ");
        scanf("%d", &item);
        (*top)++;
        stack[*top] = item;
        printf("Element pushed successfully.\n");
    }
}

// Pop operation
void pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack Underflow!\n");
    }
    else
    {
        printf("Popped element: %d\n", stack[*top]);
        (*top)--;
    }
}

// Peek operation
void peek(int stack[], int top)
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Top element is: %d\n", stack[top]);
    }
}

// Display operation
void display(int stack[], int top)
{
    int i;
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}
