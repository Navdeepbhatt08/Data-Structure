#include <stdio.h>

void disp(int);

int main()
{
    int N = 10;
    disp(N);
}
void disp(int N)
{
    if (N == 0)
        return;
    printf("%d ", N);
    disp(N - 1);
}