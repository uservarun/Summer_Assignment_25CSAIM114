#include <stdio.h>
int removeDuplicates(int arr[], int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                n--;
                j--; 
            }
        }
    }
    return n;
}
int main() {
    int arr[] = {2, 3, 2, 4, 5, 3, 6, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    size = removeDuplicates(arr, size);
    printf("Array after removing duplicates: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}