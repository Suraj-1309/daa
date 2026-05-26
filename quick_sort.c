#include<stdio.h>

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high;j++){
        if(arr[j] < pivot){
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1 , high);
    }
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted Array: ");
    printArray(arr, n);

    return 0;
}




















// Time Complexity: Best: O(n log n), Average: O(n log n), Worst: O(n^2)
// Space Complexity: O(log n) average (recursive stack), O(n) worst-case
// Explanation: Quick sort partitions and recurses; balanced partitions give O(n log n),
// but highly unbalanced partitions (sorted input with bad pivot) give O(n^2). Recursion
// depth is O(log n) on average.