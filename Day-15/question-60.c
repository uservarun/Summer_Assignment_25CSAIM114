#include <stdio.h>
void moveZeroesToEnd(int arr[], int size) {
    int nonZeroPos = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            int temp = arr[i];
            arr[i] = arr[nonZeroPos];
            arr[nonZeroPos] = temp;
            
            nonZeroPos++;
        }
    }
}
int main() {
    int arr[] = {1, 0, 3, 0, 12, 0, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    moveZeroesToEnd(arr, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}