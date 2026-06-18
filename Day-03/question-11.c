#include <stdio.h>

int main() {
    int n1, n2, a, b, temp;
    printf("Enter two integers: ");
    scanf("%d %d", &n1, &n2);
    a = n1;
    b = n2;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    printf("GCD of %d and %d is %d\n", n1, n2, a);
    return 0;
}