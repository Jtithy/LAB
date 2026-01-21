/* Write an algorithm for Bubble Sort and use it to sort the following array in ascending order:
 [34, 12, 25, 9, 18] */

#include <stdio.h>

int main()
{
    int arr[5] = {34, 12, 25, 9, 18};
    int i, j, temp;
    // Sorted by Bubble Sort
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    // Showing sorting output
    printf("The sorting array in ascending order:\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
