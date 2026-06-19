#include <stdio.h>
int tmax(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}
int main() {
    int num1;
    int num2;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);
    int m = tmax(num1, num2);
    printf("Maximum: %d\n", m);
    return 0;
}