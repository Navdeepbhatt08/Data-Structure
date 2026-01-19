#include <stdio.h>

int main()
{
    int arr[100], pos[100], neg[100], zero[100];
    int n, i;
    int p = 0, ne = 0, z = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);

        if (arr[i] > 0)
            pos[p++] = arr[i];
        else if (arr[i] < 0)
            neg[ne++] = arr[i];
        else
            zero[z++] = arr[i];
    }

    printf("\nPositive elements:\n");
    for (i = 0; i < p; i++)
        printf("%d ", pos[i]);

    printf("\nNegative elements:\n");
    for (i = 0; i < ne; i++)
        printf("%d ", neg[i]);

    printf("\nZero elements:\n");
    for (i = 0; i < z; i++)
        printf("%d ", zero[i]);

    return 0;
}
