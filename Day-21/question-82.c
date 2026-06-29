#include <stdio.h>
int main() {
    char str[100], temp;
    int left = 0, right = 0;
    printf("Enter a string: ");
    scanf("%s", str);
    while (str[right] != '\0') {
        right++;
    }
    right--;
    while (left < right) {
        temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
    printf("Reversed string: %s\n", str);
    return 0;
}