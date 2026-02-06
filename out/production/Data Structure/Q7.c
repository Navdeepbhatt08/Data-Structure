  #include <stdio.h>
int main()
{
    int n, i, j;
    int arr[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int lastNeg = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] < 0)
     {
            int temp = arr[i];
            for (j = i; j > lastNeg; j--)
            {
                arr[j] = arr[j - 1];
            }
            arr[lastNeg] = temp;
            lastNeg++;
        }
    }
    printf("After separating negae and positive elements:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

