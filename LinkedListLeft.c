#include<stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
} sl;

main()
{
    int n, i;
    sl *head = NULL, *newNode, *temp;       

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        newNode = (sl*)malloc(sizeof(sl));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = head;
        head = newNode;
    }
    printf("The linked list is: ");
    temp = head;
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
}