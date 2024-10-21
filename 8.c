#include <stdio.h>

int sumArray(int arr[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int arr[] = {8, 2, 7, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Sum of array elements: %d\n", sumArray(arr, size));
    return 0;
}