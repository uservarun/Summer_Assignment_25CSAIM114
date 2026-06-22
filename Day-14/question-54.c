#include <stdio.h>
int findFrequency(int arr[], int size, int target) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            count++;
        }
    }
    return count;
}
int main() {
    int size, target;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to find its frequency: ");
    scanf("%d", &target);
    int frequency = findFrequency(arr, size, target);
    printf("The element %d occurs %d times in the array.\n", target, frequency);
    return 0;
}