#define MAX 10
#include<stdio.h>

int stack[MAX];
int top= -1;

int push(int x)
{
  if(top==MAX-1)
  {
    printf("The Stack is full");
  }
  else
  {
    top++;
    stack[top]=x;
    printf("%d Pushed Into Stack \n",x);
  }
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    return 0;
}