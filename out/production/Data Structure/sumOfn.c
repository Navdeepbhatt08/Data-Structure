#include<stdio.h>
int sum(int);
int main()
{
  int n = 10;
  printf("The Sum of first %d numbers = %d ",n,sum(n));
  return 0 ;
}

int sum(int n)
{ 
    if(n==0)
    return 0;
    else 
    return n+sum(n-1);

}