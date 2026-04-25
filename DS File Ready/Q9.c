#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void deleteRoot(int arr[], int *n)
{
    arr[0] = arr[*n - 1];
    (*n)--;

    heapify(arr, *n, 0);
}

int main()
{
    int arr[] = {10, 5, 20, 2, 4};
    int n = 5;

    buildHeap(arr, n);

    printf("Heap: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    deleteRoot(arr, &n);

    printf("\nAfter Deletion: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}