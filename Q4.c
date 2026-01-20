#include <stdio.h>
int main()
{
    int a[10], n, i, j, count;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Frequency of each element:\n");

    for (i = 0; i < n; i++)
    {
        if (a[i] == -1)
            continue;

        count = 1;
        for (j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                count++;
                a[j] = -1;
            }
        }

        printf("%d occurs %d times\n", a[i], count);
    }

    return 0;
}
