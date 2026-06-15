#include <stdio.h>
int reverse_number(int n, int rev);
int main() {
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    int s = 1;
    if (num < 0) {
        s= -1;
        num = -num;
    }
    int reversed = s * reverse_number(num, 0);
    printf("Reversed number: %d\n", reversed);

    return 0;
}
int reverse_number(int n, int rev) {
    if (n == 0) {
        return rev;
    } else {
        return reverse_number(n / 10, rev * 10 + (n % 10));
    }
}