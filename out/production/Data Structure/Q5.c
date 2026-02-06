#include <stdio.h>
int main()
{
    int n, arr[10], i, d, flag = 1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    d = arr[1] - arr[0];
    for (i = 2; i < n; i++)
    {
        if (arr[i] - arr[i - 1] != d)
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
    {
        printf("This Is A P");
    }
    else
        printf("Not A P ");

    return 0;
}