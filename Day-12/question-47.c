#include <stdio.h>
void Fibonacci(int terms) {
    int t1 = 0, t2 = 1;
    int t3;
    for (int i = 1; i <= terms; ++i) {
        printf("%d ", t1);
        t3 = t1 + t2;
        t1 = t2;
        t2 = t3;
    }
    printf("\n");
}
int main() {
    int terms;
    printf("Enter the number of terms: ");
    scanf("%d", &terms);
    printf("Fibonacci Sequence: ");
    Fibonacci(terms);

    return 0;
}