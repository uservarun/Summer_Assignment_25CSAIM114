#include <stdio.h>
int main() {
    int arr1[] = {1, 2, 4, 5, 6};
    int arr2[] = {2, 3, 5, 7};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int i, j, k;
    printf("Union of arrays: ");
    for (i = 0; i < size1; i++) {
        printf("%d ", arr1[i]);
    }
    for (i = 0; i < size2; i++) {
        int isDuplicate = 0;
        for (j = 0; j < size1; j++) {
            if (arr2[i] == arr1[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            printf("%d ", arr2[i]);
        }
    }
    printf("\n");
    return 0;
}