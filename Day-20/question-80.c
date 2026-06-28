#include <stdio.h>
int main() {
    int matrix[10][10], rows, cols, sum;
    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int j = 0; j < cols; j++) {
        sum = 0;
        for (int i = 0; i < rows; i++) {
            sum += matrix[i][j];
        }
        printf("Sum of column %d = %d\n", j + 1, sum);
    }
    return 0;
}