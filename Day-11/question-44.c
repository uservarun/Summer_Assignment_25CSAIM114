#include <stdio.h>
long long factorial(int n) {
    if (n < 0) {
        return -1;
    }
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}
int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    long long fact = factorial(num);
    if (fact == -1) {
        printf("Error\n");
    } else {
        printf("Factorial of %d = %lld\n", num, fact);
    }
    return 0;
}