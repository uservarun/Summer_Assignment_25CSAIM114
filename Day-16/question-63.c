#include <stdio.h>
void findPairWithSum(int arr[], int n, int target) {
    int found = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                printf("Pair found: (%d, %d)\n", arr[i], arr[j]);
                found = 1;
                return;
            }
        }
    }
    if (!found) {
        printf("No pair found with the given sum.\n");
    }
}
int main() {
    int arr[] = {8, 7, 2, 5, 3, 1};
    int target = 10;
    int size = sizeof(arr) / sizeof(arr[0]);
    findPairWithSum(arr, size, target);
    return 0;
}