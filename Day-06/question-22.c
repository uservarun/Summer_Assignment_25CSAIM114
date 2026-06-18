#include <stdio.h>

int binaryToDecimal(long long n) {
    int decimalNum = 0;
    int base = 1;
    long long temp = n;
    while (temp > 0) {
        int lastDigit = temp % 10;
        temp = temp / 10;
        decimalNum += lastDigit * base;
        base = base * 2;
    }
    return decimalNum;
}
int main() {
    long long n;
    printf("Enter a binary number: ");
    scanf("%lld", &n);
    printf("Decimal equivalent: %d\n", binaryToDecimal(n));
    return 0;
}