#include <stdio.h>
int checkDuplicates(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = i + 1; j < size; j++) {
            if(arr[i] == arr[j]) {
                return 1;
            }
        }
    }
    return 0;
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    if(checkDuplicates(arr, size)) {
        printf("Array contains duplicates.\n");
    } else {
        printf("Array does not contain duplicates.\n");
    }
    return 0;
}
