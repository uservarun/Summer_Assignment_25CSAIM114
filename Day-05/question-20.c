#include <stdio.h>
int main() {
    long long num, originalNum;
    long long mpf = -1;
    printf("Enter a positive integer: ");
    scanf("%lld", &num);
    originalNum = num;
    if (num <= 1) {
        printf("Numbers less than or equal to 1 do not have prime factors.\n");
        return 0;
    }
    while (num % 2 == 0) {
        mpf= 2;
        num /= 2;
    }
    for (long long i = 3; i * i <= num; i += 2) {
        while (num % i == 0) {
            mpf= i;
            num /= i;
        }
    }
    if (num > 2) {
        mpf = num;
    }
    printf("The largest prime factor of %lld is: %lld\n", originalNum, mpf);
    return 0;
}