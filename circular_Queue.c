#include<stdio.h>
#define max 5

int Cenqueue(int[],int,int);
int Cdequeue(int[],int,int);

main()
{
    int  cq[max],rear=-1,front = -1,ch;
     do
     {
        printf("\n 1. insert queue \n 2. Delete Element \n 3. Display \n 4. peek \n Enter your choice \n ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
            rear = Cenqueue(cq,front,rear);
            if(front == -1 )
            {
                 front = 0;
            }
            break;

            case 2:
            rear = Cenqueue(cq,front,rear);
            if(front == -1 )
            {
                 front = 0;
            }
            break;
        }
     }
    
}

