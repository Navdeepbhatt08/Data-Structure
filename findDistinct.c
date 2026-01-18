#include <stdio.h>
// Main function
int main()
{
    int arr1[100], n, ctr = 0;  // Declare an array to store integer values, n for array size, and ctr for counting duplicates
    int i, j, k;  // Declare loop counters
 
    
    printf("Input %d elements in the array :\n", n);
    for (i = 0; i < n; i++)
    {
        printf("element - %d : ", i);
        scanf("%d", &arr1[i]);  // Read the input and store it in the array
    }
    // Print unique elements in the array
    printf("\nThe unique elements found in the array are: \n");
    for (i = 0; i < n; i++)
    {
        ctr = 0;  // Reset the counter for each element
        for (j = 0, k = n; j < k + 1; j++)
        {
            /* Increment the counter when the search value is duplicate. */
            if (i != j)
            {
                if (arr1[i] == arr1[j])
                {
                    ctr++;
                }
            }
        }
        if (ctr == 0)
        {
            printf("%d ", arr1[i]);  // Print the unique element
        }
    }
    printf("\n\n");
    return 0;  // Return 0 to indicate successful execution
}
