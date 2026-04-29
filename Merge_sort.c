#include <stdio.h>

void merge(int A[], int t[], int lb, int mid, int ub)
{
    int i = lb;      // left subarray pointer
    int j = mid + 1; // right subarray pointer
    int k = lb;      // temp array pointer

    // Merge both halves
    while (i <= mid && j <= ub)
    {
        if (A[i] <= A[j])
        {
            t[k++] = A[i++];
        }
        else
        {
            t[k++] = A[j++];
        }
    }

    // Copy remaining elements
    while (i <= mid)
    {
        t[k++] = A[i++];
    }

    while (j <= ub)
    {
        t[k++] = A[j++];
    }

    // Copy back to original array
    for (i = lb; i <= ub; i++)
    {
        A[i] = t[i];
    }
}

void m_sort(int A[], int t[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;

        m_sort(A, t, lb, mid);
        m_sort(A, t, mid + 1, ub);

        merge(A, t, lb, mid, ub);
    }
}

int main()
{
    int A[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(A) / sizeof(A[0]);

    int temp[n];

    m_sort(A, temp, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}