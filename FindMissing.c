#include <stdio.h>
int findMissing(int a[], int n)
{
    int N = n + 1;

    int totalSum = N * (N + 1) / 2;

    int arrSum = 0;
    for (int i = 0; i < n; i++)
    {
        arrSum += a[i];
    }
    return totalSum - arrSum;
}

int main() {
    int i;
    int arr1[] = {1, 3, 4, 2, 5, 6, 9, 8};
    int ctr = sizeof(arr1) / sizeof(arr1[0]);
    // Finding and displaying the missing number
    printf("The missing number is : %d \n", findMissing(arr1, ctr));

    return 0;
}