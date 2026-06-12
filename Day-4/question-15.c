#include <stdio.h>
#include <math.h>
int isArmstrong(int num) {
    int originalNum = num;
    int remainder;
    int n = 0;
    int result = 0;
    while (originalNum != 0) {
        originalNum /= 10;
        ++n;
    }
    originalNum = num;
    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += pow(remainder, n);
        originalNum /= 10;
    }
    if (result == num)
        return 1;
    else
        return 0;
}
int main() {
    int num;
    printf("Enter an integer: ");
    if (scanf("%d", &num) != 1) {
        return 1;
    }
    if (isArmstrong(num))
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);
    return 0;
}