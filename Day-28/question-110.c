#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Account {
    int acc_num;
    char name[50];
    double balance;
};
void createAccount(FILE *fp) {
    struct Account a;
    printf("Enter Account Number: ");
    scanf("%d", &a.acc_num);
    getchar();
    printf("Enter Account Holder Name: ");
    fgets(a.name, 50, stdin);
    a.name[strcspn(a.name, "\n")] = 0;
    a.balance = 0.0;
    fseek(fp, 0, SEEK_END);
    fwrite(&a, sizeof(struct Account), 1, fp);
    printf("Account created successfully with 0.0 balance!\n");
}
void depositMoney(FILE *fp) {
    int num, found = 0;
    double amount;
    struct Account a;
    printf("Enter Account Number: ");
    scanf("%d", &num);
    rewind(fp);
    while (fread(&a, sizeof(struct Account), 1, fp)) {
        if (a.acc_num == num) {
            found = 1;
            printf("Enter Amount to Deposit: ");
            scanf("%lf", &amount);
            if (amount <= 0) {
                printf("Invalid amount.\n");
            } else {
                a.balance += amount;
                fseek(fp, -sizeof(struct Account), SEEK_CUR);
                fwrite(&a, sizeof(struct Account), 1, fp);
                printf("Successfully deposited. New Balance: %.2f\n", a.balance);
            }
            break;
        }
    }
    if (!found) printf("Account not found.\n");
}
void withdrawMoney(FILE *fp) {
    int num, found = 0;
    double amount;
    struct Account a;
    printf("Enter Account Number: ");
    scanf("%d", &num);
    rewind(fp);
    while (fread(&a, sizeof(struct Account), 1, fp)) {
        if (a.acc_num == num) {
            found = 1;
            printf("Enter Amount to Withdraw: ");
            scanf("%lf", &amount);
            if (amount > a.balance) {
                printf("Insufficient balance! Current Balance: %.2f\n", a.balance);
            } else if (amount <= 0) {
                printf("Invalid amount.\n");
            } else {
                a.balance -= amount;
                fseek(fp, -sizeof(struct Account), SEEK_CUR);
                fwrite(&a, sizeof(struct Account), 1, fp);
                printf("Successfully withdrawn. New Balance: %.2f\n", a.balance);
            }
            break;
        }
    }
    if (!found) printf("Account not found.\n");
}
void checkBalance(FILE *fp) {
    int num, found = 0;
    struct Account a;
    printf("Enter Account Number: ");
    scanf("%d", &num);
    rewind(fp);
    while (fread(&a, sizeof(struct Account), 1, fp)) {
        if (a.acc_num == num) {
            found = 1;
            printf("\nAccount Number: %d\n", a.acc_num);
            printf("Holder Name: %s\n", a.name);
            printf("Current Balance: %.2f\n", a.balance);
            break;
        }
    }
    if (!found) printf("Account not found.\n");
}
int main() {
    FILE *fp = fopen("bank.dat", "rb+");
    if (fp == NULL) {
        fp = fopen("bank.dat", "wb