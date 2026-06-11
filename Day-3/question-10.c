#include <stdio.h>
#include <stdbool.h>
#include <math.h>
int main() {
    int l, u;
    printf("Enter lower limit: ");
    scanf("%d", &l);
    printf("Enter upper limit: ");
    scanf("%d", &u);
    printf("Prime numbers between %d and %d are:\n", l, u);
    for (int num = l; num <= u; num++) {
        if (num <= 1) {
            continue;
        }
        bool isPrime = true;
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            printf("%d ", num);
        }
    }
    return 0;
}