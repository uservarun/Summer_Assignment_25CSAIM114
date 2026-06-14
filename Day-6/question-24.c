#include <stdio.h>
double power(double x, int n) {
    double result = 1.0;
    long long absN = n;
    if (absN < 0) {
        absN = -absN;
    }
    while (absN > 0) {
        if (absN % 2 == 1) {
            result *= x;
        }
        x *= x;
        absN /= 2;
    }
    if (n < 0) {
        return 1.0 / result;
    }
    return result;
}
int main() {
    double x;
    int n;
    printf("Enter base (x): ");
    scanf("%lf", &x);
    printf("Enter exponent (n): ");
    scanf("%d", &n);

    printf("%.6f^%d = %.6f\n", x, n, power(x, n));

    return 0;
}