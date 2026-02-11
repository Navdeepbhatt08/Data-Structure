#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int data;
    struct stack* next;
} stack ;

stack * push(stack*);
stack * pop(stack*);
void display(stack*);

main()
{
    
}

