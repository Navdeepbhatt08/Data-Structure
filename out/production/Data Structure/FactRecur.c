#include<stdio.h>
int fact(n);

int main(){

    int n = 5;
    printf("The Factorial of %d is = %d ",n,fact(n));
    return 0 ;
}
int fact(int n )
{
    if(n==1)
    return 1;
    else 
    return n*fact(n-1);
}