#include <stdio.h>

int main()
{
    int a[100], n, i;
    int d, missing = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    d = a[1] - a[0];
    for(i = 2; i < n; i++)
    {
        if(a[i] - a[i - 1] < d)
            d = a[i] - a[i - 1];
    }

    for(i = 1; i < n; i++)
    {
        if(a[i] - a[i - 1] != d)
        {
            missing = a[i - 1] + d;
            break;
        }
    }

    if(missing != 0)
    {
        printf("Missing term is: %d\n", missing);
        printf("AP series including missing term:\n");

        for(i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
            if(a[i] + d == missing)
                printf("%d ", missing);
        }
    }
    else
    {
        printf("The given sequence is a complete AP (no missing term)");
    }

    return 0;
}
