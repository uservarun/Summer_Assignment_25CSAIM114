#include <stdio.h>
int findMaxFrequencyElement(int arr[], int n) {
    int max_element = arr[0];
    int max_count = 0;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            max_element = arr[i];
        }
    }
    return max_element;
}
int main() {
    int arr[] = {1, 3, 2, 1, 4, 1, 3, 2, 1, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int max_freq_el = findMaxFrequencyElement(arr, size);
    printf("The element with the maximum frequency is: %d\n", max_freq_el);
    return 0;
}