#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student {
    int id;
    char name[50];
    float gpa;
};
void addStudent(FILE *fp) {
    struct Student s;
    printf("Enter ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);
    printf("Enter GPA: ");
    scanf("%f", &s.gpa);
    fwrite(&s, sizeof(struct Student), 1, fp);
}
void displayStudents(FILE *fp) {
    struct Student s;
    rewind(fp);
    printf("\nID\tName\t\tGPA\n");
    printf("---------------------------\n");
    while (fread(&s, sizeof(struct Student), 1, fp) == 1) {
        printf("%d\t%-15s\t%.2f\n", s.id, s.name, s.gpa);
    }
}
void searchStudent(FILE *fp) {
    struct Student s;
    int id, found = 0;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    rewind(fp);
    while (fread(&s, sizeof(struct Student), 1, fp) == 1) {
        if (s.id == id) {
            printf("\nID: %d\nName: %s\nGPA: %.2f\n", s.id, s.name, s.gpa);
            found = 1;
            break;
        }
    }
    if (!found) printf("Student not found.\n");
}
int main() {
    FILE *fp = fopen("students.dat", "rb+");
    if (fp == NULL) {
        fp = fopen("students.dat", "wb+");
        if (fp == NULL) {
            printf("Error opening file.\n");
            return 1;
        }
    }
    int choice;
    while (1) {
        printf("\n1. Add Student\n2. Display Students\n3. Search Student\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1) addStudent(fp);
        else if (choice == 2) displayStudents(fp);
        else if (choice == 3) searchStudent(fp);
        else if (choice == 4) break;
        else printf("Invalid choice.\n");
    }
    fclose(fp);
    return 0;
}