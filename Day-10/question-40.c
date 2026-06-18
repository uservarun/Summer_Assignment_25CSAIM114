#include <stdio.h>
int main() {
    int n = 5;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (int k = 1; k <= i; k++) {
            printf("%C", 'A' + k - 1);
        }
        for (int l = i - 1; l >= 1; l--) {
            printf("%C", 'A' + l - 1);
        }
        printf("\n");
    }
    return 0;
}