#include<stdio.h>

int fibbo(int);

int main()
{
    int n =10;
     for ( int i = 0; i < 8; i++)
     {
        printf("%d ",fibbo(i));
     }
     return 0 ;
     
} //This is our Fibonacci Series

int fibbo(int n )
{
    if(n==0 || n==1)
    return n;
    else
    return (fibbo(n-1)+fibbo(n-2));
}