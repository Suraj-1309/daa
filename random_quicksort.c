#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Choose a random pivot and partition
int randomPartition(int arr[], int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);

    swap(&arr[randomIndex], &arr[high]); // Move random pivot to end
    return partition(arr, low, high);
}

// Randomized Quick Sort
void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomPartition(arr, low, high);

        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {34, 7, 23, 32, 5, 62};
    int n = sizeof(arr) / sizeof(arr[0]);

    srand(time(NULL)); // Seed random number generator

    printf("Original array: ");
    printArray(arr, n);

    randomizedQuickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 // Time Complexity: Best: O(n log n), Average: O(n log n), Worst: O(n^2)
 // Space Complexity: O(log n) on average (recursive stack), O(n) worst-case
// Explanation: Randomizing the pivot makes worst-case partitions unlikely, so
// the expected (average) cost is O(n log n). Worst-case still occurs if partitions
// are consistently unbalanced; recursion depth determines extra space.




