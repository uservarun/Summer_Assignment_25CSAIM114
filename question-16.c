#include <stdio.h>
int main() {
    int start, end, i, temp, remainder, n, result, power;
    printf("Enter lower and upper num ");
    scanf("%d %d", &start, &end);
    printf("Armstrong numbers between %d and %d are: ", start, end);
    for (i = start; i <= end; i++) {
        if (i < 0) continue;
        n = 0;
        temp = i;
        while (temp != 0) {
            temp /= 10;
            n++;
        }
        result = 0;
        temp = i;
        while (temp != 0) {
            remainder = temp % 10;
            power = 1;
            for (int j = 0; j < n; j++) {
                power *= remainder;
            }
            result += power;
            temp /= 10;
        }
        if (result == i) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}