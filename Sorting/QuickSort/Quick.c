// Write a code using your suitable language(C,C++,Java,any other) for Quick sort.

#include <stdio.h>

// For element swapping
void swap(int *m, int *n)
{
    int t = *m;
    *m = *n;
    *n = t;
}

// Using partitioning method to sort
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j)
    {
        while (arr[i] <= pivot && i <= high)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main()
{
    int a[6] = {9, 1, 5, 6, 35, 60};

    // Function call to sort
    quickSort(a, 0, 5);

    // Printing the sorted array
    printf("Sorted Array Using Quick Sort Technigue:\n");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
