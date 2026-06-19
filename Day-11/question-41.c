#include <stdio.h>
int sum(int a, int b) {
    return a + b;
}
int main() {
    int num1;
    int num2;
    printf("Enter num1 ");
    scanf("%d",&num1);
    printf("Enter num2 ");
    scanf("%d",&num2);
    int result = sum(num1, num2);
    printf("Sum: %d\n", result);
    return 0;
}