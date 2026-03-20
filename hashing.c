#define m 10
#include<stdio.h> 
main()
{

    int ht[m],i,key;
    ht[i]=-1;
    while (1)
    {
        printf("Enter the key ");
        scanf("%d",&key);
        i=key%m;

        ht[i]=key;
    }
}