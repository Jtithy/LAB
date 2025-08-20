#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int temperatures[] = {32, 28, 35, 30, 31, 29, 34, 33, 36, 27};
    int n = sizeof(temperatures) / sizeof(temperatures[0]);
    printf("Original temperatures: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", temperatures[i]);
    }
    printf("\n");
    bubbleSort(temperatures, n);
    printf("Sorted temperatures: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", temperatures[i]);
    }
    printf("\n");
    int searchTemp;
    printf("Enter temperature to search for: ");
    scanf("%d", &searchTemp);
    int result = binarySearch(temperatures, 0, n - 1, searchTemp);
    if (result != -1) {
        printf("Temperature %d found at index %d in the sorted array.\n", searchTemp, result);
    } else {
        printf("Temperature %d not found in the array.\n", searchTemp);
    }
    return 0;
}