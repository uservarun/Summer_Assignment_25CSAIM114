#include <stdio.h>
void findDuplicates(int arr[], int size) {
    int foundDuplicate = 0;
    for (int i = 0; i < size; i++) {
        int isAlreadyPrinted = 0;
        for (int k = 0; k < i; k++) {
            if (arr[i] == arr[k]) {
                isAlreadyPrinted = 1;
                break;
            }
        }
        if (isAlreadyPrinted) {
            continue;
        }
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                if (!foundDuplicate) {
                    printf("Duplicate elements are: ");
                    foundDuplicate = 1;
                }
                printf("%d ", arr[i]);
                break;
            }
        }
    }
    if (!foundDuplicate) {
        printf("No duplicate elements found in the array.");
    }
    printf("\n");
}
int main() {
    int size;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    findDuplicates(arr, size);
    return 0;
}