#include <stdio.h>

void findLargestTwo(int arr[], int size) {
    int largest = arr[0], secondLargest = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if(arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }
    printf("Largest element: %d\n", largest);
    printf("Second largest element: %d\n", secondLargest);
}

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    findLargestTwo(arr, size);
    return 0;
}
