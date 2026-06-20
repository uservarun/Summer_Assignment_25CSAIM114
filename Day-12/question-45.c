#include <stdio.h>

int isPalindrome(int num) {
    int rev = 0;
    int original = num;
    int rem;
    while (num > 0) {
        rem = num % 10;
        rev = rev* 10 + rem;
        num = num / 10;
    }
    if (original == rev) {
        return 1;
    } else {
        return 0;
    }
}
int main() {
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);
    if (isPalindrome(number)) {
        printf("%d is a palindrome.\n", number);
    } else {
        printf("%d is not a palindrome.\n", number);
    }
    return 0;
}