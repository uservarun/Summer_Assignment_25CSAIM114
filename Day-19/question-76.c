#include <stdio.h>
int main() {
    int i, j, sum = 0;
    int matrix[3][3];
    printf("Enter elements of the 3x3 matrix:\n");
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (i = 0; i < 3; ++i) {
        sum += matrix[i][i];
    }
    printf("Sum of the main diagonal elements: %d\n", sum);
    return 0;
}