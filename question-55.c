#include <stdio.h>
#include <limits.h>
int findSecondLargest(int arr[], int size) {
    int first = INT_MIN;
    int second = INT_MIN;

    for (int i = 0; i < size; i++) {
        if (arr[i] > first) {
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }
    return second;
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
    int secondLargest = findSecondLargest(arr, size);
    if (secondLargest == INT_MIN) {
        printf("There is no second largest unique element.\n");
    } else {
        printf("The second largest element is: %d\n", secondLargest);
    }
    return 0;
}