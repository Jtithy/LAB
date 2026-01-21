/* Write an algorithm to sort an array using Deletion Sort, where the smallest element is repeatedly deleted from the list and stored in a new array until the original list becomes empty.
 Sort the array:
 [40, 10, 30, 20]
 */

#include <stdio.h>

int main()
{
    int arr[4] = {40, 10, 30, 20};
    int sorted[4];
    int n = 4;
    int i, j, min, index;

    for (i = 0; i < 4; i++)
    {
        min = arr[0];
        index = 0;

        for (j = 1; j < n; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                index = j;
            }
        }

        sorted[i] = min;

        for (j = index; j < n - 1; j++)
        {
            arr[j] = arr[j + 1];
        }

        n--;
    }

    for (i = 0; i < 4; i++)
    {
        printf("%d ", sorted[i]);
    }

    return 0;
}
