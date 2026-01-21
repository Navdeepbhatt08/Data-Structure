#define MAX 10

#include <stdio.h>
int stack[MAX], top = -1;
int push(int);

int main()
{

    push(10);
    push(20);
    push(30);
    push(40);

    return 0;
}

int push(int x)
{
    if (top == MAX - 1)
    {
        printf("The Stack Is Full :");
    }
    else
        top++;
    stack[top] = x;
    printf("\n %d Pushed Into Stack ", x);

}