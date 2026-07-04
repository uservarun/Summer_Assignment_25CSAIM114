#include <stdio.h>
int main() {
    int choice;
    float balance = 5000.0, amount;
    do {
        printf("\n--- ATM Simulation ---\n");
        printf("1. Check Balance\n2. Deposit\n3. Withdraw\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Your current balance is: $%.2f\n", balance);
                break;
            case 2:
                printf("Enter deposit amount: ");
                scanf("%f", &amount);
                if (amount > 0) {
                    balance += amount;
                    printf("$%.2f deposited successfully.\n", amount);
                } else {
                    printf("Invalid amount.\n");
                }
                break;
            case 3:
                printf("Enter withdrawal amount: ");
                scanf("%f", &amount);
                if (amount > balance) {
                    printf("Insufficient balance!\n");
                } else if (amount > 0) {
                    balance -= amount;
                    printf("$%.2f withdrawn successfully.\n", amount);
                } else {
                    printf("Invalid amount.\n");
                }
                break;
            case 4:
                printf("Thank you for using the ATM. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}