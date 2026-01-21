/* Write an algorithm for Insertion Sort. Show how the array
 [22, 11, 44, 33, 55]
 */

#include <stdio.h>

int main()
{
    int arr[5] = {22, 11, 44, 33, 55};
    int i, j, key;

    for (i = 1; i < 5; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    printf("Sorted array using Insertion Sort:\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
