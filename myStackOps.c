#include<stdio.h>
#define max 5

int push(int top, int stack[]);
int pop(int top, int stack[]);
void disp(int top, int stack[]);

main()
{
    int stack[max],top = -1,ch;
    do
    {
        printf("1. Push \n2. POP \n3. Display \n Enter your choice : ");
        scanf("%d",&ch);
          switch (ch)
          {
          case 1:
          top = push(top , stack[])  
          break;
          
          default:
            break;
          }

    } while (ch<=4);
    
}