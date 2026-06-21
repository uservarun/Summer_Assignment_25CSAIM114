#include <stdio.h>
int main() {
    int n;
    int ceven = 0, codd = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            ceven++;
        } else {
            codd++;
        }
    }
    printf("Total even elements = %d\n", ceven);
    printf("Total odd elements = %d\n", codd);

    return 0;
}