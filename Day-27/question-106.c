#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

void addEmployee(FILE *fp) {
    struct Employee e;
    printf("\nEnter Employee ID: ");
    scanf("%d", &e.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", e.name);
    printf("Enter Salary: ");
    scanf("%f", &e.salary);
    fseek(fp, 0, SEEK_END);
    fwrite(&e, sizeof(struct Employee), 1, fp);
    printf("Record added successfully!\n");
}

void displayEmployees(FILE *fp) {
    struct Employee e;
    rewind(fp);
    printf("\nID\tName\t\tSalary\n");
    printf("-----------------------------------\n");
    while (fread(&e, sizeof(struct Employee), 1, fp) == 1) {
        printf("%d\t%-15s\t%.2f\n", e.id, e.name, e.salary);
    }
}

void searchEmployee(FILE *fp) {
    struct Employee e;
    int id, found = 0;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);
    rewind(fp);
    while (fread(&e, sizeof(struct Employee), 1, fp) == 1) {
        if (e.id == id) {
            printf("\nRecord Found:\n");
            printf("ID: %d\nName: %s\nSalary: %.2f\n", e.id, e.name, e.salary);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee record not found.\n");
    }
}

void updateEmployee(FILE *fp) {
    struct Employee e;
    int id, found = 0;
    printf("\nEnter Employee ID to update: ");
    scanf("%d", &id);
    rewind(fp);
    while (fread(&e, sizeof(struct Employee), 1, fp) == 1) {
        if (e.id == id) {
            printf("Enter New Name: ");
            scanf(" %[^\n]", e.name);
            printf("Enter New Salary: ");
            scanf("%f", &e.salary);
            fseek(fp, -sizeof(struct Employee), SEEK_CUR);
            fwrite(&e, sizeof(struct Employee), 1, fp);
            printf("Record updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee record not found.\n");
    }
}

int main() {
    FILE *fp = fopen("employees.dat", "rb+");
    if (fp == NULL) {
        fp = fopen("employees.dat", "wb+");
        if (fp == NULL) {
            printf("Error creating or opening file.\n");
            return 1;
        }
    }
    int choice;
    while (1) {
        printf("\n=== Employee Management System ===\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEmployee(fp);
                break;
            case 2:
                displayEmployees(fp);
                break;
            case 3:
                searchEmployee(fp);
                break;
            case 4:
                updateEmployee(fp);
                break;
            case 5:
                fclose(fp);
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}