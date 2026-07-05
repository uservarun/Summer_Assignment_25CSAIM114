#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SalaryRecord {
    int empId;
    char name[50];
    float baseSalary;
    float allowance;
    float deduction;
    float netSalary;
};

void calculateNetSalary(struct SalaryRecord *s) {
    s->netSalary = s->baseSalary + s->allowance - s->deduction;
}

void addSalaryRecord(FILE *fp) {
    struct SalaryRecord s;
    printf("\nEnter Employee ID: ");
    scanf("%d", &s.empId);
    printf("Enter Employee Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter Base Salary ($): ");
    scanf("%f", &s.baseSalary);
    printf("Enter Allowances ($): ");
    scanf("%f", &s.allowance);
    printf("Enter Deductions ($): ");
    scanf("%f", &s.deduction);
    
    calculateNetSalary(&s);
    
    fseek(fp, 0, SEEK_END);
    fwrite(&s, sizeof(struct SalaryRecord), 1, fp);
    printf("\nSalary record added successfully!\n");
}

void displaySalarySlip(struct SalaryRecord s) {
    printf("\n====================================");
    printf("\n           SALARY SLIP              ");
    printf("\n====================================");
    printf("\nEmployee ID  : %d", s.empId);
    printf("\nName         : %s", s.name);
    printf("\n------------------------------------");
    printf("\nBase Salary  : $%10.2f", s.baseSalary);
    printf("\nAllowances   : +$%9.2f", s.allowance);
    printf("\nDuctions     : -$%9.2f", s.deduction);
    printf("\n------------------------------------");
    printf("\nNet Salary   : $%10.2f", s.netSalary);
    printf("\n====================================\n");
}

void displayAllRecords(FILE *fp) {
    struct SalaryRecord s;
    rewind(fp);
    
    printf("\n%-7s %-15s %-12s %-10s %-10s %-12s\n", "ID", "Name", "Base Sal", "Allow.", "Deduct.", "Net Salary");
    printf("--------------------------------------------------------------------------\n");
    
    int count = 0;
    while (fread(&s, sizeof(struct SalaryRecord), 1, fp) == 1) {
        printf("%-7d %-15s %-12.2f %-10.2f %-10.2f %-12.2f\n", 
               s.empId, s.name, s.baseSalary, s.allowance, s.deduction, s.netSalary);
        count++;
    }
    if (count == 0) {
        printf("No records found.\n");
    }
}

void searchSalaryRecord(FILE *fp) {
    struct SalaryRecord s;
    int id, found = 0;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);
    
    rewind(fp);
    while (fread(&s, sizeof(struct SalaryRecord), 1, fp) == 1) {
        if (s.empId == id) {
            displaySalarySlip(s);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Record not found for Employee ID %d.\n", id);
    }
}

void updateSalaryComponents(FILE *fp) {
    struct SalaryRecord s;
    int id, found = 0;
    printf("\nEnter Employee ID to update payroll: ");
    scanf("%d", &id);
    
    rewind(fp);
    while (fread(&s, sizeof(struct SalaryRecord), 1, fp) == 1) {
        if (s.empId == id) {
            printf("\nCurrent details found. Enter updated financial data:\n");
            printf("New Base Salary ($): ");
            scanf("%f", &s.baseSalary);
            printf("New Allowances ($): ");
            scanf("%f", &s.allowance);
            printf("New Deductions ($): ");
            scanf("%f", &s.deduction);
            
            calculateNetSalary(&s);
            
            fseek(fp, -sizeof(struct SalaryRecord), SEEK_CUR);
            fwrite(&s, sizeof(struct SalaryRecord), 1, fp);
            printf("\nPayroll record updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Record not found for Employee ID %d.\n", id);
    }
}

int main() {
    FILE *fp = fopen("payroll.dat", "rb+");
    if (fp == NULL) {
        fp = fopen("payroll.dat", "wb+");
        if (fp == NULL) {
            printf("Critical Error: Cannot open or create payroll ledger file.\n");
            return 1;
        }
    }
    
    int choice;
    while (1) {
        printf("\n======= SALARY MANAGEMENT SYSTEM =======");
        printf("\n1. Add Employee Payroll Record");
        printf("\n2. View All Salary Sheets");
        printf("\n3. Search & Generate Salary Slip");
        printf("\n4. Modify Salary Components");
        printf("\n5. Exit");
        printf("\nEnter choice (1-5): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addSalaryRecord(fp); break;
            case 2: displayAllRecords(fp); break;
            case 3: searchSalaryRecord(fp); break;
            case 4: updateSalaryComponents(fp); break;
            case 5: 
                fclose(fp); 
                printf("\nDatabase closed safely. Exiting...\n"); 
                exit(0);
            default: printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}