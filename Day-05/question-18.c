#include <stdio.h>
int main() {
    int num, original, rem, sum = 0;
    long fact;
    printf("Enter an integer: ");
    scanf("%d", &num);
    original = num; 
    while (num > 0) {
        rem = num % 10;
        fact = 1;
        for (int i = 1; i <= rem; i++) {
            fact *= i;
        }

        sum += fact;   // Add the factorial to sum
        num /= 10;     // Remove the last digit
    }
    if (sum == original && original > 0) {
        printf("%d is a Strong Number.\n", original);
    } else {
        printf("%d is NOT a Strong Number.\n", original);
    }
    return 0;
}