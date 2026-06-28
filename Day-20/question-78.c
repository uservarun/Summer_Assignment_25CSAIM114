#include <stdio.h>
int main() {
    int matrix[10][10], rows, cols, isSymmetric = 1;
    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);
    if (rows != cols) {
        printf("The matrix is not symmetric.\n");
        return 0;
    }
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
        if (!isSymmetric) {
            break;
        }
    }
    if (isSymmetric) {
        printf("The matrix is symmetric.\n");
    } else {
        printf("The matrix is not symmetric.\n");
    }
    return 0;
}