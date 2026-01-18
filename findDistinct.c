#include <stdio.h>

void distinctElements(int arr[], int size)
{
    printf("Distinct elements in the array are: ");
    for (int i = 0; i < size; i++)
    {
        int isDistinct = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                isDistinct = 0;
                break;
            }
        }
        if (isDistinct)
        {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main()
{
    int arr[] = {1, 4, 6, 1, 2, 8, 4, 7, 6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    printDistinctElements(arr, n);
    return 0;
}
