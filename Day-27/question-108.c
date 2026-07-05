#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Marksheet {
    int rollNo;
    char name[50];
    float math;
    float science;
    float english;
    float total;
    float percentage;
    char grade[3];
};

void calculateGrades(struct Marksheet *m) {
    m->total = m->math + m->science + m->english;
    m->percentage = m->total / 3.0;

    if (m->percentage >= 90) strcpy(m->grade, "A+");
    else if (m->percentage >= 80) strcpy(m->grade, "A");
    else if (m->percentage >= 70) strcpy(m->grade, "B");
    else if (m->percentage >= 60) strcpy(m->grade, "C");
    else if (m->percentage >= 50) strcpy(m->grade, "D");
    else strcpy(m->grade, "F");
}

void addRecord(FILE *fp) {
    struct Marksheet m;
    printf("\nEnter Roll Number: ");
    scanf("%d", &m.rollNo);
    printf("Enter Student Name: ");
    scanf(" %[^\n]", m.name);
    printf("Enter Marks for Math (out of 100): ");
    scanf("%f", &m.math);
    printf("Enter Marks for Science (out of 100): ");
    scanf("%f", &m.science);
    printf("Enter Marks for English (out of 100): ");
    scanf("%f", &m.english);

    calculateGrades(&m);

    fseek(fp, 0, SEEK_END);
    fwrite(&m, sizeof(struct Marksheet), 1, fp);
    printf("\nRecord added successfully!\n");
}

void printMarksheet(struct Marksheet m) {
    printf("\n=============================================");
    printf("\n             OFFICIAL MARKSHEET              ");
    printf("\n=============================================");
    printf("\nRoll No : %-10d Student Name: %s", m.rollNo, m.name);
    printf("\n---------------------------------------------");
    printf("\nSubject          Maximum Marks     Marks Obtained");
    printf("\n---------------------------------------------");
    printf("\nMathematics           100              %6.2f", m.math);
    printf("\nScience               100              %6.2f", m.science);
    printf("\nEnglish               100              %6.2f", m.english);
    printf("\n---------------------------------------------");
    printf("\nTotal Marks:     300               Obtained: %.2f", m.total);
    printf("\nPercentage:      %-10.2f        Grade:    %s", m.percentage, m.grade);
    printf("\nResult:          %-10s", (m.percentage >= 50) ? "PASSED" : "FAILED");
    printf("\n=============================================\n");
}

void generateAllMarksheets(FILE *fp) {
    struct Marksheet m;
    rewind(fp);
    int count = 0;
    while (fread(&m, sizeof(struct Marksheet), 1, fp) == 1) {
        printMarksheet(m);
        count++;
    }
    if (count == 0) {
        printf("\nNo student records found.\n");
    }
}

void searchStudentMarksheet(FILE *fp) {
    struct Marksheet m;
    int roll, found = 0;
    printf("\nEnter Roll Number to generate marksheet: ");
    scanf("%d", &roll);

    rewind(fp);
    while (fread(&m, sizeof(struct Marksheet), 1, fp) == 1) {
        if (m.rollNo == roll) {
            printMarksheet(m);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nRecord not found for Roll Number %d.\n", roll);
    }
}

int main() {
    FILE *fp = fopen("marks.dat", "rb+");
    if (fp == NULL) {
        fp = fopen("marks.dat", "wb+");
        if (fp == NULL) {
            printf("Error: Cannot create data ledger.\n");
            return 1;
        }
    }

    int choice;
    while (1) {
        printf("\n======= MARKSHEET GENERATION SYSTEM =======");
        printf("\n1. Add Student Marks");
        printf("\n2. Generate All Report Cards");
        printf("\n3. Search & Generate Individual Marksheet");
        printf("\n4. Exit");
        printf("\nEnter choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addRecord(fp); break;
            case 2: generateAllMarksheets(fp); break;
            case 3: searchStudentMarksheet(fp); break;
            case 4:
                fclose(fp);
                printf("\nDatabase saved. Exiting...\n");
                exit(0);
            default: printf("\nInvalid option! Please select again.\n");
        }
    }
    return 0;
}