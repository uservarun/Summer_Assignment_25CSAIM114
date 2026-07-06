#include <stdio.h>
#include <stdlib.h>
int main() {
    int choice;
    double num1, num2, result;
    while(1) {
        printf("\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if(choice == 5) {
            exit(0);
        }
        if(choice >= 1 && choice <= 4) {
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
        }
        switch(choice) {
            case 1:
                result = num1 + num2;
                printf("Result: %.2lf\n", result);
                break;
            case 2:
                result = num1 - num2;
                printf("Result: %.2lf\n", result);
                break;
            case 3:
                result = num1 * num2;
                printf("Result: %.2lf\n", result);
                break;
            case 4:
                if(num2 != 0) {
                    result = num1 / num2;
                    printf("Result: %.2lf\n", result);
                } else {
                    printf("Error! Division by zero.\n");
                }
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}